/**************************************************************************/
/*!
    @file     ili9325.c
    @author   S. Jung (tummychow)

    @section  DESCRIPTION

    Driver for ILI9325 240x320 pixel TFT LCD displays.

    This driver uses an 8-bit interface and a 16-bit RGB565 colour palette.

    Code is heavily derived from the HX8347G driver (which uses the same
    interface) and an older LPC1343 driver written by K. Townsend.

    @section  LICENSE

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
#include "ili9325.h"
#include "core/delay/delay.h"
#include "core/gpio/gpio.h"
// #include "drivers/displays/graphic/touchscreen.h"

static volatile lcdOrientation_t lcdOrientation = LCD_ORIENTATION_PORTRAIT;

// Screen/Driver Properties
// i have added support for hw orientation/scroll, so the properties have
// been changed
static lcdProperties_t ili9325Properties = { 240, // Screen width
                                             320, // Screen height
                                             true, // Has touchscreen?
                                             true, // Allows orientation changes?
                                             true, // Supports HW scrolling?
                                             true, // Driver includes fast horizontal line function?
                                             true }; // Driver includes fast vertical line function?

// this init sequence is lifted from adafruit ili9325 lib
// i tried to add some comments, but refer to datasheet for register details
static const uint16_t ILI9325_InitSequence[] = {
    // shift outputs from S720 to S1
    ILI9325_DRIV_OUT_CTRL, 0x0100,
    // turn on line inversion
    ILI9325_DRIV_WAV_CTRL, 0x0700,
    // enable GRAM address increment in either dir (horizontal selected)
    // swap RGB to BGR when writing to GRAM
    ILI9325_ENTRY_MOD, 0x1030,
    // front porch = 3, back porch = 2
    ILI9325_DISP_CTRL2, 0x0302,
    // configure some non-display-area drive controls
    ILI9325_DISP_CTRL3, 0x0000,
    // FMARK on
    ILI9325_DISP_CTRL4, 0x0000,
    // initialize power control registers
    ILI9325_POW_CTRL1, 0x0000,
    ILI9325_POW_CTRL2, 0x0007,
    ILI9325_POW_CTRL3, 0x0000,
    ILI9325_POW_CTRL4, 0x0000,
    ILI9325_INIT_DELAY, 1000,
    // activate source driver and power supply
    ILI9325_POW_CTRL1, 0x14B0,
    ILI9325_INIT_DELAY, 500,
    // lower the stepup frequencies
    ILI9325_POW_CTRL2, 0x0007,
    ILI9325_INIT_DELAY, 500,
    // enable VGL and set vreg1out
    ILI9325_POW_CTRL3, 0x008E,
    // vcom to 1.1x vreg1out
    ILI9325_POW_CTRL4, 0x0C00,
    // vcomh to 0.895x vreg1out
    ILI9325_POW_CTRL7, 0x0015,
    ILI9325_INIT_DELAY, 500,
    // set up gamma correction
    ILI9325_GAMMA_CTRL1, 0x0000,
    ILI9325_GAMMA_CTRL2, 0x0107,
    ILI9325_GAMMA_CTRL3, 0x0000,
    ILI9325_GAMMA_CTRL4, 0x0203,
    ILI9325_GAMMA_CTRL5, 0x0402,
    ILI9325_GAMMA_CTRL6, 0x0000,
    ILI9325_GAMMA_CTRL7, 0x0207,
    ILI9325_GAMMA_CTRL8, 0x0000,
    ILI9325_GAMMA_CTRL9, 0x0203,
    ILI9325_GAMMA_CTRL10, 0x0403,
    // set initial cursor positions
    ILI9325_GRAM_HOR_AD, 0x0000,
    ILI9325_GRAM_VER_AD, 0x0000,
    // set intial window positions (covers the whole screen)
    ILI9325_HOR_START_AD, 0x0000,
    ILI9325_HOR_END_AD, 0x00EF, // 239
    ILI9325_VER_START_AD, 0x0000,
    ILI9325_VER_END_AD, 0x013F, // 319
    // set up gate scan
    ILI9325_GATE_SCAN_CTRL1, 0xA700,
    // enable scrolling and greyscale inversion
    ILI9325_GATE_SCAN_CTRL2, 0x0003,
    // 16 clocks per line
    ILI9325_PANEL_IF_CTRL1, 0x0010,
    // enable gate drivers and turn the display on
    ILI9325_DISP_CTRL1, 0x0133,
    ILI9325_INIT_DELAY, 500,
};

/*************************************************/
/* Private Methods                               */
/*************************************************/
void ili9325Delay(unsigned int t)
{
    unsigned char t1;
    while (t--)
        for (t1 = 10; t1 > 0; t1--)
        {
            ASM("nop");
        }
}

