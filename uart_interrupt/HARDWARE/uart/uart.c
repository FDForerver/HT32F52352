#include "uart.h"

/************************************************************串口1 PA4 PA5**********************************************/
static void USART_CKCU_Config()
{
	CKCU_PeripClockConfig_TypeDef CCLOCK;
	
	CCLOCK.Bit.AFIO = 1;
	COM1_CLK(CCLOCK) = 1;
	
	CKCU_PeripClockConfig(CCLOCK, ENABLE);
}
 
static void USART_AFIO_Config()
{
	AFIO_GPxConfig(COM1_TX_GPIO_ID, COM1_TX_AFIO_PIN, AFIO_FUN_USART_UART);
	AFIO_GPxConfig(COM1_RX_GPIO_ID, COM1_RX_AFIO_PIN, AFIO_FUN_USART_UART);
}
 
static void USARTx_Config()
{
	USART_InitTypeDef USART_InitStructure;
	
	/*USART初始化
	*波特率：115200
	*字节长度：8位
	*停止位：1位
	*校验位：无			
	*模式：正常模式
	**/
	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_WordLength = USART_WORDLENGTH_8B;
	USART_InitStructure.USART_StopBits = USART_STOPBITS_1;
	USART_InitStructure.USART_Parity = USART_PARITY_NO;
	USART_InitStructure.USART_Mode = USART_MODE_NORMAL;
	USART_Init(COM1_PORT  , &USART_InitStructure);
	
	/* 设置USART中断标志 */
	USART_IntConfig(COM1_PORT, USART_INT_RXDR, ENABLE);
	/* 使能USART接收、发送 */
	USART_TxCmd(COM1_PORT, ENABLE);
	USART_RxCmd(COM1_PORT, ENABLE);
	/* 初始化中断 */
	NVIC_EnableIRQ(COM1_IRQn);
	
}
 
void USARTx_Init()
{
	USART_CKCU_Config();
	USART_AFIO_Config();
	USARTx_Config();
}



/************************************************************串口2 PA2 PA3**********************************************/
static void USART_CKCU_Config2()
{
	CKCU_PeripClockConfig_TypeDef CCLOCK;
	
	CCLOCK.Bit.AFIO = 1;
	COM_CLK(CCLOCK) = 1;
	
	CKCU_PeripClockConfig(CCLOCK, ENABLE);
}
 
static void USART_AFIO_Config2()
{
	AFIO_GPxConfig(COM_TX_GPIO_ID, COM_TX_AFIO_PIN, AFIO_FUN_USART_UART);
	AFIO_GPxConfig(COM_RX_GPIO_ID, COM_RX_AFIO_PIN, AFIO_FUN_USART_UART);
}
 
static void USARTx_Config2()
{
	USART_InitTypeDef USART_InitStructure;
	
	/*USART初始化
	*波特率：115200
	*字节长度：8位
	*停止位：1位
	*校验位：无			
	*模式：正常模式
	**/
	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_WordLength = USART_WORDLENGTH_8B;
	USART_InitStructure.USART_StopBits = USART_STOPBITS_1;
	USART_InitStructure.USART_Parity = USART_PARITY_NO;
	USART_InitStructure.USART_Mode = USART_MODE_NORMAL;
	USART_Init(COM_PORT  , &USART_InitStructure);
	
	/* 设置USART中断标志 */
	USART_IntConfig(COM_PORT, USART_INT_RXDR, ENABLE);
	/* 使能USART接收、发送 */
	USART_TxCmd(COM_PORT, ENABLE);
	USART_RxCmd(COM_PORT, ENABLE);
	/* 初始化中断 */
	NVIC_EnableIRQ(COM_IRQn);
	
}
 
void USARTx_Init2(void)
{
	USART_CKCU_Config2();
	USART_AFIO_Config2();
	USARTx_Config2();
}


void Uart_Init(void)
{
	 USARTx_Init();
	 USARTx_Init2();
}
/**********************************************共用代码****************************************************/
 
// 发送一个字节
void Usart_Sendbyte(HT_USART_TypeDef* USARTx, u8 Data)
{
	USART_SendData(USARTx, Data);
	// 等待发送数据寄存器清空
	while (USART_GetFlagStatus(USARTx, USART_FLAG_TXDE) == RESET);		
}
 
//发送每个元素数据长度为8位的数组
void Usart_SendArray(HT_USART_TypeDef* USARTx, u8 *array,u8 num)
{
	u8 i;
	for( i = 0;i < num;i++)
	{
		Usart_Sendbyte(USARTx,*array);
		array++;
	}
}
 
// 发送字符串
void Usart_SendStr(HT_USART_TypeDef* USARTx, uint8_t *str)
{
	uint8_t i;
	for(i = 0;str[i] != '\0';i++)
	{
		Usart_Sendbyte(USARTx,str[i]);
	}
}
 
// 重定向c库函数printf到串口，重定向后可使用printf函数
int fputc(int ch, FILE *f)
{
	/* 发送一个字节数据到串口 */
	USART_SendData(COM1_PORT, (uint8_t) ch);
		
	/* 等待发送完毕 */
	while (USART_GetFlagStatus(COM1_PORT, USART_FLAG_TXDE) == RESET);		
	
	return (ch);
}
 
// 重定向c库函数scanf到串口，重写向后可使用scanf、getchar等函数
int fgetc(FILE *f)
{
	/* 等待串口输入数据 */
	while (USART_GetFlagStatus(COM1_PORT, USART_FLAG_RXDNE) == RESET);
 
	return (int)USART_ReceiveData(COM1_PORT);
}
