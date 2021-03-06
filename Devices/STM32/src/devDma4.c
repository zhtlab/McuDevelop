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

#define _DEV_DMA4_C_

#include        <stdio.h>
#include        <string.h>

#include        "system.h"
#include        "devErrno.h"
#include        "devDma4.h"

struct _stDma         dma;

/*
 * unit: 1=DMA1, 2=DMA2
 * ch:   don't care
 *
 */
int
DevDmaInit(int unit, int ch, devDmaParam_t *param)
{
  int                   result = -1;
  uint32_t              cr = 0;

  stm32Dev_DMA          *p;
  int                   aSize;
  int                   ch7;

  if(unit == -1) {
    memset(&dma, 0, sizeof(dma));
#ifdef DMA1_PTR
    dma.sc[1].dev = DMA1_PTR;
#endif
#ifdef DMA2_PTR
    dma.sc[2].dev = DMA2_PTR;
#endif
    result = 0;
    goto end;
  }

  if(ch >= 8) unit = 2;

  p  = dma.sc[unit].dev;
  ch &= 0x7;

  aSize = param->aSize;
  //if(param->aSize == DEVDMA_SIZE_32BITS) aSize = sizeof(uint32_t);

  /* direction */
  if(param->mem) {
    cr |= DMA_CCR_MEM2MEM_YES;
  } else {
    if(param->dirBA) cr |= DMA_CCR_DIR_READ_PERI;
    else             cr |= DMA_CCR_DIR_READ_MEM;
  }
  /* increment */
  if(param->aInc) cr |= DMA_CCR_MINC_YES;
  if(param->bInc) cr |= DMA_CCR_PINC_YES;
  /* size */
  switch(param->aSize) {
  case DEVDMA_SIZE_8BITS:  cr |= DMA_CCR_MSIZE_8BITS;  break;
  case DEVDMA_SIZE_16BITS: cr |= DMA_CCR_MSIZE_16BITS; break;
  case DEVDMA_SIZE_32BITS: cr |= DMA_CCR_MSIZE_32BITS; break;
  }
  switch(param->bSize) {
  case DEVDMA_SIZE_8BITS:  cr |= DMA_CCR_PSIZE_8BITS;  break;
  case DEVDMA_SIZE_16BITS: cr |= DMA_CCR_PSIZE_16BITS; break;
  case DEVDMA_SIZE_32BITS: cr |= DMA_CCR_PSIZE_32BITS; break;
  }
  /* circular mode */
  if(param->circ) cr |= DMA_CCR_CIRC_YES;
  /* interrupts */
  if(param->intrTC) cr |= DMA_CCR_TCIE_YES;
  if(param->intrHC) cr |= DMA_CCR_HTIE_YES;
  if(param->intrER) cr |= DMA_CCR_TEIE_YES;

  /* disable dma */
  p->CH[ch-1].CCR   = 0;

  /* set to registers */
#ifdef DMA_NO_CSELR
#else
  p->CSELR &= ~DMA_CSELR_DMA_MASK(ch);
  p->CSELR |= DMA_CSELR_DMA_SEL(ch, param->req & 7);
#endif
  p->CH[ch-1].CPAR  = (uint32_t)param->b;
  p->CH[ch-1].CMAR = (uint32_t)param->a;
  p->CH[ch-1].CNDTR = param->cnt;
  p->CH[ch-1].CCR   = cr;

#if 0
  /* clear interrupt status */
  p->IFCR = DMA_ISR_ALL_CLEAR(ch);

  /* enable */
  p->CH[ch-1].CCR |= DMA_CCR_EN_YES;
#endif

end:
  result = 0;

  return result;
}
int
DevDmaInitAddrSize(int unit, int ch, devDmaParam_t *param)
{
  int                   result = -1;
  uint32_t              cr = 0;

  stm32Dev_DMA          *p;
  int                   aSize;
  int                   ch7;

  if(unit == -1) {
    memset(&dma, 0, sizeof(dma));
#ifdef DMA1_PTR
    dma.sc[1].dev = DMA1_PTR;
#endif
#ifdef DMA2_PTR
    dma.sc[2].dev = DMA2_PTR;
#endif
    result = 0;
    goto end;
  }

  if(ch >= 8) unit = 2;

  p  = dma.sc[unit].dev;
  ch &= 0x7;

  /* set to registers */
  p->CH[ch-1].CPAR  = (uint32_t)param->b;
  p->CH[ch-1].CMAR = (uint32_t)param->a;
  p->CH[ch-1].CNDTR = param->cnt;

end:
  result = 0;

  return result;
}


