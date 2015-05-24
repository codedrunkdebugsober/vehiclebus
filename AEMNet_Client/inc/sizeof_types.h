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

#ifndef SIZEOF_TYPES_H_
#define SIZEOF_TYPES_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <limits.h>

#if __x86_64__
/* 64-bit */
#define SIZEOF_POINTER  (8)

#else

#define SIZEOF_POINTER  (4)

#endif


#if (LONG_MAX == LONG_LONG_MAX)

#define SIZEOF_LONG     (8)

#elif (LONG_MAX == INT_MAX)

#define SIZEOF_LONG     (4)

#endif

#if (INT_MAX == CHAR_MAX)

#define SIZEOF_INT      (1)

#elif (INT_MAX == SHORT_MAX)

#define SIZEOF_INT      (2)

#else

#define SIZEOF_INT      (4)

#endif

#ifdef __cplusplus
}
#endif

#endif /* SIZEOF_TYPES_H_ */
