/*
 * Copyright (c) 2016 zhtlab
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

#ifndef _STM32OTG_H_
#define _STM32OTG_H_

typedef struct {
  __IO uint32_t         CTL;
#define USB_EPCTL_EPENA_SHIFT   (31)
#define USB_EPCTL_EPENA_MASK    (1 << (USB_EPCTL_EPENA_SHIFT))
#define USB_EPCTL_EPENA_NO      (0 << (USB_EPCTL_EPENA_SHIFT))
#define USB_EPCTL_EPENA_YES     (1 << (USB_EPCTL_EPENA_SHIFT))
#define USB_EPCTL_EPDIS_SHIFT   (30)
#define USB_EPCTL_EPDIS_MASK    (1 << (USB_EPCTL_EPDIS_SHIFT))
#define USB_EPCTL_EPDIS_NO      (0 << (USB_EPCTL_EPDIS_SHIFT))
#define USB_EPCTL_EPDIS_YES     (1 << (USB_EPCTL_EPDIS_SHIFT))
#define USB_EPCTL_SD1PID_SODDFRM_SHIFT  (29)
#define USB_EPCTL_SD1PID_SODDFRM_MASK   (1 << (USB_EPCTL_SD1PID_SODDFRM_SHIFT))
#define USB_EPCTL_SD1PID_SODDFRM        (1 << (USB_EPCTL_SD1PID_SODDFRM_SHIFT))
#define USB_EPCTL_SD0PID_SEVNFRM_SHIFT  (28)
#define USB_EPCTL_SD0PID_SEVNFRM_MASK   (1 << (USB_EPCTL_SD0PID_SEVNFRM_SHIFT))
#define USB_EPCTL_SD0PID_SEVNFRM        (1 << (USB_EPCTL_SD0PID_SEVNFRM_SHIFT))
#define USB_EPCTL_SNAK_SHIFT    (27)
#define USB_EPCTL_SNAK_MASK     (1 << (USB_EPCTL_SNAK_SHIFT))
#define USB_EPCTL_SNAK          (1 << (USB_EPCTL_SNAK_SHIFT))
#define USB_EPCTL_CNAK_SHIFT    (26)
#define USB_EPCTL_CNAK_MASK     (1 << (USB_EPCTL_CNAK_SHIFT))
#define USB_EPCTL_CNAK          (1 << (USB_EPCTL_CNAK_SHIFT))
#define USB_EPCTL_TXFNUM_SHIFT  (22)
#define USB_EPCTL_TXFNUM_MASK   (0xf  << (USB_EPCTL_TXFNUM_SHIFT))
#define USB_EPCTL_TXFNUM_VAL(x) (((x) << (USB_EPCTL_TXFNUM_SHIFT)) & USB_EPCTL_TXFNUM_MASK)
#define USB_EPCTL_STALL_SHIFT   (21)
#define USB_EPCTL_STALL_MASK    (1 << (USB_EPCTL_STALL_SHIFT))
#define USB_EPCTL_STALL_NO      (0 << (USB_EPCTL_STALL_SHIFT))
#define USB_EPCTL_STALL_YES     (1 << (USB_EPCTL_STALL_SHIFT))
#define USB_EPCTL_EPTYP_SHIFT   (18)
#define USB_EPCTL_EPTYP_MASK    (3 << (USB_EPCTL_EPTYP_SHIFT))
#define USB_EPCTL_EPTYP_CTRL    (0 << (USB_EPCTL_EPTYP_SHIFT))
#define USB_EPCTL_EPTYP_ISOC    (1 << (USB_EPCTL_EPTYP_SHIFT))
#define USB_EPCTL_EPTYP_BULK    (2 << (USB_EPCTL_EPTYP_SHIFT))
#define USB_EPCTL_EPTYP_INTR    (3 << (USB_EPCTL_EPTYP_SHIFT))
#define USB_EPCTL_USBAEP_SHIFT  (15)
#define USB_EPCTL_USBAEP_MASK   (1 << (USB_EPCTL_USBAEP_SHIFT))
#define USB_EPCTL_USBAEP_NO     (0 << (USB_EPCTL_USBAEP_SHIFT))
#define USB_EPCTL_USBAEP_YES    (1 << (USB_EPCTL_USBAEP_SHIFT))
#define USB_EPCTL_MPSIZ_SHIFT   (0)
#define USB_EPCTL_MPSIZ_MASK    (0x3ff << (USB_EPCTL_MPSIZ_SHIFT))
#define USB_EPCTL_MPSIZ_VAL(x)  ((x) << (USB_EPCTL_MPSIZ_SHIFT))

  uint32_t              reserved04;
  __IO uint32_t         INT;            /* 0x08 */
#define USB_EPINT_NAK_SHIFT     (13)
#define USB_EPINT_NAK_MASK      (1 << (USB_EPINT_NAK_SHIFT))
#define USB_EPINT_TXFE_SHIFT    (7)
#define USB_EPINT_TXFE_MASK     (1 << (USB_EPINT_TXFE_SHIFT))
#define USB_EPINT_B2BSTUP_SHIFT (6)
#define USB_EPINT_B2BSTUP_MASK  (1 << (USB_EPINT_B2BSTUP_SHIFT))
#define USB_EPINT_STSPHSRX_SHIFT (5)
#define USB_EPINT_STSPHSRX_MASK  (1 << (USB_EPINT_STSPHSRX_SHIFT))
#define USB_EPINT_OTEPDIS_SHIFT (4)
#define USB_EPINT_OTEPDIS_MASK  (1 << (USB_EPINT_OTEPDIS_SHIFT))
#define USB_EPINT_STUP_SHIFT    (3)
#define USB_EPINT_STUP_MASK     (1 << (USB_EPINT_STUP_SHIFT))
#define USB_EPINT_EPDISD_SHIFT  (1)
#define USB_EPINT_EPDISD_MASK   (1 << (USB_EPINT_EPDISD_SHIFT))
#define USB_EPINT_XFRC_SHIFT    (0)
#define USB_EPINT_XFRC_MASK     (1 << (USB_EPINT_XFRC_SHIFT))

  uint32_t              reserved0c;
  __IO uint32_t         SIZ;            /* 0x10 */
  /* STUPCNT is for SETUP OUT packet */
