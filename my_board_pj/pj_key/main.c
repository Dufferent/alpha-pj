#include "./include/env/include.h"

/* env val*/
key_status uKEY;

int main(void)
{
    unsigned char key_buf=0;
    /* clk initure */
    clk_enable();
    /* led gpio initure */
    gpio_set();
    /* key initure*/
    key_init(&uKEY);
    /* loop */
    while(1)
    {
        /* key scan */
        key_scan(&uKEY);
        if(uKEY.key_0_release)
        {
            /* do nothing */
        }
        else
        {
            if(uKEY.key_0_press.press_long)
            {
                    key_buf = 1;
            }
            if(uKEY.key_0_press.press_short)
            {
                    key_buf = 2;
            }
        }
        switch(key_buf)
        {
            case 0:/*do nothing*/break;
            case 1:led_flash();
            case 2:led_off();
            default:/*do nothing*/break;
        }
    }

    return 0;
}