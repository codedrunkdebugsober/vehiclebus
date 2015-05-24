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

/**
 * @file    controller_area_network.h
 * @brief   CAN message utilities.
 */

#ifndef CONTROLLER_AREA_NETWORK_H_
#define CONTROLLER_AREA_NETWORK_H_

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
 * Inclusion Dependencies
 *****************************************************************************/

#include <stdint.h>
#ifdef __linux__
#include <linux/can.h>
#else
#define CAN_EFF_FLAG 0x80000000U /* EFF/SFF is set in the MSB */
#define CAN_RTR_FLAG 0x40000000U /* remote transmission request */
#define CAN_ERR_FLAG 0x20000000U /* error frame */
#endif

/*****************************************************************************
 * Macros
 *****************************************************************************/

#define CONTROLLER_AREA_NETWORK_MESSAGE_PAYLOAD_MAX_LENGTH  (8)   /**< Maximum can message payload size. */

#define STANDARD_CAN_ADDRESSING_MAX_ID_VAL                  (0x7FF)

/*****************************************************************************
 * Type and Constant definitions
 *****************************************************************************/

typedef uint32_t canid_t;

#ifndef __linux__

/**
 * struct can_frame - basic CAN frame structure
 * @can_id:  the CAN ID of the frame and CAN_*_FLAG flags, see above.
 * @can_dlc: the data length field of the CAN frame
 * @data:    the CAN frame payload.
 */
struct can_frame
{
    uint32_t can_id;  /* 32 bit CAN_ID + EFF/RTR/ERR flags */
    uint8_t can_dlc; /* data length code: 0 .. 8 */
    uint8_t data[8] __attribute__((aligned(8)));
};

#endif

typedef struct can_frame can_frame_t;

/*****************************************************************************
 * Global Declarations
 *****************************************************************************/

/*****************************************************************************
 * Public Function Prototypes
 *****************************************************************************/



#ifdef __cplusplus
}
#endif

#endif /* CONTROLLER_AREA_NETWORK_H_ */