#define USB_EPSIZ_STUPCNT_SHIFT (29)
#define USB_EPSIZ_STUPCNT_MASK  (3 << (USB_EPSIZ_STUPCNT_SHIFT))
#define USB_EPSIZ_STUPCNT_1PKTS (1 << (USB_EPSIZ_STUPCNT_SHIFT))
#define USB_EPSIZ_STUPCNT_2PKTS (2 << (USB_EPSIZ_STUPCNT_SHIFT))
#define USB_EPSIZ_STUPCNT_3PKTS (3 << (USB_EPSIZ_STUPCNT_SHIFT))
  /* MCNT is for IN packet and EP1,2, ... */
#define USB_EPSIZ_MCNT_SHIFT    (29)
#define USB_EPSIZ_MCNT_MASK     (3 << (USB_EPSIZ_MCNT_SHIFT))
#define USB_EPSIZ_MCNT_1PKTS    (1 << (USB_EPSIZ_MCNT_SHIFT))
#define USB_EPSIZ_MCNT_2PKTS    (2 << (USB_EPSIZ_MCNT_SHIFT))
#define USB_EPSIZ_MCNT_3PKTS    (3 << (USB_EPSIZ_MCNT_SHIFT))
#define USB_EPSIZ_PKTCNT_SHIFT  (19)
#define USB_EPSIZ_PKTCNT_MASK   (1 << (USB_EPSIZ_PKTCNT_SHIFT))
#define USB_EPSIZ_PKTCNT_ZERO   (0 << (USB_EPSIZ_PKTCNT_SHIFT))
#define USB_EPSIZ_PKTCNT_ONE    (1 << (USB_EPSIZ_PKTCNT_SHIFT))
#define USB_EPSIZ_PKTCNT_TWO    (2 << (USB_EPSIZ_PKTCNT_SHIFT))
#define USB_EPSIZ_PKTCNT_THREE  (3 << (USB_EPSIZ_PKTCNT_SHIFT))
#define USB_EPSIZ_XFRSIZ_SHIFT  (0)
#define USB_EPSIZ_XFRSIZ_MASK   (0x7f << (USB_EPSIZ_XFRSIZ_SHIFT))
#define USB_EPSIZ_XFRSIZ_VAL(x) (((x) << (USB_EPSIZ_XFRSIZ_SHIFT)) & (USB_EPSIZ_XFRSIZ_MASK))
  __IO uint32_t         DMA;            /* 0x14  out only */
  __IO uint32_t         STS;            /* 0x18  in only */
  uint32_t              reserved1c;
} stm32Usb320aDevEp_t;

