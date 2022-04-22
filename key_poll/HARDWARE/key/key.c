#include "key.h"
#include "delay.h"

#include "led.h"

//按键配置
void Key_Init(void)
{
	CKCU_PeripClockConfig_TypeDef CKCUClock= {{0}};
	CKCUClock.Bit.PB = 1;  //开启GPIOB时钟
	CKCUClock.Bit.AFIO = 1; 
	CKCU_PeripClockConfig(CKCUClock, ENABLE);	
	
	AFIO_GPxConfig(GPIO_PB,GPIO_PIN, AFIO_MODE_DEFAULT); 
	GPIO_InputConfig(HT_GPIO_GROUP, GPIO_PIN, ENABLE);
	GPIO_DirectionConfig(HT_GPIOB,GPIO_PIN, GPIO_DIR_IN);            //配置GPIO模式：GPIO_DIR_OUT输出orGPIO_DIR_IN输入                                                                              */

 
}


//按键轮询
void Key_Scans(void)
{
	if(GPIO_ReadInBit(HT_GPIOB,GPIO_PIN_4) == RESET){ //读按键接口的电平
			delay_ms(20); //延时去抖动
			if(GPIO_ReadInBit(HT_GPIOB,GPIO_PIN_4) == RESET){ //读按键接口的电平
					LED1_ON(); 
				while(GPIO_ReadInBit(HT_GPIOB,GPIO_PIN_4) == RESET); //等待按键松开 
				}
		}
}
