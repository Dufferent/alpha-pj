#ifndef __REGISTOR_H
#define __REGISTOR_H


/***************************department**********************************/
/* clk base addr */
#define  CCM_0 *( ( volatile unsigned int *)0x20C4068U )
#define  CCM_1 *( ( volatile unsigned int *)0x20C406CU )
#define  CCM_2 *( ( volatile unsigned int *)0x20C4070U )
#define  CCM_3 *( ( volatile unsigned int *)0x20C4074U )
#define  CCM_4 *( ( volatile unsigned int *)0x20C4078U )
#define  CCM_5 *( ( volatile unsigned int *)0x20C407CU )
#define  CCM_6 *( ( volatile unsigned int *)0x20C4080U )

/*clk ctl registor*/
#define  CCM_CCSR   *( ( volatile unsigned int *)0x20C400CU )
#define  ANALOG_ARM *( ( volatile unsigned int *)0x20C8000U )
#define  CCM_CACCR  *( ( volatile unsigned int *)0x20C4010U )
#define  ANALOG_PDF_528 *( ( volatile unsigned int *)0x20C8100U )
#define  ANALOG_PDF_480 *( ( volatile unsigned int *)0x20C80F0U )
#define  CCM_CBCMR  *( ( volatile unsigned int *)0x20C4018U )
#define  CCM_CBCDR  *( ( volatile unsigned int *)0x20C4014U )
#define  CCM_CDHIPR *( ( volatile unsigned int *)0x20C4048U )
#define  CCM_CSCMR1 *( ( volatile unsigned int *)0x20C401CU )
#define  CCM_CSCMR2 *( ( volatile unsigned int *)0x20C4020U )
#define  CCM_CSCDR1 *( ( volatile unsigned int *)0x20C4024U )

/***************************department**********************************/
/* gpio base addr */

/* GPIO1_IO03->led0 */
/* IO初始化的两个寄存器地址 */
#define SW_MUX_CTL_GPIO1_IO03 *( ( volatile unsigned int *)0x20E0068U )
#define SW_PAD_CTL_GPIO1_IO03 *( ( volatile unsigned int *)0x20E02F4U )

/* GPIO! IO18->key0  */
/* USART1 CTR addr */
#define SW_MUX_CTL_USART1_CTRS *( ( volatile unsigned int *)0x20E008CU )
#define SW_PAD_CTL_USART1_CTRS *( ( volatile unsigned int *)0x20E0318U )



/* uart port addr*/
#define SW_MUX_CTL_PAD_UART1_TX_DATA  *( ( volatile unsigned int *)0x20E0084U )
#define SW_PAD_CTL_PAD_UART1_TX_DATA  *( ( volatile unsigned int *)0x20E0310U )
#define SW_MUX_CTL_PAD_UART1_RX_DATA  *( ( volatile unsigned int *)0x20E0088U )
#define SW_PAD_CTL_PAD_UART1_RX_DATA  *( ( volatile unsigned int *)0x20E0314U )
/* uart registors */
/* uart structor */
typedef struct{
  volatile unsigned int UART1_URXD;
           unsigned char void_space1[60];/* (16-1) * 4 */
  volatile unsigned int UART1_UTXD;
           unsigned char void_space2[60];/* (16-1) * 4 */
  volatile unsigned int UART1_UCR1;
  volatile unsigned int UART1_UCR2;
  volatile unsigned int UART1_UCR3;
  volatile unsigned int UART1_UCR4;
  volatile unsigned int UART1_UFCR;
  volatile unsigned int UART1_USR1;
  volatile unsigned int UART1_USR2;
  volatile unsigned int UART1_UESC;
  volatile unsigned int UART1_UTIM;
  volatile unsigned int UART1_UBIR;
  volatile unsigned int UART1_UBMR;
  volatile unsigned int UART1_UBRC;
  volatile unsigned int UART1_ONEMS;
  volatile unsigned int UART1_UTS;
  volatile unsigned int UART1_UMCR;
}uart1;
/* uart reg addr base */
#define UART_BASE (0x2020000U)
#define UART_1    ((uart1*)UART_BASE)
#define UART1_SELECT_INPUT *( ( volatile unsigned int *)0X20E0624U )



