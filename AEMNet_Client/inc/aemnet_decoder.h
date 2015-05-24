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

#ifndef AEMNET_DECODER_H_
#define AEMNET_DECODER_H_

#include <stdint.h>
#include "controller_area_network.h"

#ifdef __cplusplus
extern "C" {
#endif

double aemnet_decode_engine_speed(uint16_t encoded_engine_speed);
double aemnet_decode_engine_load(uint16_t encoded_engine_load);
double aemnet_decode_throttle(uint16_t encoded_throttle);
int8_t aemnet_decode_air_temp(uint8_t encoded_air_temp);
int8_t aemnet_decode_coolant_temp(uint8_t encoded_coolant_temp);
double aemnet_decode_analog(uint16_t encoded_analog_value);
double aemnet_decode_o2(uint8_t encoded_o2);
double aemnet_decode_vehicle_speed(uint16_t encoded_speed);
uint8_t aemnet_decode_gear_calculated(uint8_t encoded_gear_calculated);
double aemnet_decode_ignition_timing(uint8_t encoded_ignition_timing);
double aemnet_decode_battery_volts(uint16_t encoded_battery_volts);

#ifdef __cplusplus
}
#endif

#endif /* AEMNET_DECODER_H_ */
