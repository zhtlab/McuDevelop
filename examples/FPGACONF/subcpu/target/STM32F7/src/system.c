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

#define _SYSTEM_STM32H7_C_
#define _SYSTEM_C_

#include        <stdio.h>
#include        <stdint.h>
#include        <string.h>

#include        "config.h"
#include        "system.h"
#include        "devGpio.h"
#include        "stm32f7Rcc.h"
#include        "devCrs.h"



#define SYSTEM_TIMER_REG        (TIM5_PTR->CNT)     /* decrement counter */

static systemClockFreq_t        systemClk;
uint32_t                        SystemCoreClock; /* used in the CMSIS */


void
SystemInit(void)
{
  /*********************************
   * set normal clock setting
   */
  SystemChangeClockDefault();


  /*********************************
   * cache control
   */
#if CONFIG_CACHE_INST_ENABLE
  SCB_EnableICache();
#endif
#if CONFIG_CACHE_DATA_ENABLE
  SystemMpuConfig();
  //SCB_EnableDCache();
#endif


  /*********************************
   * fpu control
   */
#if (__FPU_PRESENT == 1) && (__FPU_USED == 1)
  SCB->CPACR |= ((3UL << 10*2)|(3UL << 11*2));  /* set CP10 and CP11 Full Access */
  __DSB();
  __ISB();      /* reset the instruction pipe line and enable FPU */
#endif

#if 0
  /*********************************
   * clock control
   */
  //systemClockFreq_t     clk;
  //RCC_PTR->APB2ENR |= RCC_APB2ENR_SYSCFGEN_YES;
  SystemChangeClockHigher();
  SystemUpdateClockValue();
  //SystemGetClockValue(&clk);
#endif

#if 0
  devCrsParam_t     crs;
  /* Clock recovery base clock is set enable */
  RCC_PTR->APB1HENR |= (RCC_APB1HENR_CRSEN_YES);

  /* reset once */
  (RCC_PTR->APB1HRSTR) |=  RCC_APB1HRSTR_CRSRST_YES;
  (RCC_PTR->APB1HRSTR) &= ~RCC_APB1HRSTR_CRSRST_MASK;

  crs.src = CRS_CLOCK_SOURCE_USB2;
  DevCrsInit(&crs);
#endif


  /*********************************
   * clock gate control
   */
  /* pwr */
  RCC_PTR->APB1ENR |= RCC_APB1ENR_PWREN_YES;

  /* dctm */
  //RCC_PTR->AHB1ENR |= RCC_AHB1ENR_DTCMRAMEN_YES;

  /* gpio */
  RCC_PTR->AHB1ENR |= (RCC_AHB1ENR_GPIOAEN_YES | RCC_AHB1ENR_GPIOBEN_YES |
                       RCC_AHB1ENR_GPIOCEN_YES | RCC_AHB1ENR_GPIODEN_YES |
                       RCC_AHB1ENR_GPIOEEN_YES | RCC_AHB1ENR_GPIOFEN_YES |
                       RCC_AHB1ENR_GPIOGEN_YES | RCC_AHB1ENR_GPIOHEN_YES |
                       RCC_AHB1ENR_GPIOIEN_YES);
  /* i2c */
  RCC_PTR->APB1ENR |= RCC_APB1ENR_I2C2EN_YES;

  /* wait about 20ms @16MHz */
  for(int i = 0; i < 20000; i++) RCC_PTR->CR;

  /* usart */
  RCC_PTR->APB2ENR |= RCC_APB2ENR_USART1EN_YES;

  /* spi */
  RCC_PTR->APB2ENR |= RCC_APB2ENR_SPI1EN_YES;

  /* timer */

  /* fmc */
  RCC_PTR->AHB3ENR |= RCC_AHB3ENR_FMCEN_YES;

  /* dma */
  RCC_PTR->AHB1ENR |= RCC_AHB1ENR_DMA1EN_YES | RCC_AHB1ENR_DMA2EN_YES;

  /* sdmmc en and 100MHz   SDCLK upto 50MHz */
  RCC_PTR->APB2ENR |= RCC_APB2ENR_SDMMC1EN_YES;
  RCC_PTR->DCKCFGR2 |= RCC_DCKCFGR2_SDMMC1SEL_PLLQ;

  /* adc, dac */
  RCC_PTR->APB2ENR |= RCC_APB2ENR_ADC1EN_YES;

#if 0
  /* usb, otg */
  RCC_PTR->AHB1ENR |= RCC_AHB1ENR_OTGHSEN_YES | RCC_AHB1ENR_OTGHSULPIEN_YES;
  //RCC_PTR->APB2ENR |= RCC_APB2ENR_OTGPHYCEN_YES;

  /* usb phy controller,  enable LDO, enable CTRLer */
  int         tout = 0x400000;
  USBPHYC_PTR->LDO |= USBPHYC_LDO_DISABLE_YES;  /* errata: 1 is enable */
  while((USBPHYC_PTR->LDO & USBPHYC_LDO_STATUS_MASK)) {
    if(tout-- <= 0) break;
  }

  switch(CONFIG_CLOCK_HSE) {
  case 12000000: USBPHYC_PTR->PLL1 = USBPHYC_PLL1_SEL_12MHZ; break;
  case 12500000: USBPHYC_PTR->PLL1 = USBPHYC_PLL1_SEL_12_5MHZ; break;
  case 16000000: USBPHYC_PTR->PLL1 = USBPHYC_PLL1_SEL_16MHZ; break;
  case 24000000: USBPHYC_PTR->PLL1 = USBPHYC_PLL1_SEL_24MHZ; break;
  case 25000000: USBPHYC_PTR->PLL1 = USBPHYC_PLL1_SEL_25MHZ; break;
  }

  USBPHYC_PTR->TUNE =
    USBPHYC_TUNE_HSDRVCHKITRM_20_94MA |
    USBPHYC_TUNE_HSDRVRFRED_SHIFT |
    USBPHYC_TUNE_HSDRVDCCUR_DEC5MV |
    USBPHYC_TUNE_LFSCAPEN_YES | USBPHYC_TUNE_INCURREN_YES | USBPHYC_TUNE_INCURRINT_YES;

  USBPHYC_PTR->PLL1 |= USBPHYC_PLL1_EN_YES;
#endif


  /*********************************
   * set interrupt vector pointer
   */
  extern uint32_t       sectVectorStart[];
  SCB->VTOR = (uint32_t)&sectVectorStart;

  return;
}


