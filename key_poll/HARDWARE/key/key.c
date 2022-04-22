#include "key.h"
#include "delay.h"

#include "led.h"

//��������
void Key_Init(void)
{
	CKCU_PeripClockConfig_TypeDef CKCUClock= {{0}};
	CKCUClock.Bit.PB = 1;  //����GPIOBʱ��
	CKCUClock.Bit.AFIO = 1; 
	CKCU_PeripClockConfig(CKCUClock, ENABLE);	
	
	AFIO_GPxConfig(GPIO_PB,GPIO_PIN, AFIO_MODE_DEFAULT); 
	GPIO_InputConfig(HT_GPIO_GROUP, GPIO_PIN, ENABLE);
	GPIO_DirectionConfig(HT_GPIOB,GPIO_PIN, GPIO_DIR_IN);            //����GPIOģʽ��GPIO_DIR_OUT���orGPIO_DIR_IN����                                                                              */

 
}


//������ѯ
void Key_Scans(void)
{
	if(GPIO_ReadInBit(HT_GPIOB,GPIO_PIN_4) == RESET){ //�������ӿڵĵ�ƽ
			delay_ms(20); //��ʱȥ����
			if(GPIO_ReadInBit(HT_GPIOB,GPIO_PIN_4) == RESET){ //�������ӿڵĵ�ƽ
					LED1_ON(); 
				while(GPIO_ReadInBit(HT_GPIOB,GPIO_PIN_4) == RESET); //�ȴ������ɿ� 
				}
		}
}
