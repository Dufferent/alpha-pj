#ifndef __KEY_H
#define __KEY_H

/* key mode status structure */
typedef struct 
{   
    int press_long;
    int press_short;
}press_status;

typedef struct{
        press_status key_0_press;
        int key_0_release;
}key_status;
/* function external */ 
void key_init(key_status *KEY);
void key_scan(key_status *KEY);

/* value */
extern key_status uKEY;

#endif