/**************************************************************************/
/*!
    @brief  Sends a 16-bit command + 16-bits data
*/
/**************************************************************************/
void ili9325WriteRegister(uint16_t command, uint16_t data)
{
    // Write command
    CLR_CS_CD_SET_RD_WR;
    LPC_GPIO->MPIN[ILI9325_DATA_PORT] = (command >> 8) << ILI9325_DATA_OFFSET;
    CLR_WR;
    SET_WR;
    LPC_GPIO->MPIN[ILI9325_DATA_PORT] = (command & 0xFF) << ILI9325_DATA_OFFSET;
    CLR_WR;
    SET_WR;

    // Write data
    SET_CD;
    LPC_GPIO->MPIN[ILI9325_DATA_PORT] = (data >> 8) << ILI9325_DATA_OFFSET;
    CLR_WR;
    SET_WR;
    LPC_GPIO->MPIN[ILI9325_DATA_PORT] = (data & 0xFF) << ILI9325_DATA_OFFSET;
    CLR_WR;
    SET_WR;
}

/**************************************************************************/
/*!
    @brief  Sends a 16-bit command
*/
/**************************************************************************/
void ili9325WriteCommand(const uint16_t command)
{
    // Send command
    CLR_CS_CD_SET_RD_WR;
    LPC_GPIO->MPIN[ILI9325_DATA_PORT] = (command >> 8) << ILI9325_DATA_OFFSET;
    CLR_WR;
    SET_WR;
    LPC_GPIO->MPIN[ILI9325_DATA_PORT] = (command & 0xFF) << ILI9325_DATA_OFFSET;
    CLR_WR;
    SET_WR;
}

/**************************************************************************/
/*!
    @brief  Sends 16-bits of data
*/
/**************************************************************************/
void ili9325WriteData(const uint16_t data)
{
    // Send data
    CLR_CS_SET_CD_RD_WR;
    // This won't work since it will only set the 1 bits and leave 0's as is
    LPC_GPIO->MPIN[ILI9325_DATA_PORT] = (data >> 8) << ILI9325_DATA_OFFSET;
    CLR_WR;
    SET_WR;
    // This won't work since it will only set the 1 bits and leave 0's as is
    LPC_GPIO->MPIN[ILI9325_DATA_PORT] = (data & 0xFF) << ILI9325_DATA_OFFSET;
    CLR_WR;
    SET_WR;
}

/**************************************************************************/
/*!
    @brief  Reads the results from a 16-bit command
*/
/**************************************************************************/
uint16_t ili9325ReadRegister(uint16_t command)
{
    uint8_t high, low;
    high = low = 0;

    // Send command
    CLR_CS_CD_SET_RD_WR;
    LPC_GPIO->MPIN[ILI9325_DATA_PORT] = (command >> 8) << ILI9325_DATA_OFFSET;
    CLR_WR;
    SET_WR;
    LPC_GPIO->MPIN[ILI9325_DATA_PORT] = (command & 0xFF) << ILI9325_DATA_OFFSET;
    CLR_WR;
    SET_WR;

    // Set pins to input
    ILI9325_GPIO2DATA_SETINPUT;

    // Read results
    SET_CD_RD_WR;
    CLR_RD;
    ili9325Delay(10);
    high = LPC_GPIO->MPIN[ILI9325_DATA_PORT] >> ILI9325_DATA_OFFSET;
    printf("high: 0x%02X\r\n", high);
    SET_RD;
    CLR_RD;
    ili9325Delay(10);
    low = LPC_GPIO->MPIN[ILI9325_DATA_PORT] >> ILI9325_DATA_OFFSET;
    printf("low: 0x%02X\r\n", low);
    SET_RD;
    SET_CS;

    // Set pins to output
    ILI9325_GPIO2DATA_SETOUTPUT;

    return (uint16_t)((high << 8) | (low));
}

