/*
 * Copyright (c) 2018,2019 zhtlab
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

#define _MAIN_C_

#include        <stdint.h>
#include        <stdio.h>

#include        "config.h"

#include        "system.h"
#include        "intr.h"
#include        "devGpio.h"
#include        "devUsart.h"
#include        "devSpi16.h"
#include        "devDma4.h"
#include        "devCounter.h"
#include        "gpio.h"
#include        "devCrs.h"
#include        "fifo.h"
#include        "command.h"
#include        "imu.h"

#include        "main.h"

const uint8_t           strVersionText[] = CONFIG_VERSION_FIRM_TEXT;


static uint32_t         system1ms = 0;

void            MainEntry(void);
int             _putchar(char c);
int             _getc(void);

static void     MainInitUsart(void);
static void     MainInitTim(void);
static void     MainInitSpi(void);



uint32_t        tim2msb = 0;
typedef struct {
  uint16_t      flag;
#define       MAIN_TIM2_IC_VALID        (1<<0)
#define       MAIN_TIM2_IC_OVERWRITE    (1<<1)
  uint16_t      tLsb;
  uint32_t      tMsb;
} mainTim2Ic_t;
static mainTim2Ic_t     mainTim2Ic[4];


void
SystemIncrement1ms(void)
{
  system1ms--;

  return;
}

 /*__ATTR_INTR("SystemSysTickIntr")*/ void
SystemSysTickIntr(void)
{
  system1ms--;
  return;
}
uint32_t
SystemGetCounter(void)
{
  return system1ms;
}
void
SystemWaitCounter(int ms)
{
  uint32_t      t;

  t = system1ms;
  while((t - system1ms) < ms);

  return;
}



static uint8_t  mainCommandBuf[128];
static int      mainCommandPos = 0;
void
MainUartLoop(void)
{
  int           len = 0;
  int           c;
  static int    cnt = 0;

  while((c = _getc()) >= 0) {

    if(c >= 0) {
      if(c == '\n') {
      } else if(c == '\r') {
        int             ac;

        c = '\n';
        puts("\n");

        mainCommandBuf[mainCommandPos] = '\0';
        CommandProcess(mainCommandBuf);

        mainCommandPos = 0;
      } else if(c == '\b') {
        cnt = 0;
        if(mainCommandPos > 0) {
          mainCommandPos--;
          puts("\b \b");
        }
      } else {
        if(mainCommandPos < sizeof(mainCommandBuf)) {
          uint8_t       str[2];
          mainCommandBuf[mainCommandPos] = c;
          mainCommandPos++;
          str[0] = c;
          str[1] = '\n';
          puts(str);
        }
      }
    }
  }

  return;
}






