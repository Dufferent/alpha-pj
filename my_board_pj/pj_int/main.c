#include "./include/env/include.h"

int main(void)
{
    /*system clk set*/
    systemclk_initure();
    /* clk initure */
    clk_enable();
    /* interrupt initure */
    int_init();
    /* gpio initure */
    gpio_set();
    /* loop */
    while(1)
    {
        led_flash();
    }

    return 0;
}