int
DevDmaStart(int unit, int ch)
{
  int                   result = -1;
  stm32Dev_DMA          *p;

  if(ch >= 8) unit = 2;

  p  = dma.sc[unit].dev;
  ch &= 7;

  /* clear interrupt status */
  p->IFCR = DMA_ISR_ALL_CLEAR(ch);

  /* enable */
  p->CH[ch-1].CCR |= DMA_CCR_EN_YES;

end:
  result = 0;

  return result;
}


int
DevDmaStop(int unit, int ch)
{
  int                   result = -1;
  stm32Dev_DMA          *p;

  if(ch >= 8) unit = 2;

  p  = dma.sc[unit].dev;
  ch &= 7;

  /* disable */
  p->CH[ch-1].CCR &= ~DMA_CCR_EN_MASK;

end:
  result = 0;

  return result;
}


void
DevDmaClearIntr(int unit, int ch)
{
  stm32Dev_DMA  *p;

  if(ch >= 8) unit = 2;
  ch &= 7;

#ifdef DMA2_PTR
  if(unit == 1) {
    DMA1_PTR->IFCR = DMA_ISR_CGIF_CLEAR(ch);
  } else {
    DMA2_PTR->IFCR = DMA_ISR_CGIF_CLEAR(ch);
  }
#else
  DMA1_PTR->IFCR = DMA_ISR_CGIF_CLEAR(ch);
#endif

  return;
}


int
DevDmaIsFinished(int unit, int ch)
{
  int           result = DEV_ERRNO_UNKNOWN;
  stm32Dev_DMA  *p;

  if(ch >= 8) unit = 2;

  p  = dma.sc[unit].dev;
  ch &= 7;

  if(!p->CH[ch-1].CNDTR) {
    result = DEV_ERRNO_SUCCESS; /* finished, if NDT is 0 */
  }

end:
  return result;
}


int
DevDmaGetTransferedCount(int unit, int ch)
{
  int           result = 0;
  uint32_t      val;

  result = DevDmaGetCounterValue(unit, ch, &val);
  if(result == DEV_ERRNO_SUCCESS) {
    result = val;
  }

  return result;
}


int
DevDmaGetCounterValue(int unit, int ch, uint32_t *pSize)
{
  int           result = DEV_ERRNO_UNKNOWN;
  stm32Dev_DMA  *p;

  if(!pSize) goto fail;
  if(ch >= 8) unit = 2;

  p  = dma.sc[unit].dev;
  ch &= 7;

  *pSize = p->CH[ch-1].CNDTR;

  result = DEV_ERRNO_SUCCESS;

fail:
  return result;
}


void
DevDmaDebugShowRegs(int unit, int ch)
{
  stm32Dev_DMA          *p;

  if(ch >= 8) unit = 2;

  p  = dma.sc[unit].dev;
  ch &= 7;

  printf("dma%d.ch%x cr: %x, cselr %x \r\n", unit, ch, p->CH[ch-1].CCR,
#ifdef DMA_NO_CSELR
         0
#else
         p->CSELR
#endif
         );
  printf("par: %x, mar: %x, cnt %x\r\n", p->CH[ch-1].CPAR, p->CH[ch-1].CMAR, p->CH[ch-1].CNDTR);

  return;
}