void main(void) {
  MainEntry();
}
void
MainEntry(void)
{
  uint32_t              *pSrc, *pSrcEnd, *pDest;
  register uint32_t     sp, pc;
  int                   isPowerSwPushed;
  uint32_t              tout;
  uint32_t              val, valPrev;
  int                   cnt[4] = {0};

  extern uint32_t  sectVectorStart;

  extern const uint16_t gpioDefaultTbl[];

  DevGpioInit();
  DevGpioSets(gpioDefaultTbl);
  IntrInit(0);

  {
    systemClockFreq_t   clk;
    SystemGetClockValue(&clk);
    SysTick_Config((clk.systick<<2)/1000);      /* adhoc */
  }

#if 0
  /* init the systick counter */
  IntrSetEntry(0, SysTick_IRQn, (void *)RtosSysTickEntry);
  NVIC_SetPriority(SysTick_IRQn, 15);
  NVIC_EnableIRQ(SysTick_IRQn);
#endif

  /* other interrupt */
  NVIC_SetPriority(MemoryManagement_IRQn, 0);
  NVIC_SetPriority(BusFault_IRQn, 0);
  NVIC_SetPriority(UsageFault_IRQn, 0);
  NVIC_SetPriority(DebugMonitor_IRQn, 0);

  FifoInit();

  DevDmaInit(-1, 0, NULL);
  MainInitUsart();
  MainInitTim();
  MainInitSpi();



  puts("\n\n\n\n\n\n\n\n\n\n#-----\n");
  puts("# IMU4P was started\n");

  systemClockFreq_t   clk;
  SystemGetClockValue(&clk);
  SystemDebugShowClockValue(&clk);


  __enable_irq();

  /* CS pin is generated low and high */
  for(int j = 0; j < 1000; j++) {
    for(int i = 0; i < 4; i++) {
      ImuGenCsPulse(i, 0);
    }
  }

  for(int i = 0; i < 4; i++) {
    ImuInit(i);
  }


  int i;
  int isPushSw = 0, isPushSwPrev = 0;

  uint32_t      tLedWait;
  int           fLed = 0;
  /* Infinite loop */
  while(1) {
    MainUartLoop();

    if((tLedWait - SystemGetCounter()) >= 1000) {
      tLedWait = SystemGetCounter();
      if(fLed) {
        SystemGpioSetPowerLedOff();
      } else {
        SystemGpioSetPowerLedOn();
      }
      fLed = !fLed;
    }

    for(int i = 0; i < 4; i++) {
      __disable_irq();
      if(mainTim2Ic[i].flag) {
        mainTim2Ic[i].flag = 0;
        __enable_irq();

        {
          imuValue_t  imu;
          ImuReadValue(i, &imu);
          printf("%08x%04x  ", mainTim2Ic[i].tMsb, mainTim2Ic[i].tLsb);
          printf("%d %8x ", i, cnt[i]);
          printf("%4x %4x %4x  ", imu.gyro.x, imu.gyro.y, imu.gyro.z);
          printf("%4x %4x %4x  ", imu.acc.x,  imu.acc.y,  imu.acc.z);
          printf("%6x  ", imu.ts);
          printf("%2x  ", imu.temp4x);
          puts("\n");

          cnt[i]++;
        }
        __disable_irq();
      }
      __enable_irq();
    }


  }
  /************************************************
   *  Updater is not exist,  halt
   */
  while(1);

}


/*** USART **********************************************************/
static void
MainInitUsart(void)
{
  devUsartParam_t       param;

  DevUsartInit(-1, NULL);

  memset(&param, 0, sizeof(param));
  param.baud = CONFIG_SYSTEM_USART_BAUD;
  param.bit = DEVUSART_BIT_8;
  param.stop = DEVUSART_STOP_1;
  param.mode = DEVUSART_MODE_PIO;
  param.parity = DEVUSART_PARITY_NONE;
  param.szFifoTx = 6;
  param.szFifoRx = 6;
  DevUsartInit(CONFIG_SYSTEM_USART_PORT, &param);

#if 0
  __NVIC_SetPriority(DMA1_Stream0_IRQn, 5);
  __NVIC_EnableIRQ(DMA1_Stream0_IRQn);
  /* DMA1_Stream1_IRQn interrupt configuration */
  __NVIC_SetPriority(DMA1_Stream1_IRQn, 5);
  __NVIC_EnableIRQ(DMA1_Stream1_IRQn);
#endif

  return;
}


/*** TIM  ***********************************************************/
/* PWM */
static void
MainInitTim(void)
{
  devCounterParam_t     param;

  DevCounterInit(-1, NULL);

  /********************************************************
   * 32.768kHz --> [ETR TIM2]
   */

  /********************************************************
   * TIM2:  freerun count, input capture
   */
  memset(&param, 0, sizeof(param));
  param.chnum = (DEVCOUNTER_SETCH(DEVCOUNTER_CH_CLKTRG) |
                 DEVCOUNTER_SETCH(DEVCOUNTER_CH_1) |
                 DEVCOUNTER_SETCH(DEVCOUNTER_CH_2) |
                 DEVCOUNTER_SETCH(DEVCOUNTER_CH_3) |
                 DEVCOUNTER_SETCH(DEVCOUNTER_CH_4));

  param.clktrg.mode = (DEVTIME_CLKTRG_MODE_FREERUN |
                       DEVTIME_CLKTRG_CTG_EXTERNAL2 | DEVTIME_CLKTRG_SEL(0));
  param.clktrg.intr = 1;
  //param.clktrg.filter = 0;
  param.clktrg.reload = 0xffff;
  //param.clktrg.prescaler = 0;

  param.ch.mode = DEVCOUNTER_MODE_IC;
  param.ch.intr = 1;
  DevCounterInit(TIM2_NUM, &param);

  __NVIC_SetPriority(TIM2_IRQn, 0);
  __NVIC_EnableIRQ(TIM2_IRQn);

  return;
}


