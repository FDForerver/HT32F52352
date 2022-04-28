#include "time.h"
#include "delay.h"



//输出四路PWM波控制后轮两个电机
//arr：自动重装值
//psc：时钟预分频数
//GT0 PA4 PA5 PA6 PA7
//产生一个20ms 定时周期 
void GPTM_PWM_init(void)
{
 
    TM_TimeBaseInitTypeDef TimeBaseIniture;   //结构体
    TM_OutputInitTypeDef   OutIniture;
 
    CKCU_PeripClockConfig_TypeDef CKCUClock = {{0}};
    CKCUClock.Bit.PC        = 1;       //GPIOA时钟打开
    CKCUClock.Bit.AFIO       = 1;       //复用时钟
    CKCUClock.Bit.GPTM0      = 1;
    CKCU_PeripClockConfig(CKCUClock, ENABLE);      //时钟使能
    AFIO_GPxConfig(GPIO_PC,HTGPIO_PIN, AFIO_MODE_4);  //开启复用功能
		GPIO_DirectionConfig(HT_GPIOC,HTGPIO_PIN,GPIO_DIR_OUT);
		TM_ClearFlag(HT_GPTM0, TM_FLAG_UEV);  //清除更新中断标志
    TM_OutputStructInit(&OutIniture);    //填写每个变量的默认值

    //定时器时基以及计数方式初始化

    TimeBaseIniture.CounterMode = TM_CNT_MODE_UP;            //边沿对齐向上模式
    TimeBaseIniture.CounterReload = 200-1;                       //计数重装载计数器
    TimeBaseIniture.Prescaler = 4800 -1;                           //预分频系数
    TimeBaseIniture.PSCReloadTime=TM_PSC_RLD_IMMEDIATE;    //立即重装载
    TM_TimeBaseInit(HT_GPTM0,&TimeBaseIniture);
 
//  0通道输出 PA4
    OutIniture.Channel= TM_CH_0;
    OutIniture.Control= TM_CHCTL_ENABLE;         //GPTM通道使能
    OutIniture.OutputMode=TM_OM_PWM1 ;          //GPTM 通道 PWM1输出模式  PWM2模式翻转
    OutIniture.Polarity= TM_CHP_INVERTED;    //GPTM 通道极性是低电平或下降沿      
   // OutIniture.Compare=200;                      // 这个是配置占空比的
    TM_OutputModeConfig(HT_GPTM0,TM_CH_0,TM_OM_PWM1);
    TM_OutputInit(HT_GPTM0,&OutIniture);
 
 
//  1通道输出 PA5
    OutIniture.Channel=TM_CH_1;
    OutIniture.Control=TM_CHCTL_ENABLE;         //GPTM通道使能
    OutIniture.OutputMode=TM_OM_PWM1;          //GPTM 通道 PWM1输出模式  PWM2模式翻转
    OutIniture.Polarity=TM_CHP_INVERTED;     //GPTM 通道极性是低电平或下降沿        
    //OutIniture.Compare=200;                      // 这个是配置占空比的
    TM_OutputModeConfig(HT_GPTM0,TM_CH_1,TM_OM_PWM1);
    TM_OutputInit(HT_GPTM0,&OutIniture);


//  2通道输出 PA6
    OutIniture.Channel=TM_CH_2;
    OutIniture.Control=TM_CHCTL_ENABLE;         //GPTM通道使能
    OutIniture.OutputMode=TM_OM_PWM1;          //GPTM 通道 PWM1输出模式  PWM2模式翻转
    OutIniture.Polarity=TM_CHP_INVERTED;    //GPTM 通道极性是低电平或下降沿         
    //OutIniture.Compare=200;                      // 这个是配置占空比的
    TM_OutputModeConfig(HT_GPTM0,TM_CH_2,TM_OM_PWM1);
    TM_OutputInit(HT_GPTM0,&OutIniture);
 
//  3通道输出 PA7
    OutIniture.Channel=TM_CH_3;
    OutIniture.Control=TM_CHCTL_ENABLE;         //GPTM通道使能
    OutIniture.OutputMode=TM_OM_PWM1;          //GPTM 通道 PWM1输出模式  PWM2模式翻转
    OutIniture.Polarity=TM_CHP_INVERTED;    //GPTM 通道极性是低电平或下降沿        
   // OutIniture.Compare=200;                      // 这个是配置占空比的
    TM_OutputModeConfig(HT_GPTM0,TM_CH_3,TM_OM_PWM1);
    TM_OutputInit(HT_GPTM0,&OutIniture);
	
    TM_IntConfig(HT_GPTM0, TM_INT_CH0CC|TM_INT_CH1CC|TM_INT_CH2CC|TM_INT_CH3CC, ENABLE);  //中断		
    TM_Cmd(HT_GPTM0,ENABLE);  //使能计数
}


/**
 * 功能：舵机驱动(可从0~180，每45度旋转一次)
 * 参数：angle  ；舵机旋转度数(相对角度)
 * 返回值：None
 */
void Servo_Run(uint16_t angle)
{
    switch(angle)
    {
		case 180 :TM_SetCaptureCompare(HT_GPTM0,TM_CH_0,175); break;//对应180度
		case 135 :TM_SetCaptureCompare(HT_GPTM0,TM_CH_0,180); break;//对应135度
		case 90  :TM_SetCaptureCompare(HT_GPTM0,TM_CH_0,185); break;//对应90度
		case 45  :TM_SetCaptureCompare(HT_GPTM0,TM_CH_0,190); break;//对应45度
		case 0   :TM_SetCaptureCompare(HT_GPTM0,TM_CH_0,195); break;//对应0度
    }
}


void Servo_Run2(uint16_t angle)
{
    switch(angle)
    {
		case 180 :TM_SetCaptureCompare(HT_GPTM0,TM_CH_1,175); break;//对应180度
		case 135 :TM_SetCaptureCompare(HT_GPTM0,TM_CH_1,180); break;//对应135度
		case 90  :TM_SetCaptureCompare(HT_GPTM0,TM_CH_1,185); break;//对应90度
		case 45  :TM_SetCaptureCompare(HT_GPTM0,TM_CH_1,190); break;//对应45度
		case 0   :TM_SetCaptureCompare(HT_GPTM0,TM_CH_1,195); break;//对应0度
    }
}


void Servo_Run3(uint16_t angle)
{
    switch(angle)
    {
		case 180 :TM_SetCaptureCompare(HT_GPTM0,TM_CH_2,175); break;//对应180度
		case 135 :TM_SetCaptureCompare(HT_GPTM0,TM_CH_2,180); break;//对应135度
		case 90  :TM_SetCaptureCompare(HT_GPTM0,TM_CH_2,185); break;//对应90度
		case 45  :TM_SetCaptureCompare(HT_GPTM0,TM_CH_2,190); break;//对应45度
		case 0   :TM_SetCaptureCompare(HT_GPTM0,TM_CH_2,195); break;//对应0度
    }
}

void Servo_Run4(uint16_t angle)
{
    switch(angle)
    {
		case 180 :TM_SetCaptureCompare(HT_GPTM0,TM_CH_3,175); break;//对应180度
		case 135 :TM_SetCaptureCompare(HT_GPTM0,TM_CH_3,180); break;//对应135度
		case 90  :TM_SetCaptureCompare(HT_GPTM0,TM_CH_3,185); break;//对应90度
		case 45  :TM_SetCaptureCompare(HT_GPTM0,TM_CH_3,190); break;//对应45度
		case 0   :TM_SetCaptureCompare(HT_GPTM0,TM_CH_3,195); break;//对应0度
    }
}
