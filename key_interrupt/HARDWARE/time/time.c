#include "time.h"
#include "led.h"



void Timer_Init(void)
{	
	CKCU_PeripClockConfig_TypeDef CKCUClock= {{0}};
	CKCUClock.Bit.BFTM1 = 1;  //开启中断时钟
	CKCU_PeripClockConfig(CKCUClock, ENABLE);
	
	NVIC_EnableIRQ(BFTM1_IRQn);
	
	BFTM_SetCounter(HT_BFTM1, 0);
//	BFTM_SetCompare(HT_BFTM1, SystemCoreClock);//定时1s产生中断
	BFTM_SetCompare(HT_BFTM1, SystemCoreClock*1000);//定时1ms产生中断
	BFTM_IntConfig(HT_BFTM1, ENABLE);//使能中断
	BFTM_EnaCmd(HT_BFTM1, ENABLE);//使能BFTM

}


