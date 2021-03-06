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

#ifndef _GPIO_IMU4P_H_
#define _GPIO_IMU4P_H_

#define GPIO_POWER_SW           GPIO_PORTNUM(GPIO_PORT_D,  2)
#define GPIO_UPDATE_LED         GPIO_PORTNUM(GPIO_PORT_B, 15)
#define GPIO_POWER_LED          GPIO_PORTNUM(GPIO_PORT_B, 14)

#define GPIO_USART1_TXD         GPIO_PORTNUM(GPIO_PORT_A,  9)
#define GPIO_USART1_RXD         GPIO_PORTNUM(GPIO_PORT_A, 10)

#define GPIO_INT0               GPIO_PORTNUM(GPIO_PORT_A,  0)
#define GPIO_INT1               GPIO_PORTNUM(GPIO_PORT_A,  1)
#define GPIO_INT2               GPIO_PORTNUM(GPIO_PORT_A,  2)
#define GPIO_INT3               GPIO_PORTNUM(GPIO_PORT_A,  3)
#define GPIO_TIM2_ETR           GPIO_PORTNUM(GPIO_PORT_A, 15)

#define GPIO_SPI1_SCK           GPIO_PORTNUM(GPIO_PORT_A,  5)
#define GPIO_SPI1_MISO          GPIO_PORTNUM(GPIO_PORT_A,  6)
#define GPIO_SPI1_MOSI          GPIO_PORTNUM(GPIO_PORT_A,  7)
#if !CONFIG_SYSTEM_SWD_ENABLE
#define GPIO_SPI1_CS0X          GPIO_PORTNUM(GPIO_PORT_A, 13)
#define GPIO_SPI1_CS1X          GPIO_PORTNUM(GPIO_PORT_A, 14)
#endif
#define GPIO_SPI1_CS2X          GPIO_PORTNUM(GPIO_PORT_B,  0)
#define GPIO_SPI1_CS3X          GPIO_PORTNUM(GPIO_PORT_B,  1)

#define GPIO_MCO                GPIO_PORTNUM(GPIO_PORT_A,  8)

#define GPIO_32KIN              GPIO_PORTNUM(GPIO_PORT_C, 14)



#ifdef _SYSTEM_C_
const uint16_t gpioDefaultTbl[] = {
  PORT_CTRL(GPIO_POWER_SW,   GPIO_MODE_INPUT,  GPIO_PULL_UP,   0),
  PORT_CTRL(GPIO_UPDATE_LED, GPIO_MODE_OUTPUT, GPIO_PULL_NONE, 0),
  PORT_CTRL(GPIO_POWER_LED,  GPIO_MODE_OUTPUT, GPIO_PULL_NONE, 0),

  PORT_CTRL(GPIO_USART1_TXD, GPIO_MODE_FUNC,   GPIO_PULL_NONE, GPIO_FUNC(4)),
  PORT_CTRL(GPIO_USART1_RXD, GPIO_MODE_FUNC,   GPIO_PULL_NONE, GPIO_FUNC(4)),

  PORT_CTRL(GPIO_INT0,       GPIO_MODE_FUNC,   GPIO_PULL_DOWN, GPIO_FUNC(2)),
  PORT_CTRL(GPIO_INT1,       GPIO_MODE_FUNC,   GPIO_PULL_DOWN, GPIO_FUNC(2)),
  PORT_CTRL(GPIO_INT2,       GPIO_MODE_FUNC,   GPIO_PULL_DOWN, GPIO_FUNC(2)),
  PORT_CTRL(GPIO_INT3,       GPIO_MODE_FUNC,   GPIO_PULL_DOWN, GPIO_FUNC(2)),
  PORT_CTRL(GPIO_TIM2_ETR,   GPIO_MODE_FUNC,   GPIO_PULL_NONE, GPIO_FUNC(2)),

  PORT_CTRL(GPIO_SPI1_SCK,   GPIO_MODE_FUNC,   GPIO_PULL_NONE, GPIO_FUNC(0)),
  PORT_CTRL(GPIO_SPI1_MISO,  GPIO_MODE_FUNC,   GPIO_PULL_NONE, GPIO_FUNC(0)),
  PORT_CTRL(GPIO_SPI1_MOSI,  GPIO_MODE_FUNC,   GPIO_PULL_NONE, GPIO_FUNC(0)),
#if !CONFIG_SYSTEM_SWD_ENABLE
  PORT_CTRL(GPIO_SPI1_CS0X,  GPIO_MODE_OUTPUT, GPIO_PULL_NONE, 1),
  PORT_CTRL(GPIO_SPI1_CS1X,  GPIO_MODE_OUTPUT, GPIO_PULL_NONE, 1),
#endif
  PORT_CTRL(GPIO_SPI1_CS2X,  GPIO_MODE_OUTPUT, GPIO_PULL_NONE, 1),
  PORT_CTRL(GPIO_SPI1_CS3X,  GPIO_MODE_OUTPUT, GPIO_PULL_NONE, 1),

#if CONFIG_MCO_ENABLE
  PORT_CTRL(GPIO_MCO,         GPIO_MODE_FUNC,  GPIO_PULL_NONE, GPIO_FUNC(0)),
#endif

  PORT_CTRL_END,
};
#endif

#define GpioSetUsbEnable()              
#define GpioSetUsbDisable()             

#define GpioGetPowerSw()        GPIO_GET(GPIO_POWER_SW)
#define GpioSetPowerLedOff()    //(GPIO_PTR[CONFIG_POWER_LED_PORTNUM].BRR = (1UL<<(CONFIG_POWER_LED_BITNUM)))
#define GpioSetPowerLedOn()     //(GPIO_PTR[CONFIG_POWER_LED_PORTNUM].BSRR = (1UL<<(CONFIG_POWER_LED_BITNUM)))
#define GpioSetUpdateLedOff()   //(GPIO_PTR[CONFIG_UPDATE_LED_PORTNUM].BRR = (1UL<<(CONFIG_UPDATE_LED_BITNUM)))
#define GpioSetUpdateLedOn()    //(GPIO_PTR[CONFIG_UPDATE_LED_PORTNUM].BSRR = (1UL<<(CONFIG_UPDATE_LED_BITNUM)))


#if CONFIG_SYSTEM_SWD_ENABLE
#define GpioSetSpiCs0XEn()      
#define GpioSetSpiCs0XDis()     
#define GpioSetSpiCs1XEn()      
#define GpioSetSpiCs1XDis()     
#else
#define GpioSetSpiCs0XEn()      GPIO_CLEAR(GPIO_SPI1_CS0X)
#define GpioSetSpiCs0XDis()     GPIO_SET(GPIO_SPI1_CS0X)
#define GpioSetSpiCs1XEn()      GPIO_CLEAR(GPIO_SPI1_CS1X)
#define GpioSetSpiCs1XDis()     GPIO_SET(GPIO_SPI1_CS1X)
#endif
#define GpioSetSpiCs2XEn()      GPIO_CLEAR(GPIO_SPI1_CS2X)
#define GpioSetSpiCs2XDis()     GPIO_SET(GPIO_SPI1_CS2X)
#define GpioSetSpiCs3XEn()      GPIO_CLEAR(GPIO_SPI1_CS3X)
#define GpioSetSpiCs3XDis()     GPIO_SET(GPIO_SPI1_CS3X)

#endif