void
SystemLoop(void)
{
  return;
}



void
SystemChangeClockDefault(void)
{
  /* enable HSION bit */
  RCC_PTR->CR |= RCC_CR_HSION_YES;

  RCC_PTR->CFGR = 0;
  RCC_PTR->CR &= ~(RCC_CR_HSEON_MASK | RCC_CR_CSSON_MASK |
               RCC_CR_PLLON_MASK);

  /* reset the following registers */
  RCC_PTR->PLLCFGR = 0x24003010;
  RCC_PTR->CR &= ~RCC_CR_HSEBYP_MASK;
  RCC_PTR->CIR = 0;
  while(!(RCC_PTR->CR & (RCC_CR_HSIRDY_MASK)));

  return;
}
void
SystemChangeClockHigher(void)
{
  uint32_t              val;

  /** change core voltage */
#if 0
  /* already enabled */
  PWR_PTR->CR1 |= PWR_CR1_ODSWEN_YES;
  while(!(PWR_PTR->CSR1 & PWR_CSR1_ODSWRDY_MASK));
  PWR_PTR->CR1 |= PWR_CR1_ODEN_YES;
  while(!(PWR_PTR->CSR1 & PWR_CSR1_ODRDY_MASK));
  /* already selected range1 */
  PWR_PTR->CR1 |= PWR_CR1_VOS_RANGE1_180MHZ;
  while(!(PWR_PTR->CSR1 & PWR_CSR1_VOSRDY_MASK));
#endif

  /* change flash access time */
  /* 2.7V -- 3.6V
   *  (  0 -  30]: 0WS
   *  ( 30 -  60]: 1WS
   *  ( 60 -  90]: 2WS
   *  ( 90 - 120]: 3WS
   *  (120 - 150]: 4WS
   *  (150 - 180]: 5WS
   *  (180 - 210]: 6WS
   */
  FLASH_PTR->ACR = FLASH_LATENCY_CLK(CONFIG_CLOCK_FREQ_CPU/30000000);

  /*** select clock sources */
  //RCC_PTR->CR |= RCC_CR_HSEON_YES| RCC_CR_HSEBYP_YES;
  //while(!(RCC_PTR->CR & (RCC_CR_HSERDY_MASK)));

  /* pll1 settings  vco range (100-432MHz)
   * HSI=16MHz
   * M=8(2MHz), N=200(400MHz)
   * P=4(100MHz), Q=4(100MHz)
   */
  RCC_PTR->PLLCFGR  = (RCC_PLLCFGR_PLLSRC_HSI16 |
                       RCC_PLLCFGR_PLLM_DIV(8) | RCC_PLLCFGR_PLLN_MULX(CONFIG_CLOCK_FREQ_CPU/1000000) |
                       RCC_PLLCFGR_PLLP_DIV2 | RCC_PLLCFGR_PLLQ_DIV(8) );

  RccPll1Enable();

  /* clock divider */
  /* APB1 is up to  54MHz
   * APB2 is up to 108MHz
   */
  RCC_PTR->CFGR = (RCC_CFGR_HPRE_DIV1 |
                   RCC_CFGR_PPRE1_DIV4 | RCC_CFGR_PPRE2_DIV2);

  /* the system clock is selected to PLL1 */
  RCC_PTR->CFGR |= RCC_CFGR_SW_PLL;
  while((RCC_PTR->CFGR & RCC_CFGR_SWS_MASK) != RCC_CFGR_SWS_PLL);


  /*** MCO setting */
#if CONFIG_MCO_ENABLE
  val = RCC_PTR->CFGR;
  val &= ~(RCC_CFGR_MCO2SEL_MASK | RCC_CFGR_MCO2PRE_MASK |
           RCC_CFGR_MCO1SEL_MASK | RCC_CFGR_MCO1PRE_MASK);
  val |= RCC_CFGR_MCO1SEL_PLL | RCC_CFGR_MCO1PRE_DIV2;
  val |= RCC_CFGR_MCO2SEL_SYSCLK | RCC_CFGR_MCO2PRE_DIV2;
  RCC_PTR->CFGR = val;
#endif

  return;
}
void
SystemChangeClock180MHz(void)
{
  uint32_t              val;

  /** change core voltage */
#if 0
  /* already enabled */
  PWR_PTR->CR1 |= PWR_CR1_ODSWEN_YES;
  while(!(PWR_PTR->CSR1 & PWR_CSR1_ODSWRDY_MASK));
  PWR_PTR->CR1 |= PWR_CR1_ODEN_YES;
  while(!(PWR_PTR->CSR1 & PWR_CSR1_ODRDY_MASK));
  /* already selected range1 */
  PWR_PTR->CR1 |= PWR_CR1_VOS_RANGE1_180MHZ;
  while(!(PWR_PTR->CSR1 & PWR_CSR1_VOSRDY_MASK));
#endif

  /* change flash access time */
  /* 1.7V -- 2.1V
   *  (  0 -  20]: 0WS
   *  ( 20 -  40]: 1WS
   *  ( 40 -  60]: 2WS
   *  ( 60 -  80]: 3WS
   *  ( 80 - 100]: 4WS
   *  (100 - 120]: 5WS
   *  (120 - 140]: 6WS
   *  (140 - 160]: 7WS
   *  (160 - 180]: 8WS
   */
  FLASH_PTR->ACR = FLASH_LATENCY_CLK(CONFIG_CLOCK_FREQ_CPU/20000000);

  /*** select clock sources */
  //RCC_PTR->CR |= RCC_CR_HSEON_YES| RCC_CR_HSEBYP_YES;
  //while(!(RCC_PTR->CR & (RCC_CR_HSERDY_MASK)));

  /* pll1 settings  vco range (100-432MHz)
   * HSI=16MHz
   * M=8(2MHz), N=200(400MHz)
   * P=4(100MHz), Q=4(100MHz)
   */
  RCC_PTR->PLLCFGR  = (RCC_PLLCFGR_PLLSRC_HSI16 |
                       RCC_PLLCFGR_PLLM_DIV(8) | RCC_PLLCFGR_PLLN_MULX(CONFIG_CLOCK_FREQ_CPU180/1000000) |
                       RCC_PLLCFGR_PLLP_DIV2 | RCC_PLLCFGR_PLLQ_DIV(8) );

  RccPll1Enable();

  /* clock divider */
  /* APB1 is up to  54MHz
   * APB2 is up to 108MHz
   */
  RCC_PTR->CFGR = (RCC_CFGR_HPRE_DIV1 |
                   RCC_CFGR_PPRE1_DIV4 | RCC_CFGR_PPRE2_DIV2);

  /* the system clock is selected to PLL1 */
  RCC_PTR->CFGR |= RCC_CFGR_SW_PLL;
  while((RCC_PTR->CFGR & RCC_CFGR_SWS_MASK) != RCC_CFGR_SWS_PLL);


  /*** MCO setting */
#if CONFIG_MCO_ENABLE
  val = RCC_PTR->CFGR;
  val &= ~(RCC_CFGR_MCO2SEL_MASK | RCC_CFGR_MCO2PRE_MASK |
           RCC_CFGR_MCO1SEL_MASK | RCC_CFGR_MCO1PRE_MASK);
  val |= RCC_CFGR_MCO1SEL_PLL | RCC_CFGR_MCO1PRE_DIV2;
  val |= RCC_CFGR_MCO2SEL_SYSCLK | RCC_CFGR_MCO2PRE_DIV2;
  RCC_PTR->CFGR = val;
#endif

  return;
}


