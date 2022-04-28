/*********************************************************************************************************//**
 * @file    ht32f5xxxx_dac.h
 * @version $Rev:: 3897         $
 * @date    $Date:: 2019-05-20 #$
 * @brief   The header file of the DAC library.
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
#ifndef __HT32F5XXXX_DAC_H
#define __HT32F5XXXX_DAC_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------------------------------------*/
#include "ht32.h"

/** @addtogroup HT32F5xxxx_Peripheral_Driver HT32F5xxxx Peripheral Driver
  * @{
  */

/** @addtogroup DAC
  * @{
  */


/* Exported types ------------------------------------------------------------------------------------------*/
/** @defgroup DAC_Exported_Types DAC exported types
  * @{
  */

/**
  * @}
  */

/* Exported constants --------------------------------------------------------------------------------------*/
/** @defgroup DAC_Exported_Constants DAC exported constants
  * @{
  */
#define ASYNC_MODE                      (0x00000000)
#define SYNC_MODE                       (0x00000001)

#define IS_DAC_CONVERSION_MODE(MODE)    (((MODE) == ASYNC_MODE) || ((MODE) == SYNC_MODE))


#define DAC_CH0                         (0)
#define DAC_CH1                         (1)

#define IS_DAC_CHANNEL(CHANNEL)         (((CHANNEL) == DAC_CH0) || ((CHANNEL) == DAC_CH1))


#define DAC_INT_DOR0IE                  (0x00000001)
#define DAC_INT_DOR1IE                  (0x00000002)


#define IS_DAC_INT(INT)                 ((((INT) & 0xFFFFFFF0) == 0) && ((INT) != 0))


#define DAC_FLAG_DOR0IF                 (0x00000001)
#define DAC_FLAG_DOR1IF                 (0x00000002)

#define IS_DAC_FLAG(FLAG)               (((FLAG) == DAC_FLAG_DOR0IF) || \
                                         ((FLAG) == DAC_FLAG_DOR1IF))


#define DAC_REFERENCE_VDDA              (0)
#define DAC_REFERENCE_VREF              (1UL << 14)

#define IS_DAC_REFERENCE(REF)           (((REF) == DAC_REFERENCE_VDDA) || ((REF) == DAC_REFERENCE_VREF))


#define DAC_RESOLUTION_12BIT            (0)
#define DAC_RESOLUTION_8BIT             (1UL << 2)

#define IS_DAC_RESOLUTION(RES)          (((RES) == DAC_RESOLUTION_8BIT) || ((RES) == DAC_RESOLUTION_12BIT))

/**
  * @}
  */

/* Exported functions --------------------------------------------------------------------------------------*/
/** @defgroup DAC_Exported_Functions DAC exported functions
  * @{
  */
void DAC_DeInit(void);

void DAC_ModeConfig(u8 ModeSel);
void DAC_IntConfig(u32 DAC_INT, ControlStatus NewState);
FlagStatus DAC_GetFlagStatus(u32 DAC_Flag);
void DAC_ClearFlag(u32 DAC_Flag);

void DAC_ReferenceConfig(u8 DAC_Ch, u32 RefSel);
void DAC_ResolutionConfig(u8 DAC_Ch, u32 ResoSel);

void DAC_OutBufCmd(u8 DAC_Ch, ControlStatus NewState);
void DAC_Cmd(u8 DAC_Ch, ControlStatus NewState);

void DAC_SetData(u8 DAC_Ch, u32 Data);
u16 DAC_GetOutData(u8 DAC_Ch);
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
