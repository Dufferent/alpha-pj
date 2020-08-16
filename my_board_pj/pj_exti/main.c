#include "./include/env/include.h"

int main(void)
{
    /* Interrupt Enable*/
    int_init();
    /* clk initure */
    clk_enable();
    /*system clk set*/
    systemclk_initure();
    /* led initure */
    led_init();
    /* exti initure */
    exti_init();

    /* loop */
    while(1)
    {
        //led_flash();
        led_on();
        delay(5000);
    }

    return 0;
}