const static uint8_t   systemAHBPrescalerTable[]   = RCC_CLOCK_HPRETABLE;
const static uint8_t   systemPeri1PrescalerTable[] = RCC_CLOCK_PPRETABLE;
const static uint8_t   systemPeri2PrescalerTable[] = RCC_CLOCK_PPRETABLE;
void
SystemUpdateClockValue(void)
{
  int           div, shift;
  uint32_t      freqPllIn;
  uint32_t      m, n;
  uint32_t      vco;

  /*** PLL clock source selector */
  switch(RCC_PTR->PLLCFGR & RCC_PLLCFGR_PLLSRC_MASK) {
  case RCC_PLLCFGR_PLLSRC_HSI16: freqPllIn = RCC_CLOCK_HSI;    break;
  case RCC_PLLCFGR_PLLSRC_HSE:   freqPllIn = CONFIG_CLOCK_HSE; break;
    /* case PLLCKSELR_PLLSRC_CSI: */
  default:                   freqPllIn = 0;    break;
  }
  systemClk.pllin = freqPllIn;

  /*** freq_VCO = (freq_PLLIN / M) * N,   freq_SYSCLK = freq_VCO / DIVP */
  /*** calc PLL1 frequency value */
  CALCPLL(RCC_PTR->PLLCFGR, 1, freqPllIn);

  /* calc core,HCLK,SysTick clock */
  SystemCoreClockUpdate();

  /* APB1, 2 */
  div   = (RCC_PTR->CFGR &  RCC_CFGR_PPRE1_MASK) >>  RCC_CFGR_PPRE1_SHIFT;
  shift = systemPeri1PrescalerTable[div];
  systemClk.pclk1 = systemClk.hclk >> shift;
  div   = (RCC_PTR->CFGR &  RCC_CFGR_PPRE2_MASK) >>  RCC_CFGR_PPRE2_SHIFT;
  shift = systemPeri2PrescalerTable[div];
  systemClk.pclk2 = systemClk.hclk >> shift;

  return;
}
static void
SystemCoreClockUpdate(void)
{
  int           div, shift;
  uint32_t      clk;

  /* SYSCLK selector */
  switch (RCC_PTR->CFGR & RCC_CFGR_SWS_MASK) {
  case RCC_CFGR_SWS_HSI:
    clk = RCC_CLOCK_HSI;
    break;

  case RCC_CFGR_SWS_HSE:
    clk = CONFIG_CLOCK_HSE;
    break;

  case RCC_CFGR_SWS_PLL:
    clk = systemClk.pll1.P;
    break;
  }
  systemClk.sysclk  = clk;

  /* AHB1: HCLK frequency */
  div   = (RCC_PTR->CFGR & RCC_CFGR_HPRE_MASK);
  div >>= RCC_CFGR_HPRE_SHIFT;
  shift = systemAHBPrescalerTable[div];
  systemClk.hclk  = clk >> shift;
  systemClk.core = systemClk.hclk;
  systemClk.systick = systemClk.hclk;

  /* for FreeRTOS */
  SystemCoreClock = systemClk.hclk;

  return;
}


