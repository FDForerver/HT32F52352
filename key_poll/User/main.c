#include "ht32.h"
#include "ht32_board.h"
#include "led.h"
#include "delay.h"
#include "uart.h"
#include "key.h"

/**********************TH32 �����жϵ��**********************
Author:С��

Date:2022-4-18
******************************************************/

uint8_t key_stat = 0; //����״̬
int main()
{
//	uint8_t keynum = 0;
	Led_Init();
	USARTx_Init();
	Key_Init();
	printf("------key test------\n");
	while(1)
	{
		Key_Scans();
	}
}

