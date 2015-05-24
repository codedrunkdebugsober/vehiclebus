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

#include "aemnet_decoder.h"
#include "panic.h"
#include "util.h"

#define AEMNET_ENGINE_SPEED_MIN_VAL         0.0
#define AEMNET_ENGINE_SPEED_MAX_VAL         25599.94

#define AEMNET_ENGINE_LOAD_MIN_VAL          0.0
#define AEMNET_ENGINE_LOAD_MAX_VAL          99.998

#define AEMNET_THROTTLE_MIN_VAL             0.0
#define AEMNET_THROTTLE_MAX_VAL             99.998

#define AEMNET_ANALOG_MIN_VAL               0.0
#define AEMNET_ANALOG_MAX_VAL               5.0999

#define AEMNET_O2_MIN_VAL                   0.5
#define AEMNET_O2_MAX_VAL                   1.496

#define AEMNET_VEHICLE_SPEED_MIN_VAL        0.0
#define AEMNET_VEHICLE_SPEED_MAX_VAL        255.996

#define AEMNET_GEAR_CALCULATED_MIN_VAL      0
#define AEMNET_GEAR_CALCULATED_MAX_VAL      255

#define AEMNET_IGNITION_TIMING_MIN_VAL      -17.0
#define AEMNET_IGNITION_TIMING_MAX_VAL      72.65

#define AEMNET_BATTERY_VOLTS_MIN_VAL        0
#define AEMNET_BATTERY_VOLTS_MAX_VAL        16.089

/**
 * Convert the AEMnet encoded engine speed value into RPM.
 *
 * @param   The AEMnet encoded engine speed.
 *
 * @return  Engine RPM.
 */
double aemnet_decode_engine_speed(uint16_t encoded_engine_speed)
{
    double decoded_engine_speed;

    decoded_engine_speed = encoded_engine_speed * 0.39063;
    decoded_engine_speed = CLAMP(decoded_engine_speed, AEMNET_ENGINE_SPEED_MIN_VAL, AEMNET_ENGINE_SPEED_MAX_VAL);
    return decoded_engine_speed;
}

/**
 * Convert the AEMnet encoded engine load into a standard engine load percentage.
 *
 * @param   AEMnet encoded engine load.
 *
 * @return  Engine load (percentage value ranging from AEMNET_ENGINE_LOAD_MIN_VAL to AEMNET_ENGINE_LOAD_MAX_VAL)
 */
double aemnet_decode_engine_load(uint16_t encoded_engine_load)
{
    double decoded_engine_load;

    decoded_engine_load = encoded_engine_load * 0.0015259;
    decoded_engine_load = CLAMP(decoded_engine_load, AEMNET_ENGINE_LOAD_MIN_VAL, AEMNET_ENGINE_LOAD_MAX_VAL);
    return decoded_engine_load;
}


double aemnet_decode_throttle(uint16_t encoded_throttle)
{
    double decoded_throttle;

    decoded_throttle = encoded_throttle * 0.0015259;
    decoded_throttle = CLAMP(decoded_throttle, AEMNET_THROTTLE_MIN_VAL, AEMNET_THROTTLE_MAX_VAL);
    return decoded_throttle;
}

int8_t aemnet_decode_air_temp(uint8_t encoded_air_temp)
{
    return (int8_t)encoded_air_temp;
}

int8_t aemnet_decode_coolant_temp(uint8_t encoded_coolant_temp)
{
    return (int8_t)encoded_coolant_temp;
}

double aemnet_decode_analog(uint16_t encoded_analog_value)
{
    double decoded_analog_value;

    decoded_analog_value = encoded_analog_value * 0.00007782;
    decoded_analog_value = CLAMP(decoded_analog_value, AEMNET_ANALOG_MIN_VAL, AEMNET_ANALOG_MAX_VAL);
    return decoded_analog_value;
}

double aemnet_decode_o2(uint8_t encoded_o2)
{
    double decoded_o2;

    decoded_o2 = encoded_o2 * 0.00390625 + .5;
    decoded_o2 = CLAMP(decoded_o2, AEMNET_O2_MIN_VAL, AEMNET_O2_MAX_VAL);
    return decoded_o2;
}

double aemnet_decode_vehicle_speed(uint16_t encoded_speed)
{
    double decoded_vehicle_speed;

    decoded_vehicle_speed = encoded_speed * 0.00390625;
    decoded_vehicle_speed = CLAMP(decoded_vehicle_speed, AEMNET_VEHICLE_SPEED_MIN_VAL, AEMNET_VEHICLE_SPEED_MAX_VAL);
    return decoded_vehicle_speed;
}

uint8_t aemnet_decode_gear_calculated(uint8_t encoded_gear_calculated)
{
    return encoded_gear_calculated;
}

double aemnet_decode_ignition_timing(uint8_t encoded_ignition_timing)
{
    double decoded_ignition_timing;

    decoded_ignition_timing = encoded_ignition_timing * 0.35156 - 17;
    decoded_ignition_timing = CLAMP(decoded_ignition_timing, AEMNET_IGNITION_TIMING_MIN_VAL, AEMNET_IGNITION_TIMING_MAX_VAL);
    return decoded_ignition_timing;
}

double aemnet_decode_battery_volts(uint16_t encoded_battery_volts)
{
    double decoded_vehicle_speed;

    decoded_vehicle_speed = encoded_battery_volts * 0.0002455;
    decoded_vehicle_speed = CLAMP(decoded_vehicle_speed, AEMNET_BATTERY_VOLTS_MIN_VAL, AEMNET_BATTERY_VOLTS_MAX_VAL);
    return decoded_vehicle_speed;
}
