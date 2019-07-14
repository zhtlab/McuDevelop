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

#ifndef _STM32F7RCC_H_
#define _STM32F7RCC_H_

/* STM32F730 reference manual  DocID RM0431 Rev 3 */

#define RCC_CLOCK_HPRETABLE     {0, 0, 0, 0,  0, 0, 0, 0,  1, 2, 3, 4,  6, 7, 8, 9}
#define RCC_CLOCK_PPRETABLE     {0, 0, 0, 0,  1, 2, 3, 4}
typedef struct {
  __IO uint32_t         CR;             /* 0x00 */
#define RCC_CR_PLLSAIRDY_SHIFT          29
#define RCC_CR_PLLSAIRDY_MASK           (1 << (RCC_CR_PLLSAIRDY_SHIFT))
#define RCC_CR_PLLSAIRDY_NO             (0 << (RCC_CR_PLLSAIRDY_SHIFT))
#define RCC_CR_PLLSAIRDY_YES		(1 << (RCC_CR_PLLSAIRDY_SHIFT))
#define RCC_CR_PLLSAION_SHIFT           28
#define RCC_CR_PLLSAION_MASK            (1 << (RCC_CR_PLLSAION_SHIFT))
#define RCC_CR_PLLSAION_NO              (0 << (RCC_CR_PLLSAION_SHIFT))
#define RCC_CR_PLLSAION_YES		(1 << (RCC_CR_PLLSAION_SHIFT))
#define RCC_CR_PLLI2SRDY_SHIFT          27
#define RCC_CR_PLLI2SRDY_MASK           (1 << (RCC_CR_PLLI2SRDY_SHIFT))
#define RCC_CR_PLLI2SRDY_NO             (0 << (RCC_CR_PLLI2SRDY_SHIFT))
#define RCC_CR_PLLI2SRDY_YES		(1 << (RCC_CR_PLLI2SRDY_SHIFT))
#define RCC_CR_PLLI2SON_SHIFT		26
#define RCC_CR_PLLI2SON_MASK		(1 << (RCC_CR_PLLI2SON_SHIFT))
#define RCC_CR_PLLI2SON_NO		(0 << (RCC_CR_PLLI2SON_SHIFT))
#define RCC_CR_PLLI2SON_YES		(1 << (RCC_CR_PLLI2SON_SHIFT))
#define RCC_CR_PLLRDY_SHIFT		25
#define RCC_CR_PLLRDY_MASK		(1 << (RCC_CR_PLLRDY_SHIFT))
#define RCC_CR_PLLRDY_NO		(0 << (RCC_CR_PLLRDY_SHIFT))
#define RCC_CR_PLLRDY_YES		(1 << (RCC_CR_PLLRDY_SHIFT))
#define RCC_CR_PLLON_SHIFT		24
#define RCC_CR_PLLON_MASK		(1 << (RCC_CR_PLLON_SHIFT))
#define RCC_CR_PLLON_NO                 (0 << (RCC_CR_PLLON_SHIFT))
#define RCC_CR_PLLON_YES		(1 << (RCC_CR_PLLON_SHIFT))
#define RCC_CR_CSSON_SHIFT		19
#define RCC_CR_CSSON_MASK		(1 << (RCC_CR_CSSON_SHIFT))
#define RCC_CR_CSSON_NO                 (0 << (RCC_CR_CSSON_SHIFT))
#define RCC_CR_CSSON_YES		(1 << (RCC_CR_CSSON_SHIFT))
#define RCC_CR_HSEBYP_SHIFT		18
#define RCC_CR_HSEBYP_MASK		(1 << (RCC_CR_HSEBYP_SHIFT))
#define RCC_CR_HSEBYP_NO		(0 << (RCC_CR_HSEBYP_SHIFT))
#define RCC_CR_HSEBYP_YES		(1 << (RCC_CR_HSEBYP_SHIFT))
#define RCC_CR_HSERDY_SHIFT		17
#define RCC_CR_HSERDY_MASK		(1 << (RCC_CR_HSERDY_SHIFT))
#define RCC_CR_HSERDY_NO		(0 << (RCC_CR_HSERDY_SHIFT))
#define RCC_CR_HSERDY_YES		(1 << (RCC_CR_HSERDY_SHIFT))
#define RCC_CR_HSEON_SHIFT		16
#define RCC_CR_HSEON_MASK		(1 << (RCC_CR_HSEON_SHIFT))
#define RCC_CR_HSEON_NO                 (0 << (RCC_CR_HSEON_SHIFT))
#define RCC_CR_HSEON_YES		(1 << (RCC_CR_HSEON_SHIFT))
#define RCC_CR_HSIRDY_SHIFT		1
#define RCC_CR_HSIRDY_MASK		(1 << (RCC_CR_HSIRDY_SHIFT))
#define RCC_CR_HSIRDY_NO                (0 << (RCC_CR_HSIRDY_SHIFT))
#define RCC_CR_HSIRDY_YES		(1 << (RCC_CR_HSIRDY_SHIFT))
#define RCC_CR_HSION_SHIFT		0
#define RCC_CR_HSION_MASK               (1 << (RCC_CR_HSION_SHIFT))
#define RCC_CR_HSION_NO                 (0 << (RCC_CR_HSION_SHIFT))
#define RCC_CR_HSION_YES                (1 << (RCC_CR_HSION_SHIFT))

  __IO uint32_t         PLLCFGR;        /* 0x04 */
#define RCC_PLLCFGR_PLLQ_SHIFT          24
#define RCC_PLLCFGR_PLLQ_MASK           (15 << (RCC_PLLCFGR_PLLQ_SHIFT))
#define RCC_PLLCFGR_PLLQ_DIV2           ( 2 << (RCC_PLLCFGR_PLLQ_SHIFT))
#define RCC_PLLCFGR_PLLQ_DIV3           ( 3 << (RCC_PLLCFGR_PLLQ_SHIFT))
#define RCC_PLLCFGR_PLLQ_DIV(x)         (((x) << (RCC_PLLCFGR_PLLQ_SHIFT)) & RCC_PLLCFGR_PLLQ_MASK)

#define RCC_PLLCFGR_PLLSRC_SHIFT	22
#define RCC_PLLCFGR_PLLSRC_MASK		(1 << (RCC_PLLCFGR_PLLSRC_SHIFT))
#define RCC_PLLCFGR_PLLSRC_HSI16        (0 << (RCC_PLLCFGR_PLLSRC_SHIFT))
#define RCC_PLLCFGR_PLLSRC_HSE          (1 << (RCC_PLLCFGR_PLLSRC_SHIFT))
#define RCC_PLLCFGR_PLLP_SHIFT		16
#define RCC_PLLCFGR_PLLP_MASK		(3 << (RCC_PLLCFGR_PLLP_SHIFT))
#define RCC_PLLCFGR_PLLP_DIV2		(0 << (RCC_PLLCFGR_PLLP_SHIFT))
#define RCC_PLLCFGR_PLLP_DIV4		(1 << (RCC_PLLCFGR_PLLP_SHIFT))
#define RCC_PLLCFGR_PLLP_DIV6		(2 << (RCC_PLLCFGR_PLLP_SHIFT))
#define RCC_PLLCFGR_PLLP_DIV8		(3 << (RCC_PLLCFGR_PLLP_SHIFT))

#define RCC_PLLCFGR_PLLN_SHIFT		6
#define RCC_PLLCFGR_PLLN_MASK		(0x1ff << (RCC_PLLCFGR_PLLN_SHIFT))
#define RCC_PLLCFGR_PLLN_MULX(x)	(((x) & 0x1ff) << (RCC_PLLCFGR_PLLN_SHIFT))
#define RCC_PLLCFGR_PLLN_MUL0_XXX	(0 << (RCC_PLLCFGR_PLLN_SHIFT))
#define RCC_PLLCFGR_PLLN_MUL1_XXX	(2 << (RCC_PLLCFGR_PLLN_SHIFT))
#define RCC_PLLCFGR_PLLN_MUL49_XXX	(49 << (RCC_PLLCFGR_PLLN_SHIFT))
#define RCC_PLLCFGR_PLLN_MUL50		(50 << (RCC_PLLCFGR_PLLN_SHIFT))
#define RCC_PLLCFGR_PLLN_MUL51		(51 << (RCC_PLLCFGR_PLLN_SHIFT))
#define RCC_PLLCFGR_PLLN_MUL432		(432 << (RCC_PLLCFGR_PLLN_SHIFT))
#define RCC_PLLCFGR_PLLN_MUL433_XXX     (433 << (RCC_PLLCFGR_PLLN_SHIFT))
#define RCC_PLLCFGR_PLLN_MUL511_XXX     (511 << (RCC_PLLCFGR_PLLN_SHIFT))
#define RCC_PLLCFGR_PLLM_SHIFT		0
#define RCC_PLLCFGR_PLLM_MASK		(0x3f << (RCC_PLLCFGR_PLLM_SHIFT))
#define RCC_PLLCFGR_PLLM_DIV2		(2 << (RCC_PLLCFGR_PLLM_SHIFT))
#define RCC_PLLCFGR_PLLM_DIV3		(3 << (RCC_PLLCFGR_PLLM_SHIFT))
#define RCC_PLLCFGR_PLLM_DIV63		(63 << (RCC_PLLCFGR_PLLM_SHIFT))
#define RCC_PLLCFGR_PLLM_DIV(x)		(((x) << (RCC_PLLCFGR_PLLM_SHIFT)) & RCC_PLLCFGR_PLLM_MASK)

  __IO uint32_t         CFGR;           /* 0x08 */
#define RCC_CFGR_MCO2SEL_SHIFT		30
#define RCC_CFGR_MCO2SEL_MASK		(3 << (RCC_CFGR_MCO2SEL_SHIFT))
#define RCC_CFGR_MCO2SEL_SYSCLK		(0 << (RCC_CFGR_MCO2SEL_SHIFT))
#define RCC_CFGR_MCO2SEL_PLLI2S		(1 << (RCC_CFGR_MCO2SEL_SHIFT))
#define RCC_CFGR_MCO2SEL_HSE		(2 << (RCC_CFGR_MCO2SEL_SHIFT))
#define RCC_CFGR_MCO2SEL_PLL		(3 << (RCC_CFGR_MCO2SEL_SHIFT))
#define RCC_CFGR_MCO2PRE_SHIFT          27
#define RCC_CFGR_MCO2PRE_MASK           (7 << (RCC_CFGR_MCO2PRE_SHIFT))
#define RCC_CFGR_MCO2PRE_DIV1           (0 << (RCC_CFGR_MCO2PRE_SHIFT))
#define RCC_CFGR_MCO2PRE_DIV2           (4 << (RCC_CFGR_MCO2PRE_SHIFT))
#define RCC_CFGR_MCO2PRE_DIV3           (5 << (RCC_CFGR_MCO2PRE_SHIFT))
#define RCC_CFGR_MCO2PRE_DIV4		(6 << (RCC_CFGR_MCO2PRE_SHIFT))
#define RCC_CFGR_MCO2PRE_DIV5		(7 << (RCC_CFGR_MCO2PRE_SHIFT))
#define RCC_CFGR_MCO1PRE_SHIFT          24
#define RCC_CFGR_MCO1PRE_MASK           (7 << (RCC_CFGR_MCO1PRE_SHIFT))
#define RCC_CFGR_MCO1PRE_DIV1           (0 << (RCC_CFGR_MCO1PRE_SHIFT))
#define RCC_CFGR_MCO1PRE_DIV2           (4 << (RCC_CFGR_MCO1PRE_SHIFT))
#define RCC_CFGR_MCO1PRE_DIV3           (5 << (RCC_CFGR_MCO1PRE_SHIFT))
#define RCC_CFGR_MCO1PRE_DIV4		(6 << (RCC_CFGR_MCO1PRE_SHIFT))
#define RCC_CFGR_MCO1PRE_DIV5		(7 << (RCC_CFGR_MCO1PRE_SHIFT))
#define RCC_CFGR_MCO1SEL_SHIFT		21
#define RCC_CFGR_MCO1SEL_MASK		(3 << (RCC_CFGR_MCO1SEL_SHIFT))
#define RCC_CFGR_MCO1SEL_HSI		(0 << (RCC_CFGR_MCO1SEL_SHIFT))
#define RCC_CFGR_MCO1SEL_LSE		(1 << (RCC_CFGR_MCO1SEL_SHIFT))
#define RCC_CFGR_MCO1SEL_HSE		(2 << (RCC_CFGR_MCO1SEL_SHIFT))
#define RCC_CFGR_MCO1SEL_PLL		(3 << (RCC_CFGR_MCO1SEL_SHIFT))

#define RCC_CFGR_PPRE2_SHIFT		13		/* APB2 */
#define RCC_CFGR_PPRE2_MASK		(7 << (RCC_CFGR_PPRE2_SHIFT))
#define RCC_CFGR_PPRE2_DIV1		(0 << (RCC_CFGR_PPRE2_SHIFT))
#define RCC_CFGR_PPRE2_DIV2		(4 << (RCC_CFGR_PPRE2_SHIFT))
#define RCC_CFGR_PPRE2_DIV4		(5 << (RCC_CFGR_PPRE2_SHIFT))
#define RCC_CFGR_PPRE2_DIV8		(6 << (RCC_CFGR_PPRE2_SHIFT))
#define RCC_CFGR_PPRE2_DIV16		(7 << (RCC_CFGR_PPRE2_SHIFT))
#define RCC_CFGR_PPRE1_SHIFT		10		/* APB1 */
#define RCC_CFGR_PPRE1_MASK		(7 << (RCC_CFGR_PPRE1_SHIFT))
#define RCC_CFGR_PPRE1_DIV1		(0 << (RCC_CFGR_PPRE1_SHIFT))
#define RCC_CFGR_PPRE1_DIV2		(4 << (RCC_CFGR_PPRE1_SHIFT))
#define RCC_CFGR_PPRE1_DIV4		(5 << (RCC_CFGR_PPRE1_SHIFT))
#define RCC_CFGR_PPRE1_DIV8		(6 << (RCC_CFGR_PPRE1_SHIFT))
#define RCC_CFGR_PPRE1_DIV16		(7 << (RCC_CFGR_PPRE1_SHIFT))
#define RCC_CFGR_HPRE_SHIFT             4               /* AHB */
#define RCC_CFGR_HPRE_MASK		(0xf << (RCC_CFGR_HPRE_SHIFT))
#define RCC_CFGR_HPRE_DIV1		(0 << (RCC_CFGR_HPRE_SHIFT))
#define RCC_CFGR_HPRE_DIV2		(8 << (RCC_CFGR_HPRE_SHIFT))
#define RCC_CFGR_HPRE_DIV4		(9 << (RCC_CFGR_HPRE_SHIFT))
#define RCC_CFGR_HPRE_DIV8		(10 << (RCC_CFGR_HPRE_SHIFT))
#define RCC_CFGR_HPRE_DIV16             (11 << (RCC_CFGR_HPRE_SHIFT))
#define RCC_CFGR_HPRE_DIV64             (12 << (RCC_CFGR_HPRE_SHIFT))
#define RCC_CFGR_HPRE_DIV128            (13 << (RCC_CFGR_HPRE_SHIFT))
#define RCC_CFGR_HPRE_DIV256            (14 << (RCC_CFGR_HPRE_SHIFT))
#define RCC_CFGR_HPRE_DIV512            (15 << (RCC_CFGR_HPRE_SHIFT))
#define RCC_CFGR_SWS_SHIFT              2
#define RCC_CFGR_SWS_MASK               (3 << (RCC_CFGR_SWS_SHIFT))
#define RCC_CFGR_SWS_HSI                (0 << (RCC_CFGR_SWS_SHIFT))
#define RCC_CFGR_SWS_HSE                (1 << (RCC_CFGR_SWS_SHIFT))
#define RCC_CFGR_SWS_PLL                (2 << (RCC_CFGR_SWS_SHIFT))
#define RCC_CFGR_SWS_NA                 (3 << (RCC_CFGR_SWS_SHIFT))
#define RCC_CFGR_SW_SHIFT               0
#define RCC_CFGR_SW_MASK                (3 << (RCC_CFGR_SW_SHIFT))
#define RCC_CFGR_SW_HSI                 (0 << (RCC_CFGR_SW_SHIFT))
#define RCC_CFGR_SW_HSE                 (1 << (RCC_CFGR_SW_SHIFT))
#define RCC_CFGR_SW_PLL                 (2 << (RCC_CFGR_SW_SHIFT))
#define RCC_CFGR_SW_NA                  (3 << (RCC_CFGR_SW_SHIFT))

  __IO uint32_t         CIR;           /* 0x0c */
#define RCC_CICR_CSSC_SHIFT		23
#define RCC_CICR_CSSC_MASK		(1 << (RCC_CICR_LSE_CSSC_SHIFT))
#define RCC_CICR_CSSC_NO		(0 << (RCC_CICR_LSE_CSSC_SHIFT))
#define RCC_CICR_CSSC_YES		(1 << (RCC_CICR_LSE_CSSC_SHIFT))
#define RCC_CICR_PLLI2S_RDYC_SHIFT	21
#define RCC_CICR_PLLI2S_RDYC_MASK	(1 << (RCC_CICR_PLLI2S_RDYC_SHIFT))
#define RCC_CICR_PLLI2S_RDYC_NO         (0 << (RCC_CICR_PLLI2S_RDYC_SHIFT))
#define RCC_CICR_PLLI2S_RDYC_YES	(1 << (RCC_CICR_PLLI2S_RDYC_SHIFT))
#define RCC_CICR_PLL_RDYC_SHIFT		20
#define RCC_CICR_PLL_RDYC_MASK		(1 << (RCC_CICR_PLL_RDYC_SHIFT))
#define RCC_CICR_PLL_RDYC_NO		(0 << (RCC_CICR_PLL_RDYC_SHIFT))
#define RCC_CICR_PLL_RDYC_YES		(1 << (RCC_CICR_PLL_RDYC_SHIFT))
#define RCC_CICR_HSE_RDYC_SHIFT		19
#define RCC_CICR_HSE_RDYC_MASK		(1 << (RCC_CICR_HSE_RDYC_SHIFT))
#define RCC_CICR_HSE_RDYC_NO		(0 << (RCC_CICR_HSE_RDYC_SHIFT))
#define RCC_CICR_HSE_RDYC_YES		(1 << (RCC_CICR_HSE_RDYC_SHIFT))
#define RCC_CICR_HSI_RDYC_SHIFT		18
#define RCC_CICR_HSI_RDYC_MASK		(1 << (RCC_CICR_HSI_RDYC_SHIFT))
#define RCC_CICR_HSI_RDYC_NO		(0 << (RCC_CICR_HSI_RDYC_SHIFT))
#define RCC_CICR_HSI_RDYC_YES		(1 << (RCC_CICR_HSI_RDYC_SHIFT))
#define RCC_CICR_LSE_RDYC_SHIFT		17
#define RCC_CICR_LSE_RDYC_MASK		(1 << (RCC_CICR_LSE_RDYC_SHIFT))
#define RCC_CICR_LSE_RDYC_NO		(0 << (RCC_CICR_LSE_RDYC_SHIFT))
#define RCC_CICR_LSE_RDYC_YES		(1 << (RCC_CICR_LSE_RDYC_SHIFT))
#define RCC_CICR_LSI_RDYC_SHIFT		16
#define RCC_CICR_LSI_RDYC_MASK		(1 << (RCC_CICR_LSI_RDYC_SHIFT))
#define RCC_CICR_LSI_RDYC_NO		(0 << (RCC_CICR_LSI_RDYC_SHIFT))
#define RCC_CICR_LSI_RDYC_YES		(1 << (RCC_CICR_LSI_RDYC_SHIFT))
#define RCC_CIER_PLLI2S_RDYIE_SHIFT	13
#define RCC_CIER_PLLI2S_RDYIE_MASK	(1 << (RCC_CIER_PLLI2S_RDYIE_SHIFT))
#define RCC_CIER_PLLI2S_RDYIE_NO	(0 << (RCC_CIER_PLLI2S_RDYIE_SHIFT))
#define RCC_CIER_PLLI2S_RDYIE_YES	(1 << (RCC_CIER_PLLI2S_RDYIE_SHIFT))
#define RCC_CIER_PLL_RDYIE_SHIFT	12
#define RCC_CIER_PLL_RDYIE_MASK		(1 << (RCC_CIER_PLL_RDYIE_SHIFT))
#define RCC_CIER_PLL_RDYIE_NO		(0 << (RCC_CIER_PLL_RDYIE_SHIFT))
#define RCC_CIER_PLL_RDYIE_YES		(1 << (RCC_CIER_PLL_RDYIE_SHIFT))
#define RCC_CIER_HSE_RDYIE_SHIFT	11
#define RCC_CIER_HSE_RDYIE_MASK		(1 << (RCC_CIER_HSE_RDYIE_SHIFT))
#define RCC_CIER_HSE_RDYIE_NO		(0 << (RCC_CIER_HSE_RDYIE_SHIFT))
#define RCC_CIER_HSE_RDYIE_YES		(1 << (RCC_CIER_HSE_RDYIE_SHIFT))
#define RCC_CIER_HSI_RDYIE_SHIFT	10
#define RCC_CIER_HSI_RDYIE_MASK		(1 << (RCC_CIER_HSI_RDYIE_SHIFT))
#define RCC_CIER_HSI_RDYIE_NO		(0 << (RCC_CIER_HSI_RDYIE_SHIFT))
#define RCC_CIER_HSI_RDYIE_YES		(1 << (RCC_CIER_HSI_RDYIE_SHIFT))
#define RCC_CIER_LSE_RDYIE_SHIFT	9
#define RCC_CIER_LSE_RDYIE_MASK		(1 << (RCC_CIER_LSE_RDYIE_SHIFT))
#define RCC_CIER_LSE_RDYIE_NO		(0 << (RCC_CIER_LSE_RDYIE_SHIFT))
#define RCC_CIER_LSE_RDYIE_YES		(1 << (RCC_CIER_LSE_RDYIE_SHIFT))
#define RCC_CIER_LSI_RDYIE_SHIFT	8
#define RCC_CIER_LSI_RDYIE_MASK		(1 << (RCC_CIER_LSI_RDYIE_SHIFT))
#define RCC_CIER_LSI_RDYIE_NO		(0 << (RCC_CIER_LSI_RDYIE_SHIFT))
#define RCC_CIER_LSI_RDYIE_YES		(1 << (RCC_CIER_LSI_RDYIE_SHIFT))
#define RCC_CIFR_CSSF_SHIFT		7
#define RCC_CIFR_CSSF_MASK		(1 << (RCC_CIFR_LSE_CSSF_SHIFT))
#define RCC_CIFR_CSSF_NO		(0 << (RCC_CIFR_LSE_CSSF_SHIFT))
#define RCC_CIFR_CSSF_YES		(1 << (RCC_CIFR_LSE_CSSF_SHIFT))
#define RCC_CIFR_PLLI2S_RDYF_SHIFT	6
#define RCC_CIFR_PLLI2S_RDYF_MASK	(1 << (RCC_CIFR_PLLI2S_RDYF_SHIFT))
#define RCC_CIFR_PLLI2S_RDYF_NO         (0 << (RCC_CIFR_PLLI2S_RDYF_SHIFT))
#define RCC_CIFR_PLLI2S_RDYF_YES	(1 << (RCC_CIFR_PLLI2S_RDYF_SHIFT))
#define RCC_CIFR_PLL_RDYF_SHIFT		5
#define RCC_CIFR_PLL_RDYF_MASK		(1 << (RCC_CIFR_PLL_RDYF_SHIFT))
#define RCC_CIFR_PLL_RDYF_NO		(0 << (RCC_CIFR_PLL_RDYF_SHIFT))
#define RCC_CIFR_PLL_RDYF_YES		(1 << (RCC_CIFR_PLL_RDYF_SHIFT))
#define RCC_CIFR_HSE_RDYF_SHIFT		4
#define RCC_CIFR_HSE_RDYF_MASK		(1 << (RCC_CIFR_HSE_RDYF_SHIFT))
#define RCC_CIFR_HSE_RDYF_NO		(0 << (RCC_CIFR_HSE_RDYF_SHIFT))
#define RCC_CIFR_HSE_RDYF_YES		(1 << (RCC_CIFR_HSE_RDYF_SHIFT))
#define RCC_CIFR_HSI_RDYF_SHIFT		3
#define RCC_CIFR_HSI_RDYF_MASK		(1 << (RCC_CIFR_HSI_RDYF_SHIFT))
#define RCC_CIFR_HSI_RDYF_NO		(0 << (RCC_CIFR_HSI_RDYF_SHIFT))
#define RCC_CIFR_HSI_RDYF_YES		(1 << (RCC_CIFR_HSI_RDYF_SHIFT))
#define RCC_CIFR_LSE_RDYF_SHIFT		1
#define RCC_CIFR_LSE_RDYF_MASK		(1 << (RCC_CIFR_LSE_RDYF_SHIFT))
#define RCC_CIFR_LSE_RDYF_NO		(0 << (RCC_CIFR_LSE_RDYF_SHIFT))
#define RCC_CIFR_LSE_RDYF_YES		(1 << (RCC_CIFR_LSE_RDYF_SHIFT))
#define RCC_CIFR_LSI_RDYF_SHIFT		0
#define RCC_CIFR_LSI_RDYF_MASK		(1 << (RCC_CIFR_LSI_RDYF_SHIFT))
#define RCC_CIFR_LSI_RDYF_NO		(0 << (RCC_CIFR_LSI_RDYF_SHIFT))
#define RCC_CIFR_LSI_RDYF_YES		(1 << (RCC_CIFR_LSI_RDYF_SHIFT))

  __IO uint32_t         AHB1RSTR;       /* 0x10 */
  __IO uint32_t         AHB2RSTR;       /* 0x14 */
  __IO uint32_t         AHB3RSTR;       /* 0x18 */
  __IO uint32_t         reserved0x1c;   /* 0x1c */

  __IO uint32_t         APB1RSTR;       /* 0x20 */
  __IO uint32_t         APB2RSTR;       /* 0x24 */
  __IO uint32_t         reserved0x24;   /* 0x28 */
  __IO uint32_t         reserved0x2c;   /* 0x2c */

  __IO uint32_t         AHB1ENR;        /* 0x30 */
#define RCC_AHB1ENR_DMA2EN_SHIFT	22
#define RCC_AHB1ENR_DMA2EN_MASK		(1 << (RCC_AHB1ENR_DMA2EN_SHIFT))
#define RCC_AHB1ENR_DMA2EN_NO		(0 << (RCC_AHB1ENR_DMA2EN_SHIFT))
#define RCC_AHB1ENR_DMA2EN_YES		(1 << (RCC_AHB1ENR_DMA2EN_SHIFT))
#define RCC_AHB1ENR_DMA1EN_SHIFT	21
#define RCC_AHB1ENR_DMA1EN_MASK		(1 << (RCC_AHB1ENR_DMA1EN_SHIFT))
#define RCC_AHB1ENR_DMA1EN_NO		(0 << (RCC_AHB1ENR_DMA1EN_SHIFT))
#define RCC_AHB1ENR_DMA1EN_YES		(1 << (RCC_AHB1ENR_DMA1EN_SHIFT))
#define RCC_AHB1ENR_DTCMRAMEN_SHIFT	20
#define RCC_AHB1ENR_DTCMRAMEN_MASK	(1 << (RCC_AHB1ENR_DTCMRAMEN_SHIFT))
#define RCC_AHB1ENR_DTCMRAMEN_NO	(0 << (RCC_AHB1ENR_DTCMRAMEN_SHIFT))
#define RCC_AHB1ENR_DTCMRAMEN_YES	(1 << (RCC_AHB1ENR_DTCMRAMEN_SHIFT))
#define RCC_AHB1ENR_CRCEN_SHIFT		12
#define RCC_AHB1ENR_CRCEN_MASK		(1 << (RCC_AHB1ENR_CRCEN_SHIFT))
#define RCC_AHB1ENR_CRCEN_NO		(0 << (RCC_AHB1ENR_CRCEN_SHIFT))
#define RCC_AHB1ENR_CRCEN_YES		(1 << (RCC_AHB1ENR_CRCEN_SHIFT))
#define RCC_AHB1ENR_FLASHEN_SHIFT	8
#define RCC_AHB1ENR_FLASHEN_MASK	(1 << (RCC_AHB1ENR_FLASHEN_SHIFT))
#define RCC_AHB1ENR_FLASHEN_NO		(0 << (RCC_AHB1ENR_FLASHEN_SHIFT))
#define RCC_AHB1ENR_FLASHEN_YES		(1 << (RCC_AHB1ENR_FLASHEN_SHIFT))
#define RCC_AHB1ENR_GPIOAEN_SHIFT       0
#define RCC_AHB1ENR_GPIOAEN_MASK        (1 << (RCC_AHB1ENR_GPIOAEN_SHIFT))
#define RCC_AHB1ENR_GPIOAEN_NO          (0 << (RCC_AHB1ENR_GPIOAEN_SHIFT))
#define RCC_AHB1ENR_GPIOAEN_YES         (1 << (RCC_AHB1ENR_GPIOAEN_SHIFT))
#define RCC_AHB1ENR_GPIOBEN_SHIFT       1
#define RCC_AHB1ENR_GPIOBEN_MASK        (1 << (RCC_AHB1ENR_GPIOBEN_SHIFT))
#define RCC_AHB1ENR_GPIOBEN_NO          (0 << (RCC_AHB1ENR_GPIOBEN_SHIFT))
#define RCC_AHB1ENR_GPIOBEN_YES         (1 << (RCC_AHB1ENR_GPIOBEN_SHIFT))
#define RCC_AHB1ENR_GPIOCEN_SHIFT       2
#define RCC_AHB1ENR_GPIOCEN_MASK        (1 << (RCC_AHB1ENR_GPIOCEN_SHIFT))
#define RCC_AHB1ENR_GPIOCEN_NO          (0 << (RCC_AHB1ENR_GPIOCEN_SHIFT))
#define RCC_AHB1ENR_GPIOCEN_YES         (1 << (RCC_AHB1ENR_GPIOCEN_SHIFT))
#define RCC_AHB1ENR_GPIODEN_SHIFT       3
#define RCC_AHB1ENR_GPIODEN_MASK        (1 << (RCC_AHB1ENR_GPIODEN_SHIFT))
#define RCC_AHB1ENR_GPIODEN_NO          (0 << (RCC_AHB1ENR_GPIODEN_SHIFT))
#define RCC_AHB1ENR_GPIODEN_YES         (1 << (RCC_AHB1ENR_GPIODEN_SHIFT))
#define RCC_AHB1ENR_GPIOEEN_SHIFT       4
#define RCC_AHB1ENR_GPIOEEN_MASK        (1 << (RCC_AHB1ENR_GPIOEEN_SHIFT))
#define RCC_AHB1ENR_GPIOEEN_NO          (0 << (RCC_AHB1ENR_GPIOEEN_SHIFT))
#define RCC_AHB1ENR_GPIOEEN_YES         (1 << (RCC_AHB1ENR_GPIOEEN_SHIFT))
#define RCC_AHB1ENR_GPIOFEN_SHIFT       5
#define RCC_AHB1ENR_GPIOFEN_MASK        (1 << (RCC_AHB1ENR_GPIOFEN_SHIFT))
#define RCC_AHB1ENR_GPIOFEN_NO          (0 << (RCC_AHB1ENR_GPIOFEN_SHIFT))
#define RCC_AHB1ENR_GPIOFEN_YES         (1 << (RCC_AHB1ENR_GPIOFEN_SHIFT))
#define RCC_AHB1ENR_GPIOGEN_SHIFT       6
#define RCC_AHB1ENR_GPIOGEN_MASK        (1 << (RCC_AHB1ENR_GPIOGEN_SHIFT))
#define RCC_AHB1ENR_GPIOGEN_NO          (0 << (RCC_AHB1ENR_GPIOGEN_SHIFT))
#define RCC_AHB1ENR_GPIOGEN_YES         (1 << (RCC_AHB1ENR_GPIOGEN_SHIFT))
#define RCC_AHB1ENR_GPIOHEN_SHIFT       7
#define RCC_AHB1ENR_GPIOHEN_MASK        (1 << (RCC_AHB1ENR_GPIOHEN_SHIFT))
#define RCC_AHB1ENR_GPIOHEN_NO          (0 << (RCC_AHB1ENR_GPIOHEN_SHIFT))
#define RCC_AHB1ENR_GPIOHEN_YES         (1 << (RCC_AHB1ENR_GPIOHEN_SHIFT))
#define RCC_AHB1ENR_GPIOIEN_SHIFT       8
#define RCC_AHB1ENR_GPIOIEN_MASK        (1 << (RCC_AHB1ENR_GPIOIEN_SHIFT))
#define RCC_AHB1ENR_GPIOIEN_NO          (0 << (RCC_AHB1ENR_GPIOIEN_SHIFT))
#define RCC_AHB1ENR_GPIOIEN_YES         (1 << (RCC_AHB1ENR_GPIOIEN_SHIFT))

#define RCC_GPIOAEN_YES                 (RCC_AHB1ENR_GPIOAEN_YES)
#define RCC_GPIOBEN_YES                 (RCC_AHB1ENR_GPIOBEN_YES)
#define RCC_GPIOCEN_YES                 (RCC_AHB1ENR_GPIOCEN_YES)
#define RCC_GPIODEN_YES                 (RCC_AHB1ENR_GPIODEN_YES)
#define RCC_GPIOEEN_YES                 (RCC_AHB1ENR_GPIOEEN_YES)
#define RCC_GPIOFEN_YES                 (RCC_AHB1ENR_GPIOFEN_YES)
#define RCC_GPIOGEN_YES                 (RCC_AHB1ENR_GPIOGEN_YES)
#define RCC_GPIOHEN_YES                 (RCC_AHB1ENR_GPIOHEN_YES)
#define RCC_GPIOIEN_YES                 (RCC_AHB1ENR_GPIOIEN_YES)

  __IO uint32_t         AHB2ENR;        /* 0x34 */
#define RCC_AHB2ENR_OTGEN_SHIFT         22
#define RCC_AHB2ENR_OTGEN_MASK		(1 << (RCC_AHB2ENR_OTGEN_SHIFT))
#define RCC_AHB2ENR_OTGEN_NO		(0 << (RCC_AHB2ENR_OTGEN_SHIFT))
#define RCC_AHB2ENR_OTGEN_YES		(1 << (RCC_AHB2ENR_OTGEN_SHIFT))

  __IO uint32_t         AHB3ENR;        /* 0x38 */
  __IO uint32_t         reserved0x3c;   /* 0x3c */

  __IO uint32_t         APB1ENR;        /* 0x40 */
#define RCC_APB1ENR_PWREN_SHIFT	28
#define RCC_APB1ENR_PWREN_MASK		(1 << (RCC_APB1ENR_PWREN_SHIFT))
#define RCC_APB1ENR_PWREN_NO		(0 << (RCC_APB1ENR_PWREN_SHIFT))
#define RCC_APB1ENR_PWREN_YES		(1 << (RCC_APB1ENR_PWREN_SHIFT))
#define RCC_APB1ENR_I2C3EN_SHIFT	23
#define RCC_APB1ENR_I2C3EN_MASK	(1 << (RCC_APB1ENR_I2C3EN_SHIFT))
#define RCC_APB1ENR_I2C3EN_NO		(0 << (RCC_APB1ENR_I2C3EN_SHIFT))
#define RCC_APB1ENR_I2C3EN_YES		(1 << (RCC_APB1ENR_I2C3EN_SHIFT))
#define RCC_APB1ENR_I2C2EN_SHIFT	22
#define RCC_APB1ENR_I2C2EN_MASK	(1 << (RCC_APB1ENR_I2C2EN_SHIFT))
#define RCC_APB1ENR_I2C2EN_NO		(0 << (RCC_APB1ENR_I2C2EN_SHIFT))
#define RCC_APB1ENR_I2C2EN_YES		(1 << (RCC_APB1ENR_I2C2EN_SHIFT))
#define RCC_APB1ENR_I2C1EN_SHIFT	21
#define RCC_APB1ENR_I2C1EN_MASK	(1 << (RCC_APB1ENR_I2C1EN_SHIFT))
#define RCC_APB1ENR_I2C1EN_NO		(0 << (RCC_APB1ENR_I2C1EN_SHIFT))
#define RCC_APB1ENR_I2C1EN_YES		(1 << (RCC_APB1ENR_I2C1EN_SHIFT))
#define RCC_APB1ENR_USART2EN_SHIFT	17
#define RCC_APB1ENR_USART2EN_MASK	(1 << (RCC_APB1ENR_USART2EN_SHIFT))
#define RCC_APB1ENR_USART2EN_NO	(0 << (RCC_APB1ENR_USART2EN_SHIFT))
#define RCC_APB1ENR_USART2EN_YES	(1 << (RCC_APB1ENR_USART2EN_SHIFT))
#define RCC_APB1ENR_SPI3EN_SHIFT	15
#define RCC_APB1ENR_SPI3EN_MASK	(1 << (RCC_APB1ENR_SPI3EN_SHIFT))
#define RCC_APB1ENR_SPI3EN_NO		(0 << (RCC_APB1ENR_SPI3EN_SHIFT))
#define RCC_APB1ENR_SPI3EN_YES		(1 << (RCC_APB1ENR_SPI3EN_SHIFT))
#define RCC_APB1ENR_SPI2EN_SHIFT	14
#define RCC_APB1ENR_SPI2EN_MASK	(1 << (RCC_APB1ENR_SPI2EN_SHIFT))
#define RCC_APB1ENR_SPI2EN_NO		(0 << (RCC_APB1ENR_SPI2EN_SHIFT))
#define RCC_APB1ENR_SPI2EN_YES		(1 << (RCC_APB1ENR_SPI2EN_SHIFT))
#define RCC_APB1ENR_WWDGEN_SHIFT	11
#define RCC_APB1ENR_WWDGEN_MASK	(1 << (RCC_APB1ENR_WWDGEN_SHIFT))
#define RCC_APB1ENR_WWDGEN_NO		(0 << (RCC_APB1ENR_WWDGEN_SHIFT))
#define RCC_APB1ENR_WWDGEN_YES		(1 << (RCC_APB1ENR_WWDGEN_SHIFT))
#define RCC_APB1ENR_TIM5EN_SHIFT	3
#define RCC_APB1ENR_TIM5EN_MASK	(1 << (RCC_APB1ENR_TIM5EN_SHIFT))
#define RCC_APB1ENR_TIM5EN_NO		(0 << (RCC_APB1ENR_TIM5EN_SHIFT))
#define RCC_APB1ENR_TIM5EN_YES		(1 << (RCC_APB1ENR_TIM5EN_SHIFT))
#define RCC_APB1ENR_TIM4EN_SHIFT	2
#define RCC_APB1ENR_TIM4EN_MASK	(1 << (RCC_APB1ENR_TIM4EN_SHIFT))
#define RCC_APB1ENR_TIM4EN_NO		(0 << (RCC_APB1ENR_TIM4EN_SHIFT))
#define RCC_APB1ENR_TIM4EN_YES		(1 << (RCC_APB1ENR_TIM4EN_SHIFT))
#define RCC_APB1ENR_TIM3EN_SHIFT	1
#define RCC_APB1ENR_TIM3EN_MASK	(1 << (RCC_APB1ENR_TIM3EN_SHIFT))
#define RCC_APB1ENR_TIM3EN_NO		(0 << (RCC_APB1ENR_TIM3EN_SHIFT))
#define RCC_APB1ENR_TIM3EN_YES		(1 << (RCC_APB1ENR_TIM3EN_SHIFT))
#define RCC_APB1ENR_TIM2EN_SHIFT	0
#define RCC_APB1ENR_TIM2EN_MASK	(1 << (RCC_APB1ENR_TIM2EN_SHIFT))
#define RCC_APB1ENR_TIM2EN_NO		(0 << (RCC_APB1ENR_TIM2EN_SHIFT))
#define RCC_APB1ENR_TIM2EN_YES		(1 << (RCC_APB1ENR_TIM2EN_SHIFT))

  __IO uint32_t         APB2ENR;        /* 0x44 */
#define RCC_APB2ENR_TIM11EN_SHIFT	18
#define RCC_APB2ENR_TIM11EN_MASK	(1 << (RCC_APB2ENR_TIM11EN_SHIFT))
#define RCC_APB2ENR_TIM11EN_NO		(0 << (RCC_APB2ENR_TIM11EN_SHIFT))
#define RCC_APB2ENR_TIM11EN_YES		(1 << (RCC_APB2ENR_TIM11EN_SHIFT))
#define RCC_APB2ENR_TIM10EN_SHIFT	17
#define RCC_APB2ENR_TIM10EN_MASK	(1 << (RCC_APB2ENR_TIM10EN_SHIFT))
#define RCC_APB2ENR_TIM10EN_NO		(0 << (RCC_APB2ENR_TIM10EN_SHIFT))
#define RCC_APB2ENR_TIM10EN_YES		(1 << (RCC_APB2ENR_TIM10EN_SHIFT))
#define RCC_APB2ENR_TIM9EN_SHIFT	16
#define RCC_APB2ENR_TIM9EN_MASK         (1 << (RCC_APB2ENR_TIM9EN_SHIFT))
#define RCC_APB2ENR_TIM9EN_NO		(0 << (RCC_APB2ENR_TIM9EN_SHIFT))
#define RCC_APB2ENR_TIM9EN_YES		(1 << (RCC_APB2ENR_TIM9EN_SHIFT))
#define RCC_APB2ENR_SYSCFGEN_SHIFT	14
#define RCC_APB2ENR_SYSCFGEN_MASK	(1 << (RCC_APB2ENR_SYSCFGEN_SHIFT))
#define RCC_APB2ENR_SYSCFGEN_NO		(0 << (RCC_APB2ENR_SYSCFGEN_SHIFT))
#define RCC_APB2ENR_SYSCFGEN_YES	(1 << (RCC_APB2ENR_SYSCFGEN_SHIFT))
#define RCC_APB2ENR_SPI4EN_SHIFT	13
#define RCC_APB2ENR_SPI4EN_MASK		(1 << (RCC_APB2ENR_SPI4EN_SHIFT))
#define RCC_APB2ENR_SPI4EN_NO		(0 << (RCC_APB2ENR_SPI4EN_SHIFT))
#define RCC_APB2ENR_SPI4EN_YES		(1 << (RCC_APB2ENR_SPI4EN_SHIFT))
#define RCC_APB2ENR_SPI1EN_SHIFT	12
#define RCC_APB2ENR_SPI1EN_MASK		(1 << (RCC_APB2ENR_SPI1EN_SHIFT))
#define RCC_APB2ENR_SPI1EN_NO		(0 << (RCC_APB2ENR_SPI1EN_SHIFT))
#define RCC_APB2ENR_SPI1EN_YES		(1 << (RCC_APB2ENR_SPI1EN_SHIFT))
#define RCC_APB2ENR_SDIOEN_SHIFT	11
#define RCC_APB2ENR_SDIOEN_MASK         (1 << (RCC_APB2ENR_SDIOEN_SHIFT))
#define RCC_APB2ENR_SDIOEN_NO		(0 << (RCC_APB2ENR_SDIOEN_SHIFT))
#define RCC_APB2ENR_SDIOEN_YES          (1 << (RCC_APB2ENR_SDIOEN_SHIFT))
#define RCC_APB2ENR_USART6EN_SHIFT	5
#define RCC_APB2ENR_USART6EN_MASK	(1 << (RCC_APB2ENR_USART6EN_SHIFT))
#define RCC_APB2ENR_USART6EN_NO		(0 << (RCC_APB2ENR_USART6EN_SHIFT))
#define RCC_APB2ENR_USART6EN_YES	(1 << (RCC_APB2ENR_USART6EN_SHIFT))
#define RCC_APB2ENR_USART1EN_SHIFT	4
#define RCC_APB2ENR_USART1EN_MASK	(1 << (RCC_APB2ENR_USART1EN_SHIFT))
#define RCC_APB2ENR_USART1EN_NO		(0 << (RCC_APB2ENR_USART1EN_SHIFT))
#define RCC_APB2ENR_USART1EN_YES	(1 << (RCC_APB2ENR_USART1EN_SHIFT))
#define RCC_APB2ENR_TIM1EN_SHIFT	0
#define RCC_APB2ENR_TIM1EN_MASK         (1 << (RCC_APB2ENR_TIM1EN_SHIFT))
#define RCC_APB2ENR_TIM1EN_NO		(0 << (RCC_APB2ENR_TIM1EN_SHIFT))
#define RCC_APB2ENR_TIM1EN_YES		(1 << (RCC_APB2ENR_TIM1EN_SHIFT))

  uint32_t              reserved0x48;   /* 0x48 */
  uint32_t              reserved0x4c;   /* 0x4c */

  __IO uint32_t         AHB1LPENR;      /* 0x50 */
  __IO uint32_t         AHB2LPENR;      /* 0x54 */
  __IO uint32_t         AHB3LPENR;      /* 0x58 */
  uint32_t              reserved0x5c;   /* 0x5c */

  __IO uint32_t         APB1LPENR;      /* 0x60 */
  __IO uint32_t         APB2LPENR;      /* 0x64 */
  uint32_t              reserved0x68;   /* 0x68 */
  uint32_t              reserved0x6c;   /* 0x6c */

  __IO uint32_t         BDCR;           /* 0x70 */
#define RCC_BDCR_BDRST_SHIFT		16
#define RCC_BDCR_BDRST_MASK		(1 << (RCC_BDCR_BDRST_SHIFT))
#define RCC_BDCR_BDRST_NO		(0 << (RCC_BDCR_BDRST_SHIFT))
#define RCC_BDCR_BDRST_YES		(1 << (RCC_BDCR_BDRST_SHIFT))
#define RCC_BDCR_RTCEN_SHIFT		15
#define RCC_BDCR_RTCEN_MASK		(1 << (RCC_BDCR_RTCEN_SHIFT))
#define RCC_BDCR_RTCEN_NO		(0 << (RCC_BDCR_RTCEN_SHIFT))
#define RCC_BDCR_RTCEN_YES		(1 << (RCC_BDCR_RTCEN_SHIFT))
#define RCC_BDCR_RTCSELSEL_SHIFT        8
#define RCC_BDCR_RTCSELSEL_MASK         (3 << (RCC_BDCR_RTCSELSEL_SHIFT))
#define RCC_BDCR_RTCSELSEL_NONE         (0 << (RCC_BDCR_RTCSELSEL_SHIFT))
#define RCC_BDCR_RTCSELSEL_LSE          (1 << (RCC_BDCR_RTCSELSEL_SHIFT))
#define RCC_BDCR_RTCSELSEL_LSI          (2 << (RCC_BDCR_RTCSELSEL_SHIFT))
#define RCC_BDCR_RTCSELSEL_HSE          (3 << (RCC_BDCR_RTCSELSEL_SHIFT))
#define RCC_BDCR_LSEDRVSEL_SHIFT	3
#define RCC_BDCR_LSEDRVSEL_MASK		(3 << (RCC_BDCR_LSEDRVSEL_SHIFT))
#define RCC_BDCR_LSEDRVSEL_LOWERCAP	(0 << (RCC_BDCR_LSEDRVSEL_SHIFT))
#define RCC_BDCR_LSEDRVSEL_MEDLOWCAP	(1 << (RCC_BDCR_LSEDRVSEL_SHIFT))
#define RCC_BDCR_LSEDRVSEL_MEDHIGHCAP	(2 << (RCC_BDCR_LSEDRVSEL_SHIFT))
#define RCC_BDCR_LSEDRVSEL_HIGHERCAP	(3 << (RCC_BDCR_LSEDRVSEL_SHIFT))
#define RCC_BDCR_LSEBYP_SHIFT		2
#define RCC_BDCR_LSEBYP_MASK		(1 << (RCC_BDCR_LSEBYP_SHIFT))
#define RCC_BDCR_LSEBYP_NO		(0 << (RCC_BDCR_LSEBYP_SHIFT))
#define RCC_BDCR_LSEBYP_YES		(1 << (RCC_BDCR_LSEBYP_SHIFT))
#define RCC_BDCR_LSERDY_SHIFT		1
#define RCC_BDCR_LSERDY_MASK		(1 << (RCC_BDCR_LSERDY_SHIFT))
#define RCC_BDCR_LSERDY_NO		(0 << (RCC_BDCR_LSERDY_SHIFT))
#define RCC_BDCR_LSERDY_YES		(1 << (RCC_BDCR_EN_SHIFT))
#define RCC_BDCR_LSEON_SHIFT		0
#define RCC_BDCR_LSEON_MASK		(1 << (RCC_BDCR_LSEON_SHIFT))
#define RCC_BDCR_LSEON_NO		(0 << (RCC_BDCR_LSEON_SHIFT))
#define RCC_BDCR_LSEON_YES		(1 << (RCC_BDCR_LSEON_SHIFT))

  __IO uint32_t                 CSR;    /* 0x74 */
#define RCC_CSR_LPWRRSTF_SHIFT		31
#define RCC_CSR_LPWRRSTF_MASK		(1 << (RCC_CSR_LPWRRSTF_SHIFT))
#define RCC_CSR_LPWRRSTF_NO		(0 << (RCC_CSR_LPWRRSTF_SHIFT))
#define RCC_CSR_LPWRRSTF_YES		(1 << (RCC_CSR_LPWRRSTF_SHIFT))
#define RCC_CSR_WWDGRSTF_SHIFT		30
#define RCC_CSR_WWDGRSTF_MASK		(1 << (RCC_CSR_WWDGRSTF_SHIFT))
#define RCC_CSR_WWDGRSTF_NO		(0 << (RCC_CSR_WWDGRSTF_SHIFT))
#define RCC_CSR_WWDGRSTF_YES		(1 << (RCC_CSR_WWDGRSTF_SHIFT))
#define RCC_CSR_IWWGRSTF_SHIFT		29
#define RCC_CSR_IWWGRSTF_MASK		(1 << (RCC_CSR_IWWGRSTF_SHIFT))
#define RCC_CSR_IWWGRSTF_NO		(0 << (RCC_CSR_IWWGRSTF_SHIFT))
#define RCC_CSR_IWWGRSTF_YES		(1 << (RCC_CSR_IWWGRSTF_SHIFT))
#define RCC_CSR_SFTRSTF_SHIFT		28
#define RCC_CSR_SFTRSTF_MASK		(1 << (RCC_CSR_SFTRSTF_SHIFT))
#define RCC_CSR_SFTRSTF_NO		(0 << (RCC_CSR_SFTRSTF_SHIFT))
#define RCC_CSR_SFTRSTF_YES		(1 << (RCC_CSR_SFTRSTF_SHIFT))
#define RCC_CSR_PORRSTF_SHIFT		27
#define RCC_CSR_PORRSTF_MASK		(1 << (RCC_CSR_PORRSTF_SHIFT))
#define RCC_CSR_PORRSTF_NO		(0 << (RCC_CSR_PORRSTF_SHIFT))
#define RCC_CSR_PORRSTF_YES		(1 << (RCC_CSR_PORRSTF_SHIFT))
#define RCC_CSR_PINRSTF_SHIFT		26
#define RCC_CSR_PINRSTF_MASK		(1 << (RCC_CSR_PINRSTF_SHIFT))
#define RCC_CSR_PINRSTF_NO		(0 << (RCC_CSR_PINRSTF_SHIFT))
#define RCC_CSR_PINRSTF_YES		(1 << (RCC_CSR_PINRSTF_SHIFT))
#define RCC_CSR_OBLRSTF_SHIFT		25
#define RCC_CSR_OBLRSTF_MASK		(1 << (RCC_CSR_OBLRSTF_SHIFT))
#define RCC_CSR_OBLRSTF_NO		(0 << (RCC_CSR_OBLRSTF_SHIFT))
#define RCC_CSR_OBLRSTF_YES		(1 << (RCC_CSR_OBLRSTF_SHIFT))
#define RCC_CSR_FWRSTF_SHIFT		24
#define RCC_CSR_FWRSTF_MASK		(1 << (RCC_CSR_FWRSTF_SHIFT))
#define RCC_CSR_FWRSTF_NO		(0 << (RCC_CSR_FWRSTF_SHIFT))
#define RCC_CSR_FWRSTF_YES		(1 << (RCC_CSR_FWRSTF_SHIFT))
#define RCC_CSR_RMVF_SHIFT		23
#define RCC_CSR_RMVF_MASK		(1 << (RCC_CSR_RMVF_SHIFT))
#define RCC_CSR_RMVF_NO		        (0 << (RCC_CSR_RMVF_SHIFT))
#define RCC_CSR_RMVF_YES		(1 << (RCC_CSR_RMVF_SHIFT))
#define RCC_CSR_LSIRDY_SHIFT		1
#define RCC_CSR_LSIRDY_MASK		(1 << (RCC_CSR_LSIRDY_SHIFT))
#define RCC_CSR_LSIRDY_NO		(0 << (RCC_CSR_LSIRDY_SHIFT))
#define RCC_CSR_LSIRDY_YES		(1 << (RCC_CSR_LSIRDY_SHIFT))
#define RCC_CSR_LSION_SHIFT		0
#define RCC_CSR_LSION_MASK		(1 << (RCC_CSR_LSION_SHIFT))
#define RCC_CSR_LSION_NO		(0 << (RCC_CSR_LSION_SHIFT))
#define RCC_CSR_LSION_YES		(1 << (RCC_CSR_LSION_SHIFT))

  uint32_t              reserved0x74;   /* 0x78 */
  uint32_t              reserved0x7c;   /* 0x7c */

  __IO uint32_t         SSCGR;          /* 0x80 */
  __IO uint32_t         PLLI2SCFGR;     /* 0x84 */
  uint32_t              reserved0x88;   /* 0x88 */
  __IO uint32_t         DCKCFGR;        /* 0x8c */
  __IO uint32_t         DCKCFGR2;       /* 0x90 */

} stm32Dev_RCC;



