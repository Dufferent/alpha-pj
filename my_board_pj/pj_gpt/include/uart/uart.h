#ifndef __UART_H
#define __UART_H

/* function extern */
void uart1_init(void);
void uart_ts_byte(unsigned char ch);
void uart_printf(unsigned char *ptr);
unsigned char uart_rec_byte(void);

/* interrupt extern */
void UART_REC_IRQ(void);

#endif