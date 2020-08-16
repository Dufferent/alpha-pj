#include "../env/include.h"


/*function defination*/
void clk_enable(void)
{
    /* all clk is enabled */
    CCM_0 = 0xFFFFFFFF;
    CCM_1 = 0xFFFFFFFF;
    CCM_2 = 0xFFFFFFFF;
    CCM_3 = 0xFFFFFFFF;
    CCM_4 = 0xFFFFFFFF;
    CCM_5 = 0xFFFFFFFF;
    CCM_6 = 0xFFFFFFFF;
}

/* system clk initure */
void systemclk_initure(void)
{
    unsigned int reg = 0;
    /* 1、设置 ARM 内核时钟为 528MHz */
    if( (CCM_CCSR >> 2)&0x1 == 0 )/* if pll1 clk */
    {
         CCM_CCSR &= ~(1 << 8); /* set step clk source */
         CCM_CCSR |= (1 << 2);  /* 配置 pll1_sw_clk 时钟源为 step_clk */
    }
    ANALOG_ARM =  (1 << 13) | ((88 << 0) & 0X7F);
    CCM_CCSR  &= ~(1 << 2);/* 将 pll_sw_clk 时钟切换回 pll1_main_clk */
    CCM_CACCR  = 1;        /* ARM 内核时钟为 pll1_sw_clk/2=1056/2=528Mhz */
    /* 2、设置 PLL2(SYS PLL)各个 PFD */
    reg = ANALOG_PDF_528;
    reg &= ~(0X3F3F3F3F); /* 清除原来的设置 */
    reg |= 32<<24; /* PLL2_PFD3=528*18/32=297Mhz */
    reg |= 24<<16; /* PLL2_PFD2=528*18/24=396Mhz */
    reg |= 16<<8; /* PLL2_PFD1=528*18/16=594Mhz */
    reg |= 27<<0; /* PLL2_PFD0=528*18/27=352Mhz */
    ANALOG_PDF_528=reg; /* 设置 PLL2_PFD0~3 */

    /* 3、设置 PLL3(USB1)各个 PFD */
    reg = 0; /* 清零 */
    reg = ANALOG_PDF_480;
    reg &= ~(0X3F3F3F3F); /* 清除原来的设置 */
    reg |= 19<<24; /* PLL3_PFD3=480*18/19=454.74Mhz */
    reg |= 17<<16; /* PLL3_PFD2=480*18/17=508.24Mhz */
    reg |= 16<<8; /* PLL3_PFD1=480*18/16=540Mhz */
    reg |= 12<<0; /* PLL3_PFD0=480*18/12=720Mhz */
    ANALOG_PDF_480=reg; /* 设置 PLL3_PFD0~3 */ 

    /* 4、设置 AHB 时钟 最小 6Mhz， 最大 132Mhz */
    CCM_CBCMR &= ~(3 << 18); /* 清除设置*/
    CCM_CBCMR |= (1 << 18); /* pre_periph_clk=PLL2_PFD2=396MHz */
    CCM_CBCMR &= ~(1 << 25); /* periph_clk=pre_periph_clk=396MHz */
    while(CCM_CDHIPR & (1 << 5));/* 等待握手完成 */

    /* 修改 AHB_PODF 位的时候需要先禁止 AHB_CLK_ROOT 的输出，但是
    * 我没有找到关闭 AHB_CLK_ROOT 输出的的寄存器，所以就没法设置。
    * 下面设置 AHB_PODF 的代码仅供学习参考不能直接拿来使用！！
    * 内部 boot rom 将 AHB_PODF 设置为了 3 分频，即使我们不设置 AHB_PODF，
    * AHB_ROOT_CLK 也依旧等于 396/3=132Mhz。
    */
    #if 0
    /* 要先关闭 AHB_ROOT_CLK 输出，否则时钟设置会出错 */
    CCM->CBCDR &= ~(7 << 10);/* CBCDR 的 AHB_PODF 清零 */
    CCM->CBCDR |= 2 << 10; /* AHB_PODF 3 分频，AHB_CLK_ROOT=132MHz */
    while(CCM->CDHIPR & (1 << 1));/* 等待握手完成 */
    #endif
    /* 5、设置 IPG_CLK_ROOT 最小 3Mhz，最大 66Mhz */
    CCM_CBCDR &= ~(3 << 8); /* CBCDR 的 IPG_PODF 清零 */
    CCM_CBCDR |= 1 << 8; /* IPG_PODF 2 分频，IPG_CLK_ROOT=66MHz */

    /* 6、设置 PERCLK_CLK_ROOT 时钟 */
    CCM_CSCMR1 &= ~(1 << 6); /* PERCLK_CLK_ROOT 时钟源为 IPG */
    CCM_CSCMR1 &= ~(7 << 0); /* PERCLK_PODF 位清零，即 1 分频 */

}