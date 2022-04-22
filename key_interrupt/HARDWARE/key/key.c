#include "key.h"
#include "delay.h"

void Key_Init(void)
{
	EXTI_InitTypeDef EXTI_InitStruct;	
	CKCU_PeripClockConfig_TypeDef CKCUClock= {{0}};
	CKCUClock.Bit.PB = 1;  //开启GPIOB时钟
	CKCUClock.Bit.AFIO = 1; 
	CKCUClock.Bit.EXTI = 1;  //开启中断时钟
	CKCU_PeripClockConfig(CKCUClock, ENABLE);
	
	GPIO_InputConfig(HT_GPIO_GROUP, GPIO_PIN, ENABLE);
  GPIO_PullResistorConfig(HT_GPIO_GROUP, GPIO_PIN, GPIO_PR);

	
	//GPIOB_4 中断配置
	AFIO_GPxConfig( GPIO_PB, AFIO_PIN_4, AFIO_FUN_GPIO);
  AFIO_EXTISourceConfig(AFIO_EXTI_CH_4, AFIO_ESS_PB);//中断来源选择PB3
	EXTI_InitStruct.EXTI_Channel=EXTI_CHANNEL_4;
	EXTI_InitStruct.EXTI_Debounce=EXTI_DEBOUNCE_ENABLE;//决定是否去抖
	EXTI_InitStruct.EXTI_DebounceCnt = 65535;     
	EXTI_InitStruct.EXTI_IntType=EXTI_POSITIVE_EDGE;  //上升沿触发
	EXTI_Init(&EXTI_InitStruct);	
	NVIC_EnableIRQ(EXTI4_15_IRQn);//	
	EXTI_IntConfig(EXTI_CHANNEL_4, ENABLE);//检测中断源状态函数
	
	
	//GPIOB_2 中断配置
	AFIO_GPxConfig( GPIO_PB, AFIO_PIN_2, AFIO_FUN_GPIO);
  AFIO_EXTISourceConfig(AFIO_EXTI_CH_2, AFIO_ESS_PB);//中断来源选择PB3
	EXTI_InitStruct.EXTI_Channel=EXTI_CHANNEL_2;
	EXTI_InitStruct.EXTI_Debounce=EXTI_DEBOUNCE_ENABLE;//决定是否去抖
	EXTI_InitStruct.EXTI_DebounceCnt = 65535;     
	EXTI_InitStruct.EXTI_IntType=EXTI_POSITIVE_EDGE;  //上升沿触发
	EXTI_Init(&EXTI_InitStruct);	
	NVIC_EnableIRQ(EXTI2_3_IRQn);//	
	EXTI_IntConfig(EXTI_CHANNEL_2, ENABLE);//检测中断源状态函数
	
}



