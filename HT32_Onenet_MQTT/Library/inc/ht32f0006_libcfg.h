/*********************************************************************************************************//**
 * @file    ht32f0006_libcfg.h
 * @version $Rev:: 2862         $
 * @date    $Date:: 2018-06-11 #$
 * @brief   The library configuration file.
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
#ifndef __HT32F0006_LIBCFG_H
#define __HT32F0006_LIBCFG_H

/* Settings ------------------------------------------------------------------------------------------------*/

#if !defined(USE_MEM_HT32F0006)
#define USE_MEM_HT32F0006
#endif

#define LIBCFG_MAX_SPEED                  (48000000)

#define LIBCFG_FLASH_PAGESIZE             (512)

#ifdef USE_MEM_HT32F0006
  #define LIBCFG_FLASH_SIZE               (LIBCFG_FLASH_PAGESIZE * 255)
  #define LIBCFG_RAM_SIZE                 (1024 * 16)
  #define LIBCFG_CHIPNAME                 (0x0006)
#endif
#define LIBCFG_FLASH_2PAGE_PER_WPBIT      (1)
#define LIBCFG_PDMA                       (1)

#define LIBCFG_AFE0006                    (1)
#define LIBCFG_LSE                        (1)
#define LIBCFG_USBD                       (1)
#define LIBCFG_CRC                        (1)
#define LIBCFG_GPIOC                      (1)

#define LIBCFG_MIDI                       (1)
#define LIBCFG_QSPI                       (1)
#define LIBCFG_BFTM1                      (1)
#define LIBCFG_DACDUAL16                  (1)
#define LIBCFG_DIV                        (1)
#define LIBCFG_I2S                        (1)
#define LIBCFG_PWRCU_VDD_2V0_3V6          (1)
#define LIBCFG_GPIOC                      (1)
#define LIBCFG_GPIOD                      (1)
#define LIBCFG_NO_PWRCU_V15_READY_SOURCE  (1)
#define LIBCFG_ADC_CH8_11                 (1)
#define LIBCFG_ADC_CH12_15                (1)
#endif
