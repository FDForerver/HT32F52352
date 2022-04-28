#include "usart.h"

#include "led.h"
#include "delay.h"
#include "time.h"
#include "dht11.h"


//网络
#include "esp8266.h"
#include "onenet.h"

//C包
#include "string.h"

void Hardware_Init(void)
{
	
	USART1_Configuration();//打印信息用				//串口1，打印信息用
	
	USART0_Configuration();						//串口2，驱动ESP8266用
	
	Led_Init();        //LED初始化
	dou_dht11_init();   //温度初始化
	GPTM_PWM_init();  //舵机相关初始化
	Servo_Run(45);
	Servo_Run2(45);
	Servo_Run3(45);
	Servo_Run4(45);
	UsartPrintf(USART_DEBUG, " Hardware init OK\r\n");
	
}
 int main(void)
 {	

	unsigned char *dataPtr = NULL;
	 
	unsigned short timeCount = 0;	//发送间隔变量
	 
	Hardware_Init();//硬件初始化
	 
	ESP8266_Init();					//初始化ESP8266
	 
	printf("8266_INIT_END\n");
	 
	while(OneNet_DevLink())			//接入OneNET
	delay_ms(500);
	printf("接入onenet成功");
	while(1) 
	{		
 	
		
		if(++timeCount >= 150)		//时间间隔1s
		{

			dou_dht11_get_data();
			delay_ms(20);
			printf("hum temp=%d .%d %d .%d\r\n",H_H,H_L,T_H,T_L);

			
			 printf( "OneNet_SendData\r\n");//通过串口1发送提示信息（要开始发送数据了）
					
				OneNet_SendData();//发送数据给onenet
				
				printf("send_data_end\n");
				timeCount = 0;
				
				ESP8266_Clear();
		}
		
		dataPtr = ESP8266_GetIPD(0);//获取平台返回的数据
		if(dataPtr != NULL)//如果返回数据不为空
		OneNet_RevPro(dataPtr);//平台返回数据检测		
		delay_ms(10); 	
	}
}