/**************************************************************************/
/*!
    @brief  Reads 16-bits of data from the current pixel location
*/
/**************************************************************************/
uint16_t ili9325ReadData(void)
{
    uint8_t high, low;
    high = low = 0;

    CLR_CS_SET_CD_RD_WR;

    // Set pins to input
    ILI9325_GPIO2DATA_SETINPUT;
    CLR_RD;
    ili9325Delay(10);
    high = LPC_GPIO->MPIN[ILI9325_DATA_PORT] >> ILI9325_DATA_OFFSET;
    printf("high: 0x%02X\r\n", high);
    SET_RD;
    CLR_RD;
    ili9325Delay(10);
    low = LPC_GPIO->MPIN[ILI9325_DATA_PORT] >> ILI9325_DATA_OFFSET;
    printf("low: 0x%02X\r\n", low);
    SET_RD;
    SET_CS;
    ILI9325_GPIO2DATA_SETOUTPUT;

    return (uint16_t)((high << 8) | (low));
}

/**************************************************************************/
/*!
    @brief  Sets the cursor to the specified X/Y position
*/
/**************************************************************************/
void ili9325SetCursor(const uint16_t x, const uint16_t y)
{
    // updated from adafruit ili9325lib
    ili9325WriteRegister(ILI9325_GRAM_HOR_AD, x);
    ili9325WriteRegister(ILI9325_GRAM_VER_AD, y);
}

/**************************************************************************/
/*!
    @brief  Sends the initialisation sequence to the display controller
*/
/**************************************************************************/
void ili9325InitDisplay(void)
{
    uint8_t i, a, d;

    // Clear data line
    LPC_GPIO->CLR[ILI9325_DATA_PORT] |= ILI9325_DATA_MASK;

    SET_RD;
    SET_WR;
    SET_CS;
    SET_CD;

    // Reset display
    CLR_RESET;
    delay(10);
    SET_RESET;
    delay(500);

    // Send the init sequence
    // the original loop length calculation was based on an array of uint8_t
    // so sizeof the first element is 1 byte and you can divide by 2 to get half
    // the elements, as needed
    // now that we're using uint16_t, we need to make sure that the sizeof gets
    // scaled up properly
    // i hope this constant is getting calculated at compile time
    for (i = 0; i < sizeof(ILI9325_InitSequence) / (2 * sizeof(ILI9325_InitSequence[0])); i++)
    {
        a = ILI9325_InitSequence[i * 2];
        d = ILI9325_InitSequence[i * 2 + 1];

        if (a == ILI9325_INIT_DELAY)
        {
            // the hx8347g code would choose to always delay for 1000 "units"
            // for now, i've set the delay to be proportional to the # of units
            // encoded in the init array
            // i'm not sure what the units are atm so this may require a fix,
            // the init array encodes delays in milliseconds
            ili9325Delay(d);
        }
        else
        {
            ili9325WriteRegister(a, d);
        }
    }
}

/**************************************************************************/
/*!
    @brief  Sets the window confines
*/
/**************************************************************************/
void ili9325SetWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
{
    // this is derived from the lpc1343 codebase version, whose arguments are
    // slightly different (takes x0, y0, width and height)
    // for this, i'm going to assume the args are absolute coords,
    // and x0<x1 and y0<y1
    ili9325WriteRegister(ILI9325_HOR_START_AD, x0);
    ili9325WriteRegister(ILI9325_HOR_END_AD, x1);
    ili9325WriteRegister(ILI9325_VER_START_AD, y0);
    ili9325WriteRegister(ILI9325_VER_END_AD, y1);

    ili9325SetCursor(x0, y0);
}

/*************************************************/
/* Public Methods                                */
/*************************************************/

