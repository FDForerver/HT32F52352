#include "time.h"
#include "led.h"
#include "uart.h"

uint16_t count = 0;  //��ʱ
uint8_t led_flag = 0; //led���з�ת��־
uint8_t time = 0;//��˸ʱ��

void Timer_Init(void)
{	
	CKCU_PeripClockConfig_TypeDef CKCUClock= {{0}};
	CKCUClock.Bit.BFTM1 = 1;  //�����ж�ʱ��
	CKCU_PeripClockConfig(CKCUClock, ENABLE);
	
	NVIC_EnableIRQ(BFTM1_IRQn);
	
	BFTM_SetCounter(HT_BFTM1, 0);
	//BFTM_SetCompare(HT_BFTM1, SystemCoreClock);//��ʱ1s�����ж�
	BFTM_SetCompare(HT_BFTM1, SystemCoreClock/1000);//��ʱ1ms�����ж�
	BFTM_IntConfig(HT_BFTM1, ENABLE);//ʹ���ж�
	BFTM_EnaCmd(HT_BFTM1, ENABLE);//ʹ��BFTM
}



void BFTM1_IRQHandler(void)
{
		if(BFTM_GetFlagStatus(HT_BFTM1) != RESET )
		{	
		
			count++;			
			if(count == 1000) //1s
			{	
				time++;
				printf("-------------LED FLASH count :%02d------------\n",time);		
				count = 0;
				if(led_flag == 0)
				{
					LED1_ON();
					led_flag = 1;
				}		
				else if(led_flag == 1)
				{
					led_flag = 0;
					LED1_OFF();
				}
			}
			BFTM_ClearFlag(HT_BFTM1);//����жϱ�־
		}	
}

