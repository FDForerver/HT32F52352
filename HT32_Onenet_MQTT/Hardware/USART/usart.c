#include "usart.h"
#include "esp8266.h"
#include "delay.h"
#include "HT32F52352_SK.H"
#include "ht32_board_config.h"

//C��
#include <stdarg.h>


/* Global variables ----------------------------------------------------------------------------------------*/
uc8  *gURTx_Ptr;
vu32 gURTx_Length = 0;
u8  *gURRx_Ptr;
vu32 gURRx_Length = 0;

vu32 gIsTxFinished = FALSE;

/* Private variables ---------------------------------------------------------------------------------------*/
uc8 gHelloString[] = "Hello, this is USART Tx/Rx FIFO example. Please enter 5 characters...\r\n";
u8 gTx_Buffer[128];
u8 gRx_Buffer[128];



/**************************ʵ�ֺ���********************************************
����˵��������usart0����

*******************************************************************************/ 
void USART0_Configuration(void)
{
  gURRx_Ptr = gRx_Buffer;
	
	
	#if 0 // Use following function to configure the IP clock speed.
  // The UxART IP clock speed must be faster 16x then the baudrate.
  CKCU_SetPeripPrescaler(CKCU_PCLK_UxARTn, CKCU_APBCLKPRE_DIV2);
  #endif
	
	{
		CKCU_PeripClockConfig_TypeDef CKCUClock= {{0}};
		CKCUClock.Bit.AFIO = 1;
		CKCUClock.Bit.PA=1;
		CKCUClock.Bit.USART0=1;
		CKCU_PeripClockConfig(CKCUClock, ENABLE);
	}
	//HTCFG_UART_IPN 
	GPIO_PullResistorConfig(HT_GPIOA, GPIO_PIN_3, GPIO_PR_UP);
	
  AFIO_GPxConfig(USART_GPIO_GROUP, USART_TX_PIN, AFIO_FUN_USART_UART);
  AFIO_GPxConfig(USART_GPIO_GROUP, USART_RX_PIN, AFIO_FUN_USART_UART);

  /*
		�����ʣ� 115200
		���ȣ�   8bits
		ֹͣλ�� 1λ
	  У��λ�� ��			
	  ģʽ��   ����ģʽ
  */
	USART_InitTypeDef USART_InitStructure={0};
	
	
  USART_InitStructure.USART_BaudRate = 115200;
  USART_InitStructure.USART_WordLength = USART_WORDLENGTH_8B;
  USART_InitStructure.USART_StopBits = USART_STOPBITS_1;
  USART_InitStructure.USART_Parity = USART_PARITY_NO;
  USART_InitStructure.USART_Mode = USART_MODE_NORMAL;
  USART_Init(COM0_PORT, &USART_InitStructure);

	 //Enable �ж�����    
  NVIC_EnableIRQ(COM0_IRQn);
	
	// Enable UxART Tx and Rx interrupt  
   USART_IntConfig(COM0_PORT, USART_INT_RXDR , ENABLE);
	
  // ʹ�� COM1_PORT  ���ͺͽ��� 
  USART_TxCmd(COM0_PORT, ENABLE);
  USART_RxCmd(COM0_PORT, ENABLE);
	
}


