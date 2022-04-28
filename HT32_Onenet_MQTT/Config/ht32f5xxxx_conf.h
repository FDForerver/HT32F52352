/*********************************************************************************************************//**
 * @file    IP/Example/ht32f5xxxx_conf.h
 * @version $Rev:: 4449         $
 * @date    $Date:: 2019-12-27 #$
 * @brief   Library configuration file.
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
//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------

/* Define to prevent recursive inclusion -------------------------------------------------------------------*/
#ifndef __HT32F5XXXX_CONF_H
#define __HT32F5XXXX_CONF_H

/* Exported constants --------------------------------------------------------------------------------------*/

#define RETARGET_USB        1
#define RETARGET_SYSLOG     2
#define RETARGET_COM1       10
#define RETARGET_COM2       11
#define RETARGET_USART0     12
#define RETARGET_USART1     13
#define RETARGET_UART0      14
#define RETARGET_UART1      15
#define RETARGET_UART2      16
#define RETARGET_UART3      17


/* Retarget settings of the C standard I/O library functions (printf, scanf, getchar, ...etc.)              */
/*
//  <q> Enable Retarget
//  <o1> Retarget port
//      <1=> USB Virtual COM
//      <2=> Syslog
//      <10=> COM1
//      <11=> COM2
//      <12=> USART0
//      <13=> USART1
//      <14=> UART0
//      <15=> UART1
//      <16=> UART2
//      <17=> UART3
//  <q2> Enable Auto Return
//       <i> Auto Return function adds "\r" before "\n" automatically when print message by Retarget.
*/
#define _RETARGET            1
#define RETARGET_PORT        10
#define _AUTO_RETURN         0

#ifndef AUTO_RETURN
#if (_AUTO_RETURN == 1)
#define AUTO_RETURN
#endif
#endif

/* Enable Interrupt Mode for UxART Retarget
// <h> Retarget COM/UxART Setting
//  <o0> UxART Baudrate
//  <q1> Enable Interrupt Mode for UxART Tx Retarget
//  <q2> Define UxARTn_IRQHandler By Retarget (ht32_serial.c)
//    <i> Disable (RETARGET_DEFINE_HANDLER = 0) if application already have UxARTn_IRQHandler.
//    <i> RETARGET_UART_IRQHandler() shall be called by UxARTn_IRQHandler when disable.
//  <o3> Tx Buffer Length (in byte)
// </h>
*/
#define RETARGET_UxART_BAUDRATE       115200
#define RETARGET_INT_MODE             0
#define RETARGET_DEFINE_HANDLER       1
#define RETARGET_INT_BUFFER_SIZE      64

#if (_RETARGET == 1)
#if (RETARGET_PORT == RETARGET_USB)
  #define RETARGET_IS_USB
//  <h> Retarget USB Virtual COM Setting
//  <o0> Communication (Interrupt IN)
//      <1=> Endpoint 1
//      <2=> Endpoint 2
//      <3=> Endpoint 3
//      <4=> Endpoint 4
//      <5=> Endpoint 5
//      <6=> Endpoint 6
//      <7=> Endpoint 7
//  <o1> Data Rx (Bulk OUT)
//      <1=> Endpoint 1
//      <2=> Endpoint 2
//      <3=> Endpoint 3
//      <4=> Endpoint 4
//      <5=> Endpoint 5
//      <6=> Endpoint 6
//      <7=> Endpoint 7
//  <o2> Data Tx (Bulk IN)
//      <1=> Endpoint 1
//      <2=> Endpoint 2
//      <3=> Endpoint 3
//      <4=> Endpoint 4
//      <5=> Endpoint 5
//      <6=> Endpoint 6
//      <7=> Endpoint 7
//  <o3> Communication Endpoint Buffer Length (in byte) <4-64:4>
//  <o4> Data Rx Endpoint Buffer Length (in byte) <4-64:4>
//  <o5> Data Tx Endpoint Buffer Length (in byte) <4-64:4>
//  <o6> Rx Buffer Length (in byte) <64-1024:4>
//  <o7> Tx Buffer Length (in byte) <1-63:1>
//    <i> Please use "SERIAL_Flush()" to sent out the buffer data immediately when Tx Buffer Length > 1.
//  <o8> USB Tx Mode (BULK IN)
//      <0=> Block Mode (Wait until both USB and terminal software are ready)
//      <1=> Non-Block Mode (Drop data if USB or terminal software is not ready)
//  <q9> Enable HSI Auto Trim By USB Function
//    <i> Need turn on if the USB clock source is from HSI (PLL USBPLL clock Source).
  #define RETARGET_CTRL_EPT      (5)
  #define RETARGET_RX_EPT        (6)
  #define RETARGET_TX_EPT        (7)
  #define RETARGET_CTRL_EPTLEN   (8)
  #define RETARGET_RX_EPTLEN     (64)
  #define RETARGET_TX_EPTLEN     (64)
  #define RETARGET_BUFFER_SIZE   (64)
  #define RETARGET_TXBUFFER_SIZE (1) // Use "SERIAL_Flush()" to sent out the buffer data immediately when Tx Buffer Length > 1.
  #define RETARGET_USB_MODE      (0)
  #define RETARGET_HSI_ATM       (1)
