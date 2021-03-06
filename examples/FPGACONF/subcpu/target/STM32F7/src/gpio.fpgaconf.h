/*
 * Copyright (c) 2019 zhtlab
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files
 * (the "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to permit
 * persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */
#ifndef _GPIO_USBSOFIC_H_
#define _GPIO_USBSOFIC_H_


#define GPIO_POWER_SW_X         GPIO_PORTNUM(CONFIG_POWER_SW_PORTNUM, CONFIG_POWER_SW_BITNUM)
#define GPIO_UPDATE_LED         GPIO_PORTNUM(CONFIG_UPDATE_LED_PORTNUM, CONFIG_UPDATE_LED_BITNUM)
#define GPIO_POWER_LED          GPIO_PORTNUM(CONFIG_POWER_LED_PORTNUM, CONFIG_POWER_LED_BITNUM)

// gpio
#define GPIO_PORT_A0            GPIO_PORTNUM(GPIO_PORT_A,  0)
#define GPIO_PORT_A1            GPIO_PORTNUM(GPIO_PORT_A,  1)
#define GPIO_PORT_A2            GPIO_PORTNUM(GPIO_PORT_A,  2)
#define GPIO_PORT_A3            GPIO_PORTNUM(GPIO_PORT_A,  3)
#define GPIO_PORT_A4            GPIO_PORTNUM(GPIO_PORT_A,  4)
#define GPIO_PORT_A5            GPIO_PORTNUM(GPIO_PORT_A,  5)
#define GPIO_PORT_A6            GPIO_PORTNUM(GPIO_PORT_A,  6)
#define GPIO_PORT_A7            GPIO_PORTNUM(GPIO_PORT_A,  7)

// sdio
#define GPIO_SDMMC_CLK          GPIO_PORTNUM(GPIO_PORT_C, 12)
#define GPIO_SDMMC_CMD          GPIO_PORTNUM(GPIO_PORT_D,  2)
#define GPIO_SDMMC_D0           GPIO_PORTNUM(GPIO_PORT_C,  8)
#define GPIO_SDMMC_D1           GPIO_PORTNUM(GPIO_PORT_C,  9)
#define GPIO_SDMMC_D2           GPIO_PORTNUM(GPIO_PORT_C, 10)
#define GPIO_SDMMC_D3           GPIO_PORTNUM(GPIO_PORT_C, 11)
#define GPIO_SDMMC_CDETX        GPIO_PORTNUM(GPIO_PORT_C, 13)
#define GPIO_SDMMC_WP_X         GPIO_PORTNUM(GPIO_PORT_C,  3)

// spi for fpga config
#define GPIO_SPI1_SCK           GPIO_PORTNUM(GPIO_PORT_B,  3)
#define GPIO_SPI1_MOSI          GPIO_PORTNUM(GPIO_PORT_B,  5)
#define GPIO_SPI1_MISO          GPIO_PORTNUM(GPIO_PORT_B,  4)
#define GPIO_SPI1_CS0X          GPIO_PORTNUM(GPIO_PORT_B,  7)
#define GPIO_SPI1_CS1X          GPIO_PORTNUM(GPIO_PORT_B,  8)
#define GPIO_SPI1_CS2X          GPIO_PORTNUM(GPIO_PORT_C,  4)
#define GPIO_SPI1_CS3X          GPIO_PORTNUM(GPIO_PORT_C,  6)

