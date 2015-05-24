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
#include <stdbool.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <pthread.h>
#include <endian.h>
#include "aemnet_client.h"
#include "aemnet_protocol.h"
#include "aemnet_decoder.h"
#include "socketcan.h"
#include "controller_area_network.h"
#include "panic.h"

#define AEMNET_ID_DATA_1_ID     0x01F0A000
#define AEMNET_ID_ANALOG_1_ID   0x01F0A001
#define AEMNET_ID_ANALOG_2_ID   0x01F0A002
#define AEMNET_ID_DATA_2_ID     0x01F0A003

static void *aemnet_receive_thread(void *arg);
static void receive_can_message(void);
static void parse_aemnet_can_message(can_frame_t const * const frame);

static int socket_handle;
static pthread_t aemnet_receive_thread_handle;
static char keepRunning = false;
static aemnet_vehicle_data_t *aemnet_vehicle_data = NULL;

void start_aemnet_client(int sock_handle, aemnet_vehicle_data_t *ptr_aemnet_vehicle_data)
{
    int status;

    socket_handle = sock_handle;
    aemnet_vehicle_data = ptr_aemnet_vehicle_data;

    status = pthread_create(&aemnet_receive_thread_handle, NULL, aemnet_receive_thread, NULL);
    if (status != 0)
    {
        PANIC("pthread_create");
    }
}

static void *aemnet_receive_thread(void *arg)
{
    keepRunning = true;

    while (keepRunning)
    {
        receive_can_message();
    }

    return NULL;
}

static void receive_can_message(void)
{
    can_frame_t frame;
    int ret;

    ret = recv(socket_handle, &frame, sizeof(can_frame_t), 0);

    if (ret < 0)
    {
        PANIC("recvfrom");
    }

    frame.can_id = frame.can_id & CAN_EFF_MASK;

    parse_aemnet_can_message(&frame);
}

static void parse_aemnet_can_message(can_frame_t const * const frame)
{
    switch (frame->can_id)
    {
        case AEMNET_ID_DATA_1_ID:

            aemnet_decode_data_1_message(frame,
                    &aemnet_vehicle_data->engine_speed,
                    &aemnet_vehicle_data->engine_load,
                    &aemnet_vehicle_data->throttle,
                    &aemnet_vehicle_data->air_temp,
                    &aemnet_vehicle_data->coolant_temp);
            break;
        case AEMNET_ID_ANALOG_1_ID:
            aemnet_decode_analog_1_message(frame,
                    &aemnet_vehicle_data->analog_9,
                    &aemnet_vehicle_data->analog_10,
                    &aemnet_vehicle_data->analog_11,
                    &aemnet_vehicle_data->analog_12);
            break;
        case AEMNET_ID_ANALOG_2_ID:
            aemnet_decode_analog_2_message(frame,
                    &aemnet_vehicle_data->analog_13,
                    &aemnet_vehicle_data->analog_14,
                    &aemnet_vehicle_data->analog_15,
                    &aemnet_vehicle_data->analog_16);
            break;
        case AEMNET_ID_DATA_2_ID:
            aemnet_decode_data_2_message(frame,
                    &aemnet_vehicle_data->o2_1,
                    &aemnet_vehicle_data->o2_2,
                    &aemnet_vehicle_data->vehicle_speed,
                    &aemnet_vehicle_data->gear_calculated,
                    &aemnet_vehicle_data->ignition_timing,
                    &aemnet_vehicle_data->battery_volts);
            break;
        default:
#warning "TODO: Log message"
            break;
    }
}
