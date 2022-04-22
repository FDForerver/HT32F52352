#ifndef _DELAY_H_
#define _DELAY_H_

#include "ht32f5xxxx_ckcu.h"
#include "ht32f5xxxx_gpio.h"
#include "ht32_cm0plus_misc.h"

void delay_us(u32 us);
void delay_ms(u16 ms);
void delay_s(u16 s);

#endif