/**************************************************************************/
/*!
    @brief  Configures any pins or HW and initialises the LCD controller
*/
/**************************************************************************/
void lcdInit(void)
{
    // Set control line pins to output
    LPC_GPIO->DIR[ILI9325_CONTROL_PORT] |= (1 << ILI9325_CS_PIN);
    LPC_GPIO->DIR[ILI9325_CONTROL_PORT] |= (1 << ILI9325_CD_PIN);
    LPC_GPIO->DIR[ILI9325_CONTROL_PORT] |= (1 << ILI9325_WR_PIN);
    LPC_GPIO->DIR[ILI9325_CONTROL_PORT] |= (1 << ILI9325_RD_PIN);

    // Set data port pins to output
    ILI9325_GPIO2DATA_SETOUTPUT;
    // set up GPIO masking for data port - EXPERIMENTAL
    LPC_GPIO->MASK[ILI9325_DATA_PORT] = ~ILI9325_DATA_MASK;

    // Set backlight pin to output and turn it on
    LPC_GPIO->DIR[ILI9325_BL_PORT] |= (1 << ILI9325_BL_PIN);
    lcdBacklight(TRUE);

    // Set reset pin to output
    LPC_GPIO->DIR[ILI9325_RES_PORT] |= (1 << ILI9325_RES_PIN);
    // Low then high to reset
    CLR_RESET;
    delay(50);
    SET_RESET;

    // Initialize the display
    ili9325InitDisplay();

    delay(50);

    // Set lcd to default orientation
    // i uncommented this now that lcd orientation is implemented
    // the default, as set earlier in this file, is PORTRAIT
    lcdSetOrientation(lcdOrientation);

    // Fill screen
    lcdFillRGB(COLOR_BLUE);

    // Initialise the touch screen (and calibrate if necessary)
    // tsInit();
}

/**************************************************************************/
/*!
    @brief  Enables or disables the LCD backlight
*/
/**************************************************************************/
void lcdBacklight(bool state)
{
    // Set the backlight
    if (state)
    {
        SET_BL;
    }
    else
    {
        CLR_BL;
    }
}

/**************************************************************************/
/*!
    @brief  Renders a simple test pattern on the LCD
*/
/**************************************************************************/
void lcdTest(void)
{
    // SJ todo: add an interesting test pattern
}

/**************************************************************************/
/*!
    @brief  Fills the LCD with the specified 16-bit color
*/
/**************************************************************************/
void lcdFillRGB(uint16_t color)
{
    uint32_t i;
    i = lcdGetWidth() * lcdGetHeight();

    ili9325SetCursor(0, 0);
    ili9325WriteCommand(ILI9325_RW_GRAM); // command code changed from hx8347

    // Fill screen
    while (i--)
    {
        ili9325WriteData(color);
    }
}

/**************************************************************************/
/*!
    @brief  Draws a single pixel at the specified X/Y location
*/
/**************************************************************************/
void lcdDrawPixel(uint16_t x, uint16_t y, uint16_t color)
{
    if ((x >= lcdGetWidth()) || (y >= lcdGetHeight()))
        return;

    ili9325SetCursor(x, y);
    ili9325WriteCommand(ILI9325_RW_GRAM); // command code changed from hx8347
    ili9325WriteData(color);
}

/**************************************************************************/
/*!
    @brief  Draws an array of consecutive RGB565 pixels (much
            faster than addressing each pixel individually)
*/
/**************************************************************************/
void lcdDrawPixels(uint16_t x, uint16_t y, uint16_t *data, uint32_t len)
{
    // SJ todo: implement this?
}

/**************************************************************************/
/*!
    @brief  Optimised routine to draw a horizontal line faster than
            setting individual pixels
*/
/**************************************************************************/
void lcdDrawHLine(uint16_t x0, uint16_t x1, uint16_t y, uint16_t color)
{
    // Allows for slightly better performance than setting individual pixels
    // SJ todo: implement in terms of adafruit ili9325::flood ?
    uint16_t x, pixels;

    if (x1 < x0)
    {
        // Switch x1 and x0
        x = x1;
        x1 = x0;
        x0 = x;
    }

    // Check limits
    if (x1 >= lcdGetWidth())
    {
        x1 = lcdGetWidth() - 1;
    }
    if (x0 >= lcdGetWidth())
    {
        x0 = lcdGetWidth() - 1;
    }

    ili9325SetCursor(x0, y);
    ili9325WriteCommand(ILI9325_RW_GRAM); // command changed from hx8347
    // Draw line
    for (pixels = 0; pixels < x1 - x0 + 1; pixels++)
    {
        ili9325WriteData(color);
    }
}

