#ifndef __REGISTOR_H
#define __REGISTOR_H

/* clk base addr */
#define  CCM_0 *( ( volatile unsigned int *)0x20C4068U )
#define  CCM_1 *( ( volatile unsigned int *)0x20C406CU )
#define  CCM_2 *( ( volatile unsigned int *)0x20C4070U )
#define  CCM_3 *( ( volatile unsigned int *)0x20C4074U )
#define  CCM_4 *( ( volatile unsigned int *)0x20C4078U )
#define  CCM_5 *( ( volatile unsigned int *)0x20C407CU )
#define  CCM_6 *( ( volatile unsigned int *)0x20C4080U )

/* gpio base addr */
/* GPIO1_IO03->led0 */
/* IO初始化的两个寄存器地址 */
#define SW_MUX_CTL_GPIO1_IO03 *( ( volatile unsigned int *)0x20E0068U )
#define SW_PAD_CTL_GPIO1_IO03 *( ( volatile unsigned int *)0x20E02F4U )
/* gpio registoers*/
#define GPIO1_DR   *( ( volatile unsigned int *)0X209C000U )
#define GPIO1_GDR  *( ( volatile unsigned int *)0X209C004U )
#define GPIO1_PSR  *( ( volatile unsigned int *)0X209C008U )
#define GPIO1_ICR1 *( ( volatile unsigned int *)0X209C00CU )
#define GPIO1_ICR2 *( ( volatile unsigned int *)0X209C010U )
#define GPIO1_IMR  *( ( volatile unsigned int *)0X209C014U )
#define GPIO1_ISR  *( ( volatile unsigned int *)0X209C018U )
#define GPIO1_EDG  *( ( volatile unsigned int *)0X209C01CU )



#endif
