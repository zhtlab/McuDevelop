/*
 * Copyright (c) 2018 zhtlab
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

#define	_PERII2C_C_

#include	<stdint.h>

#include	"config.h"
#include	"system.h"
#include	"gpio.h"

#include	"peri.h"
#include	"periI2c.h"

#define	PERII2C_UNIT_MAX		3

extern struct _stPeri	peri;

static stm32Dev_I2C     *pu[] = {
  I2C1_PTR, I2C2_PTR, I2C3_PTR,
};
const static uint16_t	gpioInitScl[] = {
  PORT_CTRL(GPIO_I2C1_SCL, GPIO_MODE_FUNC, GPIO_PULL_OD, GPIO_FUNC4_I2C),
  PORT_CTRL(GPIO_I2C2_SCL, GPIO_MODE_FUNC, GPIO_PULL_OD, GPIO_FUNC4_I2C),
  PORT_CTRL(GPIO_I2C3_SCL, GPIO_MODE_FUNC, GPIO_PULL_OD, GPIO_FUNC4_I2C),
};
const static uint16_t	gpioInitSda[] = {
  PORT_CTRL(GPIO_I2C1_SDA, GPIO_MODE_FUNC, GPIO_PULL_OD, GPIO_FUNC4_I2C),
  PORT_CTRL(GPIO_I2C2_SDA, GPIO_MODE_FUNC, GPIO_PULL_OD, GPIO_FUNC4_I2C),
  PORT_CTRL(GPIO_I2C3_SDA, GPIO_MODE_FUNC, GPIO_PULL_OD, GPIO_FUNC4_I2C),
};
const static uint16_t	gpioUninitScl[] = {
  PORT_CTRL(GPIO_I2C1_SCL, GPIO_MODE_INPUT, GPIO_PULL_NONE, 0),
  PORT_CTRL(GPIO_I2C2_SCL, GPIO_MODE_INPUT, GPIO_PULL_NONE, 0),
  PORT_CTRL(GPIO_I2C3_SCL, GPIO_MODE_INPUT, GPIO_PULL_NONE, 0),
};
const static uint16_t	gpioUninitSda[] = {
  PORT_CTRL(GPIO_I2C1_SDA, GPIO_MODE_INPUT, GPIO_PULL_NONE, 0),
  PORT_CTRL(GPIO_I2C2_SDA, GPIO_MODE_INPUT, GPIO_PULL_NONE, 0),
  PORT_CTRL(GPIO_I2C3_SDA, GPIO_MODE_INPUT, GPIO_PULL_NONE, 0),
};
const static int	dmaChTbl[] = {
  DMA_CH7, DMA_CH5, DMA_CH3,  
};


int
PeriI2cInit(int unit)
{
  int				result = PERI_ERROR_UNKNOWN;
  struct _stStm32l4_DMACH	*ch;
  uint32_t			val;
  stm32Dev_I2C                  *u;
  int				dmaCh;

  if(unit >= PERII2C_UNIT_MAX) goto fail;

#if 0
  switch(unit) {
  case	0: RCC_PTR->APB2ENR  |= RCC_APB2ENR_I2C1EN_YES; break;
  case	1: RCC_PTR->APB1ENR1 |= RCC_APB1ENR1_I2C2EN_YES; break;
  case	2: RCC_PTR->APB1ENR1 |= RCC_APB1ENR1_I2C3EN_YES; break;
  }
#endif

  u = pu[unit];

  /* gpio function setting */
  SystemGpioSet(gpioInitScl[unit]);
  SystemGpioSet(gpioInitSda[unit]);

#if 0
  /* dma setting */
  dmaCh = dmaChTbl[unit];
  ch = &DMA_PTR[DMA_MODULE1].ch[dmaCh];
  DMA_PTR[DMA_MODULE1].cselr &= ~CSELR_DMA_MASK(dmaCh);
  DMA_PTR[DMA_MODULE1].cselr |=  CSELR_DMA_SEL(dmaCh, 3);
    
  ch->ccr = 0;
  ch->cndtr = PERI_RX_BUF_SIZE;
  ch->cmar = (uint32_t) peri.bufRx;
  ch->cpar = (uint32_t) &u->rxdr;
  ch->ccr = CCR_MEM2MEM_NO | CCR_MSIZE_8BIT | CCR_PSIZE_8BIT | \
    CCR_MINC_YES | CCR_PINC_NO | CCR_DIR_READ_PERI | CCR_EN_YES;