typedef struct {
  /* 0x00 */
  __IO uint32_t         GOTGCTL;
#define USB_GOTGCTL_BVALOVAL_SHIFT      (7)
#define USB_GOTGCTL_BVALOVAL_MASK       (1 << (USB_GOTGCTL_BVALOVAL_SHIFT))
#define USB_GOTGCTL_BVALOVAL_NOS        (0 << (USB_GOTGCTL_BVALOVAL_SHIFT))
#define USB_GOTGCTL_BVALOVAL_YES        (1 << (USB_GOTGCTL_BVALOVAL_SHIFT))
#define USB_GOTGCTL_BVALOEN_SHIFT       (6)
#define USB_GOTGCTL_BVALOEN_MASK        (1 << (USB_GOTGCTL_BVALOEN_SHIFT))
#define USB_GOTGCTL_BVALOEN_NO          (0 << (USB_GOTGCTL_BVALOEN_SHIFT))
#define USB_GOTGCTL_BVALOEN_YES         (1 << (USB_GOTGCTL_BVALOEN_SHIFT))

  __IO uint32_t         GOTGINT;
#define USB_GOTGINT_SEDET_SHIFT         (2)
#define USB_GOTGINT_SEDET_MASK          (1 << (USB_GOTGINT_SEDET_SHIFT))
#define USB_GOTGINT_SEDET_DIS           (0 << (USB_GOTGINT_SEDET_SHIFT))
#define USB_GOTGINT_SEDET_EN            (1 << (USB_GOTGINT_SEDET_SHIFT))


/*** 0x08 OTG_GAHBCFG     x is available to set 1 to 16 */
  __IO uint32_t         GAHBCFG;
#define USB_GAHBCFG_DMAEN_SHIFT         (4)
#define USB_GAHBCFG_DMAEN_MASK          (1 << (USB_GAHBCFG_DMAEN_SHIFT))
#define USB_GAHBCFG_DMAEN_NO            (0 << (USB_GAHBCFG_DMAEN_SHIFT))
#define USB_GAHBCFG_DMAEN_YES           (1 << (USB_GAHBCFG_DMAEN_SHIFT))
#define USB_GAHBCFG_HBSTLEN_SHIFT       (1)
#define USB_GAHBCFG_HBSTLEN_MASK        (15 << (USB_GAHBCFG_HBSTLEN_SHIFT))
#define USB_GAHBCFG_HBSTLEN_1WORD       (0 << (USB_GAHBCFG_HBSTLEN_SHIFT))
#define USB_GAHBCFG_HBSTLEN_4WORDS      (3 << (USB_GAHBCFG_HBSTLEN_SHIFT))
#define USB_GAHBCFG_HBSTLEN_8WORDS      (3 << (USB_GAHBCFG_HBSTLEN_SHIFT))
#define USB_GAHBCFG_HBSTLEN_16WORDS     (7 << (USB_GAHBCFG_HBSTLEN_SHIFT))
#define USB_GAHBCFG_GINTMSK_SHIFT       (0)
#define USB_GAHBCFG_GINTMSK_MASK        (1 << (USB_GAHBCFG_GINTMSK_SHIFT))
#define USB_GAHBCFG_GINTMSK_NO          (0 << (USB_GAHBCFG_GINTMSK_SHIFT))
#define USB_GAHBCFG_GINTMSK_YES         (1 << (USB_GAHBCFG_GINTMSK_SHIFT))

  __IO uint32_t         GUSBCFG;
  __IO uint32_t         GRSTCTL;
#define USB_GRSTCTL_TXFNUM_SHIFT        (6)
#define USB_GRSTCTL_TXFNUM_MASK         (0x1f << (USB_GRSTCTL_TXFNUM_SHIFT))
#define USB_GRSTCTL_TXFNUM(x)           (((x) << (USB_GRSTCTL_TXFNUM_SHIFT)) & (USB_GRSTCTL_TXFNUM_MASK))
#define USB_GRSTCTL_TXFNUM_ALL          (0x10 << (USB_GRSTCTL_TXFNUM_SHIFT))
#define USB_GRSTCTL_TXFFLSH_SHIFT       (5)
#define USB_GRSTCTL_TXFFLSH_MASK        (1 << (USB_GRSTCTL_TXFFLSH_SHIFT))
#define USB_GRSTCTL_TXFFLSH_DIS         (0 << (USB_GRSTCTL_TXFFLSH_SHIFT))
#define USB_GRSTCTL_TXFFLSH_EN          (1 << (USB_GRSTCTL_TXFFLSH_SHIFT))
#define USB_GRSTCTL_RXFFLSH_SHIFT       (4)
#define USB_GRSTCTL_RXFFLSH_MASK        (1 << (USB_GRSTCTL_RXFFLSH_SHIFT))
#define USB_GRSTCTL_RXFFLSH_DIS         (0 << (USB_GRSTCTL_RXFFLSH_SHIFT))
#define USB_GRSTCTL_RXFFLSH_EN          (1 << (USB_GRSTCTL_RXFFLSH_SHIFT))
#define USB_GRSTCTL_CSRST_SHIFT         (0)
#define USB_GRSTCTL_CSRST_MASK          (1 << (USB_GRSTCTL_CSRST_SHIFT))
#define USB_GRSTCTL_CSRST_DIS           (0 << (USB_GRSTCTL_CSRST_SHIFT))
#define USB_GRSTCTL_CSRST_EN            (1 << (USB_GRSTCTL_CSRST_SHIFT))

  __IO uint32_t         GINTSTS;
  __IO uint32_t         GINTMSK;
#define USB_GINTSTS_WKUINT_SHIFT        (31)
#define USB_GINTSTS_WKUINT_MASK         (1 << (USB_GINTSTS_WKUINT_SHIFT))
#define USB_GINTSTS_WKUINT_EN           (1 << (USB_GINTSTS_WKUINT_SHIFT))
#define USB_GINTSTS_SRQINT_SHIFT        (30)
#define USB_GINTSTS_SRQINT_MASK         (1 << (USB_GINTSTS_SRQINT_SHIFT))
#define USB_GINTSTS_SRQINT_EN           (1 << (USB_GINTSTS_SRQINT_SHIFT))
#define USB_GINTSTS_DISCINT_SHIFT       (29)
#define USB_GINTSTS_DISCINT_MASK        (1 << (USB_GINTSTS_DISCINT_SHIFT))
#define USB_GINTSTS_DISCINT_EN          (1 << (USB_GINTSTS_DISCINT_SHIFT))
#define USB_GINTSTS_CIDSCHG_SHIFT       (28)
#define USB_GINTSTS_CIDSCHG_MASK        (1 << (USB_GINTSTS_CIDSCHG_SHIFT))
#define USB_GINTSTS_CIDSCHG_EN          (1 << (USB_GINTSTS_CIDSCHG_SHIFT))
#define USB_GINTSTS_LPMINT_SHIFT        (27)
#define USB_GINTSTS_LPMINT_MASK         (1 << (USB_GINTSTS_LPMINT_SHIFT))
#define USB_GINTSTS_LPMINT_EN           (1 << (USB_GINTSTS_LPMINT_SHIFT))
#define USB_GINTSTS_PXFRM_IISOOXFR_SHIFT      (21)
#define USB_GINTSTS_PXFRM_IISOOXFR_MASK       (1 << (USB_GINTSTS_PXFRM_IISOOXFR_SHIFT))
#define USB_GINTSTS_PXFRM_IISOOXFR_EN         (1 << (USB_GINTSTS_PXFRM_IISOOXFR_SHIFT))
#define USB_GINTSTS_IISOIXFR_SHIFT      (20)
#define USB_GINTSTS_IISOIXFR_MASK       (1 << (USB_GINTSTS_IISOIXFR_SHIFT))
#define USB_GINTSTS_IISOIXFR_EN         (1 << (USB_GINTSTS_IISOIXFR_SHIFT))
#define USB_GINTSTS_OEPINT_SHIFT        (19)
#define USB_GINTSTS_OEPINT_MASK         (1 << (USB_GINTSTS_OEPINT_SHIFT))
#define USB_GINTSTS_OEPINT_EN           (1 << (USB_GINTSTS_OEPINT_SHIFT))
#define USB_GINTSTS_IEPINT_SHIFT        (18)
#define USB_GINTSTS_IEPINT_MASK         (1 << (USB_GINTSTS_IEPINT_SHIFT))
#define USB_GINTSTS_IEPINT_EN           (1 << (USB_GINTSTS_IEPINT_SHIFT))

#define USB_GINTSTS_ENUMDNE_SHIFT       (13)
#define USB_GINTSTS_ENUMDNE_MASK        (1 << (USB_GINTSTS_ENUMDNE_SHIFT))
#define USB_GINTSTS_ENUMDNE_EN          (1 << (USB_GINTSTS_ENUMDNE_SHIFT))
#define USB_GINTSTS_USBRST_SHIFT        (12)
#define USB_GINTSTS_USBRST_MASK         (1 << (USB_GINTSTS_USBRST_SHIFT))
#define USB_GINTSTS_USBRST_EN           (1 << (USB_GINTSTS_USBRST_SHIFT))
#define USB_GINTSTS_USBSUSP_SHIFT       (11)
#define USB_GINTSTS_USBSUSP_MASK        (1 << (USB_GINTSTS_USBSUSP_SHIFT))
#define USB_GINTSTS_USBSUSP_EN          (1 << (USB_GINTSTS_USBSUSP_SHIFT))
#define USB_GINTSTS_ESUSP_SHIFT         (10)
#define USB_GINTSTS_ESUSP_MASK          (1 << (USB_GINTSTS_ESUSP_SHIFT))
#define USB_GINTSTS_ESUSP_EN            (1 << (USB_GINTSTS_ESUSP_SHIFT))
#define USB_GINTSTS_RXFLVL_SHIFT        (4)
#define USB_GINTSTS_RXFLVL_MASK         (1 << (USB_GINTSTS_RXFLVL_SHIFT))
#define USB_GINTSTS_RXFLVL_EN           (1 << (USB_GINTSTS_RXFLVL_SHIFT))
#define USB_GINTSTS_SOF_SHIFT           (3)
#define USB_GINTSTS_SOF_MASK            (1 << (USB_GINTSTS_SOF_SHIFT))
#define USB_GINTSTS_SOF_EN              (1 << (USB_GINTSTS_SOF_SHIFT))
#define USB_GINTSTS_OTGINT_SHIFT        (2)
#define USB_GINTSTS_OTGINT_MASK         (1 << (USB_GINTSTS_OTGINT_SHIFT))
#define USB_GINTSTS_OTGINT_EN           (1 << (USB_GINTSTS_OTGINT_SHIFT))
#define USB_GINTSTS_MMIS_SHIFT          (1)
#define USB_GINTSTS_MMIS_MASK           (1 << (USB_GINTSTS_MMIS_SHIFT))
#define USB_GINTSTS_MMIS_EN             (1 << (USB_GINTSTS_MMIS_SHIFT))
#define USB_GINTSTS_CMOD_SHIFT          (0)
#define USB_GINTSTS_CMOD_MASK           (1 << (USB_GINTSTS_CMOD_SHIFT))

  __IO uint32_t         GRXSTSR;                /* debug */
  __IO uint32_t         GRXSTSP;                /* normal use */
#define USB_GRXSTSP_FRMNUM_SHIFT         (21)
#define USB_GRXSTSP_FRMNUM_MASK          (0xf << (USB_GRXSTSP_FRMNUM_SHIFT))
#define USB_GRXSTSP_PKTSTS_SHIFT         (17)
#define USB_GRXSTSP_PKTSTS_MASK          (0xf << (USB_GRXSTSP_PKTSTS_SHIFT))
#define USB_GRXSTSP_PKTSTS_OUT_NAK       (1 << (USB_GRXSTSP_PKTSTS_SHIFT))
#define USB_GRXSTSP_PKTSTS_OUT_RECV      (2 << (USB_GRXSTSP_PKTSTS_SHIFT))
#define USB_GRXSTSP_PKTSTS_INOUT_COMPLETE (3 << (USB_GRXSTSP_PKTSTS_SHIFT))
#define USB_GRXSTSP_PKTSTS_SETUP_COPMLETE (4 << (USB_GRXSTSP_PKTSTS_SHIFT))
#define USB_GRXSTSP_PKTSTS_TOGGLE_ERROR  (5 << (USB_GRXSTSP_PKTSTS_SHIFT))
#define USB_GRXSTSP_PKTSTS_SETUP_RECV    (6 << (USB_GRXSTSP_PKTSTS_SHIFT))
#define USB_GRXSTSP_PKTSTS_CH_HALT       (7 << (USB_GRXSTSP_PKTSTS_SHIFT))
#define USB_GRXSTSP_DPID_SHIFT           (15)
#define USB_GRXSTSP_DPID_MASK            (3 << (USB_GRXSTSP_DPID_SHIFT))
#define USB_GRXSTSP_DPID_DATA0           (0 << (USB_GRXSTSP_DPID_SHIFT))
#define USB_GRXSTSP_DPID_DATA1           (1 << (USB_GRXSTSP_DPID_SHIFT))
#define USB_GRXSTSP_DPID_DATA2           (2 << (USB_GRXSTSP_DPID_SHIFT))
#define USB_GRXSTSP_DPID_MDATA           (3 << (USB_GRXSTSP_DPID_SHIFT))
#define USB_GRXSTSP_BCNT_SHIFT           (4)
#define USB_GRXSTSP_BCNT_MASK            (0x3ff << (USB_GRXSTSP_BCNT_SHIFT))
#define USB_GRXSTSP_EPNUM_SHIFT          (0)
#define USB_GRXSTSP_EPNUM_MASK           (0xf << (USB_GRXSTSP_EPNUM_SHIFT))

  __IO uint32_t         GRXFSIZ;
#define USB_GRXSIZ_RXFD_SHIFT           (0)
#define USB_GRXSIZ_RXFD_MASK            (0xffff << (USB_GRXSIZ_RXFD_SHIFT))
  __IO uint32_t         DIEPTXF0_HNPTXFSIZ;
#define USB_DIEPTXF_FD_SHIFT            (16)
#define USB_DIEPTXF_FD_MASK             (0xffff << (USB_DIEPTXF_FD_SHIFT))
#define USB_DIEPTXF_SA_SHIFT            (0)
#define USB_DIEPTXF_SA_MASK             (0xffff << (USB_DIEPTXF_SA_SHIFT))
  __IO uint32_t         HNPTXSTS;
  __IO uint32_t         GI2CCTL;
  uint32_t              reserved_034;
  __IO uint32_t         GCCFG;
#define USB_GCCFG_VBDEN_SHIFT           (21)
#define USB_GCCFG_VBDEN_MASK            (3 << (USB_GCCFG_VBDEN_SHIFT))
#define USB_GCCFG_VBDEN_NO              (0 << (USB_GCCFG_VBDEN_SHIFT))
#define USB_GCCFG_VBDEN_YES             (1 << (USB_GCCFG_VBDEN_SHIFT))
#define USB_GCCFG_SDEN_SHIFT            (20)
#define USB_GCCFG_SDEN_MASK             (3 << (USB_GCCFG_SDEN_SHIFT))
#define USB_GCCFG_SDEN_NO               (0 << (USB_GCCFG_SDEN_SHIFT))
#define USB_GCCFG_SDEN_YES              (1 << (USB_GCCFG_SDEN_SHIFT))
#define USB_GCCFG_PDEN_SHIFT            (19)
#define USB_GCCFG_PDEN_MASK             (3 << (USB_GCCFG_PDEN_SHIFT))
#define USB_GCCFG_PDEN_NO               (0 << (USB_GCCFG_PDEN_SHIFT))
#define USB_GCCFG_PDEN_YES              (1 << (USB_GCCFG_PDEN_SHIFT))
#define USB_GCCFG_PWRDWN_SHIFT          (16)
#define USB_GCCFG_PWRDWN_MASK           (3 << (USB_GCCFG_PWRDWN_SHIFT))
#define USB_GCCFG_PWRDWN_NO             (0 << (USB_GCCFG_PWRDWN_SHIFT))
#define USB_GCCFG_PWRDWN_YES            (1 << (USB_GCCFG_PWRDWN_SHIFT))
  __IO uint32_t         CID;
  __IO uint32_t         GSNPSID;
  __IO uint32_t         GHWCFG1;
  __IO uint32_t         GHWCFG2;
  __IO uint32_t         GHWCFG3;
  uint32_t              reserved_050;
  __IO uint32_t         GLPMCFG;
  __IO uint32_t         GPWRDN;
  __IO uint32_t         GDFIFOCFG;
  __IO uint32_t         GADPCTL;
  uint32_t              reserved_064[39];
  /* 0x100 */
  __IO uint32_t         HPTXFSIZ;
  __IO uint32_t         DIEPTXF[15];

  /* 0x140 */
  uint32_t              reserved_140[0xb0];

  /* 0x400   host controller */
  __IO uint32_t         HCFGM;
  __IO uint32_t         HFIR;
  __IO uint32_t         HAFNUM;
  uint32_t              reserved_40c;
  __IO uint32_t         XPTXSTS;
  __IO uint32_t         HAINT;
  __IO uint32_t         HAINTMSK;
  uint32_t              reserved_41c[0x9];
  __IO uint32_t         HPRT;
#define USB_HPRT_PRST_SHIFT             (8)
#define USB_HPRT_PRST_MASK              (1 << (USB_HPRT_PRST_SHIFT))
#define USB_HPRT_PRST_NO                (0 << (USB_HPRT_PRST_SHIFT))
#define USB_HPRT_PRST_YES               (1 << (USB_HPRT_PRST_SHIFT))
#define USB_HPRT_POCCHNG_SHIFT          (5)
#define USB_HPRT_POCCHNG_MASK           (1 << (USB_HPRT_POCCHNG_SHIFT))
#define USB_HPRT_POCCHNG_NO             (0 << (USB_HPRT_POCCHNG_SHIFT))
#define USB_HPRT_POCCHNG_YES            (1 << (USB_HPRT_POCCHNG_SHIFT))
#define USB_HPRT_PENCHNG_SHIFT          (5)
#define USB_HPRT_PENCHNG_MASK           (1 << (USB_HPRT_PENCHNG_SHIFT))
#define USB_HPRT_PENCHNG_NO             (0 << (USB_HPRT_PENCHNG_SHIFT))
#define USB_HPRT_PENCHNG_YES            (1 << (USB_HPRT_PENCHNG_SHIFT))
#define USB_HPRT_PENA_SHIFT             (2)
#define USB_HPRT_PENA_MASK              (1 << (USB_HPRT_PENA_SHIFT))
#define USB_HPRT_PENA_NO                (0 << (USB_HPRT_PENA_SHIFT))
#define USB_HPRT_PENA_YES               (1 << (USB_HPRT_PENA_SHIFT))
#define USB_HPRT_PCDET_SHIFT            (1)
#define USB_HPRT_PCDET_MASK             (1 << (USB_HPRT_PCDET_SHIFT))
#define USB_HPRT_PCDET_NO               (0 << (USB_HPRT_PCDET_SHIFT))
#define USB_HPRT_PCDET_YES              (1 << (USB_HPRT_PCDET_SHIFT))
#define USB_HPRT_PCSTS_SHIFT            (0)
#define USB_HPRT_PCSTS_MASK             (1 << (USB_HPRT_PCSTS_SHIFT))
#define USB_HPRT_PCSTS_NO               (0 << (USB_HPRT_PCSTS_SHIFT))
#define USB_HPRT_PCSTS_YES              (1 << (USB_HPRT_PCSTS_SHIFT))
  uint32_t              reserved_444[0xef];

  /* 0x800   device controller */
  __IO uint32_t         DCFG;
#define USB_DCFG_DAD_SHIFT              (4)
#define USB_DCFG_DAD_MASK               (0x7f << (USB_DCFG_DAD_SHIFT))
#define USB_DCFG_DSPD_SHIFT             (0)
#define USB_DCFG_DSPD_MASK              (3 << (USB_DCFG_DSPD_SHIFT))
#define USB_DCFG_DSPD_HS                (0 << (USB_DCFG_DSPD_SHIFT))
#define USB_DCFG_DSPD_FS_IN_HS          (1 << (USB_DCFG_DSPD_SHIFT))
#define USB_DCFG_DSPD_RESERVED2         (2 << (USB_DCFG_DSPD_SHIFT))
#define USB_DCFG_DSPD_FS                (3 << (USB_DCFG_DSPD_SHIFT))

  __IO uint32_t         DCTL;
#define USB_DCTL_CGONAK_SHIFT           (10)
#define USB_DCTL_CGONAK_MASK            (1 << (USB_DCTL_CGONAK_SHIFT))
#define USB_DCTL_CGONAK_HIGH            (0 << (USB_DCTL_CGONAK_SHIFT))
#define USB_DCTL_CGONAK_FULL            (1 << (USB_DCTL_CGONAK_SHIFT))
#define USB_DCTL_SGONAK_SHIFT           (9)
#define USB_DCTL_SGONAK_MASK            (1 << (USB_DCTL_SGONAK_SHIFT))
#define USB_DCTL_SGONAK_HIGH            (0 << (USB_DCTL_SGONAK_SHIFT))
#define USB_DCTL_SGONAK_FULL            (1 << (USB_DCTL_SGONAK_SHIFT))
#define USB_DCTL_CGINAK_SHIFT           (8)
#define USB_DCTL_CGINAK_MASK            (1 << (USB_DCTL_CGINAK_SHIFT))
#define USB_DCTL_CGINAK_HIGH            (0 << (USB_DCTL_CGINAK_SHIFT))
#define USB_DCTL_CGINAK_FULL            (1 << (USB_DCTL_CGINAK_SHIFT))
#define USB_DCTL_SGINAK_SHIFT           (7)
#define USB_DCTL_SGINAK_MASK            (1 << (USB_DCTL_SGINAK_SHIFT))
#define USB_DCTL_SGINAK_HIGH            (0 << (USB_DCTL_SGINAK_SHIFT))
#define USB_DCTL_SGINAK_FULL            (1 << (USB_DCTL_SGINAK_SHIFT))
#define USB_DCTL_SDIS_SHIFT             (1)
#define USB_DCTL_SDIS_MASK              (1 << (USB_DCTL_SDIS_SHIFT))
#define USB_DCTL_SDIS_CONNECT           (0 << (USB_DCTL_SDIS_SHIFT))
#define USB_DCTL_SDIS_DISCONNECT        (1 << (USB_DCTL_SDIS_SHIFT))
#define USB_DCTL_RWUSIG_SHIFT           (0)
#define USB_DCTL_RWUSIG_MASK            (1 << (USB_DCTL_RWUSIG_SHIFT))
#define USB_DCTL_RWUSIG_CONNECT         (0 << (USB_DCTL_RWUSIG_SHIFT))
#define USB_DCTL_RWUSIG_DISCONNECT      (1 << (USB_DCTL_RWUSIG_SHIFT))

  __IO uint32_t         DSTS;
#define USB_DSTS_FNSOF_SHIFT            (8)
#define USB_DSTS_FNSOF_MASK             (0x3ff << (USB_DSTS_FNSOF_SHIFT))
#define USB_DSTS_FNSOF_LSB_MASK         (1     << (USB_DSTS_FNSOF_SHIFT))
#define USB_DSTS_EERR_SHIFT             (3)
#define USB_DSTS_EERR_MASK              (1 << (USB_DSTS_EERR_SHIFT))
#define USB_DSTS_EERR_NO                (0 << (USB_DSTS_EERR_SHIFT))
#define USB_DSTS_EERR_YES               (1 << (USB_DSTS_EERR_SHIFT))
#define USB_DSTS_ENUMSPD_SHIFT          (1)
#define USB_DSTS_ENUMSPD_MASK           (3 << (USB_DSTS_ENUMSPD_SHIFT))
#define USB_DSTS_ENUMSPD_HIGH           (0 << (USB_DSTS_ENUMSPD_SHIFT))
#define USB_DSTS_ENUMSPD_FULL           (3 << (USB_DSTS_ENUMSPD_SHIFT))
#define USB_DSTS_SUSPSTS_SHIFT          (0)
#define USB_DSTS_SUSPSTS_MASK           (1 << (USB_DSTS_SUSPSTS_SHIFT))
#define USB_DSTS_SUSPSTS_NO             (0 << (USB_DSTS_SUSPSTS_SHIFT))
#define USB_DSTS_SUSPSTS_YES            (1 << (USB_DSTS_SUSPSTS_SHIFT))

  uint32_t              Reserved_80c;
  __IO uint32_t         DIEPMSK;
#define USB_DIEPMSK_NAKM_SHIFT          (12)
#define USB_DIEPMSK_NAKM_MASK           (1 << (USB_DIEPMSK_NAKM_SHIFT))
#define USB_DIEPMSK_NAKM_EN             (1 << (USB_DIEPMSK_NAKM_SHIFT))
#define USB_DIEPMSK_INEPNEM_SHIFT       (6)
#define USB_DIEPMSK_INEPNEM_MASK        (1 << (USB_DIEPMSK_INEPNEM_SHIFT))
#define USB_DIEPMSK_INEPNEM_EN          (1 << (USB_DIEPMSK_INEPNEM_SHIFT))
#define USB_DIEPMSK_INEPNMM_SHIFT       (5)
#define USB_DIEPMSK_INEPNMM_MASK        (1 << (USB_DIEPMSK_INEPNMM_SHIFT))
#define USB_DIEPMSK_INEPNMM_EN          (1 << (USB_DIEPMSK_INEPNMM_SHIFT))
#define USB_DIEPMSK_ITTXFEMSK_SHIFT     (4)
#define USB_DIEPMSK_ITTXFEMSK_MASK      (1 << (USB_DIEPMSK_ITTXFEMSK_SHIFT))
#define USB_DIEPMSK_ITTXFEMSK_EN        (1 << (USB_DIEPMSK_ITTXFEMSK_SHIFT))
#define USB_DIEPMSK_TOM_SHIFT           (3)
#define USB_DIEPMSK_TOM_MASK            (1 << (USB_DIEPMSK_TOM_SHIFT))
#define USB_DIEPMSK_TOM_EN              (1 << (USB_DIEPMSK_TOM_SHIFT))
#define USB_DIEPMSK_EPDM_SHIFT          (1)
#define USB_DIEPMSK_EPDM_MASK           (1 << (USB_DIEPMSK_EPDM_SHIFT))
#define USB_DIEPMSK_EPDM_EN             (1 << (USB_DIEPMSK_EPDM_SHIFT))
#define USB_DIEPMSK_XFRCM_SHIFT         (0)
#define USB_DIEPMSK_XFRCM_MASK          (1 << (USB_DIEPMSK_XFRCM_SHIFT))
#define USB_DIEPMSK_XFRCM_EN            (1 << (USB_DIEPMSK_XFRCM_SHIFT))
  __IO uint32_t         DOEPMSK;
#define USB_DOEPMSK_NYETM_SHIFT         (14)
#define USB_DOEPMSK_NYETM_MASK          (1 << (USB_DOEPMSK_NYETM_SHIFT))
#define USB_DOEPMSK_NYETM_EN            (1 << (USB_DOEPMSK_NYETM_SHIFT))
#define USB_DOEPMSK_BOIM_SHIFT          (9)
#define USB_DOEPMSK_BOIM_MASK           (1 << (USB_DOEPMSK_BOIM_SHIFT))
#define USB_DOEPMSK_BOIM_EN             (1 << (USB_DOEPMSK_BOIM_SHIFT))
#define USB_DOEPMSK_TXFURM_SHIFT        (8)
#define USB_DOEPMSK_TXFURM_MASK         (1 << (USB_DOEPMSK_TXFURM_SHIFT))
#define USB_DOEPMSK_TXFURM_EN           (1 << (USB_DOEPMSK_TXFURM_SHIFT))
#define USB_DOEPMSK_B2BSTUPM_SHIFT      (6)
#define USB_DOEPMSK_B2BSTUPM_MASK       (1 << (USB_DOEPMSK_B2BSTUPM_SHIFT))
#define USB_DOEPMSK_B2BSTUPM_EN         (1 << (USB_DOEPMSK_B2BSTUPM_SHIFT))
#define USB_DOEPMSK_ETEPDM_SHIFT        (4)
#define USB_DOEPMSK_ETEPDM_MASK         (1 << (USB_DOEPMSK_ETEPDM_SHIFT))
#define USB_DOEPMSK_ETEPDM_EN           (1 << (USB_DOEPMSK_ETEPDM_SHIFT))
#define USB_DOEPMSK_STUPM_SHIFT         (3)
#define USB_DOEPMSK_STUPM_MASK          (1 << (USB_DOEPMSK_STUPM_SHIFT))
#define USB_DOEPMSK_STUPM_EN            (1 << (USB_DOEPMSK_STUPM_SHIFT))
#define USB_DOEPMSK_EPDM_SHIFT          (1)
#define USB_DOEPMSK_EPDM_MASK           (1 << (USB_DOEPMSK_EPDM_SHIFT))
#define USB_DOEPMSK_EPDM_EN             (1 << (USB_DOEPMSK_EPDM_SHIFT))
#define USB_DOEPMSK_XFRCM_SHIFT         (0)
#define USB_DOEPMSK_XFRCM_MASK          (1 << (USB_DOEPMSK_XFRCM_SHIFT))
#define USB_DOEPMSK_XFRCM_EN            (1 << (USB_DOEPMSK_XFRCM_SHIFT))

  __IO uint32_t         DAINT;
#define USB_DAINT_OEPINT_SHIFT          (16)
#define USB_DAINT_OEPINT_MASK           (0xffff << (USB_DAINT_OEPINT_SHIFT))
#define USB_DAINT_OEPINT_BIT(x)         (((1<<(x)) << (USB_DAINT_OEPINT_SHIFT)) & (USB_DAINT_OEPINT_MASK))
#define USB_DAINT_IEPINT_SHIFT          (0)
#define USB_DAINT_IEPINT_MASK           (0xffff << (USB_DAINT_IEPINT_SHIFT))
#define USB_DAINT_IEPINT_BIT(x)         (((1<<(x)) << (USB_DAINT_IEPINT_SHIFT)) & (USB_DAINT_IEPINT_MASK))

  __IO uint32_t         DAINTMSK;
  uint32_t              reserved_820;
  uint32_t              reserved_824;
  __IO uint32_t         DVBUSDIS;
  __IO uint32_t         DVBUSPULSE;
  __IO uint32_t         DTHRCTL;
#define USB_DTHRCTL_RXTHRLEN_SHIFT      (17)
#define USB_DTHRCTL_RXTHRLEN_MASK       (0x3ff << (USB_DTHRCTL_RXTHRLEN_SHIFT))
#define USB_DTHRCTL_RXTHRLEN_VAL(x)     (((x) << (USB_DTHRCTL_RXTHRLEN_SHIFT))&USB_DTHRCTL_RXTHRLEN_MASK)
#define USB_DTHRCTL_RXTHREN_SHIFT       (16)
#define USB_DTHRCTL_RXTHREN_MASK        (1 << (USB_DTHRCTL_RXTHREN_SHIFT))
#define USB_DTHRCTL_RXTHREN_NO          (0 << (USB_DTHRCTL_RXTHREN_SHIFT))
#define USB_DTHRCTL_RXTHREN_YES         (1 << (USB_DTHRCTL_RXTHREN_SHIFT))
#define USB_DTHRCTL_TXTHRLEN_SHIFT      (2)
#define USB_DTHRCTL_TXTHRLEN_MASK       (0x3ff << (USB_DTHRCTL_TXTHRLEN_SHIFT))
#define USB_DTHRCTL_TXTHRLEN_VAL(x)     (((x) << (USB_DTHRCTL_TXTHRLEN_SHIFT))&USB_DTHRCTL_TXTHRLEN_MASK)
#define USB_DTHRCTL_ISOTHREN_SHIFT      (1)
#define USB_DTHRCTL_ISOTHREN_MASK       (1 << (USB_DTHRCTL_ISOTHREN_SHIFT))
#define USB_DTHRCTL_ISOTHREN_NO         (0 << (USB_DTHRCTL_ISOTHREN_SHIFT))
#define USB_DTHRCTL_ISOTHREN_YES        (1 << (USB_DTHRCTL_ISOTHREN_SHIFT))
#define USB_DTHRCTL_NONISOTHREN_SHIFT   (0)
#define USB_DTHRCTL_NONISOTHREN_MASK    (1 << (USB_DTHRCTL_NONISOTHREN_SHIFT))
#define USB_DTHRCTL_NONISOTHREN_NO      (0 << (USB_DTHRCTL_NONISOTHREN_SHIFT))
#define USB_DTHRCTL_NONISOTHREN_YES     (1 << (USB_DTHRCTL_NONISOTHREN_SHIFT))

  __IO uint32_t         DIEPEMPMSK;
  __IO uint32_t         DEACHINT;
  __IO uint32_t         DEACHINTMSK;
  uint32_t              reserved_840;
  __IO uint32_t         DINEP1MSK;
  uint32_t              reserved_848;
  __IO uint32_t         DOUTEP1MSK;
  uint32_t              reserved_850[0x2c];

  /* 0x900 */
  stm32Usb320aDevEp_t   in[16];         /* 0x20 * 0x10pcs = 0x200 */

  /* 0xb00 */
  stm32Usb320aDevEp_t   out[16];        /* 0x20 * 0x10pcs = 0x200 */

  /* 0xd00 */
  uint32_t              reserved_d00[0x40];


  /* 0xe00 */
  __IO uint32_t         PCGCCTL;
#define USB_PCGCCTL_STOPCLK_SHIFT       (0)
#define USB_PCGCCTL_STOPCLK_MASK        (1 << (USB_PCGCCTL_STOPCLK_SHIFT))
#define USB_PCGCCTL_STOPCLK_NO          (0 << (USB_PCGCCTL_STOPCLK_SHIFT))
#define USB_PCGCCTL_STOPCLK_YES         (1 << (USB_PCGCCTL_STOPCLK_SHIFT))
  uint32_t              reserved_e04[0x7f];

  /* 0x1000  FIFO */
#define USB_FIFO_SIZE   0x1000
  __IO uint32_t         DFIFO[15][USB_FIFO_SIZE/4];

} stm32Dev_USB;



