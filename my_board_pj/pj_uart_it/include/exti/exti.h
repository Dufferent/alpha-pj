#ifndef __EXTI_H
#define __EXTI_H

/* function defination*/
void exti_init(void);
void gpio1_io18_irqhandler(unsigned int gicciar, void *param);
#endif