// </h>
#elif (RETARGET_PORT == RETARGET_COM1)
  #define RETARGET_COM_PORT         COM1
  #define RETARGET_USART_PORT       COM1_PORT
  #define RETARGET_UART_IRQn        COM1_IRQn
  #define RETARGET_UART_IRQHandler  COM1_IRQHandler
  #define RETARGET_IS_UART
#elif (RETARGET_PORT == RETARGET_COM2)
  #define RETARGET_COM_PORT         COM2
  #define RETARGET_USART_PORT       COM2_PORT
  #define RETARGET_UART_IRQn        COM2_IRQn
  #define RETARGET_UART_IRQHandler  COM2_IRQHandler
  #define RETARGET_IS_UART
#elif (RETARGET_PORT == RETARGET_USART0)
  #define RETARGET_USART_PORT       HT_USART0
  #define RETARGET_UART_IRQn        USART0_IRQn
  #define RETARGET_UART_IRQHandler  USART0_IRQHandler
  #define RETARGET_IS_UART
#elif (RETARGET_PORT == RETARGET_USART1)
  #define RETARGET_USART_PORT       HT_USART1
  #define RETARGET_UART_IRQn        USART1_IRQn
  #define RETARGET_UART_IRQHandler  USART1_IRQHandler
  #define RETARGET_IS_UART
#elif (RETARGET_PORT == RETARGET_UART0)
  #define RETARGET_USART_PORT       HT_UART0
  #define RETARGET_UART_IRQn        UART0_IRQn
  #define RETARGET_UART_IRQHandler  UART0_IRQHandler
  #define RETARGET_IS_UART
#elif (RETARGET_PORT == RETARGET_UART1)
  #define RETARGET_USART_PORT       HT_UART1
  #define RETARGET_UART_IRQn        UART1_IRQn
  #define RETARGET_UART_IRQHandler  UART1_IRQHandler
  #define RETARGET_IS_UART
#elif (RETARGET_PORT == RETARGET_UART2)
  #define RETARGET_USART_PORT       HT_UART2
  #define RETARGET_UART_IRQn        UART2_IRQn
  #define RETARGET_UART_IRQHandler  UART2_IRQHandler
  #define RETARGET_IS_UART
#elif (RETARGET_PORT == RETARGET_UART3)
  #define RETARGET_USART_PORT       HT_UART3
  #define RETARGET_UART_IRQn        UART3_IRQn
  #define RETARGET_UART_IRQHandler  UART3_IRQHandler
  #define RETARGET_IS_UART
#endif
  extern void RETARGET_Configuration(void);
#else
  #define RETARGET_Configuration(...)
  #undef printf
  #undef getchar
  #define printf(...)
  #define getchar()  (0)
#endif

#if (RETARGET_DEFINE_HANDLER == 0)
#undef RETARGET_UART_IRQHandler
#endif

/*
//<q> Enable CKOUT function
*/
#define ENABLE_CKOUT              0


/* The DEBUG definition to enter debug mode for library                                                     */
/*
//<q> Library Debug mode
*/
#define HT32_LIB_DEBUG      0


/* Enable/disable the specific peripheral inclusion                                                         */

//  <h> Library inclusion configuration
/* ADC -----------------------------------------------------------------------------------------------------*/
/*
//<q> ADC Library
*/
#define _ADC          1

/* AES -----------------------------------------------------------------------------------------------------*/
/*
//<q> AES Library
*/
#define _AES          1

/* BFTM ----------------------------------------------------------------------------------------------------*/
/*
//<q> BFTM Library
*/
#define _BFTM         1

