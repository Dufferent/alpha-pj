#include "../env/include.h"

/*function defination*/

/*gpio initure*/
void gpio_set(void)
{
    /*配置复用映射*/
    SW_MUX_CTL_GPIO1_IO03 = 0x5;
    /*配置IO电器属性*/
    SW_PAD_CTL_GPIO1_IO03 = 0x10B0;
    /* 配置为 */
    /* 100K 下拉 */
    /* 保持 */
    /* 使能保持 */ 
    /* 失能开漏 */
    /* speed 200Mhz */
    /* DSE2R02 */
    /*Slow Slew Rate */

    /*配置输入输出模式*/
                    /*gpio:   16 15  ...  ... 3210   */               
    GPIO1_GDR = 0x8;/* 0x0008->0000_0000_0000_1000->gpio[3] IO_mode = 1 */
}
/*led initure*/
void led_init(void)
{
    gpio_set();
    GPIO1_DR = 0;//点亮led
}
/*open led*/
void led_on(void)
{
    GPIO1_DR &= ~(1<<3);  /* 0001<<3 == 1000 ~$() == 111...0111 */
}
/*off led*/
void led_off(void)
{
    GPIO1_DR |=  (1<<3);  /* 0001<<3 == 1000 gpio3 置1 led灯灭 */
}
/*flash led between 500ms*/
void led_flash(void)
{
    led_on();
    delay(200);
    led_off();
    delay(200);
}