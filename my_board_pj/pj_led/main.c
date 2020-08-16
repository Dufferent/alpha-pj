#include "./include/env/include.h"

int main(void)
{
    /* clk initure */
    clk_enable();


    /* gpio initure */
    gpio_set();
    /* loop */
    while(1)
    {
        led_flash();
    }

    return 0;
}