/**************************ʵ�ֺ���********************************************
����˵��������HT_USATR1����
���ߣ�LIANG WENFA
���ڣ�2021��1��26��

*******************************************************************************/ 
void USART1_Configuration(void)
{
	CKCU_PeripClockConfig_TypeDef CKCUClock= {{0}};
	CKCUClock.Bit.AFIO = 1;
	CKCUClock.Bit.PA=1;
	COM1_CLK(CKCUClock)  = 1;  //����COM0 ʱ��
	CKCU_PeripClockConfig(CKCUClock, ENABLE);
	
	GPIO_PullResistorConfig(HT_GPIOA, GPIO_PIN_5, GPIO_PR_UP);
	
  AFIO_GPxConfig(USART1_GPIO_GROUP, USART1_TX_PIN, AFIO_FUN_USART_UART);
  AFIO_GPxConfig(USART1_GPIO_GROUP, USART1_RX_PIN, AFIO_FUN_USART_UART);

  /*
		�����ʣ� 115200
		���ȣ�   8bits
		ֹͣλ�� 1λ
	  У��λ�� ��			
	  ģʽ��   ����ģʽ
  */
	USART_InitTypeDef USART_InitStructure={0};
	
  USART_InitStructure.USART_BaudRate = 115200;
  USART_InitStructure.USART_WordLength = USART_WORDLENGTH_8B;
  USART_InitStructure.USART_StopBits = USART_STOPBITS_1;
  USART_InitStructure.USART_Parity = USART_PARITY_NO;
  USART_InitStructure.USART_Mode = USART_MODE_NORMAL;
  USART_Init(COM1_PORT, &USART_InitStructure);

	
  // ʹ�� COM1_PORT  ���ͺͽ��� 
  USART_TxCmd(COM1_PORT, ENABLE);
  USART_RxCmd(COM1_PORT, ENABLE);
	
}


//==========================================================
//	�������ƣ�	USART0_IRQHandler
//
//	�������ܣ�	���ڽ����ж�
//
//	��ڲ�����	��
//
//	���ز�����	��
//
//	˵����		
//==========================================================


/*

void USART0_IRQHandler(void)
{
	
 // bool bIsRxDataReady = FALSE;

  #if (DEBUG_IO == 1)
  #define DBG_IO1_LO()    HT32F_DVB_LEDOn(HT_LED1)
  #define DBG_IO1_HI()    HT32F_DVB_LEDOff(HT_LED1)
  #define DBG_IO2_LO()    HT32F_DVB_LEDOn(HT_LED2)
  #define DBG_IO2_HI()    HT32F_DVB_LEDOff(HT_LED2)
#else
  #define DBG_IO1_LO(...)
  #define DBG_IO1_HI(...)
  #define DBG_IO2_LO(...)
  #define DBG_IO2_HI(...)
#endif

  // Rx: Move data from UART to buffer      //
  if (USART_GetFlagStatus(COM0_PORT , USART_FLAG_RXDR))
  {
    DBG_IO1_LO();
    gURRx_Ptr[gURRx_Length++] = USART_ReceiveData(COM0_PORT);
    DBG_IO1_HI();

    #if 0
    if (gURRx_Length == 128)
    {
      while (1) {}; // Rx Buffer full
    }
    #endif
  }

  // Tx, move data from buffer to UART //
  if (USART_GetIntStatus(COM0_PORT, USART_INT_TXDE) &&
      USART_GetFlagStatus(COM0_PORT, USART_FLAG_TXDE))
  {
    DBG_IO2_LO();
    if (gURTx_Length > 0)
    {
      USART_SendData(COM0_PORT, *gURTx_Ptr++);
      gURTx_Length--;
      if (gURTx_Length == 0)
      {
        USART_IntConfig(COM0_PORT, USART_INT_TXDE, DISABLE);
      }
    }
    DBG_IO2_HI();
  }

  if (USART_GetIntStatus(COM0_PORT, USART_INT_TXC) &&
      USART_GetFlagStatus(COM0_PORT, USART_FLAG_TXC))
  {
    USART_IntConfig(COM0_PORT, USART_INT_TXC, DISABLE);
    gIsTxFinished = TRUE;
  }

}
*/

/**************************ʵ�ֺ���********************************************
����˵���������жϷ�����

*******************************************************************************
void COM1_IRQHandler(void)
{
	u8 data;
	
	if( USART_GetFlagStatus(COM1_PORT, USART_FLAG_RXDR ) )         //�����ж�
	{
		data = USART_ReceiveData(COM1_PORT);                         //��ȡ���յ�������
		printf("data = %c\n",data);                                  //���յ������ݷ��ͻص���		
	}
}
*/

/**************************ʵ�ֺ���********************************************
����˵����FIFO

*******************************************************************************/ 
void USART_Tx(HT_USART_TypeDef* USARTx,const char* TxBuffer, u32 length)
{
  int i;

  for (i = 0; i < length; i++)
  {
    while (!USART_GetFlagStatus(USARTx, USART_FLAG_TXC));
    USART_SendData(USARTx, TxBuffer[i]);
  }
}


