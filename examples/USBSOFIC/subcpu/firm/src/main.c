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

#define _MAIN_C_

#include        <stdio.h>
#include        <stdlib.h>

#include        "config.h"
#include        "system.h"

#include        "rtos.h"


#include        "usb_desc.h"

#include        "main.h"
#include        "intr.h"
#include        "fifo.h"
#include        "devGpio.h"
#include        "devCounter.h"
#include        "devUsart.h"
#include        "devI2c.h"
#include        "devSpi32.h"
#include        "si5351.h"

#include        "usbdif.h"
#include        "usb_cdcacm.h"
#include        "devUsb320a.h"



char            strVersionText[] = CONFIG_VERSION_FIRM_TEXT;


void            MainUartLoop(void);

rtosTaskId      idMain;


void
MainIncSystemTimer(void)
{
  return;
}



int             dUsbCdc;

const static rtosTaskInfo_t     mainTaskList[] = {
  /*** main task */
  {
    .pFunc = (rtosTaskFunc)MainTask,
    .pName = "main",
    .priority = RTOS_PRI_IDLE,
    .szStack = 0x400,
  },
  /*** usb task */
  {
    .pFunc = (rtosTaskFunc)MainUsbdifTask,
    .pName = "usbd",
    .priority = RTOS_PRI_NORMAL,
    .szStack = 0x1000,
  },
  /*** pll task */
  {
    .pFunc = (rtosTaskFunc)MainPllTask,
    .pName = "pll",
    .priority = RTOS_PRI_NORMAL,
    .szStack = 0x200,
  },
  /* end of list */
  {
    .pFunc = NULL,
    .pName = NULL,
    .priority = 0,
    .szStack = 0,
  },
};



#define PRINTF_CDC_FIFO  1
void
MainUartLoop(void)
{
  uint8_t           str[128];
  int               len;

  DevUsartLoop(CONFIG_SYSTEM_USART_PORT);

  if(DevUsartGetDataLen(CONFIG_SYSTEM_USART_PORT) > 0) {
    len = DevUsartRecv(CONFIG_SYSTEM_USART_PORT, str, sizeof(str)-1);
    if(len > 0) {
      str[len] = '\0';
      puts(str);
    }
  }

#if PRINTF_CDC_FIFO
  UsbCdcAcmLoop(dUsbCdc);

  len = UsbCdcAcmRecv(dUsbCdc, str, 200);
  if(len > 0) {
    UsbCdcAcmSend(dUsbCdc, str, len);
  }
#endif

  return;
}

static void
MainIdleLoop(void)
{
  static uint32_t       tCnt, i;

  if(tCnt >= 999) {
    tCnt = 0;
    i++;
    printf("idle %d\r\n", i);

    GpioSetUpdateLedOn();
    RtosTaskSleep(1);
    GpioSetUpdateLedOff();

#if CONFIG_RTOS_DEBUG_SHOW_STACK
    {
      uint8_t   strTaskList[512];
      vTaskList(strTaskList);
      puts(strTaskList);
    }
#endif

  }
  tCnt++;
}


/*extern USBD_DescriptorsTypeDef  usbDescTbl;*/
static void
MainTask(void const * argument)
{
  //DevDmaInit(-1, 0, NULL);
  //MainInitSpi();

  MainInitUsart();
  MainInitI2c();
  //MainInitCounter();

  puts("\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n#-----\r\n");
  puts("# " CONFIG_PRODUCT_NAME_TEXT " was started\r\n");

#if 0
  {
    systemClockFreq_t         p;
    SystemGetClockValue(&p);
    SystemDebugShowClockValue(&p);
  }
#endif

  /* start all tasks */
  const static rtosTaskInfo_t     *pRtos;
  pRtos = mainTaskList+1;   /* skip index 0 which is main task, already executed */
  while(1) {
    if(!pRtos->pFunc) break;
    RtosTaskCreate(pRtos, RTOS_NULL, RTOS_NULL);
    pRtos++;
  }

  /*
   * re-enable interrpt after RTOS is started
   */
  NVIC_SetPriority(TIM2_IRQn, 4);
  NVIC_EnableIRQ(TIM2_IRQn);

  /* Infinite loop */
  while(1) {
    MainUartLoop();
    RtosTaskSleep(1);
    MainIdleLoop();
  }
}


