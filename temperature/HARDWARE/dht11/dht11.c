#include "dht11.h"
#include "adc.h"



//数据定义:
//----以下变量均为全局变量--------
//----温度高8位== dou_dht11_temperature_data_h------
//----温度低8位== dou_dht11_temperature_data_l------
//----湿度高8位== dou_dht11_humidity_data_h-----
//----湿度低8位== dou_dht11_humidity_data_l-----
uint8_t dou_dht11_temperature_data_h, dou_dht11_temperature_data_l, dou_dht11_humidity_data_h, dou_dht11_humidity_data_l;
uint8_t temperature_data_h_temp, temperature_data_l_temp, humidity_data_h_temp, humidity_data_l_temp,checkdata_temp;
u8 wendu;

//设置通信引脚为输出
static void dou_dht11_pinset_out(void)
{
		GPIO_DirectionConfig(dou_dht11_HT_GPIOx, dou_dht11_GPIO_PIN, GPIO_DIR_OUT);          //设置方向为输出
		GPIO_OpenDrainConfig(dou_dht11_HT_GPIOx, dou_dht11_GPIO_PIN, DISABLE); 							//输出模式设置为推挽输出
		//GPIO_DriveConfig(dou_dht11_HT_GPIOx,dou_dht11_GPIO_PIN,GPIO_DIR_OUT,GPIO_DV_16MA); //设置输出驱动电流能力
}

//设置通信引脚为输入
static void dou_dht11_pinset_in(void)
{
		GPIO_DirectionConfig(dou_dht11_HT_GPIOx, dou_dht11_GPIO_PIN, GPIO_DIR_IN);        //设置方向为输入
		//GPIO_PullResistorConfig(dou_dht11_HT_GPIOx, dou_dht11_GPIO_PIN, GPIO_PR_DISABLE); //除能上下拉电阻
		GPIO_PullResistorConfig(dou_dht11_HT_GPIOx, dou_dht11_GPIO_PIN, GPIO_PR_UP);
		GPIO_InputConfig(dou_dht11_HT_GPIOx,dou_dht11_GPIO_PIN,ENABLE);
}

//初始化函数
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
    AFIO_GPxConfig(dou_dht11_GPIOx, dou_dht11_GPIO_PIN, AFIO_MODE_1); //配置引脚工作模式
    dou_dht11_pinset_out();
    GPIO_WriteOutBits(dou_dht11_HT_GPIOx, dou_dht11_GPIO_PIN, SET);
}

//获取引脚状态
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

//设置引脚输出
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


//读取一字节数据
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
    //主机拉低18ms? ?
    dou_dht11_set_databit(FALSE);
    delay_ms(18);
    dou_dht11_set_databit(TRUE);
    //总线由上拉电阻拉高 主机延时10us
    delay_us(20);
    //主机设为输入 判断从机响应信号 
    dou_dht11_pinset_in();
    //判断从机是否有低电平响应信号 如不响应则跳出，响应则向下运行?? ? ?
    if (dou_dht11_get_databit() == FALSE)		//T !?? ? ?
    {
        //判断从机是否发出 80us 的低电平响应信号是否结束?? ? 
        while (dou_dht11_get_databit() == FALSE);

        //判断从机是否发出 80us 的高电平，如发出则进入数据接收状态
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
        //数据接收状态 
        humidity_data_h_temp = dou_dht11_read_byte();	 	//接收湿度高八位
        humidity_data_l_temp = dou_dht11_read_byte(); 	//接收湿度低八位
        temperature_data_h_temp = dou_dht11_read_byte();//接收温度高八位
        temperature_data_l_temp = dou_dht11_read_byte();//接收温度低八位
        checkdata_temp = dou_dht11_read_byte();					//接收效验位
        /* Data transmission finishes, pull the bus high */
        dou_dht11_pinset_out();
        dou_dht11_set_databit(TRUE);
        //数据校验 
        temp = (temperature_data_h_temp + temperature_data_l_temp + humidity_data_h_temp + humidity_data_l_temp);
        if (temp == checkdata_temp)
        {
            dou_dht11_humidity_data_h = humidity_data_h_temp; 				//整数部分
            dou_dht11_humidity_data_l = humidity_data_l_temp;					//小数部分
            dou_dht11_temperature_data_h = temperature_data_h_temp;		//整数部分
            dou_dht11_temperature_data_l = temperature_data_l_temp;		//小数部分
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
