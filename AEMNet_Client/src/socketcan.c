/*
 * The MIT License (MIT)
 *
 * Copyright (c) [2015] [James O'Carroll]
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <string.h>
#include <unistd.h>
#include <linux/can.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <errno.h>
#include "socketcan.h"
#include "panic.h"

int socketcan_bind_to_interface(char const * const interface_name, char block_receive)
{
    struct sockaddr_can addr;
    struct ifreq ifr;
    int socket_handle;

    socket_handle = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    if (socket_handle < 0)
    {
        PANIC("socket");
    }
    memset(&ifr.ifr_name, 0, sizeof(ifr.ifr_name));
    strncpy(ifr.ifr_name, interface_name, IFNAMSIZ);
    if (ioctl(socket_handle, SIOCGIFINDEX, &ifr) < 0)
    {
        PANIC("SIOCGIFINDEX");
    }
    memset(&addr, 0, sizeof(addr));
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;
    if (bind(socket_handle, (struct sockaddr *) &addr, sizeof(addr)) < 0)
    {
        PANIC("bind");
    }

//    int flags = fcntl(socket_handle, F_GETFL);
//    fcntl(socket_handle, flags | O_NONBLOCK);

    if (!block_receive)
    {
        struct timeval timeVal;
        timeVal.tv_sec = 0;
        timeVal.tv_usec = 10000;
        (void)setsockopt(socket_handle, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeVal, sizeof(struct timeval));
    }

//                            recv_own_msgs = 0; /* 0 = disabled (default), 1 = enabled */
//                            setsockopt(sk, SOL_CAN_RAW, CAN_RAW_RECV_OWN_MSGS, &recv_own_msgs, sizeof(recv_own_msgs));
    return socket_handle;
}

void write_can_frame(int socket_handle, can_frame_t const * const frame)
{
    static unsigned int overload_count = 0;
    ssize_t written_bytes;

    do
    {
        written_bytes = write(socket_handle, frame, sizeof(can_frame_t));
        if (-1 == written_bytes)
        {
            if (ENOBUFS != errno)
            {
                PANIC("Failed to write to can bus");
            }
            else
            {
                printf("write overload #%d\n", overload_count++);
                usleep(1000);
            }
        }
    } while (written_bytes != sizeof(can_frame_t));
}

