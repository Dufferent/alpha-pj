#include "../env/include.h"

/* uart1 enable */
void uart1_init(void)
{
    
    /* initure IO */
    SW_MUX_CTL_PAD_UART1_TX_DATA = 0;/* set uart1 Tx mode */
    SW_MUX_CTL_PAD_UART1_RX_DATA = 0;/* set uart1 Rx mode */
    UART1_SELECT_INPUT |= 0x3;
    SW_PAD_CTL_PAD_UART1_TX_DATA = 0x10B0;/* TX fwout*/
    SW_PAD_CTL_PAD_UART1_RX_DATA = 0x10B0;/* RX fwin */

    /* disable uart1*/
    UART_1->UART1_UCR1 &= ~(1<<0);
    /* reset uart1 */
    UART_1->UART1_UCR2 &= ~(1<<0);
    while( (UART_1->UART1_UCR2&0x1) == 0 );
    /* wait reset finsh */
			
    /* set uart */
    //UART_1->UART1_UCR1 = 0;/* clear */
    UART_1->UART1_UCR1 &= ~(1<<14);/* off auto cheek boundrate */
    /* -------------------忽略RTS  关闭奇偶校验 1停止位 8bit数据位  使能发送  复位串口发送 */
    UART_1->UART1_UCR2 |= (1<<14) | (1<<5) | (1<<2) | (1<<1);
    UART_1->UART1_UCR3 |= (1<<2);
    /* 设置波特率 */
    /*
    公式：
    UART1:
    bound_rate = Ref FREQ / (16 * (UBRM + 1) / (UBIR + 1) )
    */
    /* 此处设置为 115200 */
    UART_1->UART1_UFCR = 5<<7;
    UART_1->UART1_UBIR = 71;
    UART_1->UART1_UBMR = 3124;

    /* enable uart1 */
    UART_1->UART1_UCR1 |= (1<<0);
}

void uart_ts_byte(unsigned char ch)
{
    while((UART_1->UART1_USR2 & (0x01<<3) )== 0);/* 等待上一次发送完成 */
    UART_1->UART1_UTXD = ch;/* 限制位宽 8bit */
}

void uart_printf(unsigned char *ptr)
{
    while(*ptr)
    {
        uart_ts_byte(*(ptr++));
    }
}
/* 接收到一个字节（8bit） 就返回 */
unsigned char uart_rec_byte(void)
{
    while( (UART_1->UART1_USR2 & 0x1) == 0 );
    return UART_1->UART1_URXD;
}