// fmc cpu bus for fpga config
#define GPIO_FMC_D7             GPIO_PORTNUM(GPIO_PORT_E, 10)
#define GPIO_FMC_D6             GPIO_PORTNUM(GPIO_PORT_E,  9)
#define GPIO_FMC_D5             GPIO_PORTNUM(GPIO_PORT_E,  8)
#define GPIO_FMC_D4             GPIO_PORTNUM(GPIO_PORT_E,  7)
#define GPIO_FMC_D3             GPIO_PORTNUM(GPIO_PORT_D,  1)
#define GPIO_FMC_D2             GPIO_PORTNUM(GPIO_PORT_D,  0)
#define GPIO_FMC_D1             GPIO_PORTNUM(GPIO_PORT_D, 15)
#define GPIO_FMC_D0             GPIO_PORTNUM(GPIO_PORT_D, 14)
#define GPIO_FMC_NWE            GPIO_PORTNUM(GPIO_PORT_D,  5)
#define GPIO_FMC_NOE            GPIO_PORTNUM(GPIO_PORT_D,  4)
#define GPIO_FMC_NE1            GPIO_PORTNUM(GPIO_PORT_D,  7)
#define GPIO_FMC_NE2            GPIO_PORTNUM(GPIO_PORT_G,  9)
#define GPIO_FMC_NE3            GPIO_PORTNUM(GPIO_PORT_G, 10)
#define GPIO_FMC_NE4            GPIO_PORTNUM(GPIO_PORT_G, 12)

#define GPIO_FPGA_PROGX         GPIO_PORTNUM(GPIO_PORT_C,  7)
#define GPIO_FPGA_DONE          GPIO_PORTNUM(GPIO_PORT_B,  0)
#define GPIO_CONF_SEL           GPIO_PORTNUM(GPIO_PORT_C,  5)

// usb hs
#define GPIO_USB_HS_ID          GPIO_PORTNUM(GPIO_PORT_B, 13)
#define GPIO_USB_HS_DM          GPIO_PORTNUM(GPIO_PORT_B, 14)
#define GPIO_USB_HS_DP          GPIO_PORTNUM(GPIO_PORT_B, 15)

// usart1
#define GPIO_USART1_TXD         GPIO_PORTNUM(GPIO_PORT_A,  9)
#define GPIO_USART1_RXD         GPIO_PORTNUM(GPIO_PORT_A, 10)

#if 0
#define GPIO_TIM2CH1            GPIO_PORTNUM(GPIO_PORT_A,  0)
#define GPIO_TIM2CH2            GPIO_PORTNUM(GPIO_PORT_A,  1)
#define GPIO_TIM2CH3            GPIO_PORTNUM(GPIO_PORT_A,  2)
#define GPIO_TIM2CH4            GPIO_PORTNUM(GPIO_PORT_A,  3)
#endif

// i2c master
#define GPIO_I2C2_SCL           GPIO_PORTNUM(GPIO_PORT_B, 10)
#define GPIO_I2C2_SDA           GPIO_PORTNUM(GPIO_PORT_B, 11)
// i2c slave
#define GPIO_I2C1_SCL           GPIO_PORTNUM(GPIO_PORT_B,  6)
#define GPIO_I2C1_SDA           GPIO_PORTNUM(GPIO_PORT_B,  9)


//#define GPIO_FSSOF              GPIO_PORTNUM(GPIO_PORT_A,  8)
#define GPIO_MCO1               GPIO_PORTNUM(GPIO_PORT_A,  8)
#define GPIO_MCO2               GPIO_PORTNUM(GPIO_PORT_C,  9)



