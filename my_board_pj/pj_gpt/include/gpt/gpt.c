#include "../env/include.h"
/* 高精度延时器 */
void GPT_init(void)
{
    GPT1->GPT1_CR = 0;
    GPT1->GPT1_CR = 1 << 15;
    while((GPT1->GPT1_CR >> 15) & 0x01);
    GPT1->GPT1_CR = (1<<6);
    GPT1->GPT1_PR = 65;
    GPT1->GPT1_OCR1 = 0XFFFFFFFF;
    GPT1->GPT1_CR |= 1<<0;
}

void GPT_DELAY(unsigned int usdelay)
{
    unsigned long oldcnt,newcnt;
    unsigned long tcntvalue = 0; /* 走过的总时间 */
    oldcnt = GPT1->GPT1_CNT;
    while(1)
    {
        newcnt = GPT1->GPT1_CNT;
        if(newcnt != oldcnt)
        {
            if(newcnt > oldcnt) /* GPT 是向上计数器,并且没有溢出 */
                tcntvalue += newcnt - oldcnt;
            else /* 发生溢出 */
                tcntvalue += 0XFFFFFFFF-oldcnt + newcnt;
            oldcnt = newcnt;
            if(tcntvalue >= usdelay) /* 延时时间到了 */
                break; /* 跳出 */
        }
    }
}