int
SystemGetClockValue(systemClockFreq_t *p)
{
  int           result = -1;
  if(p) {
    memcpy(p, &systemClk, sizeof(systemClockFreq_t));
    result = 0;
  }

  return result;
}
void
SystemDebugShowClockValue(systemClockFreq_t *p)
{
  printf("# clock info\r\n");
  printf("  clkin: %d\r\n", p->pllin);
  printf("  vco: %d\r\n", p->pll1.vco);
  printf("  pll1p: %d, q: %d\r\n",
         p->pll1.P, p->pll1.Q);
#if 0
  printf("  pll2p: %d, q: %d, r: %d\r\n",
         p->pll2.P, p->pll2.Q, p->pll2.R);
  printf("  pll3p: %d, q: %d, r: %d\r\n",
         p->pll3.P, p->pll3.Q, p->pll3.R);
#endif
  printf("  core:  %d, systick(x8): %d, hclk: %d\r\n",
         p->core, p->systick, p->hclk);
  printf("  pclk1: %d, pclk2: %d, pclk3: %d, pclk4: %d\r\n",
         p->pclk1, p->pclk2, p->pclk3, p->pclk4);

  return;
}


int
SystemGetVddValue(void)
{
  int           val, voltage;

  /* adc, dac */
  RCC_PTR->APB2ENR |= RCC_APB2ENR_ADC1EN_YES;

  ADC1_PTR->CR2  = ADC_CR2_ALIGN_LEFT | ADC_CR2_ADON_YES;
  ADC1_PTR->CR1  = ADC_CR1_RES_12BIT;
  ADC1_PTR->SMPR1 = ADC_SMPR1_SMP_ALLSLOW;
  ADC1_PTR->SMPR2 = ADC_SMPR2_SMP_ALLSLOW;

  ADC1_PTR->SQR1 = 0;
  ADC1_PTR->SQR3 = ADC_SQR_VREFINT;

  ADC1_PTR->CCR = (ADC_CCR_TSVREFE_YES |
                   ADC_CCR_ADCPRE_PCLK2_DIV8 |
                   ADC_CCR_DELAY_VAL(2));

  /* start AD and wait done */
  ADC1_PTR->CR2 |= ADC_CR2_SWSTART_YES;
  for(int i = 0; i < 20000; i++) {
    if(ADC1_PTR->SR & ADC_SR_EOC_MASK) break;
  }

  val = ADC1_PTR->DR;
  voltage = (1200 << 16) / val;     // "<< 16" is intead of *65535 */

  return voltage;
}


