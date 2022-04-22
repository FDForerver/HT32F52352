#include "key.h"
#include "delay.h"

void Key_Init(void)
{
	EXTI_InitTypeDef EXTI_InitStruct;	
	CKCU_PeripClockConfig_TypeDef CKCUClock= {{0}};
	CKCUClock.Bit.PB = 1;  //����GPIOBʱ��
	CKCUClock.Bit.AFIO = 1; 
	CKCUClock.Bit.EXTI = 1;  //�����ж�ʱ��
	CKCU_PeripClockConfig(CKCUClock, ENABLE);
	
	GPIO_InputConfig(HT_GPIO_GROUP, GPIO_PIN, ENABLE);
  GPIO_PullResistorConfig(HT_GPIO_GROUP, GPIO_PIN, GPIO_PR);

	
	//GPIOB_4 �ж�����
	AFIO_GPxConfig( GPIO_PB, AFIO_PIN_4, AFIO_FUN_GPIO);
  AFIO_EXTISourceConfig(AFIO_EXTI_CH_4, AFIO_ESS_PB);//�ж���Դѡ��PB3
	EXTI_InitStruct.EXTI_Channel=EXTI_CHANNEL_4;
	EXTI_InitStruct.EXTI_Debounce=EXTI_DEBOUNCE_ENABLE;//�����Ƿ�ȥ��
	EXTI_InitStruct.EXTI_DebounceCnt = 65535;     
	EXTI_InitStruct.EXTI_IntType=EXTI_POSITIVE_EDGE;  //�����ش���
	EXTI_Init(&EXTI_InitStruct);	
	NVIC_EnableIRQ(EXTI4_15_IRQn);//	
	EXTI_IntConfig(EXTI_CHANNEL_4, ENABLE);//����ж�Դ״̬����
	
	
	//GPIOB_2 �ж�����
	AFIO_GPxConfig( GPIO_PB, AFIO_PIN_2, AFIO_FUN_GPIO);
  AFIO_EXTISourceConfig(AFIO_EXTI_CH_2, AFIO_ESS_PB);//�ж���Դѡ��PB3
	EXTI_InitStruct.EXTI_Channel=EXTI_CHANNEL_2;
	EXTI_InitStruct.EXTI_Debounce=EXTI_DEBOUNCE_ENABLE;//�����Ƿ�ȥ��
	EXTI_InitStruct.EXTI_DebounceCnt = 65535;     
	EXTI_InitStruct.EXTI_IntType=EXTI_POSITIVE_EDGE;  //�����ش���
	EXTI_Init(&EXTI_InitStruct);	
	NVIC_EnableIRQ(EXTI2_3_IRQn);//	
	EXTI_IntConfig(EXTI_CHANNEL_2, ENABLE);//����ж�Դ״̬����
	
}



