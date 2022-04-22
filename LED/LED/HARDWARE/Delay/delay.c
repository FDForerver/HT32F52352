#include "delay.h"


//mS微秒级延时程序
void delay_us(u32 us)
{
	u32 i;
	SYSTICK_ClockSourceConfig(SYSTICK_SRC_STCLK);          //选择外部参考时钟作为SysTick时钟源。8MHZ
	SYSTICK_SetReloadValue(SystemCoreClock / 8 / 1000000); // 重装计数初值
	SYSTICK_IntConfig(DISABLE);                            // 是否开启中断
	SYSTICK_CounterCmd(SYSTICK_COUNTER_CLEAR);             //清空定时器
	SYSTICK_CounterCmd(SYSTICK_COUNTER_ENABLE);            //使能
	for( i = 0;i < us;i++ )
	{
		while( !( (SysTick->CTRL) & (1<<16) ) ); 
	}
 
	SYSTICK_CounterCmd(SYSTICK_COUNTER_DISABLE); //关闭
	SYSTICK_CounterCmd(SYSTICK_COUNTER_CLEAR);	 //复位清零
}

void delay_ms(u16 ms){ //mS毫秒级延时程序 	  
	while( ms-- != 0){
		delay_us(1000);	//调用1000微秒的延时
	}
}
 
void delay_s(u16 s){ //S秒级延时程序	 		  	  
	while( s-- != 0){
		delay_ms(1000);	//调用1000毫秒的延时
	}
} 
