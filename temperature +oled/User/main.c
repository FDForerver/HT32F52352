#include "ht32.h"
#include "ht32_board.h"
#include "led.h"
#include "delay.h"
#include "uart.h"
#include "dht11.h"
#include "oled.h"

/**********************TH32 oled显示温湿度**********************
Author:小殷

Date:2022-4-22
******************************************************/
uint8_t data = 0;
uint8_t sendbuf[128] = {0};

int main()
{
	Led_Init();
	USARTx_Init();
	OLED_Init();
	Usart_SendStr(HT_USART1,(uint8_t *)"------HT32 oled TEST-------\r\n");//循环发送字符串，测试用
	OLED_Clear(0);
	OLED_ShowString(20,1,"ht32 oled",8);
	OLED_ShowString(20,3,(unsigned char *)"C_T:",3); // Current_Temperature 当前温度
	OLED_ShowCHinese_Three(80,3,11); //C
			
	OLED_ShowString(20,5,(unsigned char *)"C_H:",3); // Current_Humidity 当前湿度
	OLED_ShowCHinese_Three(80,5,13); //.
	while(1)
	{
//		dou_dht11_get_data();//获取温度数据
//		sprintf((char *)sendbuf,"当前温度：%2d 当前湿度:%2d\n",dou_dht11_temperature_data_h ,dou_dht11_humidity_data_h);
//		Usart_SendStr(HT_USART1,sendbuf);
//		delay_ms(500);
			dou_dht11_get_data();//获取温度数据
			
			
			OLED_ShowNum(50,3,T_H/10,3,3);
			OLED_ShowNum(60,3,T_L%10,3,3);
			OLED_ShowNum(50,5,H_H/10,3,3);
			OLED_ShowNum(60,5,H_L%10,3,3);

		
	}
}


