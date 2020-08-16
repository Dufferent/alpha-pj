#include "./include/env/include.h"

int main(void)
{
    u8 rec;
    /* Interrupt Enable*/
    int_init();
    /* system clk set */
    systemclk_initure();
    /* clk initure */
    clk_enable();
    /* 串口初始化 boundrate:115200 */
    uart1_init();
    /* led initure */
    led_init();
    /* exti initure */
    //exti_init();
    /* Timer init */
    //epit1_init(65,500000);/* Tout = ((frac +1 )* value) / Tclk */
    /* clk=66Mhz frac=66 value=500000=>interrupt frequent = 2Hz*/

    /* loop */
    while(1)
    {
        //led_flash();
        uart_printf("请输入字符!\r\n");
        rec = uart_rec_byte();
        uart_printf("输入的字符是:\r\n");
        uart_ts_byte(rec);
    }
    return 0;
}