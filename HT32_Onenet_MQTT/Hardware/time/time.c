#include "time.h"
#include "delay.h"



//�����·PWM�����ƺ����������
//arr���Զ���װֵ
//psc��ʱ��Ԥ��Ƶ��
//GT0 PA4 PA5 PA6 PA7
//����һ��20ms ��ʱ���� 
void GPTM_PWM_init(void)
{
 
    TM_TimeBaseInitTypeDef TimeBaseIniture;   //�ṹ��
    TM_OutputInitTypeDef   OutIniture;
 
    CKCU_PeripClockConfig_TypeDef CKCUClock = {{0}};
    CKCUClock.Bit.PC        = 1;       //GPIOAʱ�Ӵ�
    CKCUClock.Bit.AFIO       = 1;       //����ʱ��
    CKCUClock.Bit.GPTM0      = 1;
    CKCU_PeripClockConfig(CKCUClock, ENABLE);      //ʱ��ʹ��
    AFIO_GPxConfig(GPIO_PC,HTGPIO_PIN, AFIO_MODE_4);  //�������ù���
		GPIO_DirectionConfig(HT_GPIOC,HTGPIO_PIN,GPIO_DIR_OUT);
		TM_ClearFlag(HT_GPTM0, TM_FLAG_UEV);  //��������жϱ�־
    TM_OutputStructInit(&OutIniture);    //��дÿ��������Ĭ��ֵ

    //��ʱ��ʱ���Լ�������ʽ��ʼ��

    TimeBaseIniture.CounterMode = TM_CNT_MODE_UP;            //���ض�������ģʽ
    TimeBaseIniture.CounterReload = 200-1;                       //������װ�ؼ�����
    TimeBaseIniture.Prescaler = 4800 -1;                           //Ԥ��Ƶϵ��
    TimeBaseIniture.PSCReloadTime=TM_PSC_RLD_IMMEDIATE;    //������װ��
    TM_TimeBaseInit(HT_GPTM0,&TimeBaseIniture);
 
//  0ͨ����� PA4
    OutIniture.Channel= TM_CH_0;
    OutIniture.Control= TM_CHCTL_ENABLE;         //GPTMͨ��ʹ��
    OutIniture.OutputMode=TM_OM_PWM1 ;          //GPTM ͨ�� PWM1���ģʽ  PWM2ģʽ��ת
    OutIniture.Polarity= TM_CHP_INVERTED;    //GPTM ͨ�������ǵ͵�ƽ���½���      
   // OutIniture.Compare=200;                      // ���������ռ�ձȵ�
    TM_OutputModeConfig(HT_GPTM0,TM_CH_0,TM_OM_PWM1);
    TM_OutputInit(HT_GPTM0,&OutIniture);
 
 
//  1ͨ����� PA5
    OutIniture.Channel=TM_CH_1;
    OutIniture.Control=TM_CHCTL_ENABLE;         //GPTMͨ��ʹ��
    OutIniture.OutputMode=TM_OM_PWM1;          //GPTM ͨ�� PWM1���ģʽ  PWM2ģʽ��ת
    OutIniture.Polarity=TM_CHP_INVERTED;     //GPTM ͨ�������ǵ͵�ƽ���½���        
    //OutIniture.Compare=200;                      // ���������ռ�ձȵ�
    TM_OutputModeConfig(HT_GPTM0,TM_CH_1,TM_OM_PWM1);
    TM_OutputInit(HT_GPTM0,&OutIniture);


//  2ͨ����� PA6
    OutIniture.Channel=TM_CH_2;
    OutIniture.Control=TM_CHCTL_ENABLE;         //GPTMͨ��ʹ��
    OutIniture.OutputMode=TM_OM_PWM1;          //GPTM ͨ�� PWM1���ģʽ  PWM2ģʽ��ת
    OutIniture.Polarity=TM_CHP_INVERTED;    //GPTM ͨ�������ǵ͵�ƽ���½���         
    //OutIniture.Compare=200;                      // ���������ռ�ձȵ�
    TM_OutputModeConfig(HT_GPTM0,TM_CH_2,TM_OM_PWM1);
    TM_OutputInit(HT_GPTM0,&OutIniture);
 
//  3ͨ����� PA7
    OutIniture.Channel=TM_CH_3;
    OutIniture.Control=TM_CHCTL_ENABLE;         //GPTMͨ��ʹ��
    OutIniture.OutputMode=TM_OM_PWM1;          //GPTM ͨ�� PWM1���ģʽ  PWM2ģʽ��ת
    OutIniture.Polarity=TM_CHP_INVERTED;    //GPTM ͨ�������ǵ͵�ƽ���½���        
   // OutIniture.Compare=200;                      // ���������ռ�ձȵ�
    TM_OutputModeConfig(HT_GPTM0,TM_CH_3,TM_OM_PWM1);
    TM_OutputInit(HT_GPTM0,&OutIniture);
	
    TM_IntConfig(HT_GPTM0, TM_INT_CH0CC|TM_INT_CH1CC|TM_INT_CH2CC|TM_INT_CH3CC, ENABLE);  //�ж�		
    TM_Cmd(HT_GPTM0,ENABLE);  //ʹ�ܼ���
}


