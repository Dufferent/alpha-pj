#ifndef __LED_H
#define __LED_H


/*function externation*/
void gpio_set(void);
/*led initure*/
void led_init(void);
/*open led*/
void led_on(void);
/*off led*/
void led_off(void);
/*flash led between 500ms*/
void led_flash(void);

#endif