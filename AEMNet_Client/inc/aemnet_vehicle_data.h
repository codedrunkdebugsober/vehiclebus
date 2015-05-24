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

#ifndef AEMNET_VEHICLE_DATA_H_
#define AEMNET_VEHICLE_DATA_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    double engine_speed;
    double engine_load;
    double throttle;
    uint8_t air_temp;
    uint8_t coolant_temp;

    double analog_9;
    double analog_10;
    double analog_11;
    double analog_12;

    double analog_13;
    double analog_14;
    double analog_15;
    double analog_16;

    double o2_1;
    double o2_2;
    double vehicle_speed;
    uint8_t gear_calculated;
    double ignition_timing;
    double battery_volts;
} aemnet_vehicle_data_t;

#ifdef __cplusplus
}
#endif

#endif /* AEMNET_VEHICLE_DATA_H_ */
