#include "ht32.h"
#include "ht32_board.h"
#include "led.h"
#include "delay.h"
#include "uart.h"
#include "time.h"

/**********************TH32 ��ʱ����˸���**********************
Author:С��

Date:2022-4-21
***************************************************************/
int main()
{
	Led_Init();
	Timer_Init();
	USARTx_Init();
	printf("---------Time Test------\n");
	while(1)
	{
	
	}
}