/* gpio registors*/
#define GPIO1_DR   *( ( volatile unsigned int *)0X209C000U )
#define GPIO1_GDR  *( ( volatile unsigned int *)0X209C004U )
#define GPIO1_PSR  *( ( volatile unsigned int *)0X209C008U )
#define GPIO1_ICR1 *( ( volatile unsigned int *)0X209C00CU )
#define GPIO1_ICR2 *( ( volatile unsigned int *)0X209C010U )
#define GPIO1_IMR  *( ( volatile unsigned int *)0X209C014U )
#define GPIO1_ISR  *( ( volatile unsigned int *)0X209C018U )
#define GPIO1_EDG  *( ( volatile unsigned int *)0X209C01CU )

/***************************department**********************************/
/* epit1 and 2 registors*/
/* 弄个结构体玩玩 */
/* make a structor for fun!...haha...*/
typedef struct{
  /* epit1 */
  volatile unsigned int EPIT1_CR;
  volatile unsigned int EPIT1_SR;
  volatile unsigned int EPIT1_LR;
  volatile unsigned int EPIT1_CMPR;
  volatile unsigned int EPIT1_CNR;
}epit1_reg;

typedef struct{
    /* epit2 */
  volatile unsigned int EPIT2_CR;
  volatile unsigned int EPIT2_SR;
  volatile unsigned int EPIT2_LR;
  volatile unsigned int EPIT2_CMPR;
  volatile unsigned int EPIT2_CNR;
}epit2_reg;
/* epit1 registor base addr defination */
#define epit1_reg_base  (0x20D0000U)
/* point structor defineation */
#define epit1 ((epit1_reg*)epit1_reg_base)

/* epit2 registor base addr defination */
#define epit2_reg_base  (0x20D4000U)
/* point structor defineation */
#define epit2 ((epit2_reg*)epit2_reg_base)

/***************************department**********************************/
typedef struct
{
  /* data */
  volatile unsigned int GPT1_CR;
  volatile unsigned int GPT1_PR;
  volatile unsigned int GPT1_SR;
  volatile unsigned int GPT1_IR;
  volatile unsigned int GPT1_OCR1;
  volatile unsigned int GPT1_OCR2;
  volatile unsigned int GPT1_OCR3;
  volatile unsigned int GPT1_ICR1;
  volatile unsigned int GPT1_ICR2;
  volatile unsigned int GPT1_CNT;
}GPT1_TYPE;

#define GPT1_BASE (0x2098000U)
#define GPT1 ((GPT1_TYPE*)GPT1_BASE)


/***************************department**********************************/

/* interrupt code table*/
/** Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS 160                /**< Number of interrupts in the Vector table */

