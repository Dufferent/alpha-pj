#include "./include/env/include.h"

int main(void)
{
    /*system clk set*/
    systemclk_initure();
    /* clk initure */
    clk_enable();
    /* Interrupt Enable*/
    int_init();
    /* led initure */
    led_init();
    /* exti initure */
    exti_init();
    /* Timer init */
    epit1_init(0,66000000/2);/* Tout = ((frac +1 )* value) / Tclk */
    /* clk=66Mhz frac=66 value=500000=>interrupt frequent = 2Hz*/
    
    /* loop */
    while(1)
    {
        //led_flash();
        //led_on();
        delay(5000);
    }

    return 0;
}