/* Clock Control -------------------------------------------------------------------------------------------*/
/*
//<q> Clock Control Library
*/
#define _CKCU         1

/* Comparator ----------------------------------------------------------------------------------------------*/
/*
//<q> Comparator Library
*/
#define _CMP          1

/* CRC -----------------------------------------------------------------------------------------------------*/
/*
//<q> CRC Library
*/
#define _CRC          1

/* DAC -----------------------------------------------------------------------------------------------------*/
/*
//<q> DAC Library
*/
#define _DAC          1

/* DAC Dual 16-bit -----------------------------------------------------------------------------------------*/
/*
//<q> DAC_Dual16 Library
*/
#define _DAC_DUAL16       1

/* DIV -----------------------------------------------------------------------------------------------------*/
/*
//<q> DIV Library
*/
#define _DIV          1

/* EBI -----------------------------------------------------------------------------------------------------*/
/*
//<q> EBI Library
*/
#define _EBI          1

/* EXTI ----------------------------------------------------------------------------------------------------*/
/*
//<q> EXTI Library
*/
#define _EXTI         1

/* Flash ---------------------------------------------------------------------------------------------------*/
/*
//<q> Flash Library
*/
#define _FLASH        1

/* GPIO ----------------------------------------------------------------------------------------------------*/
/*
//<q> GPIO Library
*/
#define _GPIO         1

/* GPTM ----------------------------------------------------------------------------------------------------*/
/*
//<q> GPTM Library
*/
#define _GPTM         1

/* I2C -----------------------------------------------------------------------------------------------------*/
/*
//<q> I2C Library
*/
#define _I2C          1

/* I2S -----------------------------------------------------------------------------------------------------*/
/*
//<q> I2S Library
*/
#define _I2S          1

/* LCD -----------------------------------------------------------------------------------------------------*/
/*
//<q> LCD Library
*/
#define _LCD          1

/* MCTM ----------------------------------------------------------------------------------------------------*/
/*
//<q> MCTM Library
*/
#define _MCTM         1

/* MIDI ----------------------------------------------------------------------------------------------------*/
/*
//<q> MIDI Library
*/
#define _MIDI       1

/* OPA -----------------------------------------------------------------------------------------------------*/
/*
//<q> OPA
*/
#define _OPA          1

/* PDMA ----------------------------------------------------------------------------------------------------*/
/*
//<q> PDMA Library
*/
#define _PDMA         1

/* PWM -----------------------------------------------------------------------------------------------------*/
/*
//<q> PWM Library
*/
#define _PWM          1

/* PWRCU ---------------------------------------------------------------------------------------------------*/
/*
//<q> PWRCU Library
*/
#define _PWRCU        1

/* RSTCU ---------------------------------------------------------------------------------------------------*/
/*
//<q> RSTCU Library
*/
#define _RSTCU        1

/* RTC -----------------------------------------------------------------------------------------------------*/
/*
//<q> RTC Library
*/
#define _RTC          1

/* SCI -----------------------------------------------------------------------------------------------------*/
/*
//<q> SCI Library
*/
#define _SCI          1

/* SCTM ----------------------------------------------------------------------------------------------------*/
/*
//<q> SCTM Library
*/
#define _SCTM         1

/* SLED ----------------------------------------------------------------------------------------------------*/
/*
//<q> SLED Library
*/
#define _SLED         1

/* SPI -----------------------------------------------------------------------------------------------------*/
/*
//<q> SPI Library
*/
#define _SPI          1

/* USART ---------------------------------------------------------------------------------------------------*/
/*
//<q0> USART/UART Library
*/
#define _USART        1

/* USBD ----------------------------------------------------------------------------------------------------*/
/*
//<q> USB Library
*/
#define _USB          1

/* WDT -----------------------------------------------------------------------------------------------------*/
/*
//<q> WDT Library
*/
#define _WDT          1

/* Misc ----------------------------------------------------------------------------------------------------*/
/*
//<q> Misc Library
*/
#define _MISC         1

/* Serial --------------------------------------------------------------------------------------------------*/
/*
//<q> Serial Library
*/
#define _SERIAL       1

/* Software DIV --------------------------------------------------------------------------------------------*/
/*
//<q> Software Divider Library
*/
#define _SWDIV        1

/* Software Random Number ----------------------------------------------------------------------------------*/
/*
//<q> Software Random Number Library
*/
#define _SWRAND       1


// </h>

#endif
