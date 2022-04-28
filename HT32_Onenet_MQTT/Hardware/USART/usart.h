#ifndef __USART_H
#define __USART_H 	

#include "ht32f5xxxx_usart.h"
#include "ht32f5xxxx_gpio.h"
#include "ht32_board.h"


//=================USART0================//
#define USART_GPIO_GROUP             GPIO_PA
#define USART_TX_PIN                 GPIO_PIN_2
#define USART_RX_PIN                 GPIO_PIN_3
#define USART_AFIO_MODE              (AFIO_FUN_USART_UART) //模式设置，默认模式：AFIO_MODE_DEFAULT ，AFIO_MODE_1~15对应模式1~15
#define USARTX_PORT                   HT_USART0



//===============USART1================//
#define USART1_GPIO_GROUP  GPIO_PA
#define USART1_TX_PIN      GPIO_PIN_4
#define USART1_RX_PIN      GPIO_PIN_5
#define USART1_AFIO_MODE   (AFIO_FUN_USART_UART)
#define USART1_PORT        HT_USART1
#define USART_DEBUG		     HT_USART1


void USART0_Configuration(void);
void USART1_Configuration(void);

void COM1_IRQHandler(void);
void Usart_Sendbyte(HT_USART_TypeDef* USARTx, u8 data);
void Usart_SendArray(HT_USART_TypeDef* USARTx, u8 *array,u8 num);
void Usart_SendStr(HT_USART_TypeDef* USARTx, char *str);
void USART_Tx(HT_USART_TypeDef* USARTx,const char* TxBuffer, u32 length);
void USART_Rx(const char* RxBuffer, u32 length);
void Int2Char_Send(HT_USART_TypeDef* USARTx,unsigned char N);
void USART_SEND_END(HT_USART_TypeDef* USARTx) ;

//串口调试信息输出函数
void UsartPrintf(HT_USART_TypeDef* USARTx, char *fmt,...);
void Usart_SendString(HT_USART_TypeDef *USARTx, unsigned char *str, unsigned short len);


#endif

