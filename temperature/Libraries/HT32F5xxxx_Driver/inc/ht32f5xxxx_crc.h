/*********************************************************************************************************//**
 * @file    ht32f5xxxx_crc.h
 * @version $Rev:: 1704         $
 * @date    $Date:: 2017-08-17 #$
 * @brief   The header file of the CRC library.
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
#ifndef __HT32F5XXXX_CRC_H
#define __HT32F5XXXX_CRC_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------------------------------------*/
#include "ht32.h"

/** @addtogroup HT32F5xxxx_Peripheral_Driver HT32F5xxxx Peripheral Driver
  * @{
  */

/** @addtogroup CRC
  * @{
  */


/* Exported types ------------------------------------------------------------------------------------------*/
/** @defgroup CRC_Exported_Types CRC exported types
  * @{
  */

/* Definition of CRC Init Structure                                                                         */
typedef enum
{
  CRC_CCITT_POLY              = 0,
  CRC_16_POLY                 = 1,
  CRC_32_POLY                 = 2,
  CRC_USER_DEFINE             = 0xF
} CRC_Mode;

typedef struct
{
  CRC_Mode Mode;
  u32 uSeed;
  u32 uCR;
} CRC_InitTypeDef;
/**
  * @}
  */

/* Exported constants --------------------------------------------------------------------------------------*/
/** @defgroup CRC_Exported_Constants CRC exported constants
  * @{
  */
#define IS_CRC_POLY(POLY)         ((POLY == CRC_CCITT_POLY) || \
                                   (POLY == CRC_16_POLY)    || \
                                   (POLY == CRC_32_POLY)    || \
                                   (POLY == CRC_USER_DEFINE))

#define CRC_NORMAL_WR             (0)
#define CRC_BIT_RVS_WR            (1UL << 2)
#define CRC_BYTE_RVS_WR           (1UL << 3)
#define CRC_CMPL_WR               (1UL << 4)

#define CRC_NORMAL_SUM            (0)
#define CRC_BIT_RVS_SUM           (1UL << 5)
#define CRC_BYTE_RVS_SUM          (1UL << 6)
#define CRC_CMPL_SUM              (1UL << 7)

#define IS_CRC_MOD(MOD)           ((MOD & 0xFFFFFF00) == 0)
/**
  * @}
  */

/* Exported functions --------------------------------------------------------------------------------------*/
/** @defgroup CRC_Exported_Functions CRC exported functions
  * @{
  */
void CRC_DeInit(HT_CRC_TypeDef* CRC);
void CRC_Init(HT_CRC_TypeDef* CRC, CRC_InitTypeDef* CRC_InitStruct);
u32 CRC_Process(HT_CRC_TypeDef* CRC, u8 *buffer, u32 length);

u16 CRC_CCITT(u16 seed, u8 *buffer, u32 length);
u16 CRC_16(u16 seed, u8 *buffer, u32 length);
u32 CRC_32(u32 seed, u8 *buffer, u32 length);
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
