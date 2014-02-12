/**************************************************************************/
/*!
    @file     ili9325.h
    @author   S. Jung (tummychow)

    @section LICENSE

    Software License Agreement (BSD License)

    Copyright (c) 2014, S. Jung
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
    1. Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
    3. Neither the name of the copyright holders nor the
    names of its contributors may be used to endorse or promote products
    derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ''AS IS'' AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
/**************************************************************************/

// file based on hx8347g.h, macros mass-renamed for ILI9325 instead
// the two displays have hardware similarities (both 8-bit 8080 interfaces)
// but their initializations are quite different

// some credit is owed to https://github.com/adafruit/TFTLCD-Library
// ktown's older lpc1343 codebase, which had a native ili9325 driver, was also
// a valuable reference

#ifndef __ILI9325_H__
#define __ILI9325_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "projectconfig.h"
#include "drivers/displays/graphic/lcd.h"

// Backlight enable and reset pins
#define ILI9325_BL_PORT               (1)
#define ILI9325_BL_PIN                (27)
#define ILI9325_RES_PORT              (1)
#define ILI9325_RES_PIN               (28)

// Control pins (these should be on the same port for best performance)
#define ILI9325_CONTROL_PORT          (1)
#define ILI9325_CS_PIN                (13)
#define ILI9325_CD_PIN                (14)
#define ILI9325_WR_PIN                (15)
#define ILI9325_RD_PIN                (16)

// Combined pin definitions for optimisation purposes.
#define ILI9325_CS_CD_PINS            ((1<<ILI9325_CS_PIN) + (1<<ILI9325_CD_PIN))
#define ILI9325_RD_WR_PINS            ((1<<ILI9325_RD_PIN) + (1<<ILI9325_WR_PIN))
#define ILI9325_WR_CS_PINS            ((1<<ILI9325_WR_PIN) + (1<<ILI9325_CS_PIN))
#define ILI9325_CD_RD_WR_PINS         ((1<<ILI9325_CD_PIN) + (1<<ILI9325_RD_PIN) + (1<<ILI9325_WR_PIN))
#define ILI9325_CS_CD_RD_WR_PINS      ((1<<ILI9325_CS_PIN) + (1<<ILI9325_CD_PIN) + (1<<ILI9325_RD_PIN) + (1<<ILI9325_WR_PIN))

// Data bus (data pins must be consecutive and on the same port)
#define ILI9325_DATA_PORT             (1)
#define ILI9325_DATA_PIN1             (19)
#define ILI9325_DATA_PIN2             (20)
#define ILI9325_DATA_PIN3             (21)
#define ILI9325_DATA_PIN4             (22)
#define ILI9325_DATA_PIN5             (23)
#define ILI9325_DATA_PIN6             (24)
#define ILI9325_DATA_PIN7             (25)
#define ILI9325_DATA_PIN8             (26)
#define ILI9325_DATA_OFFSET           (ILI9325_DATA_PIN1)
#define ILI9325_DATA_MASK             (0xFF << ILI9325_DATA_OFFSET)

// Macros to set data bus direction to input/output
#define ILI9325_GPIO2DATA_SETINPUT    do { LPC_GPIO->DIR[ILI9325_DATA_PORT] &= ~ILI9325_DATA_MASK; } while(0)
#define ILI9325_GPIO2DATA_SETOUTPUT   do { LPC_GPIO->DIR[ILI9325_DATA_PORT] |= ILI9325_DATA_MASK; } while(0)

// Macros for control line state
// NOPs required since the bit-banding is too fast for some ILI9325s to handle :(
#define CLR_CD                        do { LPC_GPIO->CLR[ILI9325_CONTROL_PORT] = (1 << ILI9325_CD_PIN); } while(0)
#define SET_CD                        do { LPC_GPIO->SET[ILI9325_CONTROL_PORT] = (1 << ILI9325_CD_PIN); } while(0)
#define CLR_CS                        do { LPC_GPIO->CLR[ILI9325_CONTROL_PORT] = (1 << ILI9325_CS_PIN); } while(0)
#define SET_CS                        do { LPC_GPIO->SET[ILI9325_CONTROL_PORT] = (1 << ILI9325_CS_PIN); } while(0)
#define CLR_WR                        do { LPC_GPIO->CLR[ILI9325_CONTROL_PORT] = (1 << ILI9325_WR_PIN); } while(0)
#define SET_WR                        do { LPC_GPIO->SET[ILI9325_CONTROL_PORT] = (1 << ILI9325_WR_PIN); } while(0)
#define CLR_RD                        do { LPC_GPIO->CLR[ILI9325_CONTROL_PORT] = (1 << ILI9325_RD_PIN); } while(0)
#define SET_RD                        do { LPC_GPIO->SET[ILI9325_CONTROL_PORT] = (1 << ILI9325_RD_PIN); } while(0)
#define CLR_RESET                     do { LPC_GPIO->CLR[ILI9325_RES_PORT] = (1 << ILI9325_RES_PORT); } while(0)
#define SET_RESET                     do { LPC_GPIO->SET[ILI9325_RES_PORT] = (1 << ILI9325_RES_PORT); } while(0)
#define CLR_BL                        do { LPC_GPIO->CLR[ILI9325_BL_PORT] = (1 << ILI9325_BL_PORT); } while(0)
#define SET_BL                        do { LPC_GPIO->SET[ILI9325_BL_PORT] = (1 << ILI9325_BL_PORT); } while(0)

