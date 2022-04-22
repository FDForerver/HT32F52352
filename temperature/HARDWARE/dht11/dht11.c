#include "dht11.h"
#include "adc.h"



//���ݶ���:
//----���±�����Ϊȫ�ֱ���--------
//----�¶ȸ�8λ== dou_dht11_temperature_data_h------
//----�¶ȵ�8λ== dou_dht11_temperature_data_l------
//----ʪ�ȸ�8λ== dou_dht11_humidity_data_h-----
//----ʪ�ȵ�8λ== dou_dht11_humidity_data_l-----
uint8_t dou_dht11_temperature_data_h, dou_dht11_temperature_data_l, dou_dht11_humidity_data_h, dou_dht11_humidity_data_l;
uint8_t temperature_data_h_temp, temperature_data_l_temp, humidity_data_h_temp, humidity_data_l_temp,checkdata_temp;
u8 wendu;

//����ͨ������Ϊ���
static void dou_dht11_pinset_out(void)
{
		GPIO_DirectionConfig(dou_dht11_HT_GPIOx, dou_dht11_GPIO_PIN, GPIO_DIR_OUT);          //���÷���Ϊ���
		GPIO_OpenDrainConfig(dou_dht11_HT_GPIOx, dou_dht11_GPIO_PIN, DISABLE); 							//���ģʽ����Ϊ�������
		//GPIO_DriveConfig(dou_dht11_HT_GPIOx,dou_dht11_GPIO_PIN,GPIO_DIR_OUT,GPIO_DV_16MA); //�������������������
}

//����ͨ������Ϊ����
static void dou_dht11_pinset_in(void)
{
		GPIO_DirectionConfig(dou_dht11_HT_GPIOx, dou_dht11_GPIO_PIN, GPIO_DIR_IN);        //���÷���Ϊ����
		//GPIO_PullResistorConfig(dou_dht11_HT_GPIOx, dou_dht11_GPIO_PIN, GPIO_PR_DISABLE); //��������������
		GPIO_PullResistorConfig(dou_dht11_HT_GPIOx, dou_dht11_GPIO_PIN, GPIO_PR_UP);
		GPIO_InputConfig(dou_dht11_HT_GPIOx,dou_dht11_GPIO_PIN,ENABLE);
}

//��ʼ������
void dou_dht11_init(void)
{
    CKCU_PeripClockConfig_TypeDef CKCUClock = {{0}};
    if (dou_dht11_GPIOx == GPIO_PA)
    {
        CKCUClock.Bit.PA = 1;
    }
    else if (dou_dht11_GPIOx == GPIO_PB)
    {
        CKCUClock.Bit.PB = 1;
    }
    else if (dou_dht11_GPIOx == GPIO_PC)
    {
        CKCUClock.Bit.PC = 1;
    }
    else if (dou_dht11_GPIOx == GPIO_PD)
    {
        CKCUClock.Bit.PD = 1;
    }
    CKCUClock.Bit.AFIO = 1;
    CKCU_PeripClockConfig(CKCUClock, ENABLE);
    AFIO_GPxConfig(dou_dht11_GPIOx, dou_dht11_GPIO_PIN, AFIO_MODE_1); //�������Ź���ģʽ
    dou_dht11_pinset_out();
    GPIO_WriteOutBits(dou_dht11_HT_GPIOx, dou_dht11_GPIO_PIN, SET);
}

//��ȡ����״̬
bool dou_dht11_get_databit(void)
{
    if (GPIO_ReadInBit(dou_dht11_HT_GPIOx, dou_dht11_GPIO_PIN) != RESET)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

//�����������
void dou_dht11_set_databit(bool level)
{
		if (level != FALSE)
    {
        GPIO_WriteOutBits(dou_dht11_HT_GPIOx, dou_dht11_GPIO_PIN, SET);
    }
    else
    {
        GPIO_WriteOutBits(dou_dht11_HT_GPIOx, dou_dht11_GPIO_PIN, RESET);
    }
}


//��ȡһ�ֽ�����
static uint8_t dou_dht11_read_byte(void)
{
    uint8_t i;
    uint8_t data = 0;
    for (i = 0; i < 8; i++)
    {
        data <<= 1;
        while ((!dou_dht11_get_databit()));
        delay_us(30);
        if (dou_dht11_get_databit())
        {
            data |= 0x1;
            while(dou_dht11_get_databit());
        }
        else
        {
            
        }
    }
    return data;
}

static bool dou_dht11_start_sampling(void)
{
    dou_dht11_pinset_out();
    //��������18ms? ?
    dou_dht11_set_databit(FALSE);
    delay_ms(18);
    dou_dht11_set_databit(TRUE);
    //������������������ ������ʱ10us
    delay_us(20);
    //������Ϊ���� �жϴӻ���Ӧ�ź� 
    dou_dht11_pinset_in();
    //�жϴӻ��Ƿ��е͵�ƽ��Ӧ�ź� �粻��Ӧ����������Ӧ����������?? ? ?
    if (dou_dht11_get_databit() == FALSE)		//T !?? ? ?
    {
        //�жϴӻ��Ƿ񷢳� 80us �ĵ͵�ƽ��Ӧ�ź��Ƿ����?? ? 
        while (dou_dht11_get_databit() == FALSE);

        //�жϴӻ��Ƿ񷢳� 80us �ĸߵ�ƽ���緢����������ݽ���״̬
        while (dou_dht11_get_databit() != FALSE);
        return TRUE;
    }
    return FALSE;
}

void dou_dht11_get_data(void)
{
		uint8_t temp;
   // ADC_IntConfig(HT_ADC, ADC_INT_SINGLE_EOC, DISABLE);
    
    if (dou_dht11_start_sampling())
    {
        //printf("DHT11 is ready to transmit data\r\n");
        //���ݽ���״̬ 
        humidity_data_h_temp = dou_dht11_read_byte();	 	//����ʪ�ȸ߰�λ
        humidity_data_l_temp = dou_dht11_read_byte(); 	//����ʪ�ȵͰ�λ
        temperature_data_h_temp = dou_dht11_read_byte();//�����¶ȸ߰�λ
        temperature_data_l_temp = dou_dht11_read_byte();//�����¶ȵͰ�λ
        checkdata_temp = dou_dht11_read_byte();					//����Ч��λ
        /* Data transmission finishes, pull the bus high */
        dou_dht11_pinset_out();
        dou_dht11_set_databit(TRUE);
        //����У�� 
        temp = (temperature_data_h_temp + temperature_data_l_temp + humidity_data_h_temp + humidity_data_l_temp);
        if (temp == checkdata_temp)
        {
            dou_dht11_humidity_data_h = humidity_data_h_temp; 				//��������
            dou_dht11_humidity_data_l = humidity_data_l_temp;					//С������
            dou_dht11_temperature_data_h = temperature_data_h_temp;		//��������
            dou_dht11_temperature_data_l = temperature_data_l_temp;		//С������
        }
				       
    }
//    else
//    {
//        
//    }
//       ADC_IntConfig(HT_ADC, ADC_INT_SINGLE_EOC, ENABLE);   
    
}

//void dou_dht11_test(void)
//{
//    while (1)
//    {
//        dou_dht11_get_data();
//        delay_ms(1000);
//    }
//}