#define USB_OTG_CORE_ID_310A            0x4F54310A
#define USB_OTG_CORE_ID_320A            0x4F54320A


/*** 0x0c OTG_GUSBCFG */
#define USB_GUSBCFG_FDMOD_SHIFT         (30)
#define USB_GUSBCFG_FDMOD_MASK          (1 << (USB_GUSBCFG_FDMOD_SHIFT))
#define USB_GUSBCFG_FDMOD_NO            (0 << (USB_GUSBCFG_FDMOD_SHIFT))
#define USB_GUSBCFG_FDMOD_YES           (1 << (USB_GUSBCFG_FDMOD_SHIFT))
#define USB_GUSBCFG_FHMOD_SHIFT         (29)
#define USB_GUSBCFG_FHMOD_MASK          (1 << (USB_GUSBCFG_FHMOD_SHIFT))
#define USB_GUSBCFG_FHMOD_NO            (0 << (USB_GUSBCFG_FHMOD_SHIFT))
#define USB_GUSBCFG_FHMOD_YES           (1 << (USB_GUSBCFG_FHMOD_SHIFT))
#define USB_GUSBCFG_TRDT_SHIFT          (10)
#define USB_GUSBCFG_TRDT_MASK           (15 << (USB_GUSBCFG_TRDT_SHIFT))
#define USB_GUSBCFG_TRDT_OVER32_0MHZ    (6 << (USB_GUSBCFG_TRDT_SHIFT))
#define USB_GUSBCFG_TRDT_27_5TO32_0MHZ  (7 << (USB_GUSBCFG_TRDT_SHIFT))
#define USB_GUSBCFG_TRDT_24_0TO27_5MHZ  (8 << (USB_GUSBCFG_TRDT_SHIFT))
#define USB_GUSBCFG_TRDT_21_8TO24_0MHZ  (9 << (USB_GUSBCFG_TRDT_SHIFT))
#define USB_GUSBCFG_TRDT_20_0TO21_8MHZ  (10 << (USB_GUSBCFG_TRDT_SHIFT))
#define USB_GUSBCFG_TRDT_18_5TO20_0MHZ  (11 << (USB_GUSBCFG_TRDT_SHIFT))
#define USB_GUSBCFG_TRDT_17_2TO18_5MHZ  (12 << (USB_GUSBCFG_TRDT_SHIFT))
#define USB_GUSBCFG_TRDT_16_0TO17_2MHZ  (13 << (USB_GUSBCFG_TRDT_SHIFT))
#define USB_GUSBCFG_TRDT_15_0TO16_0MHZ  (14 << (USB_GUSBCFG_TRDT_SHIFT))
#define USB_GUSBCFG_TRDT_14_2TO15_0MHZ  (15 << (USB_GUSBCFG_TRDT_SHIFT))
#define USB_GUSBCFG_PHYSEL_SHIFT        (6)
#define USB_GUSBCFG_PHYSEL_MASK         (1 << (USB_GUSBCFG_PHYSEL_SHIFT))
#define USB_GUSBCFG_PHYSEL_NO           (0 << (USB_GUSBCFG_PHYSEL_SHIFT))
#define USB_GUSBCFG_PHYSEL_YES          (1 << (USB_GUSBCFG_PHYSEL_SHIFT))


#endif