/**************************ʵ�ֺ���********************************************
����˵��������һ���ֽ�

*******************************************************************************/ 
void Usart_Sendbyte(HT_USART_TypeDef* USARTx, u8 data)
{
	USART_SendData(USARTx, data);
	while (USART_GetFlagStatus(USARTx, USART_FLAG_TXDE) == RESET);		
}
 
/**************************ʵ�ֺ���********************************************
����˵������������

*******************************************************************************/ 
void Usart_SendArray(HT_USART_TypeDef* USARTx, u8 *array,u8 num)
{
	u8 i;
	for( i = 0;i < num;i++)
	{
		Usart_Sendbyte(USARTx,*array);
		array++;
	}
}
 /**************************ʵ�ֺ���********************************************
����˵���������ַ���

*******************************************************************************/ 

void Usart_SendStr(HT_USART_TypeDef* USARTx, char *str)
{
	uint8_t i;
	for(i = 0;str[i] != '\0';i++)
	{
		Usart_Sendbyte(USARTx,str[i]);
	}
}

/****************************���²���Ϊ�Ծ�����Ļ���ں���*******************************/

void USART_SEND_END(HT_USART_TypeDef* USARTx)   //���ͽ�����
{
	 Usart_Sendbyte(USARTx,0xFF);
	 Usart_Sendbyte(USARTx,0xFF);
	 Usart_Sendbyte(USARTx,0xFF);	
}


void Int2Char_Send(HT_USART_TypeDef* USARTx,unsigned char N) //���¶���ֵ�ֽ�Ϊ ��λ��ʮλ����λ  ����ת��Ϊ�ַ����ͳ�ȥ
{ unsigned char g,s,b,l;
  l=N;
  b=l/100; //�ֽ��ð�λ���� �� 117/100=1.17  �Զ���ȥС��λ��  1
  l=l%100; //ȡ���� ��ȥ����λ �� 17
  s=l/10;  //17/10=1.7
  l=l%10;  //�� 7
  g=l;	   //  7
	

   //  48,49,50,51,52,53,54,55,56,57  �ַ��ֽڱ��ַ�0-9���ֽ��� 
  if(b==0) // ��λΪ 0 �Ͳ�������
  {
		if(s==0); // ʮλΪ 0 �Ͳ�������
		else Usart_Sendbyte(USARTx,s+48);
  }
  else 
	{ 
   	Usart_Sendbyte(USARTx,b+48);  // �ֽ�48=�ַ�0   �����λ��1   1+48=49   ��=�ַ� ��1��
	  Usart_Sendbyte(USARTx,s+48);
  }

   Usart_Sendbyte(USARTx,g+48);   //��λ�����ǲ���0  ������
}


void Usart_SendString(HT_USART_TypeDef *USARTx, unsigned char *str, unsigned short len)
{

	unsigned short count = 0;
	
	for(; count < len; count++)
	{
		USART_SendData(USARTx, *str++);									//��������
		while(USART_GetFlagStatus(USARTx, USART_FLAG_TXDE) == RESET);		//�ȴ��������
	}

}


/*
************************************************************
*	�������ƣ�	UsartPrintf
*
*	�������ܣ�	��ʽ����ӡ��Ϣ�����ڵ���
*
*	��ڲ�����	USARTx��������
*				fmt����������
*
*	���ز�����	��
*
*	˵����		
************************************************************
*/
void UsartPrintf(HT_USART_TypeDef* USARTx, char *fmt,...)
{

	unsigned char UsartPrintfBuf[296];
	va_list ap;
	unsigned char *pStr = UsartPrintfBuf;
	
	va_start(ap, fmt);
	vsnprintf((char *)UsartPrintfBuf, sizeof(UsartPrintfBuf), fmt, ap);							//��ʽ��
	va_end(ap);
	
	while(*pStr != 0)
	{
		USART_SendData(USARTx, *pStr++);
		while(USART_GetFlagStatus(USARTx, USART_FLAG_TXDE) == RESET);
	}

}





