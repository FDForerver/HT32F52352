/*********************************************************************************************************//**
 * @file    ht32f5xxxx_crc.c
 * @version $Rev:: 3806         $
 * @date    $Date:: 2019-05-06 #$
 * @brief   This file provides all the CRC firmware functions.
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

/* Includes ------------------------------------------------------------------------------------------------*/
#include "ht32f5xxxx_crc.h"

/** @addtogroup HT32F5xxxx_Peripheral_Driver HT32F5xxxx Peripheral Driver
  * @{
  */

/** @defgroup CRC CRC
  * @brief CRC driver modules
  * @{
  */


/* Global functions ----------------------------------------------------------------------------------------*/
/** @defgroup CRC_Exported_Functions CRC exported functions
  * @{
  */
/*********************************************************************************************************//**
 * @brief Deinitialize the CRC peripheral registers to their default reset values.
 * @param CRC: where CRC is the selected CRC peripheral.
 * @retval None
 ************************************************************************************************************/
void CRC_DeInit(HT_CRC_TypeDef* CRC)
{
  RSTCU_PeripReset_TypeDef RSTCUReset = {{0}};

  RSTCUReset.Bit.CRC = 1;
  RSTCU_PeripReset(RSTCUReset, ENABLE);
}

/*********************************************************************************************************//**
 * @brief Initialize the CRC peripheral according to the specified parameters in the CRC_InitStruct.
 * @param CRC: where CRC is the selected CRC peripheral.
 * @param CRC_InitStruct: pointer to a CRC_InitTypeDef structure.
 * @retval None
 ************************************************************************************************************/
void CRC_Init(HT_CRC_TypeDef* CRC, CRC_InitTypeDef* CRC_InitStruct)
{
  u32 uCRValue;
  HT_CRC->SDR = CRC_InitStruct->uSeed;
  switch (CRC_InitStruct->Mode)
  {
    case CRC_CCITT_POLY:
    {
      uCRValue = CRC_CCITT_POLY | CRC_NORMAL_WR | CRC_NORMAL_SUM;
      break;
    }
    case CRC_16_POLY:
    {
      uCRValue = CRC_16_POLY | CRC_BIT_RVS_WR | CRC_BIT_RVS_SUM | CRC_BYTE_RVS_SUM;
      break;
    }
    case CRC_32_POLY:
    {
      uCRValue = CRC_32_POLY | CRC_BIT_RVS_WR | CRC_BIT_RVS_SUM | CRC_BYTE_RVS_SUM | CRC_CMPL_SUM;
      break;
    }
    case CRC_USER_DEFINE:
    default:
    {
      uCRValue = CRC_InitStruct->uCR;
      break;
    }
  }

  CRC->CR = uCRValue;
}

/*********************************************************************************************************//**
 * @brief Get the CRC checksum from the given data
 * @param CRC: where CRC is the selected CRC peripheral.
 * @param buffer: pointer to the given data to be calculated
 * @param length: data length in byte
 * @retval The checksum value
 ***********************************************************************************************************/
u32 CRC_Process(HT_CRC_TypeDef* CRC, u8 *buffer, u32 length)
{
  while (length--)
  {
    wb(&CRC->DR, *buffer++); // byte write
  }

  return (HT_CRC->CSR);
}

/*********************************************************************************************************//**
 * @brief Get the CRC-CCITT checksum from the given data
 * @param seed: CRC initial data
 * @param buffer: pointer to the given data to be calculated
 * @param length: data length in byte
 * @retval The checksum value
 ************************************************************************************************************/
u16 CRC_CCITT(u16 seed, u8 *buffer, u32 length)
{
  /* CRC-CCITT poly: 0x1021                                                                                 */
  HT_CRC->SDR = seed;
  HT_CRC->CR = CRC_CCITT_POLY | CRC_NORMAL_WR | CRC_NORMAL_SUM;

  while (length--)
  {
    wb(&HT_CRC->DR, *buffer++); // byte write
  }

  return (u16)(HT_CRC->CSR);
}

/*********************************************************************************************************//**
 * @brief Get the CRC-16 checksum from the given data
 * @param seed: CRC initial data
 * @param buffer: pointer to the given data to be calculated
 * @param length: data length in byte
 * @retval The checksum value
 ************************************************************************************************************/
u16 CRC_16(u16 seed, u8 *buffer, u32 length)
{
  /* CRC-16 poly: 0x8005                                                                                    */
  HT_CRC->SDR = seed;
  HT_CRC->CR = CRC_16_POLY | CRC_BIT_RVS_WR | CRC_BIT_RVS_SUM | CRC_BYTE_RVS_SUM;

  while (length--)
  {
    wb(&HT_CRC->DR, *buffer++); // byte write
  }

  return (u16)(HT_CRC->CSR);
}

/*********************************************************************************************************//**
 * @brief Get the CRC-32 checksum from the given data
 * @param seed: CRC initial data
 * @param buffer: pointer to the given data to be calculated
 * @param length: data length in byte
 * @retval The checksum value
 ************************************************************************************************************/
u32 CRC_32(u32 seed, u8 *buffer, u32 length)
{
  /* CRC-32 poly: 0x04C11DB7                                                                                */
  HT_CRC->SDR = seed;
  HT_CRC->CR = CRC_32_POLY | CRC_BIT_RVS_WR | CRC_BIT_RVS_SUM | CRC_BYTE_RVS_SUM | CRC_CMPL_SUM;

  while (length--)
  {
    wb(&HT_CRC->DR, *buffer++); // byte write
  }

  return (HT_CRC->CSR);
}
/**
  * @}
  */


/**
  * @}
  */

/**
  * @}
  */
