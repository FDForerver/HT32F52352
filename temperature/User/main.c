#include "ht32.h"
#include "ht32_board.h"
#include "led.h"
#include "delay.h"
#include "uart.h"
#include "dht11.h"

/**********************TH32 ���ڵ��**********************
Author:С��

Date:2022-4-18
******************************************************/
uint8_t data = 0;
uint8_t sendbuf[128] = {0};

int main()
{
	Led_Init();
	USARTx_Init();
	Usart_SendStr(HT_USART1,(uint8_t *)"------HT32 UART TEST-------\r\n");//ѭ�������ַ�����������
	while(1)
	{
		dou_dht11_get_data();//��ȡ�¶�����
		sprintf((char *)sendbuf,"��ǰ�¶ȣ�%2d ��ǰʪ��:%2d\n",dou_dht11_temperature_data_h ,dou_dht11_humidity_data_h);
		Usart_SendStr(HT_USART1,sendbuf);
		delay_ms(500);
		
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
