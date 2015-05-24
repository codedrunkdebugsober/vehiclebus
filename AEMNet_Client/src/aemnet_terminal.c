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
#include "aemnet_terminal.h"

void print_aemnet_vehicle_data(aemnet_vehicle_data_t const * const aemnet_vehicle_data)
{
    printf("engine_speed:                                   %f\r\n", aemnet_vehicle_data->engine_speed);
    printf("engine_load:                                    %f\r\n", aemnet_vehicle_data->engine_load);
    printf("throttle:                                       %f\r\n", aemnet_vehicle_data->throttle);
    printf("air_temp:                                       %u\r\n", aemnet_vehicle_data->air_temp);
    printf("coolant_temp:                                   %u\r\n", aemnet_vehicle_data->coolant_temp);
    printf("analog_9:                                       %f\r\n", aemnet_vehicle_data->analog_9);
    printf("analog_10:                                      %f\r\n", aemnet_vehicle_data->analog_10);
    printf("analog_11:                                      %f\r\n", aemnet_vehicle_data->analog_11);
    printf("analog_12:                                      %f\r\n", aemnet_vehicle_data->analog_12);
    printf("analog_13:                                      %f\r\n", aemnet_vehicle_data->analog_13);
    printf("analog_14:                                      %f\r\n", aemnet_vehicle_data->analog_14);
    printf("analog_15:                                      %f\r\n", aemnet_vehicle_data->analog_15);
    printf("analog_16:                                      %f\r\n", aemnet_vehicle_data->analog_16);
    printf("O2 1:                                           %f\r\n", aemnet_vehicle_data->o2_1);
    printf("O2 2:                                           %f\r\n", aemnet_vehicle_data->o2_2);
    printf("vehicle_speed:                                  %f\r\n", aemnet_vehicle_data->vehicle_speed);
    printf("gear_calculated:                                %u\r\n", aemnet_vehicle_data->gear_calculated);
    printf("ignition_timing:                                %f\r\n", aemnet_vehicle_data->ignition_timing);
    printf("battery_volts:                                  %f\r\n", aemnet_vehicle_data->battery_volts);
}
