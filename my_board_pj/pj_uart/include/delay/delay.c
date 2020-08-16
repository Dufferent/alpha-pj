#include "../env/include.h"

/*function defination*/
void delay(int n)/*sysclk == 396Mhz*/
{
    int Ticks;
    while(n--)
    {
        for(Ticks=0;Ticks<0x7ff;Ticks++);/* 1ms */
    }
}