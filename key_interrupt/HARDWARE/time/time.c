#include "time.h"
#include "led.h"



void Timer_Init(void)
{	
	CKCU_PeripClockConfig_TypeDef CKCUClock= {{0}};
	CKCUClock.Bit.BFTM1 = 1;  //�����ж�ʱ��
	CKCU_PeripClockConfig(CKCUClock, ENABLE);
	
	NVIC_EnableIRQ(BFTM1_IRQn);
	
	BFTM_SetCounter(HT_BFTM1, 0);
//	BFTM_SetCompare(HT_BFTM1, SystemCoreClock);//��ʱ1s�����ж�
	BFTM_SetCompare(HT_BFTM1, SystemCoreClock*1000);//��ʱ1ms�����ж�
	BFTM_IntConfig(HT_BFTM1, ENABLE);//ʹ���ж�
	BFTM_EnaCmd(HT_BFTM1, ENABLE);//ʹ��BFTM

}


