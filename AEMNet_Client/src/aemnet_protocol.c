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

#include "aemnet_protocol.h"
#include "aemnet_decoder.h"
#include "byte_array_conversion.h"

void aemnet_decode_data_1_message(can_frame_t const * const frame,
        double * const engine_speed,
        double * const engine_load,
        double * const throttle,
        uint8_t * const air_temp,
        uint8_t * const coolant_temp)
{
    *engine_speed = aemnet_decode_engine_speed(read_s16_from_byte_buffer_msb(&frame->data[0]));
    *engine_load = aemnet_decode_engine_load(read_s16_from_byte_buffer_msb(&frame->data[2]));
    *throttle = aemnet_decode_throttle(read_s16_from_byte_buffer_msb(&frame->data[4]));
    *air_temp = aemnet_decode_air_temp(frame->data[6]);
    *coolant_temp = aemnet_decode_coolant_temp(frame->data[7]);
}

void aemnet_decode_analog_1_message(can_frame_t const * const frame,
        double * const analog_9,
        double * const analog_10,
        double * const analog_11,
        double * const analog_12)
{
    *analog_9 = aemnet_decode_analog(read_s16_from_byte_buffer_msb(&frame->data[0]));
    *analog_10 = aemnet_decode_analog(read_s16_from_byte_buffer_msb(&frame->data[2]));
    *analog_11 = aemnet_decode_analog(read_s16_from_byte_buffer_msb(&frame->data[4]));
    *analog_12 = aemnet_decode_analog(read_s16_from_byte_buffer_msb(&frame->data[6]));
}

void aemnet_decode_analog_2_message(can_frame_t const * const frame,
        double * const analog_13,
        double * const analog_14,
        double * const analog_15,
        double * const analog_16)
{
    *analog_13 = aemnet_decode_analog(read_s16_from_byte_buffer_msb(&frame->data[0]));
    *analog_14 = aemnet_decode_analog(read_s16_from_byte_buffer_msb(&frame->data[2]));
    *analog_15 = aemnet_decode_analog(read_s16_from_byte_buffer_msb(&frame->data[4]));
    *analog_16 = aemnet_decode_analog(read_s16_from_byte_buffer_msb(&frame->data[6]));
}

void aemnet_decode_data_2_message(can_frame_t const * const frame,
        double * const o2_1,
        double * const o2_2,
        double * const vehicle_speed,
        uint8_t * const gear_calculated,
        double * const ignition_timing,
        double * const battery_volts)
{
    *o2_1 = aemnet_decode_o2(frame->data[0]);
    *o2_2 = aemnet_decode_o2(frame->data[1]);
    *vehicle_speed = aemnet_decode_vehicle_speed(read_s16_from_byte_buffer_msb(&frame->data[2]));
    *gear_calculated = aemnet_decode_gear_calculated(frame->data[4]);
    *ignition_timing = aemnet_decode_ignition_timing(frame->data[5]);
    *battery_volts = aemnet_decode_battery_volts(read_s16_from_byte_buffer_msb(&frame->data[6]));
}
