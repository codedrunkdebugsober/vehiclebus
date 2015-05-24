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

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <endian.h>
#include <getopt.h>
#include <stdbool.h>
#include "controller_area_network.h"
#include "aemnet_client.h"
#include "aemnet_vehicle_data.h"
#include "aemnet_terminal.h"
#include "socketcan.h"
#include "terminal.h"
#include "panic.h"

static void print_aemnet_status();
static void sigterm(int signo);

static const struct option long_options[] =
{
    { "interface", required_argument, 0, 'i' },
    { 0, 0, 0, 0 }
};

static int keepRunning = 1;
static aemnet_vehicle_data_t aemnet_vehicle_data;
static char vehicle_data_updated = false;

//void decode_aemnet_data_1(can_f)

//http://aemelectronics.com/sites/default/files/forumfiles/Infinity%20AEMNet%20CAN%20Channels.pdf
//http://www.carid.com/images/aem/fuel-systems/pdf/30-2340-installation-instructions.pdf

int main(int argc, char **argv)
{
    int option_index = 0;
    int c;
    char* can_interface = NULL;

    if (argc > 0)
    {
        while (1)
        {
            option_index = 0;
            /*
             * With respect to the third argument, options:
             * Options with no colon have no arguments.
             * Options with one colon have a required argument
             * Options with two colons have an optional argument
             */
            c = getopt_long(argc, argv, "i:", long_options, &option_index);

            /* Detect the end of the options. */
            if (c == -1)
            {
                break;
            }

            switch (c)
            {
                case 0:
                    /* If this option set a flag, do nothing else now. */
                    if (long_options[option_index].flag != 0)
                    {
                        break;
                    }
                    printf("option %s", long_options[option_index].name);
                    if (optarg)
                    {
                        printf(" with arg %s", optarg);
                    }
                    printf("\n");
                    break;
                case 'i':
                    can_interface = optarg;
                    break;
                default:
                    printf("Unknown option\n");
                    break;
            }
        }
    }

    if (NULL == can_interface)
    {
        printf("syntax: %s -i can_interface <-t>\n", argv[0]);
        DIE();
    }

    signal(SIGTERM, sigterm);
    signal(SIGHUP, sigterm);
    signal(SIGINT, sigterm);

    (void)memset(&aemnet_vehicle_data, 0, sizeof(aemnet_vehicle_data));
    int socket_handle = socketcan_bind_to_interface(can_interface, true);

    start_aemnet_client(socket_handle, &aemnet_vehicle_data);

    terminal_set_cursor_invisible();
    terminal_reset_screen();
    print_aemnet_status();
    while (keepRunning)
    {
//        if (vehicle_data_updated)
//        {
            print_aemnet_status();
            vehicle_data_updated = false;
//        }c
    }
    terminal_reset_screen();
    terminal_set_cursor_visible();
    return 0;
}

static void print_aemnet_status()
{
    terminal_set_position_home();

    print_aemnet_vehicle_data(&aemnet_vehicle_data);
}

static void sigterm(int signo)
{
    keepRunning = 0;
}
