#include "../env/include.h"

/* function defination*/
void epit1_init(unsigned int frac ,unsigned int value)
{
    /* frac 分频系数 12bit 最大值不能超过 4095 0xFFF Hex*/
    if(frac > 0xFFF)/* 输入限制 */
        frac = 0xFFF;
    /* 清空CR寄存器 */
    epit1->EPIT1_CR = 0;
    //epit1->EPIT1_CR &= ~(0x3<<24);
    /* 设置CR寄存器24~25bit为01 选择 66Mhz 时钟 */
    epit1->EPIT1_CR |=  (0x1<<24);
    /* 清空CR寄存器4～15bit */
    epit1->EPIT1_CR &= ~(0xFFF<<4);
    /* 配置CR寄存器4～15bit为 frac value*/
    epit1->EPIT1_CR |= (frac<<4);
    /* 配置定时器工作模式 < CR bit3 > 0:1 ? free_running:get_and_forget*/
    epit1->EPIT1_CR |= (1<<3);
    /* 使能比较模式   <CR bit2>  1*/
    epit1->EPIT1_CR |= (1<<2);
    /* 配置初始值来源 <CR bit1>  1*/
    epit1->EPIT1_CR |= (1<<1);
    /* 设置RELOAD寄存器的值 */
    epit1->EPIT1_LR = value;
    /* 设置比较值 */
    epit1->EPIT1_CMPR = 0;/* 和零比较 */

    /* 使能GIC中断 */
    GIC_EnableIRQ(EPIT1_IRQn);
    /* 注册终端服务 */
    system_register_irqhandler(EPIT1_IRQn, (system_irq_handler_t)epit1_irqhandler, NULL);
    /* 使能中断 <set bit0 1> */
    epit1->EPIT1_CR |= 0x1;
}

void epit1_irqhandler(void)
{
    static u8 ledtog;
    //if(epit1->EPIT1_SR & (0x1) == 0)
    //{
        /* 中断服务在这里编写 */
        //GPIO1_DR = !GPIO1_DR;
        //uart_ts_byte('a');
        ledtog = GPIO1_DR &(1<<3);
        if(ledtog)
            GPIO1_DR &= ~(1<<3);
        else
            GPIO1_DR |=  (1<<3);
        
    //}
    /* clear IT_UPDATE_STATUS <set SR bit0 1>*/
    epit1->EPIT1_SR |= (0x1);
}