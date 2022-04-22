#include "led.h"

void Led_Init(void)
{
		CKCU_PeripClockConfig_TypeDef LEDCLOCK ={{0}};
		LEDCLOCK.Bit.PC = 1; //使用PC
		
		//CKCU_PeripClockConfig(CKCU_PeripClockConfig_TypeDef Clock, ControlStatus Cmd);
		CKCU_PeripClockConfig(LEDCLOCK,ENABLE); //使能时钟
		//GPIO_DirectionConfig(HT_GPIO_TypeDef* HT_GPIOx, u16 GPIO_PIN_nBITMAP, GPIO_DIR_Enum GPIO_DIR_INorOUT);
		GPIO_DirectionConfig(HT_GPIO_PORT,HT_GPIO_PIN,GPIO_DIR_OUT); //配置GPIO PC15为输出模式
		//GPIO_WriteOutBits(HT_GPIO_TypeDef* HT_GPIOx, u16 GPIO_PIN_nBITMAP, FlagStatus Status);
		GPIO_WriteOutBits(HT_GPIO_PORT,HT_GPIO_PIN,SET); //将LED1 LED2 熄灭	
}