#ifdef _SYSTEM_C_
const uint16_t gpioDefaultTbl[] = {
  // led, sw, usart
  PORT_CTRL(GPIO_POWER_SW_X,    GPIO_MODE_INPUT,  GPIO_PULL_UP,   GPIO_VAL_0),
  PORT_CTRL(GPIO_UPDATE_LED,    GPIO_MODE_OUTPUT, GPIO_PULL_NONE, GPIO_VAL_0),
  PORT_CTRL(GPIO_POWER_LED,     GPIO_MODE_OUTPUT, GPIO_PULL_NONE, GPIO_VAL_0),
  PORT_CTRL(GPIO_USART1_TXD,    GPIO_MODE_FUNC,   GPIO_PULL_NONE, GPIO_FUNC7_USART),
  PORT_CTRL(GPIO_USART1_RXD,    GPIO_MODE_FUNC,   GPIO_PULL_NONE, GPIO_FUNC7_USART),

  PORT_CTRL(GPIO_PORT_A0,       GPIO_MODE_OUTPUT,  GPIO_PULL_NONE, GPIO_VAL_0),
  PORT_CTRL(GPIO_PORT_A1,       GPIO_MODE_OUTPUT,  GPIO_PULL_NONE, GPIO_VAL_0),
  PORT_CTRL(GPIO_PORT_A2,       GPIO_MODE_OUTPUT,  GPIO_PULL_NONE, GPIO_VAL_0),
  PORT_CTRL(GPIO_PORT_A3,       GPIO_MODE_OUTPUT,  GPIO_PULL_NONE, GPIO_VAL_0),
  PORT_CTRL(GPIO_PORT_A4,       GPIO_MODE_OUTPUT,  GPIO_PULL_NONE, GPIO_VAL_0),
  PORT_CTRL(GPIO_PORT_A5,       GPIO_MODE_OUTPUT,  GPIO_PULL_NONE, GPIO_VAL_0),
  PORT_CTRL(GPIO_PORT_A6,       GPIO_MODE_OUTPUT,  GPIO_PULL_NONE, GPIO_VAL_0),
  PORT_CTRL(GPIO_PORT_A7,       GPIO_MODE_OUTPUT,  GPIO_PULL_NONE, GPIO_VAL_0),

#if 0
  PORT_CTRL(GPIO_I2C2_SDA,      GPIO_MODE_FUNC,   GPIO_PULL_UP,   GPIO_FUNC4_I2C),
  PORT_CTRL(GPIO_I2C2_SCL,      GPIO_MODE_FUNC,   GPIO_PULL_UP,   GPIO_FUNC4_I2C),
  PORT_CTRL(GPIO_I2C1_SDA,      GPIO_MODE_FUNC,   GPIO_PULL_UP,   GPIO_FUNC4_I2C),
  PORT_CTRL(GPIO_I2C1_SCL,      GPIO_MODE_FUNC,   GPIO_PULL_UP,   GPIO_FUNC4_I2C),
#endif

  PORT_CTRL(GPIO_SDMMC_CLK,     GPIO_MODE_FUNC,   GPIO_PULL_NONE, GPIO_FUNC12_SDMMC),
  PORT_CTRL(GPIO_SDMMC_CMD,     GPIO_MODE_FUNC,   GPIO_PULL_NONE, GPIO_FUNC12_SDMMC),
  PORT_CTRL(GPIO_SDMMC_D0,      GPIO_MODE_FUNC,   GPIO_PULL_NONE, GPIO_FUNC12_SDMMC),
  PORT_CTRL(GPIO_SDMMC_D1,      GPIO_MODE_FUNC,   GPIO_PULL_NONE, GPIO_FUNC12_SDMMC),
  PORT_CTRL(GPIO_SDMMC_D2,      GPIO_MODE_FUNC,   GPIO_PULL_NONE, GPIO_FUNC12_SDMMC),
  PORT_CTRL(GPIO_SDMMC_D3,      GPIO_MODE_FUNC,   GPIO_PULL_NONE, GPIO_FUNC12_SDMMC),
  PORT_CTRL(GPIO_SDMMC_CDETX,   GPIO_MODE_INPUT,  GPIO_PULL_UP,   GPIO_VAL_0),
  PORT_CTRL(GPIO_SDMMC_WP_X,    GPIO_MODE_INPUT,  GPIO_PULL_UP,   GPIO_VAL_0),

  PORT_CTRL(GPIO_SPI1_SCK,      GPIO_MODE_FUNC,   GPIO_PULL_NONE, GPIO_FUNC5_SPI),
  PORT_CTRL(GPIO_SPI1_MOSI,     GPIO_MODE_FUNC,   GPIO_PULL_NONE, GPIO_FUNC5_SPI),
  PORT_CTRL(GPIO_SPI1_MISO,     GPIO_MODE_FUNC,   GPIO_PULL_NONE, GPIO_FUNC5_SPI),
  PORT_CTRL(GPIO_SPI1_CS0X,     GPIO_MODE_OUTPUT, GPIO_PULL_NONE, GPIO_VAL_1),
  PORT_CTRL(GPIO_SPI1_CS1X,     GPIO_MODE_OUTPUT, GPIO_PULL_NONE, GPIO_VAL_1),
  PORT_CTRL(GPIO_SPI1_CS2X,     GPIO_MODE_OUTPUT, GPIO_PULL_NONE, GPIO_VAL_1),
  PORT_CTRL(GPIO_SPI1_CS3X,     GPIO_MODE_OUTPUT, GPIO_PULL_NONE, GPIO_VAL_1),

  PORT_CTRL(GPIO_FMC_D7,        GPIO_MODE_FUNC,   GPIO_PULL_NONE, GPIO_FUNC12_FMC),
  PORT_CTRL(GPIO_FMC_D6,        GPIO_MODE_FUNC,   GPIO_PULL_NONE, GPIO_FUNC12_FMC),
  PORT_CTRL(GPIO_FMC_D5,        GPIO_MODE_FUNC,   GPIO_PULL_NONE, GPIO_FUNC12_FMC),
  PORT_CTRL(GPIO_FMC_D4,        GPIO_MODE_FUNC,   GPIO_PULL_NONE, GPIO_FUNC12_FMC),
  PORT_CTRL(GPIO_FMC_D3,        GPIO_MODE_FUNC,   GPIO_PULL_NONE, GPIO_FUNC12_FMC),
  PORT_CTRL(GPIO_FMC_D2,        GPIO_MODE_FUNC,   GPIO_PULL_NONE, GPIO_FUNC12_FMC),
  PORT_CTRL(GPIO_FMC_D1,        GPIO_MODE_FUNC,   GPIO_PULL_NONE, GPIO_FUNC12_FMC),
  PORT_CTRL(GPIO_FMC_D0,        GPIO_MODE_FUNC,   GPIO_PULL_NONE, GPIO_FUNC12_FMC),
  PORT_CTRL(GPIO_FMC_NWE,       GPIO_MODE_FUNC,   GPIO_PULL_NONE, GPIO_FUNC12_FMC),
  PORT_CTRL(GPIO_FMC_NOE,       GPIO_MODE_FUNC,   GPIO_PULL_NONE, GPIO_FUNC12_FMC),
  PORT_CTRL(GPIO_FMC_NE1,       GPIO_MODE_OUTPUT, GPIO_PULL_NONE, GPIO_VAL_1),
  PORT_CTRL(GPIO_FMC_NE2,       GPIO_MODE_OUTPUT, GPIO_PULL_NONE, GPIO_VAL_1),
  PORT_CTRL(GPIO_FMC_NE3,       GPIO_MODE_OUTPUT, GPIO_PULL_NONE, GPIO_VAL_1),
  PORT_CTRL(GPIO_FMC_NE4,       GPIO_MODE_OUTPUT, GPIO_PULL_NONE, GPIO_VAL_1),
#if 0
  PORT_CTRL(GPIO_FMC_NE1,       GPIO_MODE_FUNC,   GPIO_PULL_NONE, GPIO_FUNC12_FMC),
  PORT_CTRL(GPIO_FMC_NE2,       GPIO_MODE_FUNC,   GPIO_PULL_NONE, GPIO_FUNC12_FMC),
  PORT_CTRL(GPIO_FMC_NE3,       GPIO_MODE_FUNC,   GPIO_PULL_NONE, GPIO_FUNC12_FMC),
  PORT_CTRL(GPIO_FMC_NE4,       GPIO_MODE_FUNC,   GPIO_PULL_NONE, GPIO_FUNC12_FMC),
#endif
  PORT_CTRL(GPIO_FPGA_PROGX,    GPIO_MODE_OUTPUT, GPIO_PULL_NONE, GPIO_VAL_1),
  PORT_CTRL(GPIO_FPGA_DONE,     GPIO_MODE_INPUT,  GPIO_PULL_UP,   GPIO_VAL_0),
  PORT_CTRL(GPIO_CONF_SEL,      GPIO_MODE_OUTPUT, GPIO_PULL_NONE, GPIO_VAL_0),


#if 0
  PORT_CTRL(GPIO_MCO1,          GPIO_MODE_FUNC,   GPIO_PULL_NONE, GPIO_FUNC0_SYS),
  //PORT_CTRL(GPIO_FSSOF,         GPIO_MODE_FUNC, GPIO_PULL_NONE, GPIO_FUNC10_USB),
  PORT_CTRL(GPIO_MCO2,          GPIO_MODE_FUNC,   GPIO_PULL_NONE, GPIO_FUNC0_SYS),

  PORT_CTRL(GPIO_USB_HS_DM,     GPIO_MODE_FUNC, GPIO_PULL_NONE,   GPIO_FUNC12_USBHS),
  PORT_CTRL(GPIO_USB_HS_DP,     GPIO_MODE_FUNC, GPIO_PULL_NONE,   GPIO_FUNC12_USBHS),
#endif

  PORT_CTRL_END,
};
#endif


