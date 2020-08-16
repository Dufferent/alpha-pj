/* include */
#include "../env/include.h"

void exti_init(void)
{
    /* function defination */
    /* gpio initure */
    SW_MUX_CTL_USART1_CTRS = 0x5;/* 设置为复用映射为GPIO18  */
    SW_PAD_CTL_USART1_CTRS = 0xF0C0;
    /* 设置为输入模式 */
    GPIO1_GDR |= (1<18);
    /* gpio口复用中断线 */
    GPIO1_ICR2 |= (0x3<<4);
    /* gic 注册*/
    GIC_EnableIRQ(GPIO1_Combined_16_31_IRQn);
    system_register_irqhandler(GPIO1_Combined_16_31_IRQn, (system_irq_handler_t)gpio1_io18_irqhandler, NULL);
    GIC_SetPriority(GPIO1_Combined_16_31_IRQn,5);
    /* 使能gpio1_IO18 exti*/
    GPIO1_IMR |= (0x1<<18);
}
/* 中断处理函数 */
void gpio1_io18_irqhandler(unsigned int gicciar, void *param)
{
    delay(1); /* 消抖 */
    if( (GPIO1_DR&(0x1<<18)) == 0) 
    {
        /* 中断服务 */
        led_off();
    }
    /* 清除中断表示位 */
    GPIO1_ISR |= (0x1<<18);
}