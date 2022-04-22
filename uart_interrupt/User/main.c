#include "ht32.h"
#include "ht32_board.h"
#include "led.h"
#include "delay.h"
#include "uart.h"

/**********************TH32 与 stm32 串口点灯**********************
Author:小殷

Date:2022-4-21
******************************************************/
uint8_t data = 0;


int main()
{
	Led_Init();
	Uart_Init();
	Usart_SendStr(COM1_PORT,(uint8_t *)"------HT32 UART TEST-------\r\n");//循环发送字符串，测试用
	while(1)
	{
		
	}
}



void COM1_IRQHandler(void)
{

	
	if( USART_GetFlagStatus(COM1_PORT, USART_FLAG_RXDR) )
	{
		data = USART_ReceiveData(COM1_PORT);
		//printf("data = %c\n",data);
		if(data == '1')
		{
			LED1_ON();
		
			printf("led1 on\n");
			USART_SendData(COM_PORT,'1');
		}
		else if(data == '0')
		{
			LED1_OFF();
		
			printf("led1 off\n");
			USART_SendData(COM_PORT,'0');
		}
			USART_ClearFlag(COM1_PORT, USART_FLAG_RSADD);
	}
}