#endif
  /* i2c setting */
  u->OAR1 = I2C_OAR1_OA1EN_YES |
    ((CONFIG_BOOTLOADER_PERI_I2C_ADDR) << I2C_OAR1_OA1_7BIT_SHIFT);
  u->CR2 = I2C_CR2_AUTOEND_YES | I2C_CR2_NACK;
  u->CR1 |= I2C_CR1_GCEN_YES | I2C_CR1_NOSTRETCH_YES;

  /* enable */
  u->CR1 |= I2C_CR1_PE_YES;

  result = PERI_SUCCESS;

fail:
  return result;
}


int
PeriI2cUninit(int unit)
{
  int		result = PERI_ERROR_UNKNOWN;

  stm32Dev_I2C                  *u;
  int				dmaCh;
  uint16_t			gpio;

  if(unit >= PERII2C_UNIT_MAX) goto fail;

  u = pu[unit];
  u->CR1 = 0;				/* disable I2C */
  u->CR2 = 0;
  u->OAR1 = 0;

  SystemGpioSet(gpioUninitScl[unit]);
  SystemGpioSet(gpioUninitSda[unit]);

#if 0
  dmaCh = dmaChTbl[unit];
  DMA_PTR[DMA_MODULE1].cselr &= ~CSELR_DMA_MASK(dmaCh);
#endif
#if 0
  switch(unit) {
  case	0: RCC_PTR->APB2ENR  &= ~RCC_APB2ENR_I2C1EN_YES; break;
  case	1: RCC_PTR->APB1ENR1 &= ~RCC_APB1ENR1_I2C2EN_YES; break;
  case	2: RCC_PTR->APB1ENR1 &= ~RCC_APB1ENR1_I2C3EN_YES; break;
  }
#endif

  result = PERI_SUCCESS;

fail:
  return result;
}


int
PeriI2cProbe(int unit)
{
  int		result = PERI_ERROR_UNKNOWN;
  char		ch;
  int		len;

  if(unit >= PERII2C_UNIT_MAX) goto fail;

  len = sizeof(ch);

  PeriI2cRecv(unit, &ch, &len);
  if(len >= 1) {
    result = PERI_SUCCESS;
  }
  
fail:
  return result;
}


int
PeriI2cSend(int unit, const uint8_t *ptr, int len)
{
  int		result = PERI_ERROR_UNKNOWN;
  int		i;
  stm32Dev_I2C  *u;

  if(unit >= PERII2C_UNIT_MAX) goto fail;

  u = pu[unit];

  for(i = 0; i < len; i++) {
    while(!(u->ISR & I2C_ISR_TXE_MASK));
    u->TXDR = ptr[i];
  }

  result = PERI_SUCCESS;

fail:
  return result;
}


int
PeriI2cRecv(int unit, uint8_t *ptr, int *len)
{
  int		result = PERI_ERROR_UNKNOWN;
  int		i = 0;
  int		t = 0;

  struct _stStm32l4_I2C		*u;
  struct _stStm32l4_DMACH	*ch;
  int		sz;

  if(unit >= PERII2C_UNIT_MAX) goto fail;

#if 0
  ch = &DMA_PTR[DMA_MODULE1].ch[dmaChTbl[unit]];

  ch->ccr &= ~CCR_EN_MASK;
  sz = PERI_RX_BUF_SIZE - ch->cndtr;
  if(sz > *len) sz = *len;
  if(sz > 0) {
    memcpy(ptr, peri.bufRx, sz);
    *len = sz;
  } else {
    *len = 0;
  }
  ch->cmar = (uint32_t) peri.bufRx;
  ch->cndtr = PERI_RX_BUF_SIZE;
  ch->ccr |= CCR_EN_YES;
#endif
  *len = 0;

  result = PERI_SUCCESS;

fail:
  return result;
}


int
PeriI2cIoctl(int unit, int req, void *ptr, int len)
{
  int		result = PERI_ERROR_UNKNOWN;
  uint32_t	*pL;
  //struct _stStm32l4_DMACH	*ch;

  if(!ptr || len < 0) goto fail;

  if(unit >= PERII2C_UNIT_MAX) goto fail;

  pL = (uint32_t *) ptr;
  //ch = &DMA_PTR[DMA_MODULE1].ch[dmaChTbl[unit]];

  switch(req) {
  case	PERII2C_GET_RECV_SIZE:
    *pL = PERI_RX_BUF_SIZE - 0;         /* adhoc */
    break;
  }
    
  
  result = PERI_SUCCESS;
fail:
  return result;
}