int
MainEntry(void)
{
  extern const uint16_t gpioDefaultTbl[];
  systemClockFreq_t   clk;
  uint32_t            systick;

  SystemInit();

  /* start system timer */
  DevCounterInit(-1, NULL);
  SystemInitSystemTimer();

  //MainInitSi5351();
  //SystemChangeClockHigher();
  //SystemUpdateClockValue();

  //DevGpioSets(gpioDefaultTbl);

  IntrInit(0);

  /* enable, if the FreeRTOS is not used */
#if 0
  SystemGetClockValue(&clk);
  systick = clk.systick;
  SysTick_Config(systick/1000);
#endif

  NVIC_SetPriority(PendSV_IRQn,           1);
  //NVIC_SetPriority(SysTick_IRQn,          2);

  /* System interrupt init*/
  NVIC_SetPriority(MemoryManagement_IRQn, 0);
  NVIC_SetPriority(BusFault_IRQn,         0);
  NVIC_SetPriority(UsageFault_IRQn,       0);
  NVIC_SetPriority(SVCall_IRQn,           0);
  NVIC_SetPriority(DebugMonitor_IRQn,     0);

  /* Start the first task */
  RtosTaskCreate(&mainTaskList[0], RTOS_NULL, RTOS_NULL);

  RtosKernelStart();

  while (1);
}


static void
MainInitUsart(void)
{
  /* uart initialize */
  devUsartParam_t       param;

  DevUsartInit(-1, NULL);

  param.baud = CONFIG_SYSTEM_USART_BAUD;
  param.bit = DEVUSART_BIT_8;
  param.stop = DEVUSART_STOP_1;
  param.mode = DEVUSART_MODE_PIO_FIFO;
  param.parity = DEVUSART_PARITY_NONE;
  param.szFifoTx = 10;
  param.szFifoRx = 10;
  DevUsartInit(CONFIG_SYSTEM_USART_PORT, &param);

  return;
}


void
MainInitI2c(void)
{
  /* uart initialize */
  devI2cParam_t       param;

  DevI2cInit(-1, NULL);

  memset(&param, 0, sizeof(param));
  param.speed = DEVI2C_SPEED_400KHZ;
  param.mode = DEVI2C_MODE_PIO;
  param.dma  = 0;
  param.intr = 0;

  DevI2cInit(I2C2_NUM, &param);

  NVIC_SetPriority(I2C2_EV_IRQn, 2);
  NVIC_EnableIRQ(I2C2_EV_IRQn);

  return;
}


