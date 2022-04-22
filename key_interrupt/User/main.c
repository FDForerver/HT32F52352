#include "ht32.h"
#include "ht32_board.h"
#include "led.h"
#include "delay.h"
#include "uart.h"
#include "key.h"

/**********************TH32 按键中断点灯**********************
Author:小殷

Date:2022-4-18
******************************************************/

uint8_t key_stat = 0; //按键状态
int main()
{
	uint8_t keynum = 0;
	Led_Init();
	USARTx_Init();
	Key_Init();
	printf("------key test------\n");
	while(1)
	{
		

	}
}

void EXTI4_15_IRQHandler(void)
{	
    if(key_stat == 0)
		{
			key_stat = 1;
			LED1_ON();
		}
		else if(key_stat == 1)
		{
			key_stat = 0;
			LED1_OFF();
		}
		EXTI_ClearEdgeFlag(EXTI_CHANNEL_4);
}

void EXTI2_3_IRQHandler(void)
{
	 if(key_stat == 0)
		{
			key_stat = 1;
			LED2_ON();
		}
		else if(key_stat == 1)
		{
			key_stat = 0;
			LED2_OFF();
		}
		EXTI_ClearEdgeFlag(EXTI_CHANNEL_2);
}
