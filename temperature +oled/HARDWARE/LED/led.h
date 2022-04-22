#ifndef _LED_H_
#define _LED_H_

#include "ht32f5xxxx_ckcu.h"
#include "ht32f5xxxx_gpio.h"

//�˿ںŶ���
#define HT_GPIO_PORT HT_GPIOC 
//LED���Ŷ���
#define HT_GPIO_PIN  (GPIO_PIN_14|GPIO_PIN_15)

//LED1 LED2 �궨�忪�͹�
#define LED1_ON() 	GPIO_WriteOutBits(HT_GPIO_PORT,GPIO_PIN_14,RESET)
#define LED1_OFF()  GPIO_WriteOutBits(HT_GPIO_PORT,GPIO_PIN_14,SET)

#define LED2_ON() 	GPIO_WriteOutBits(HT_GPIO_PORT,GPIO_PIN_15,RESET)
#define LED2_OFF()  GPIO_WriteOutBits(HT_GPIO_PORT,GPIO_PIN_15,SET)
void Led_Init(void);
#endif



