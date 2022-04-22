#ifndef _UART_H
#define _UART_H
 
#include "ht32f5xxxx_01.h"
#include <stdio.h>
 
//#define DEBUG_USART0					   (0)
//#define DEBUG_USART1					   (1)
// 
//#if 	DEBUG_USART0
//´®¿Ú0 USART - 0

#define COM_CLK(CK)                (CK.Bit.USART0)
#define COM_PORT                   (HT_USART0)
#define COM_IRQn                   (USART0_IRQn)
#define COM_IRQHandler             (USART0_IRQHandler)
 
#define COM_TX_GPIO_ID             (GPIO_PA)
#define COM_TX_AFIO_PIN            (AFIO_PIN_2)
#define COM_TX_AFIO_MODE           (AFIO_FUN_USART_UART)
 
#define COM_RX_GPIO_ID             (GPIO_PA)
#define COM_RX_AFIO_PIN            (AFIO_PIN_3)
#define COM_RX_AFIO_MODE           (AFIO_FUN_USART_UART)
 
//	DEBUG_USART1 
//´®¿Ú1 USART - 1
#define COM1_CLK(CK)                (CK.Bit.USART1)
#define COM1_PORT                   (HT_USART1)
#define COM1_IRQn                   (USART1_IRQn)
#define COM1_IRQHandler             (USART1_IRQHandler)
 
#define COM1_TX_GPIO_ID             (GPIO_PA)
#define COM1_TX_AFIO_PIN            (AFIO_PIN_4)
#define COM1_TX_AFIO_MODE           (AFIO_FUN_USART_UART)
 
#define COM1_RX_GPIO_ID             (GPIO_PA)
#define COM1_RX_AFIO_PIN            (AFIO_PIN_5)
#define COM1_RX_AFIO_MODE           (AFIO_FUN_USART_UART)
 
//#endif
void Uart_Init(void); 
void USARTx_Init(void);
void USARTx_Init2(void);
void Usart_Sendbyte(HT_USART_TypeDef* USARTx, u8 Data);
void Usart_SendArray(HT_USART_TypeDef* USARTx, u8 *array,u8 num);
void Usart_SendStr(HT_USART_TypeDef* USARTx, uint8_t *str);
 
#endif