// These 'combined' macros are defined to improve code performance by
// reducing the number of instructions in heavily used functions
#define CLR_CS_CD                     do { LPC_GPIO->CLR[ILI9325_CONTROL_PORT] = (ILI9325_CS_CD_PINS); } while(0)
#define SET_RD_WR                     do { LPC_GPIO->SET[ILI9325_CONTROL_PORT] = (ILI9325_RD_WR_PINS); } while(0)
#define SET_WR_CS                     do { LPC_GPIO->SET[ILI9325_CONTROL_PORT] = (ILI9325_WR_CS_PINS); } while(0)
#define SET_CD_RD_WR                  do { LPC_GPIO->SET[ILI9325_CONTROL_PORT] = (ILI9325_CD_RD_WR_PINS); } while(0)
#define CLR_CS_CD_SET_RD_WR           do { LPC_GPIO->CLR[ILI9325_CONTROL_PORT] = (ILI9325_CS_CD_PINS); LPC_GPIO->SET[ILI9325_CONTROL_PORT] = (ILI9325_RD_WR_PINS); } while(0)
#define CLR_CS_SET_CD_RD_WR           do { LPC_GPIO->CLR[ILI9325_CONTROL_PORT] = (ILI9325_CS_PIN); LPC_GPIO->SET[ILI9325_CONTROL_PORT] = (ILI9325_CD_RD_WR_PINS); } while(0)

// Used to indicate a delay in the init sequence
#define ILI9325_INIT_DELAY                      (0xF8)  // 0xFF is already used

// these init codes were taken from adafruit's ILI9325 lib
#define ILI9325_START_OSC                       (0x00)
#define ILI9325_DRIV_OUT_CTRL                   (0x01)
#define ILI9325_DRIV_WAV_CTRL                   (0x02)
#define ILI9325_ENTRY_MOD                       (0x03)
#define ILI9325_RESIZE_CTRL                     (0x04)
#define ILI9325_DISP_CTRL1                      (0x07)
#define ILI9325_DISP_CTRL2                      (0x08)
#define ILI9325_DISP_CTRL3                      (0x09)
#define ILI9325_DISP_CTRL4                      (0x0A)
#define ILI9325_RGB_DISP_IF_CTRL1               (0x0C)
#define ILI9325_FRM_MARKER_POS                  (0x0D)
#define ILI9325_RGB_DISP_IF_CTRL2               (0x0F)
#define ILI9325_POW_CTRL1                       (0x10)
#define ILI9325_POW_CTRL2                       (0x11)
#define ILI9325_POW_CTRL3                       (0x12)
#define ILI9325_POW_CTRL4                       (0x13)
#define ILI9325_GRAM_HOR_AD                     (0x20)
#define ILI9325_GRAM_VER_AD                     (0x21)
#define ILI9325_RW_GRAM                         (0x22)
#define ILI9325_POW_CTRL7                       (0x29)
#define ILI9325_FRM_RATE_COL_CTRL               (0x2B)
#define ILI9325_GAMMA_CTRL1                     (0x30)
#define ILI9325_GAMMA_CTRL2                     (0x31)
#define ILI9325_GAMMA_CTRL3                     (0x32)
#define ILI9325_GAMMA_CTRL4                     (0x35)
#define ILI9325_GAMMA_CTRL5                     (0x36)
#define ILI9325_GAMMA_CTRL6                     (0x37)
#define ILI9325_GAMMA_CTRL7                     (0x38)
#define ILI9325_GAMMA_CTRL8                     (0x39)
#define ILI9325_GAMMA_CTRL9                     (0x3C)
#define ILI9325_GAMMA_CTRL10                    (0x3D)
#define ILI9325_HOR_START_AD                    (0x50)
#define ILI9325_HOR_END_AD                      (0x51)
#define ILI9325_VER_START_AD                    (0x52)
#define ILI9325_VER_END_AD                      (0x53)
#define ILI9325_GATE_SCAN_CTRL1                 (0x60)
#define ILI9325_GATE_SCAN_CTRL2                 (0x61)
#define ILI9325_GATE_SCAN_CTRL3                 (0x6A)
#define ILI9325_PART_IMG1_DISP_POS              (0x80)
#define ILI9325_PART_IMG1_START_AD              (0x81)
#define ILI9325_PART_IMG1_END_AD                (0x82)
#define ILI9325_PART_IMG2_DISP_POS              (0x83)
#define ILI9325_PART_IMG2_START_AD              (0x84)
#define ILI9325_PART_IMG2_END_AD                (0x85)
#define ILI9325_PANEL_IF_CTRL1                  (0x90)
#define ILI9325_PANEL_IF_CTRL2                  (0x92)
#define ILI9325_PANEL_IF_CTRL3                  (0x93)
#define ILI9325_PANEL_IF_CTRL4                  (0x95)
#define ILI9325_PANEL_IF_CTRL5                  (0x97)
#define ILI9325_PANEL_IF_CTRL6                  (0x98)

#ifdef __cplusplus
}
#endif

#endif
