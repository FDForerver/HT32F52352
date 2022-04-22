#include "ht32.h"
#include "ht32_board.h"
#include "led.h"
#include "delay.h"

/**********************TH32 µ„µ∆**********************
Author:–°“Û

Date:2022-4-17
******************************************************/


int main()
{
	Led_Init();
	while(1)
	{
//		GPIO_WriteOutBits(HT_GPIOC,GPIO_PIN_14,RESET);
//		delay_ms(500);
//		GPIO_WriteOutBits(HT_GPIOC,GPIO_PIN_14,SET);
//		delay_ms(500);
		LED1_ON();
		LED2_ON();
		delay_ms(500);
		LED1_OFF();
		LED2_OFF();
		delay_ms(500);
	}
}
