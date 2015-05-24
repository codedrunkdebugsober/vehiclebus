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

#ifndef BYTE_ARRAY_CONVERSION_H_
#define BYTE_ARRAY_CONVERSION_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "sizeof_types.h"

int16_t read_s16_from_byte_buffer_lsb(unsigned char const * const ptr_buffer);

int16_t read_s16_from_byte_buffer_msb(unsigned char const * const ptr_buffer);

#ifdef __cplusplus
}
#endif

#endif /* BYTE_ARRAY_CONVERSION_H_ */
