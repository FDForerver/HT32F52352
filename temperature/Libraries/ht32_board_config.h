/*********************************************************************************************************//**
 * @file    USART/Interrupt/ht32_board_config.h
 * @version $Rev:: 5575         $
 * @date    $Date:: 2021-08-18 #$
 * @brief   The header file of board configuration.
 *************************************************************************************************************
 * @attention
 *
 * Firmware Disclaimer Information
 *
 * 1. The customer hereby acknowledges and agrees that the program technical documentation, including the
 *    code, which is supplied by Holtek Semiconductor Inc., (hereinafter referred to as "HOLTEK") is the
 *    proprietary and confidential intellectual property of HOLTEK, and is protected by copyright law and
 *    other intellectual property laws.
 *
 * 2. The customer hereby acknowledges and agrees that the program technical documentation, including the
 *    code, is confidential information belonging to HOLTEK, and must not be disclosed to any third parties
 *    other than HOLTEK and the customer.
 *
 * 3. The program technical documentation, including the code, is provided "as is" and for customer reference
 *    only. After delivery by HOLTEK, the customer shall use the program technical documentation, including
 *    the code, at their own risk. HOLTEK disclaims any expressed, implied or statutory warranties, including
 *    the warranties of merchantability, satisfactory quality and fitness for a particular purpose.
 *
 * <h2><center>Copyright (C) Holtek Semiconductor Inc. All rights reserved</center></h2>
 ************************************************************************************************************/
/* Define to prevent recursive inclusion -------------------------------------------------------------------*/
#ifndef __HT32_BOARD_CONFIG_H
#define __HT32_BOARD_CONFIG_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Settings ------------------------------------------------------------------------------------------------*/
#if defined(USE_HT32F52230_SK)
  #define _HTCFG_UART_TX_GPIOX                    A
  #define _HTCFG_UART_TX_GPION                    4
  #define _HTCFG_UART_RX_GPIOX                    A
  #define _HTCFG_UART_RX_GPION                    5
  #define HTCFG_UART_IPN                          UART0
#endif

#if defined(USE_HT32F52241_SK)
  #define _HTCFG_UART_TX_GPIOX                    A
  #define _HTCFG_UART_TX_GPION                    4
  #define _HTCFG_UART_RX_GPIOX                    A
  #define _HTCFG_UART_RX_GPION                    5
  #define HTCFG_UART_IPN                          UART1
#endif

#if defined(USE_HT32F52253_SK)
  #define _HTCFG_UART_TX_GPIOX                    A
  #define _HTCFG_UART_TX_GPION                    4
  #define _HTCFG_UART_RX_GPIOX                    A
  #define _HTCFG_UART_RX_GPION                    5
  #define HTCFG_UART_IPN                          USART1
#endif

#if defined(USE_HT32F52341_SK)
  #define _HTCFG_UART_TX_GPIOX                    A
  #define _HTCFG_UART_TX_GPION                    4
  #define _HTCFG_UART_RX_GPIOX                    A
  #define _HTCFG_UART_RX_GPION                    5
  #define HTCFG_UART_IPN                          UART1
#endif

#if defined(USE_HT32F52352_SK)
  #define _HTCFG_UART_TX_GPIOX                    A
  #define _HTCFG_UART_TX_GPION                    4
  #define _HTCFG_UART_RX_GPIOX                    A
  #define _HTCFG_UART_RX_GPION                    5
  #define HTCFG_UART_IPN                          USART1
#endif

#if defined(USE_HT32F0008_SK)
  #define _HTCFG_UART_TX_GPIOX                    A
  #define _HTCFG_UART_TX_GPION                    4
  #define _HTCFG_UART_RX_GPIOX                    A
  #define _HTCFG_UART_RX_GPION                    5
  #define HTCFG_UART_IPN                          UART0
#endif

#if defined(USE_HT32F50230_SK)
  #define _HTCFG_UART_TX_GPIOX                    A
  #define _HTCFG_UART_TX_GPION                    4
  #define _HTCFG_UART_RX_GPIOX                    A
  #define _HTCFG_UART_RX_GPION                    5
  #define HTCFG_UART_IPN                          UART1
#endif

#if defined(USE_HT32F50241_SK)
  #define _HTCFG_UART_TX_GPIOX                    A
  #define _HTCFG_UART_TX_GPION                    4
  #define _HTCFG_UART_RX_GPIOX                    A
  #define _HTCFG_UART_RX_GPION                    5
  #define HTCFG_UART_IPN                          UART1
#endif

#if defined(USE_HT32F52354_SK)
  #define _HTCFG_UART_TX_GPIOX                    A
  #define _HTCFG_UART_TX_GPION                    4
  #define _HTCFG_UART_RX_GPIOX                    A
  #define _HTCFG_UART_RX_GPION                    5
  #define HTCFG_UART_IPN                          UART1
#endif

#if defined(USE_HT32F0006_DVB)
  #define _HTCFG_UART_TX_GPIOX                    A
  #define _HTCFG_UART_TX_GPION                    2
  #define _HTCFG_UART_RX_GPIOX                    A
  #define _HTCFG_UART_RX_GPION                    3
  #define HTCFG_UART_IPN                          USART0