void
MainInitCounter(void)
{
  devCounterParam_t     param;
  systemClockFreq_t     clk;
  int                   div;

  SystemGetClockValue(&clk);
  div = clk.hclk / 48000 / 2;

  DevCounterInit(TIM_NUM_INIT, NULL);

#if 0
  /********************************************************
   * TIM4:  ADC converter sampling timing
   * PWM, AD timing generator,  98,304kHz / 2048 = 48kHz duty 50% clock
   */
  memset(&param, 0, sizeof(param));
  param.chnum = (DEVCOUNTER_SETCH(DEVCOUNTER_CH_CLKTRG) |
                 DEVCOUNTER_SETCH(DEVCOUNTER_CH_4));
  param.clktrg.mode = (DEVTIME_CLKTRG_MODE_FREERUN |
                       DEVTIME_CLKTRG_CTG_INTERNAL | DEVTIME_CLKTRG_SEL(0));
  param.clktrg.reload = div;
  param.ch.val  = div>>1;
  param.ch.mode = DEVCOUNTER_MODE_PWM;

  DevCounterInit(4, &param);
  TIM4_PTR->CR2 = 0x70;         /* extra command: OC4REF(TRGO) out for dma */

#if 0
  TIM4_PTR->DIER |= 0x02;
  __NVIC_SetPriority(TIM4_IRQn, 0);
  __NVIC_EnableIRQ(TIM4_IRQn);
#endif
#endif

  /********************************************************
   *  TIM2: 96MHz
   *        CNT  freerun  decrement counter
   *        CH1  GPS PPS counter
   *        CH2  xxx
   *        CH3  xxx
   *        CH4  SOF input (from FS SOF OUT)
   */
  memset(&param, 0, sizeof(param));
  param.chnum = (DEVCOUNTER_SETCH(DEVCOUNTER_CH_CLKTRG) |
                 DEVCOUNTER_SETCH(DEVCOUNTER_CH_4));
  param.clktrg.mode = (DEVTIME_CLKTRG_MODE_FREERUN |
                       DEVTIME_CLKTRG_CTG_INTERNAL | DEVTIME_CLKTRG_SEL(0));
  param.clktrg.prescaler = 0;
  param.clktrg.reload = 0xffffffff;
  param.clktrg.down = 1;

  param.ch.val  = 0;
  param.ch.intr = 1;
  param.ch.mode = DEVCOUNTER_MODE_IC;

  DevCounterInit(TIM2_NUM, &param);

  //NVIC_SetPriority(TIM2_IRQn, 4);
  //NVIC_EnableIRQ(TIM2_IRQn);


#if 0
  /********************************************************
   * TIM5   freerun counter
   */
  memset(&param, 0, sizeof(param));
  param.chnum = DEVCOUNTER_SETCH(DEVCOUNTER_CH_CLKTRG);
  param.clktrg.mode = (DEVTIME_CLKTRG_MODE_FREERUN |
                       DEVTIME_CLKTRG_CTG_INTERNAL | DEVTIME_CLKTRG_SEL(0));
  param.clktrg.prescaler = 197;
  param.clktrg.reload = 0xffffffff;
  param.clktrg.down = 1;
  DevCounterInit(5, &param);
#endif


#if 0
  /********************************************************
   *  TIM8
   *  SYSCLK -- [TIM8, 1/192000, CH2] -- PD
   */
#define DIV     2
  memset(&param, 0, sizeof(param));
  param.chnum = (DEVCOUNTER_SETCH(DEVCOUNTER_CH_CLKTRG) |
                 DEVCOUNTER_SETCH(DEVCOUNTER_CH_2));
  param.clktrg.mode = (DEVTIME_CLKTRG_MODE_FREERUN |
                       DEVTIME_CLKTRG_CTG_INTERNAL | DEVTIME_CLKTRG_SEL(0));
  param.clktrg.filter = 2;
  param.clktrg.reload = 12000-1;
  param.clktrg.prescaler = 15;
  param.ch.val  = 6000;
  param.ch.mode = DEVCOUNTER_MODE_PWM;
  param.ch.polneg  = 1;
  DevCounterInit(TIM8_NUM, &param);
#endif


  /********************************************************
   * TIM3
   */
  memset(&param, 0, sizeof(param));
  /* TIM3 CH1 PWM  */
  param.chnum = (DEVCOUNTER_SETCH(DEVCOUNTER_CH_CLKTRG) |
                 DEVCOUNTER_SETCH(DEVCOUNTER_CH_1));
  param.clktrg.mode = (DEVTIME_CLKTRG_MODE_FREERUN |
                       DEVTIME_CLKTRG_CTG_INTERNAL | DEVTIME_CLKTRG_SEL(0));
  param.clktrg.filter = 0;
  param.clktrg.reload = 0xffff;
  param.ch.val  = 0x8000;
  param.ch.mode = DEVCOUNTER_MODE_PWM;
  DevCounterInit(TIM3_NUM, &param);

  return;
}