/*
 * see the AN4838 document
 */
void
SystemMpuConfig(void)
{
  /* disable memory fault  and  disable mpu */
  SCB->SHCSR &= ~SCB_SHCSR_MEMFAULTENA_Msk;
  MPU->CTRL  &= ~MPU_CTRL_ENABLE_Msk;

  /* 0x60000000 (512bytes) cache disable */
  MPU->RNR  = 0;         /* region number 0 */
  MPU->RBAR = 0x60000000;
  MPU->RASR = ((1<<MPU_RASR_XN_Pos) |   /* instruction access disable */
               (3<<MPU_RASR_AP_Pos) |   /* full access */
               (0<<MPU_RASR_TEX_Pos) |  /* level 0 */
               (0<<MPU_RASR_C_Pos) |    /* cachable: no */
               (1<<MPU_RASR_S_Pos) |    /* shared: yes */
               (1<<MPU_RASR_B_Pos) |    /* buffer: yes */
               (0<<MPU_RASR_SRD_Pos) |  /* sub rigion */
               (8<<MPU_RASR_SIZE_Pos) | /* 2^(n+1), min 4 (32bytes) */
               (1<<MPU_RASR_ENABLE_Pos) /* enable */
               );

  /* enable mpu  and  enable memory fault */
  MPU->CTRL   = MPU_CTRL_PRIVDEFENA_Msk | MPU_CTRL_ENABLE_Msk;
  SCB->SHCSR  = SCB_SHCSR_MEMFAULTENA_Msk;

  return;
}


