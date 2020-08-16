#include "../env/include.h"

/* function defination */
void key_init(key_status *KEY)
{
    /* structure initure  */
    //KEY = (key_status*)malloc(sizeof(key_status));
    KEY->key_0_release = 1;
    KEY->key_0_press.press_long = 0;
    KEY->key_0_press.press_short = 0;
    /* gpio initure */
    SW_MUX_CTL_USART1_CTRS = 0x5;/* 设置为复用映射为GPIO18  */
    SW_PAD_CTL_USART1_CTRS = 0xF0C0;
    /* 设置为输入模式 */
    GPIO1_GDR |= (1<18);
}

void key_scan(key_status *KEY)
{
    if( !( GPIO1_DR&(1<<18) ) )
    {
        delay(1);/* 消抖 时间1ms */
        if( !( GPIO1_DR&(1<<18) ) )
        {
            static int keeper = 0;
            KEY->key_0_release = 0;
            while(1)
            {
                keeper++;
                if( GPIO1_DR&(1<<18) )
                    break;
            }
            if( keeper > (0x77f*2000) )/* 按键时间大于两秒 */
                KEY->key_0_press.press_long  = 1;
            else
                KEY->key_0_press.press_short = 1;
        }
    }
    else
    {
        KEY->key_0_release = 1;
    }
}