#define GpioSetUpdateLedOff()           GPIO_CLEAR(GPIO_UPDATE_LED)
#define GpioSetUpdateLedOn()            GPIO_SET(GPIO_UPDATE_LED)
#define GpioSetPowerLedOff()            GPIO_CLEAR(GPIO_POWER_LED)
#define GpioSetPowerLedOn()             GPIO_SET(GPIO_POWER_LED)
#define GpioIsPowerSwPushed()           !GPIO_GET(GPIO_POWER_SW_X)

#define GpioSetSpi0Csx_Act()            GPIO_CLEAR(GPIO_SPI1_CS0X)
#define GpioSetSpi0Csx_Inact()          GPIO_SET(GPIO_SPI1_CS0X)
#define GpioSetSpi1Csx_Act()            GPIO_CLEAR(GPIO_SPI1_CS1X)
#define GpioSetSpi1Csx_Inact()          GPIO_SET(GPIO_SPI1_CS1X)
#define GpioSetSpi2Csx_Act()            GPIO_CLEAR(GPIO_SPI1_CS2X)
#define GpioSetSpi2Csx_Inact()          GPIO_SET(GPIO_SPI1_CS2X)
#define GpioSetSpi3Csx_Act()            GPIO_CLEAR(GPIO_SPI1_CS3X)
#define GpioSetSpi3Csx_Inact()          GPIO_SET(GPIO_SPI1_CS3X)

