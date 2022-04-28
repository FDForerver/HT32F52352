#ifndef _TIME_H_
#define _TIME_H_
#include "ht32f5xxxx_bftm.h"

#define HTGPIO_PIN (GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_8|GPIO_PIN_9)


void GPTM_PWM_init(void);
void Servo_Run(uint16_t angle);
void Servo_Run2(uint16_t angle);
void Servo_Run3(uint16_t angle);
void Servo_Run4(uint16_t angle);
#endif
