#include "../env/include.h"

/*function defination*/
void delay(/*volatile unsigned*/ int n)/*sysclk == 396Mhz*/
{
    //volatile unsigned int Ticks;
    int Ticks;
    while(n--)
    {
        for(Ticks=0;Ticks<0x7ff;Ticks++);/* 1ms */
    }
}