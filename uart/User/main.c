#include "ht32.h"
#include "ht32_board.h"
#include "led.h"
#include "delay.h"
#include "uart.h"

/**********************TH32 串口点灯**********************
Author:小殷

Date:2022-4-18
******************************************************/
uint8_t data = 0;

int main()
{
	Led_Init();
	USARTx_Init();
	Usart_SendStr(HT_USART1,(uint8_t *)"------HT32 UART TEST-------\r\n");//循环发送字符串，测试用
	while(1)
	{
		
	}
}



void COM_IRQHandler(void)
{
	u8 data;
	
	if( USART_GetFlagStatus(COM_PORT, USART_FLAG_RXDR) )
	{
		data = USART_ReceiveData(COM_PORT);
		printf("data = %c\n",data);
		if(data == '0')
		{
			LED1_ON();
			printf("LED1 ON\n");
		}
		else if(data == '1')
		{
			LED1_OFF();
			printf("LED1 OFF\n");
		}
	}
}