static void
MainInitSpi(void)
/* spi initialize */
{
  devSpiParam_t       param;

  DevSpiInit(-1, NULL);

  param.clkmode = 0;
  param.bit = 8;

  /* USB storage */
  param.speed = 50000000;
  param.prescaler = 0;
  param.dmaTx = 0;      /* STM32H743 SPI has errata */
  param.dmaRx = 1;      /* do not use dma with both tx and rx */
  DevSpiInit(5, &param);

  return;
}




  /*************************************
   * usb
   */
static void
MainInitUsb(void)
{
  /* variables */
  usbdifInitParam_t     usbInitParam;
  extern uint8_t        usbDescDevice[];
  extern int            usbDescDeviceLen;
  extern uint8_t        usbDescDeviceQualifier[];
  extern int            usbDescDeviceQualifierLen;
  extern uint8_t        usbDescConfig[];
  extern int            usbDescConfigLen;
  extern usbdifStringDesc_t usbDescString;
  usbdifClassDef_t      class;
  int                   unit;
  int                   num = 0;       /* adhoc */

  /* global initialize */
  UsbifInit(-1, NULL);

  unit = 1;
  /* device initialize */
  usbInitParam.pDeviceDesc   = usbDescDevice;
  usbInitParam.lenDeviceDesc = usbDescDeviceLen;
  usbInitParam.pDeviceQualifierDesc   = usbDescDeviceQualifier;
  usbInitParam.lenDeviceQualifierDesc = usbDescDeviceQualifierLen;
  usbInitParam.pConfigDesc   = usbDescConfig;
  usbInitParam.lenConfigDesc = usbDescConfigLen;
  usbInitParam.numConfigDesc = 1;
  usbInitParam.pStringDescTbl[0] = usbDescString;
  UsbifInit(unit, &usbInitParam);

  /* cdc initialize */
#if USBDESC_ENABLE_CDCACM
  memset(&class, 0, sizeof(class));
  class.type = USBDIF_CLASSTYPE_CDC;
  class.cb = NULL;
  class.numClass = num++;       /* adhoc */
  class.ifnum = ((1<<(USBDESC_IF_CDC_DATA))
                 | (1<<(USBDESC_IF_CDC_CTRL)));
  class.epnum = (USBDIF_EPBIT(USBDESC_EP_CDC_OUT)
                 | USBDIF_EPBIT(USBDESC_EP_CDC_IN)
                 | USBDIF_EPBIT(USBDESC_EP_CDC_CTRL));
  class.pUserData = &usbcdcCb;
  dUsbCdc = UsbifRegisterClass(unit, &class);
#endif

  /* start usb middleware */
  UsbifStart(unit);

  /* start usb module */
  {
    devUsbParam_t    param;
    const static usbdifDevFifo_t  fifo = {
      /* OUT    0  1... */
      {      1024, 0},
      /* IN     0    1    2     3    4    5    6    7 */
      {       192, 128,  64, 1024, 256,  64, 256,  64}, };

    DevUsbInit(-1, NULL);

    param.dma = 0;

    /* call back setting */
    param.cb.setup = UsbdcoreCbSetup;
    param.cb.dataInDone = UsbdcoreCbDataInDone;
    param.cb.dataOut = UsbdcoreCbDataOut;
    param.cb.busState = UsbdcoreCbBusState;

    DevUsbInit(unit, &param);
    DevUsbSetTRxFifo(unit, (usbdifDevFifo_t *)&fifo);

    GpioSetUsbEnable();

    /* interrupt enable */
    NVIC_SetPriority(OTG_HS_IRQn, 5);
    NVIC_EnableIRQ(OTG_HS_IRQn);
  }

  return;
}
static void
MainUsbdifTask(void const * argument)
{

  MainInitUsb();

  /* Infinite loop */
  while(1) {
    RtosTaskSleep(100);
  }
}


static rtosQueueId     mainEventPll;
static void
MainPllTask(void const * argument)
{
  uint32_t      val;

  //mainEventPll = RtosEventCreate();
  mainEventPll = RtosQueueCreate(4, 4);

  PllpidInit(96000000, 2);

  while(1) {
    RtosQueueRecv(mainEventPll, &val, 1000);
    PllpidLoop(val);
  }

  return;
}