void
MainEnableTim(void)
{
  devCounterParam_t     param;

  memset(&param, 0, sizeof(param));
  param.chnum = (DEVCOUNTER_SETCH(DEVCOUNTER_CH_1) |
                 DEVCOUNTER_SETCH(DEVCOUNTER_CH_2) |
                 DEVCOUNTER_SETCH(DEVCOUNTER_CH_3) |
                 DEVCOUNTER_SETCH(DEVCOUNTER_CH_4));

  param.ch.mode = DEVCOUNTER_MODE_IC;
  param.ch.intr = 1;

  DevCounterInit(TIM2_NUM, &param);

  return;
}


void
MainDisableTim(void)
{
  devCounterParam_t     param;

  memset(&param, 0, sizeof(param));
  param.chnum = (DEVCOUNTER_SETCH(DEVCOUNTER_CH_1) |
                 DEVCOUNTER_SETCH(DEVCOUNTER_CH_2) |
                 DEVCOUNTER_SETCH(DEVCOUNTER_CH_3) |
                 DEVCOUNTER_SETCH(DEVCOUNTER_CH_4));

  param.ch.mode = DEVCOUNTER_MODE_DISABLE;
  DevCounterInit(TIM2_NUM, &param);

  return;
}


void
MainInterruptTim(void)
{
  uint32_t      val;
  uint32_t      sr, mask, dier;

  sr = TIM2_PTR->SR;
  dier = TIM2_PTR->DIER;

  mask = TIM_SR_CC1IF_MASK;
  sr &= dier;
  for(int i = 0; i < 4; i++) {
    if(sr & mask) {
      DevCounterGetIcValue(TIM2_NUM, i+1, &val);
      if(mainTim2Ic[i].flag & MAIN_TIM2_IC_VALID) {
        mainTim2Ic[i].flag |= MAIN_TIM2_IC_OVERWRITE;
      }
      mainTim2Ic[i].flag |= MAIN_TIM2_IC_VALID;
      mainTim2Ic[i].tLsb = val;
      mainTim2Ic[i].tMsb = tim2msb;
    }
    mask <<= 1;
  }

  if(sr & TIM_SR_UIF_MASK) {
    TIM2_PTR->SR = ~TIM_SR_UIF_MASK;
    tim2msb++;
  }

  return;
}


void
MainResetTimCounter(void)
{
  __disable_irq();

  //MainInitTim();
  DevCounterClearCounterValue(TIM2_NUM);
  tim2msb = 0;

  __enable_irq();
  return;
}

/*** SPI  ***********************************************************/
static void
MainInitSpi(void)
{
  devSpiParam_t       param;

  DevSpiInit(-1, NULL);

  memset(&param, 0, sizeof(param));
  //param.clkmode = SPI_CR1_CPOL_NO | SPI_CR1_CPHA_NO;
  param.clkmode = SPI_CR1_CPOL_YES | SPI_CR1_CPHA_YES;
  param.bit = 8;

  /* IMU control */
  //param.speed = 40000000;     /* speed: don't care */
  param.prescaler = 3;          /* 32MHz/(2^(x+1)) x={1:8Mbps, 2:4Mbps} */
  param.dmaTx = 0;
  param.dmaRx = 1;
  DevSpiInit(1, &param);

  return;
}


int
_putchar(char c)
{
  DevUsartSend(CONFIG_CONSOLE_NUMBER, &c, 1);
  return c;
}
int
puts(const char *str)
{
  DevUsartSend(CONFIG_CONSOLE_NUMBER, (uint8_t *)str, strlen(str));
  return 0;
}

int
_getc(void)
{
  int           result = -1;
  int           re;
  uint8_t       c;

  re = DevUsartRecv(CONFIG_CONSOLE_NUMBER, &c, 1);
  if(re > 0) {
    result = c & 0xff;
  }

  return result;
}
