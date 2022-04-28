/*********************************************************************************************************//**
 * @file    ht32f5xxxx_rstcu.h
 * @version $Rev:: 4546         $
 * @date    $Date:: 2020-02-20 #$
 * @brief   The header file of the Reset Control Unit library.
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
#ifndef __HT32F5XXXX_RSTCU_H
#define __HT32F5XXXX_RSTCU_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------------------------------------*/
#include "ht32.h"

/** @addtogroup HT32F5xxxx_Peripheral_Driver HT32F5xxxx Peripheral Driver
  * @{
  */

/** @addtogroup RSTCU
  * @{
  */


/* Exported types ------------------------------------------------------------------------------------------*/
/** @defgroup RSTCU_Exported_Types RSTCU exported types
  * @{
  */

/**
 * @brief Enumeration of Global reset status.
 */
typedef enum
{
  RSTCU_FLAG_SYSRST = 0,
  RSTCU_FLAG_EXTRST,
  RSTCU_FLAG_WDTRST,
  RSTCU_FLAG_PORST
} RSTCU_RSTF_TypeDef;

/**
 * @brief Definition of initial structure of peripheral reset.
 */
typedef union
{
  struct
  {
    /*  Definitions of AHB peripheral reset                                                                 */
    unsigned long PDMA       :1;
    unsigned long            :1;
    unsigned long            :1;
    unsigned long            :1;
    unsigned long            :1;
    unsigned long USBD       :1;
    unsigned long EBI        :1;
    unsigned long CRC        :1;

    unsigned long PA         :1;
    unsigned long PB         :1;
    unsigned long PC         :1;
    unsigned long PD         :1;
    unsigned long PE         :1;
    unsigned long PF         :1;
    unsigned long            :1;
    unsigned long AES        :1;

    #ifdef USE_HT32F65230_40
    unsigned long DIV        :1;
    #else
    unsigned long            :1;
    #endif
    unsigned long            :1;
    unsigned long            :1;
    unsigned long            :1;
    unsigned long            :1;
    unsigned long            :1;
    unsigned long            :1;
    unsigned long            :1;

    #ifndef USE_HT32F65230_40
    unsigned long DIV        :1;
    #else
    unsigned long            :1;
    #endif
    unsigned long QSPI       :1;
    unsigned long            :1;
    unsigned long            :1;
    unsigned long            :1;
    unsigned long            :1;
    unsigned long            :1;
    unsigned long            :1;

    /*  Definitions of APB peripheral 0 reset                                                               */
    unsigned long I2C0       :1;
    unsigned long I2C1       :1;
    unsigned long I2C2       :1;
    unsigned long            :1;
    unsigned long SPI0       :1;
    unsigned long SPI1       :1;
    unsigned long            :1;
    unsigned long            :1;

    unsigned long USART0     :1;
    unsigned long USART1     :1;
    unsigned long UART0      :1;
    unsigned long UART1      :1;
    unsigned long UART2      :1;
    unsigned long UART3      :1;
    unsigned long AFIO       :1;
    unsigned long EXTI       :1;

    unsigned long            :1;
    unsigned long            :1;
    unsigned long            :1;
    unsigned long            :1;
    unsigned long            :1;
    unsigned long            :1;
    unsigned long SLED0      :1;
    unsigned long SLED1      :1;

    unsigned long SCI0       :1;
    unsigned long I2S        :1;
    unsigned long            :1;
    unsigned long SCI1       :1;
    unsigned long MIDI       :1;
    unsigned long            :1;
    unsigned long            :1;
    unsigned long            :1;

    /* Definitions of APB peripheral 1 reset                                                                */
    unsigned long MCTM0      :1;
    unsigned long            :1;
    unsigned long            :1;
    unsigned long            :1;
    unsigned long WDT        :1;
    unsigned long            :1;
    unsigned long            :1;
    unsigned long            :1;

    unsigned long GPTM0      :1;
    unsigned long GPTM1      :1;
    unsigned long            :1;
    unsigned long            :1;
    unsigned long PWM0       :1;
    unsigned long PWM1       :1;
    unsigned long PWM2       :1;
    unsigned long            :1;

    unsigned long BFTM0      :1;
    unsigned long BFTM1      :1;
    unsigned long            :1;
    unsigned long LCD        :1;
    unsigned long            :1;
    unsigned long DAC        :1;
    unsigned long CMP        :1;
    unsigned long OPA        :1;

    unsigned long ADC0       :1;
    unsigned long ADC1       :1;
    unsigned long            :1;
    unsigned long            :1;
    unsigned long SCTM0      :1;
    unsigned long SCTM1      :1;
    unsigned long SCTM2      :1;
    unsigned long SCTM3      :1;
  } Bit;
  u32 Reg[3];
} RSTCU_PeripReset_TypeDef;

/**
  * @}
  */


/* Exported constants --------------------------------------------------------------------------------------*/
/** @defgroup RSTCU_Exported_Constants RSTCU exported constants
  * @{
  */

/* Other definitions                                                                                        */
#define IS_RSTCU_FLAG(FLAG)       ((FLAG == RSTCU_FLAG_SYSRST) || \
                                   (FLAG == RSTCU_FLAG_EXTRST) || \
                                   (FLAG == RSTCU_FLAG_WDTRST) || \
                                   (FLAG == RSTCU_FLAG_PORST))
/**
  * @}
  */

/* Exported functions --------------------------------------------------------------------------------------*/
/** @defgroup RSTCU_Exported_Functions RSTCU exported functions
  * @{
  */
FlagStatus RSTCU_GetResetFlagStatus(RSTCU_RSTF_TypeDef RSTCU_RSTF);
void RSTCU_ClearResetFlag(RSTCU_RSTF_TypeDef RSTCU_RSTF);
void RSTCU_ClearAllResetFlag(void);
void RSTCU_PeripReset(RSTCU_PeripReset_TypeDef Reset, ControlStatus Cmd);

/**
  * @}
  */


/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif
