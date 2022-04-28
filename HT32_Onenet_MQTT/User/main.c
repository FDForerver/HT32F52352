#include "usart.h"

#include "led.h"
#include "delay.h"
#include "time.h"
#include "dht11.h"


//����
#include "esp8266.h"
#include "onenet.h"

//C��
#include "string.h"

void Hardware_Init(void)
{
	
	USART1_Configuration();//��ӡ��Ϣ��				//����1����ӡ��Ϣ��
	
	USART0_Configuration();						//����2������ESP8266��
	
	Led_Init();        //LED��ʼ��
	dou_dht11_init();   //�¶ȳ�ʼ��
	GPTM_PWM_init();  //�����س�ʼ��
	Servo_Run(45);
	Servo_Run2(45);
	Servo_Run3(45);
	Servo_Run4(45);
	UsartPrintf(USART_DEBUG, " Hardware init OK\r\n");
	
}
 int main(void)
 {	

	unsigned char *dataPtr = NULL;
	 
	unsigned short timeCount = 0;	//���ͼ������
	 
	Hardware_Init();//Ӳ����ʼ��
	 
	ESP8266_Init();					//��ʼ��ESP8266
	 
	printf("8266_INIT_END\n");
	 
	while(OneNet_DevLink())			//����OneNET
	delay_ms(500);
	printf("����onenet�ɹ�");
	while(1) 
	{		
 	
		
		if(++timeCount >= 150)		//ʱ����1s
		{

			dou_dht11_get_data();
			delay_ms(20);
			printf("hum temp=%d .%d %d .%d\r\n",H_H,H_L,T_H,T_L);

			
			 printf( "OneNet_SendData\r\n");//ͨ������1������ʾ��Ϣ��Ҫ��ʼ���������ˣ�
					
				OneNet_SendData();//�������ݸ�onenet
				
				printf("send_data_end\n");
				timeCount = 0;
				
				ESP8266_Clear();
		}
		
		dataPtr = ESP8266_GetIPD(0);//��ȡƽ̨���ص�����
		if(dataPtr != NULL)//����������ݲ�Ϊ��
		OneNet_RevPro(dataPtr);//ƽ̨�������ݼ��		
		delay_ms(10); 	
	}
}