/**************************************************************************/
/*!
    @brief  Optimised routine to draw a vertical line faster than
            setting individual pixels
*/
/**************************************************************************/
void lcdDrawVLine(uint16_t x, uint16_t y0, uint16_t y1, uint16_t color)
{
    // implemented as in lpc1343 codebase: rotate, draw, unrotate
    // in fact i literally c+ped the code and it still compiled
    lcdOrientation_t orientation = lcdOrientation;
    lcdSetOrientation(orientation == LCD_ORIENTATION_PORTRAIT ? LCD_ORIENTATION_LANDSCAPE : LCD_ORIENTATION_PORTRAIT);

    lcdDrawHLine(y0, y1, lcdGetHeight() - (x + 1), color);

    lcdSetOrientation(orientation);
}

/**************************************************************************/
/*!
    @brief  Gets the 16-bit color of the pixel at the specified location
*/
/**************************************************************************/
uint16_t lcdGetPixel(uint16_t x, uint16_t y)
{
    // ktown had a warning here about how the first pixel read had to be
    // ignored because of hx8347 latching behavior
    // i'm not sure if it applies to ili9325, i'll read the datasheet later to
    // check, but for now i have removed his warning

    if ((x >= ili9325Properties.width) || (y >= ili9325Properties.height))
        return 0;

    ili9325SetCursor(x, y);
    ili9325WriteCommand(ILI9325_RW_GRAM); // command changed from hx8347
    return ili9325ReadData();
}

/**************************************************************************/
/*!
    @brief  Sets the LCD orientation to horizontal and vertical
*/
/**************************************************************************/
void lcdSetOrientation(lcdOrientation_t orientation)
{
    uint16_t entryMode = 0x1030;
    uint16_t outputControl = 0x0100;

    // implemented from ktown lpc1343 codebase
    if (orientation == LCD_ORIENTATION_LANDSCAPE)
    {
        entryMode = 0x1028;
        outputControl = 0x0000;
    }

    ili9325WriteRegister(ILI9325_ENTRY_MOD, entryMode);
    ili9325WriteRegister(ILI9325_DRIV_OUT_CTRL, outputControl);
    ili9325SetCursor(0, 0);
    lcdOrientation = orientation;
}

/**************************************************************************/
/*!
    @brief  Gets the current screen orientation (horizontal or vertical)
*/
/**************************************************************************/
lcdOrientation_t lcdGetOrientation(void)
{
    // implemented (trivially) from ktown lpc1343
    return lcdOrientation;
}

/**************************************************************************/
/*!
    @brief  Gets the width in pixels of the LCD screen (varies depending
            on the current screen orientation)
*/
/**************************************************************************/
uint16_t lcdGetWidth(void)
{
    // after adding rotation, i figured i should implement this
    if (lcdOrientation == LCD_ORIENTATION_PORTRAIT)
        return ili9325Properties.width;
    return ili9325Properties.height;
}

/**************************************************************************/
/*!
    @brief  Gets the height in pixels of the LCD screen (varies depending
            on the current screen orientation)
*/
/**************************************************************************/
uint16_t lcdGetHeight(void)
{
    // and this one too
    if (lcdOrientation == LCD_ORIENTATION_PORTRAIT)
        return ili9325Properties.height;
    return ili9325Properties.width;
}

/**************************************************************************/
/*!
    @brief  Scrolls the contents of the LCD screen vertically the
            specified number of pixels using a HW optimised routine
*/
/**************************************************************************/
void lcdScroll(int16_t pixels, uint16_t fillColor)
{
    // copied from lpc1343 codebase
    int16_t y = pixels;
    while (y < 0)
        y += 320;
    while (y >= 320)
        y -= 320;
    ili9325WriteRegister(ILI9325_GATE_SCAN_CTRL3, y);
    ili9325WriteData(y);
}

/**************************************************************************/
/*!
    @brief  Gets the controller's 16-bit (4 hexdigit) ID
*/
/**************************************************************************/
uint16_t lcdGetControllerID(void)
{
    // obviously changed from hx8347g
    return 0x9325;
}

/**************************************************************************/
/*!
    @brief  Returns the LCDs 'lcdProperties_t' that describes the LCDs
            generic capabilities and dimensions
*/
/**************************************************************************/
lcdProperties_t lcdGetProperties(void)
{
    return ili9325Properties;
}