void
SystemChangeBusWrAccess(int unit, int wrlow, int wrhigh)
{
  stm32Dev_FMC_bank   *pBank;
  uint32_t            val;

  if(wrlow  > FMC_BTR_DATAST_MAX) wrlow  = FMC_BTR_DATAST_MAX;
  if(wrhigh > FMC_BTR_ADDSET_MAX) wrhigh = FMC_BTR_ADDSET_MAX;

  pBank = &FMC_PTR->B[unit];
  val = (FMC_BTR_ACCMOD_A |
         FMC_BTR_DATAST(wrlow) | FMC_BTR_ADDSET(wrhigh));
  pBank->TR = val;

  return;
}


void
SystemGpioSet(int unit, uint32_t bit)
{
  GPIO_PTR[unit].BSRR = bit;
  return;
}
void
SystemGpioReset(int unit, uint32_t bit)
{
  GPIO_PTR[unit].BRR = bit;
  return;
}




void
SystemWdtInit(void)
{
  return;
}
void
SystemWdtClear(void)
{
  return;
}


#if 0
struct _stSystemMallocInfo {
  int                           size;
  void                          *vp;
  struct _stSystemMallocInfo    *next;
  uint32_t                      pad[1];
  /*** the following data is malloc buffer
       uint32_t                    buf[1];*/
};
static struct _stSystemMallocInfo     *pinfo[2] = {
  (struct _stSystemMallocInfo *)0x20000000,
};
static int      szRemain[2] = {
  0x10000,
  0x00000,
};
void *
SystemMallocStreamBuf(int type, int size, void *vp)
{
  void          *p = NULL;
  uint32_t      next;

  if(type >= 2) goto fail;

  if(szRemain[type] < (size + sizeof(struct _stSystemMallocInfo))) goto fail;

  pinfo[type]->size = size;
  pinfo[type]->vp = vp;
  p = (void *)(pinfo[type]+1);
  next  = (size + 15) & ~15;
  next += (uint32_t) p;
  pinfo[type]->next = (struct _stSystemMallocInfo *) next;

  pinfo[type] = pinfo[type]->next;

fail:
  return p;
}
#endif


uint32_t
SystemGetSystemTimer(void)
{
  return SYSTEM_TIMER_REG;
}
void
SystemWaitSystemTimer(uint32_t tout)
{
  uint32_t      t;
  t = SYSTEM_TIMER_REG;
  while((t - (SYSTEM_TIMER_REG)) < tout);
  return;
}


void
SystemSysTickIntr(void)
{
  SysTick->VAL;

  return;
}


#if CONFIG_SYSTEM_MALLOC_HEAP
extern void *sectHeapStart;
static void *ptrMalloc = &sectHeapStart;
static int      cntMalloc = 0;
void *
malloc(int size)
{
  void *p;

  p = ptrMalloc;
  size +=  0xf;
  size &= ~0xf;
  ptrMalloc += size;

#if CONFIG_SYSTEM_MALLOC_RTOS
  p = (void *)RtosMalloc(size);
#endif

  return p;
}
void
free(void *ptr)
{
  printf("XX free %x %x\n", ptr);
  return;
}
#endif
#if CONFIG_SYSTEM_MALLOC_RTOS
#include        "rtos.h"

void *
malloc(int size)
{
  void *p;

  p = (void *)RtosMalloc(size);

  return p;
}
void
free(void *ptr)
{
  printf("XX free %x %x\n", ptr);
  return;
}
#endif