typedef enum IRQn {
  /* Auxiliary constants */
  NotAvail_IRQn                = -128,             /**< Not available device specific interrupt */

  /* Core interrupts */
  Software0_IRQn               = 0,                /**< Cortex-A7 Software Generated Interrupt 0 */
  Software1_IRQn               = 1,                /**< Cortex-A7 Software Generated Interrupt 1 */
  Software2_IRQn               = 2,                /**< Cortex-A7 Software Generated Interrupt 2 */
  Software3_IRQn               = 3,                /**< Cortex-A7 Software Generated Interrupt 3 */
  Software4_IRQn               = 4,                /**< Cortex-A7 Software Generated Interrupt 4 */
  Software5_IRQn               = 5,                /**< Cortex-A7 Software Generated Interrupt 5 */
  Software6_IRQn               = 6,                /**< Cortex-A7 Software Generated Interrupt 6 */
  Software7_IRQn               = 7,                /**< Cortex-A7 Software Generated Interrupt 7 */
  Software8_IRQn               = 8,                /**< Cortex-A7 Software Generated Interrupt 8 */
  Software9_IRQn               = 9,                /**< Cortex-A7 Software Generated Interrupt 9 */
  Software10_IRQn              = 10,               /**< Cortex-A7 Software Generated Interrupt 10 */
  Software11_IRQn              = 11,               /**< Cortex-A7 Software Generated Interrupt 11 */
  Software12_IRQn              = 12,               /**< Cortex-A7 Software Generated Interrupt 12 */
  Software13_IRQn              = 13,               /**< Cortex-A7 Software Generated Interrupt 13 */
  Software14_IRQn              = 14,               /**< Cortex-A7 Software Generated Interrupt 14 */
  Software15_IRQn              = 15,               /**< Cortex-A7 Software Generated Interrupt 15 */
  VirtualMaintenance_IRQn      = 25,               /**< Cortex-A7 Virtual Maintenance Interrupt */
  HypervisorTimer_IRQn         = 26,               /**< Cortex-A7 Hypervisor Timer Interrupt */
  VirtualTimer_IRQn            = 27,               /**< Cortex-A7 Virtual Timer Interrupt */
  LegacyFastInt_IRQn           = 28,               /**< Cortex-A7 Legacy nFIQ signal Interrupt */
  SecurePhyTimer_IRQn          = 29,               /**< Cortex-A7 Secure Physical Timer Interrupt */
  NonSecurePhyTimer_IRQn       = 30,               /**< Cortex-A7 Non-secure Physical Timer Interrupt */
  LegacyIRQ_IRQn               = 31,               /**< Cortex-A7 Legacy nIRQ Interrupt */

  /* Device specific interrupts */
  IOMUXC_IRQn                  = 32,               /**< General Purpose Register 1 from IOMUXC. Used to notify cores on exception condition while boot. */
  DAP_IRQn                     = 33,               /**< Debug Access Port interrupt request. */
  SDMA_IRQn                    = 34,               /**< SDMA interrupt request from all channels. */
  TSC_IRQn                     = 35,               /**< TSC interrupt. */
  SNVS_IRQn                    = 36,               /**< Logic OR of SNVS_LP and SNVS_HP interrupts. */
  LCDIF_IRQn                   = 37,               /**< LCDIF sync interrupt. */
  RNGB_IRQn                    = 38,               /**< RNGB interrupt. */
  CSI_IRQn                     = 39,               /**< CMOS Sensor Interface interrupt request. */
  PXP_IRQ0_IRQn                = 40,               /**< PXP interrupt pxp_irq_0. */
  SCTR_IRQ0_IRQn               = 41,               /**< SCTR compare interrupt ipi_int[0]. */
  SCTR_IRQ1_IRQn               = 42,               /**< SCTR compare interrupt ipi_int[1]. */
  WDOG3_IRQn                   = 43,               /**< WDOG3 timer reset interrupt request. */
  Reserved44_IRQn              = 44,               /**< Reserved */
  APBH_IRQn                    = 45,               /**< DMA Logical OR of APBH DMA channels 0-3 completion and error interrupts. */
  WEIM_IRQn                    = 46,               /**< WEIM interrupt request. */
  RAWNAND_BCH_IRQn             = 47,               /**< BCH operation complete interrupt. */
  RAWNAND_GPMI_IRQn            = 48,               /**< GPMI operation timeout error interrupt. */
  UART6_IRQn                   = 49,               /**< UART6 interrupt request. */
  PXP_IRQ1_IRQn                = 50,               /**< PXP interrupt pxp_irq_1. */
  SNVS_Consolidated_IRQn       = 51,               /**< SNVS consolidated interrupt. */
  SNVS_Security_IRQn           = 52,               /**< SNVS security interrupt. */
  CSU_IRQn                     = 53,               /**< CSU interrupt request 1. Indicates to the processor that one or more alarm inputs were asserted. */
  USDHC1_IRQn                  = 54,               /**< USDHC1 (Enhanced SDHC) interrupt request. */
  USDHC2_IRQn                  = 55,               /**< USDHC2 (Enhanced SDHC) interrupt request. */
  SAI3_RX_IRQn                 = 56,               /**< SAI3 interrupt ipi_int_sai_rx. */
  SAI3_TX_IRQn                 = 57,               /**< SAI3 interrupt ipi_int_sai_tx. */
  UART1_IRQn                   = 58,               /**< UART1 interrupt request. */
  UART2_IRQn                   = 59,               /**< UART2 interrupt request. */
  UART3_IRQn                   = 60,               /**< UART3 interrupt request. */
  UART4_IRQn                   = 61,               /**< UART4 interrupt request. */
  UART5_IRQn                   = 62,               /**< UART5 interrupt request. */
  eCSPI1_IRQn                  = 63,               /**< eCSPI1 interrupt request. */
  eCSPI2_IRQn                  = 64,               /**< eCSPI2 interrupt request. */
  eCSPI3_IRQn                  = 65,               /**< eCSPI3 interrupt request. */
  eCSPI4_IRQn                  = 66,               /**< eCSPI4 interrupt request. */
  I2C4_IRQn                    = 67,               /**< I2C4 interrupt request. */
  I2C1_IRQn                    = 68,               /**< I2C1 interrupt request. */
  I2C2_IRQn                    = 69,               /**< I2C2 interrupt request. */
  I2C3_IRQn                    = 70,               /**< I2C3 interrupt request. */
  UART7_IRQn                   = 71,               /**< UART-7 ORed interrupt. */
  UART8_IRQn                   = 72,               /**< UART-8 ORed interrupt. */
  Reserved73_IRQn              = 73,               /**< Reserved */
  USB_OTG2_IRQn                = 74,               /**< USBO2 USB OTG2 */
  USB_OTG1_IRQn                = 75,               /**< USBO2 USB OTG1 */
  USB_PHY1_IRQn                = 76,               /**< UTMI0 interrupt request. */
  USB_PHY2_IRQn                = 77,               /**< UTMI1 interrupt request. */
  DCP_IRQ_IRQn                 = 78,               /**< DCP interrupt request dcp_irq. */
  DCP_VMI_IRQ_IRQn             = 79,               /**< DCP interrupt request dcp_vmi_irq. */
  DCP_SEC_IRQ_IRQn             = 80,               /**< DCP interrupt request secure_irq. */
  TEMPMON_IRQn                 = 81,               /**< Temperature Monitor Temperature Sensor (temperature greater than threshold) interrupt request. */
  ASRC_IRQn                    = 82,               /**< ASRC interrupt request. */
  ESAI_IRQn                    = 83,               /**< ESAI interrupt request. */
  SPDIF_IRQn                   = 84,               /**< SPDIF interrupt. */
  Reserved85_IRQn              = 85,               /**< Reserved */
  PMU_IRQ1_IRQn                = 86,               /**< Brown-out event on either the 1.1, 2.5 or 3.0 regulators. */
  GPT1_IRQn                    = 87,               /**< Logical OR of GPT1 rollover interrupt line, input capture 1 and 2 lines, output compare 1, 2, and 3 interrupt lines. */
  EPIT1_IRQn                   = 88,               /**< EPIT1 output compare interrupt. */
  EPIT2_IRQn                   = 89,               /**< EPIT2 output compare interrupt. */
  GPIO1_INT7_IRQn              = 90,               /**< INT7 interrupt request. */
  GPIO1_INT6_IRQn              = 91,               /**< INT6 interrupt request. */
  GPIO1_INT5_IRQn              = 92,               /**< INT5 interrupt request. */
  GPIO1_INT4_IRQn              = 93,               /**< INT4 interrupt request. */
  GPIO1_INT3_IRQn              = 94,               /**< INT3 interrupt request. */
  GPIO1_INT2_IRQn              = 95,               /**< INT2 interrupt request. */
  GPIO1_INT1_IRQn              = 96,               /**< INT1 interrupt request. */
  GPIO1_INT0_IRQn              = 97,               /**< INT0 interrupt request. */
  GPIO1_Combined_0_15_IRQn     = 98,               /**< Combined interrupt indication for GPIO1 signals 0 - 15. */
  GPIO1_Combined_16_31_IRQn    = 99,               /**< Combined interrupt indication for GPIO1 signals 16 - 31. */
  GPIO2_Combined_0_15_IRQn     = 100,              /**< Combined interrupt indication for GPIO2 signals 0 - 15. */
  GPIO2_Combined_16_31_IRQn    = 101,              /**< Combined interrupt indication for GPIO2 signals 16 - 31. */
  GPIO3_Combined_0_15_IRQn     = 102,              /**< Combined interrupt indication for GPIO3 signals 0 - 15. */
  GPIO3_Combined_16_31_IRQn    = 103,              /**< Combined interrupt indication for GPIO3 signals 16 - 31. */
  GPIO4_Combined_0_15_IRQn     = 104,              /**< Combined interrupt indication for GPIO4 signals 0 - 15. */
  GPIO4_Combined_16_31_IRQn    = 105,              /**< Combined interrupt indication for GPIO4 signals 16 - 31. */
  GPIO5_Combined_0_15_IRQn     = 106,              /**< Combined interrupt indication for GPIO5 signals 0 - 15. */
  GPIO5_Combined_16_31_IRQn    = 107,              /**< Combined interrupt indication for GPIO5 signals 16 - 31. */
  Reserved108_IRQn             = 108,              /**< Reserved */
  Reserved109_IRQn             = 109,              /**< Reserved */
  Reserved110_IRQn             = 110,              /**< Reserved */
  Reserved111_IRQn             = 111,              /**< Reserved */
  WDOG1_IRQn                   = 112,              /**< WDOG1 timer reset interrupt request. */
  WDOG2_IRQn                   = 113,              /**< WDOG2 timer reset interrupt request. */
  KPP_IRQn                     = 114,              /**< Key Pad interrupt request. */
  PWM1_IRQn                    = 115,              /**< hasRegInstance(`PWM1`)?`Cumulative interrupt line for PWM1. Logical OR of rollover, compare, and FIFO waterlevel crossing interrupts.`:`Reserved`) */
  PWM2_IRQn                    = 116,              /**< hasRegInstance(`PWM2`)?`Cumulative interrupt line for PWM2. Logical OR of rollover, compare, and FIFO waterlevel crossing interrupts.`:`Reserved`) */
  PWM3_IRQn                    = 117,              /**< hasRegInstance(`PWM3`)?`Cumulative interrupt line for PWM3. Logical OR of rollover, compare, and FIFO waterlevel crossing interrupts.`:`Reserved`) */
  PWM4_IRQn                    = 118,              /**< hasRegInstance(`PWM4`)?`Cumulative interrupt line for PWM4. Logical OR of rollover, compare, and FIFO waterlevel crossing interrupts.`:`Reserved`) */
  CCM_IRQ1_IRQn                = 119,              /**< CCM interrupt request ipi_int_1. */
  CCM_IRQ2_IRQn                = 120,              /**< CCM interrupt request ipi_int_2. */
  GPC_IRQn                     = 121,              /**< GPC interrupt request 1. */
  Reserved122_IRQn             = 122,              /**< Reserved */
  SRC_IRQn                     = 123,              /**< SRC interrupt request src_ipi_int_1. */
  Reserved124_IRQn             = 124,              /**< Reserved */
  Reserved125_IRQn             = 125,              /**< Reserved */
  CPU_PerformanceUnit_IRQn     = 126,              /**< Performance Unit interrupt ~ipi_pmu_irq_b. */
  CPU_CTI_Trigger_IRQn         = 127,              /**< CTI trigger outputs interrupt ~ipi_cti_irq_b. */
  SRC_Combined_IRQn            = 128,              /**< Combined CPU wdog interrupts (4x) out of SRC. */
  SAI1_IRQn                    = 129,              /**< SAI1 interrupt request. */
  SAI2_IRQn                    = 130,              /**< SAI2 interrupt request. */
  Reserved131_IRQn             = 131,              /**< Reserved */
  ADC1_IRQn                    = 132,              /**< ADC1 interrupt request. */
  ADC_5HC_IRQn                 = 133,              /**< ADC_5HC interrupt request. */
  Reserved134_IRQn             = 134,              /**< Reserved */
  Reserved135_IRQn             = 135,              /**< Reserved */
  SJC_IRQn                     = 136,              /**< SJC interrupt from General Purpose register. */
  CAAM_Job_Ring0_IRQn          = 137,              /**< CAAM job ring 0 interrupt ipi_caam_irq0. */
  CAAM_Job_Ring1_IRQn          = 138,              /**< CAAM job ring 1 interrupt ipi_caam_irq1. */
  QSPI_IRQn                    = 139,              /**< QSPI1 interrupt request ipi_int_ored. */
  TZASC_IRQn                   = 140,              /**< TZASC (PL380) interrupt request. */
  GPT2_IRQn                    = 141,              /**< Logical OR of GPT2 rollover interrupt line, input capture 1 and 2 lines, output compare 1, 2 and 3 interrupt lines. */
  CAN1_IRQn                    = 142,              /**< Combined interrupt of ini_int_busoff,ini_int_error,ipi_int_mbor,ipi_int_txwarning and ipi_int_waken */
  CAN2_IRQn                    = 143,              /**< Combined interrupt of ini_int_busoff,ini_int_error,ipi_int_mbor,ipi_int_txwarning and ipi_int_waken */
  Reserved144_IRQn             = 144,              /**< Reserved */
  Reserved145_IRQn             = 145,              /**< Reserved */
  PWM5_IRQn                    = 146,              /**< Cumulative interrupt line. OR of Rollover Interrupt line, Compare Interrupt line and FIFO Waterlevel crossing interrupt line */
  PWM6_IRQn                    = 147,              /**< Cumulative interrupt line. OR of Rollover Interrupt line, Compare Interrupt line and FIFO Waterlevel crossing interrupt line */
  PWM7_IRQn                    = 148,              /**< Cumulative interrupt line. OR of Rollover Interrupt line, Compare Interrupt line and FIFO Waterlevel crossing interrupt line */
  PWM8_IRQn                    = 149,              /**< Cumulative interrupt line. OR of Rollover Interrupt line, Compare Interrupt line and FIFO Waterlevel crossing interrupt line */
  ENET1_IRQn                   = 150,              /**< ENET1 interrupt */
  ENET1_1588_IRQn              = 151,              /**< ENET1 1588 Timer interrupt [synchronous] request. */
  ENET2_IRQn                   = 152,              /**< ENET2 interrupt */
  ENET2_1588_IRQn              = 153,              /**< MAC 0 1588 Timer interrupt [synchronous] request. */
  Reserved154_IRQn             = 154,              /**< Reserved */
  Reserved155_IRQn             = 155,              /**< Reserved */
  Reserved156_IRQn             = 156,              /**< Reserved */
  Reserved157_IRQn             = 157,              /**< Reserved */
  Reserved158_IRQn             = 158,              /**< Reserved */
  PMU_IRQ2_IRQn                = 159               /**< Brown-out event on either core, gpu or soc regulators. */
} IRQn_Type;

/*!
 * @}
 */ /* end of group Interrupt_vector_numbers */


/* ----------------------------------------------------------------------------
   -- Configuration of the Cortex-A7 Processor and Core Peripherals
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Cortex_Core_Configuration Configuration of the Cortex-A7 Processor and Core Peripherals
 * @{
 */

#define __CA7_REV                      0x0005    /**< Core revision r0p5 */
#define __GIC_PRIO_BITS                5         /**< Number of Bits used for Priority Levels */
#define __FPU_PRESENT                  1         /**< FPU present or not */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */

/*all types defination*/
#define __I     volatile
#define __O     volatile
#define __IO    volatile

#define ON      1
#define OFF     0

typedef signed char     int8_t;
typedef signed short    int16_t;
typedef signed int      int32_t;
typedef unsigned char   uint8_t;
typedef unsigned short  uint16_t;
typedef unsigned int    uint32_t;
typedef unsigned long long   uint64_t;

typedef signed char         s8;
typedef signed short        s16;
typedef signed int          s32;
typedef signed long long    s64;
typedef unsigned char       u8;
typedef unsigned short      u16;
typedef unsigned int        u32;
typedef unsigned long long  u64;

#endif