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