/**
 * ���ܣ��������(�ɴ�0~180��ÿ45����תһ��)
 * ������angle  �������ת����(��ԽǶ�)
 * ����ֵ��None
 */
void Servo_Run(uint16_t angle)
{
    switch(angle)
    {
		case 180 :TM_SetCaptureCompare(HT_GPTM0,TM_CH_0,175); break;//��Ӧ180��
		case 135 :TM_SetCaptureCompare(HT_GPTM0,TM_CH_0,180); break;//��Ӧ135��
		case 90  :TM_SetCaptureCompare(HT_GPTM0,TM_CH_0,185); break;//��Ӧ90��
		case 45  :TM_SetCaptureCompare(HT_GPTM0,TM_CH_0,190); break;//��Ӧ45��
		case 0   :TM_SetCaptureCompare(HT_GPTM0,TM_CH_0,195); break;//��Ӧ0��
    }
}


void Servo_Run2(uint16_t angle)
{
    switch(angle)
    {
		case 180 :TM_SetCaptureCompare(HT_GPTM0,TM_CH_1,175); break;//��Ӧ180��
		case 135 :TM_SetCaptureCompare(HT_GPTM0,TM_CH_1,180); break;//��Ӧ135��
		case 90  :TM_SetCaptureCompare(HT_GPTM0,TM_CH_1,185); break;//��Ӧ90��
		case 45  :TM_SetCaptureCompare(HT_GPTM0,TM_CH_1,190); break;//��Ӧ45��
		case 0   :TM_SetCaptureCompare(HT_GPTM0,TM_CH_1,195); break;//��Ӧ0��
    }
}


void Servo_Run3(uint16_t angle)
{
    switch(angle)
    {
		case 180 :TM_SetCaptureCompare(HT_GPTM0,TM_CH_2,175); break;//��Ӧ180��
		case 135 :TM_SetCaptureCompare(HT_GPTM0,TM_CH_2,180); break;//��Ӧ135��
		case 90  :TM_SetCaptureCompare(HT_GPTM0,TM_CH_2,185); break;//��Ӧ90��
		case 45  :TM_SetCaptureCompare(HT_GPTM0,TM_CH_2,190); break;//��Ӧ45��
		case 0   :TM_SetCaptureCompare(HT_GPTM0,TM_CH_2,195); break;//��Ӧ0��
    }
}

void Servo_Run4(uint16_t angle)
{
    switch(angle)
    {
		case 180 :TM_SetCaptureCompare(HT_GPTM0,TM_CH_3,175); break;//��Ӧ180��
		case 135 :TM_SetCaptureCompare(HT_GPTM0,TM_CH_3,180); break;//��Ӧ135��
		case 90  :TM_SetCaptureCompare(HT_GPTM0,TM_CH_3,185); break;//��Ӧ90��
		case 45  :TM_SetCaptureCompare(HT_GPTM0,TM_CH_3,190); break;//��Ӧ45��
		case 0   :TM_SetCaptureCompare(HT_GPTM0,TM_CH_3,195); break;//��Ӧ0��
    }
}