#endif

#if defined(USE_HT32F57341_SK)
  #define _HTCFG_UART_TX_GPIOX                    A
  #define _HTCFG_UART_TX_GPION                    4
  #define _HTCFG_UART_RX_GPIOX                    A
  #define _HTCFG_UART_RX_GPION                    5
  #define HTCFG_UART_IPN                          USART0
#endif

#if defined(USE_HT32F57352_SK)
  #define _HTCFG_UART_TX_GPIOX                    A
  #define _HTCFG_UART_TX_GPION                    4
  #define _HTCFG_UART_RX_GPIOX                    A
  #define _HTCFG_UART_RX_GPION                    5
  #define HTCFG_UART_IPN                          USART0
#endif

#if defined(USE_HT32F52367_SK)
  #define _HTCFG_UART_TX_GPIOX                    A
  #define _HTCFG_UART_TX_GPION                    4
  #define _HTCFG_UART_RX_GPIOX                    A
  #define _HTCFG_UART_RX_GPION                    5
  #define HTCFG_UART_IPN                          USART1
#endif

#if defined(USE_HT32F50343_SK)
  #define _HTCFG_UART_TX_GPIOX                    A
  #define _HTCFG_UART_TX_GPION                    4
  #define _HTCFG_UART_RX_GPIOX                    A
  #define _HTCFG_UART_RX_GPION                    5
  #define HTCFG_UART_IPN                          UART1
#endif

#if defined(USE_HT32F65240_DVB)
  #define _HTCFG_UART_TX_GPIOX                    A
  #define _HTCFG_UART_TX_GPION                    3
  #define _HTCFG_UART_RX_GPIOX                    A
  #define _HTCFG_UART_RX_GPION                    1
  #define HTCFG_UART_IPN                          USART0
#endif

#if defined(USE_HT32F65240_SK)
  #define _HTCFG_UART_TX_GPIOX                    A
  #define _HTCFG_UART_TX_GPION                    4
  #define _HTCFG_UART_RX_GPIOX                    A
  #define _HTCFG_UART_RX_GPION                    5
  #define HTCFG_UART_IPN                          UART0
#endif

#if defined(USE_HT32F65232_SK)  //PRELIMINARY_NOT_TEST
  #define _HTCFG_UART_TX_GPIOX                    A
  #define _HTCFG_UART_TX_GPION                    4
  #define _HTCFG_UART_RX_GPIOX                    A
  #define _HTCFG_UART_RX_GPION                    5
  #define HTCFG_UART_IPN                          UART0
#endif

#if defined(USE_HT32F61355_SK) || defined(USE_HT32F61356_SK) || defined(USE_HT32F61357_SK)
  #define _HTCFG_UART_TX_GPIOX                    C
  #define _HTCFG_UART_TX_GPION                    4
  #define _HTCFG_UART_RX_GPIOX                    C
  #define _HTCFG_UART_RX_GPION                    5
  #define HTCFG_UART_IPN                          UART0
#endif

#if defined(USE_HT32F54241_SK)
  #define _HTCFG_UART_TX_GPIOX                    A
  #define _HTCFG_UART_TX_GPION                    4
  #define _HTCFG_UART_RX_GPIOX                    A
  #define _HTCFG_UART_RX_GPION                    5
  #define HTCFG_UART_IPN                          UART1
#endif

#if defined(USE_HT32F54253_SK)
  #define _HTCFG_UART_TX_GPIOX                    A
  #define _HTCFG_UART_TX_GPION                    4
  #define _HTCFG_UART_RX_GPIOX                    A
  #define _HTCFG_UART_RX_GPION                    5
  #define HTCFG_UART_IPN                          USART1
#endif

#define HTCFG_UART_TX_GPIO_ID                     STRCAT2(GPIO_P,         _HTCFG_UART_TX_GPIOX)
#define HTCFG_UART_RX_GPIO_ID                     STRCAT2(GPIO_P,         _HTCFG_UART_RX_GPIOX)
#define HTCFG_UART_TX_AFIO_PIN                    STRCAT2(AFIO_PIN_,      _HTCFG_UART_TX_GPION)
#define HTCFG_UART_RX_AFIO_PIN                    STRCAT2(AFIO_PIN_,      _HTCFG_UART_RX_GPION)
#define HTCFG_UART_PORT                           STRCAT2(HT_,             HTCFG_UART_IPN)
#define HTCFG_UART_IRQn                           STRCAT2(HTCFG_UART_IPN, _IRQn)
#define HTCFG_UART_IRQHandler                     STRCAT2(HTCFG_UART_IPN, _IRQHandler)

#define HTCFG_UART_RX_GPIO_CLK                    STRCAT2(P,              _HTCFG_UART_RX_GPIOX)
#define HTCFG_UART_RX_GPIO_PORT                   STRCAT2(HT_GPIO,        _HTCFG_UART_RX_GPIOX)
#define HTCFG_UART_RX_GPIO_PIN                    STRCAT2(GPIO_PIN_,      _HTCFG_UART_RX_GPION)

#ifdef __cplusplus
}
#endif

#endif