#define GpioSet8bit0Csx_Act()           GPIO_CLEAR(GPIO_FMC_NE1)
#define GpioSet8bit0Csx_Inact()         GPIO_SET(GPIO_FMC_NE1)
#define GpioSet8bit1Csx_Act()           GPIO_CLEAR(GPIO_FMC_NE2)
#define GpioSet8bit1Csx_Inact()         GPIO_SET(GPIO_FMC_NE2)
#define GpioSet8bit2Csx_Act()           GPIO_CLEAR(GPIO_FMC_NE3)
#define GpioSet8bit2Csx_Inact()         GPIO_SET(GPIO_FMC_NE3)
#define GpioSet8bit3Csx_Act()           GPIO_CLEAR(GPIO_FMC_NE4)
#define GpioSet8bit3Csx_Inact()         GPIO_SET(GPIO_FMC_NE4)

#define GpioSetProgx_Act()              GPIO_CLEAR(GPIO_FPGA_PROGX)
#define GpioSetProgx_Inact()            GPIO_SET(GPIO_FPGA_PROGX)
#define GpioGetDone()                   GPIO_GET(GPIO_FPGA_DONE)
#define GpioSetConfSelSpi()             GPIO_CLEAR(GPIO_CONF_SEL)
#define GpioSetConfSel8bit()            GPIO_SET(GPIO_CONF_SEL)

#define GpioIsSdmmc1CardInserted()      (!GPIO_GET(GPIO_SDMMC_CDETX))
#define GpioIsSdmmc1WriteProtect()      (!GPIO_GET(GPIO_SDMMC_WP_X))


#define GpioSetUsbEnable()              GPIO_SET(GPIO_USB_FS_EN)
#define GpioSetUsbDisable()             GPIO_CLEAR(GPIO_USB_FS_EN)


#endif
