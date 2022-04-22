#include "delay.h"


//mS΢�뼶��ʱ����
void delay_us(u32 us)
{
	u32 i;
	SYSTICK_ClockSourceConfig(SYSTICK_SRC_STCLK);          //ѡ���ⲿ�ο�ʱ����ΪSysTickʱ��Դ��8MHZ
	SYSTICK_SetReloadValue(SystemCoreClock / 8 / 1000000); // ��װ������ֵ
	SYSTICK_IntConfig(DISABLE);                            // �Ƿ����ж�
	SYSTICK_CounterCmd(SYSTICK_COUNTER_CLEAR);             //��ն�ʱ��
	SYSTICK_CounterCmd(SYSTICK_COUNTER_ENABLE);            //ʹ��
	for( i = 0;i < us;i++ )
	{
		while( !( (SysTick->CTRL) & (1<<16) ) ); 
	}
 
	SYSTICK_CounterCmd(SYSTICK_COUNTER_DISABLE); //�ر�
	SYSTICK_CounterCmd(SYSTICK_COUNTER_CLEAR);	 //��λ����
}

void delay_ms(u16 ms){ //mS���뼶��ʱ���� 	  
	while( ms-- != 0){
		delay_us(1000);	//����1000΢�����ʱ
	}
}
 
void delay_s(u16 s){ //S�뼶��ʱ����	 		  	  
	while( s-- != 0){
		delay_ms(1000);	//����1000�������ʱ
	}
} 