/*
 *   XO -- PLLA -- MULTISYNTH0 -- DIV_R0 -- CLK0
 *   XO -- PLLB -- MULTISYNTH2 -- DIV_R2 -- CLK2
 *
 *  Limitations PLL
 *    fCLKIN      =  10 --  40MHz after input divider (divCLKIN=1,2,4,8)
 *    fVCO        = 600 -- 900MHz
 *    N/M         = (15+0/1048575), and up to (90*0/1048575)
 *
 *  Limitations MULTITYNTH
 *    fMultisynth = 0.5 -- 200MHz
 *    Multisyth   = 4, 6, 8, (8+1/1048575), and up to (900+0/1)
 *
 *  Limitations OUTPUT
 *    output div  = 1, 2, 4, 8, 16, 32, 64, 128
 *
 *  fOUT = fVCO / (Multisynth * R)
 *
 *  fVCO = fXTAL * (a + b/c)
 *
 *   8+1/1048575 -- 900*0/1
 *
 *    VCO(a, b, c) = (30, 402, 1625)
 * 24.576MHz*(32+0/1)    = 786.432MHz = 26MHz * 786432/26000 = 26 * (30 + 402/1625)
 *    DIV(a, b, c) = (32, 0, 1)
 * 24.000MHz*(32+96/125) = 786.432MHz = 26MHz * 786432/26000 = 26 * (30 + 402/1625)
 *    DIV(a, b, c) = (32, 96, 125)
 *
 */
void
MainInitSi5351(void)
{

  Si5351Init(0,
             1,
             26000000,                  // IN
             786432000, 0,              // VCO0, VCO1
             24576000, 0, 24000000,     // OUT0, 1, 2
             SI5351_OUT0_USE_VCO0 | SI5351_OUT2_USE_VCO0 | SI5351_OUT2_USE_VCO0);

  return;
}



/**
  * @brief  This function is executed in case of error occurrence.
  * @param  file: The file name as string.
  * @param  line: The line in file as a number.
  * @retval None
  */
void _Error_Handler(char *file, int line)
{
  while(1);
}



char            c1;
void
_putchar(char c)
{
  DevUsartSend(CONFIG_SYSTEM_USART_PORT, &c, 1);

#if PRINTF_CDC_FIFO
  UsbCdcAcmSend(dUsbCdc, &c, 1);
#endif



  return;
}
int
puts(const char *str)
{
  int           len;

  len = strlen(str);
  DevUsartSend(CONFIG_SYSTEM_USART_PORT, (uint8_t *)str, len);

#if PRINTF_CDC_FIFO
  len = strlen(str);
  UsbCdcAcmSend(dUsbCdc, str, len);
#endif

  return len;
}






void
TIM2_IRQHandler(void)
{
  uint32_t              sr;
  static uint32_t       ch1, ch3, ch4, prevCh1, prevCh3, prevCh4;

  sr = TIM2_PTR->SR;
  TIM2_PTR->SR = sr;

  /* GPS pps pulse */
  if(sr & TIM_SR_CC1IF_MASK) {
    ch1 = TIM2_PTR->CCR1;
    //printf("TIM2->CCR1 %x %d\r\n", ch1, prevCh1 - ch1);
    prevCh1 = ch1;
  }
  if(sr & TIM_SR_CC3IF_MASK) {
    ch3 = TIM2_PTR->CCR3;
    //printf("TIM2->CCR3 %x %d\r\n", ch3, prevCh3 - ch3);
    prevCh3 = ch3;
  }
  /* SOF pulse */
  static int   i = 0;
  if(sr & TIM_SR_CC4IF_MASK) {

    if(i == 1999) {
      uint32_t  val;
      i = 0;
      ch4 = TIM2_PTR->CCR4;
      val = prevCh4 - ch4;
      prevCh4 = ch4;

      if(mainEventPll) {
        RtosQueueSendIsr(mainEventPll, &val, 0);
      }

    }
    i++;

    UsbdevSofEntry(0);
  }

  return;
}