#define CALCPLL(reg, no, freqPllIn)      {                              \
  int div;                                                              \
  m = ( ((reg) & RCC_PLLCFGR_PLLM_MASK) >> RCC_PLLCFGR_PLLM_SHIFT);     \
  n = ( ((reg) & RCC_PLLCFGR_PLLN_MASK) >> RCC_PLLCFGR_PLLN_SHIFT);     \
  vco = (freqPllIn) / m * n;                                            \
  systemClk.pll ##no.vco = vco;                                         \
\
  /* div and store P, Q */ \
  div   = RCC_PTR->PLLCFGR & RCC_PLLCFGR_PLLP_MASK;     \
  div >>= RCC_PLLCFGR_PLLP_SHIFT;                       \
  div  += 1;                                            \
  systemClk.pll ##no.P = vco >> div;                    \
\
  div   = RCC_PTR->PLLCFGR & RCC_PLLCFGR_PLLQ_MASK;     \
  div >>= RCC_PLLCFGR_PLLQ_SHIFT;                       \
  systemClk.pll ##no.Q = vco / div;                     \
\
}


#define RccPll1Enable()                         \
{ \
  /* disable pll and wait till PLL is ready */ \
  RCC_PTR->CR &= ~RCC_CR_PLLON_MASK; \
  while(RCC_PTR->CR & RCC_CR_PLLON_MASK); \
 \
  /* enable PLL and wait becoming ready */ \
  RCC_PTR->CR |= RCC_CR_PLLON_YES; \
  while(!(RCC_PTR->CR & RCC_CR_PLLON_MASK)); \
}



#endif

