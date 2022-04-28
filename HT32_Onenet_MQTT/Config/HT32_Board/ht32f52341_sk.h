/*********************************************************************************************************//**
 * @file    ht32f52341_sk.h
 * @version $Rev:: 4217         $
 * @date    $Date:: 2019-09-12 #$
 * @brief   The header file of HT32F52341 Starter kit.
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
#ifndef __HT32F52341_SK_H
#define __HT32F52341_SK_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------------------------------------*/
#include "ht32.h"

/** @addtogroup Utilities
  * @{
  */

/** @addtogroup HT32_Board
  * @{
  */

/** @addtogroup HT32F52341_SK
  * @{
  */


/* Exported constants --------------------------------------------------------------------------------------*/
/** @defgroup HT32F52341_SK_Exported_Constants HT32F52341 Starter kit exported constants
  * @{
  */
extern HT_GPIO_TypeDef* const GPIO_PORT[GPIO_PORT_NUM];

/** @addtogroup HT32F52341_SK_LED
  * @{
  */
#define LEDn                        (3)

#define LED1_GPIO_ID                (GPIO_PB)
#define LED1_GPIO_PIN               (GPIO_PIN_4)
#define LED1_AFIO_MODE              (AFIO_FUN_GPIO)

#define LED2_GPIO_ID                (GPIO_PA)
#define LED2_GPIO_PIN               (GPIO_PIN_14)
#define LED2_AFIO_MODE              (AFIO_FUN_GPIO)

#define LED3_GPIO_ID                (GPIO_PA)
#define LED3_GPIO_PIN               (GPIO_PIN_15)
#define LED3_AFIO_MODE              (AFIO_FUN_GPIO)

typedef enum
{
  HT_LED1 = 0,
  HT_LED2 = 1,
  HT_LED3 = 2
} LED_TypeDef;
/**
  * @}
  */

/** @addtogroup HT32F52341_SK_BUTTON
  * @{
  */
#define BUTTONn                     (3)

#define WAKEUP_BUTTON_GPIO_ID       (GPIO_PB)
#define WAKEUP_BUTTON_GPIO_PIN      (GPIO_PIN_12)
#define WAKEUP_BUTTON_AFIO_MODE     (AFIO_FUN_GPIO)
#define WAKEUP_BUTTON_EXTI_CHANNEL  (12)

#define KEY1_BUTTON_GPIO_ID         (GPIO_PB)
#define KEY1_BUTTON_GPIO_PIN        (GPIO_PIN_0)
#define KEY1_BUTTON_AFIO_MODE       (AFIO_FUN_GPIO)
#define KEY1_BUTTON_EXTI_CHANNEL    (0)

#define KEY2_BUTTON_GPIO_ID         (GPIO_PC)
#define KEY2_BUTTON_GPIO_PIN        (GPIO_PIN_2)
#define KEY2_BUTTON_AFIO_MODE       (AFIO_FUN_GPIO)
#define KEY2_BUTTON_EXTI_CHANNEL    (2)

typedef enum
{
  BUTTON_WAKEUP = 0,
  BUTTON_KEY1   = 1,
  BUTTON_KEY2   = 2
} BUTTON_TypeDef;

typedef enum
{
  BUTTON_MODE_GPIO = 0,
  BUTTON_MODE_EXTI = 1
} BUTTON_MODE_TypeDef;
/**
  * @}
  */

/** @addtogroup HT32F52341_SK_BUZZER
  * @{
  */
#define BUZZER_GPIO_ID              (GPIO_PA)
#define BUZZER_AFIO_PIN             (AFIO_PIN_8)
#define BUZZER_AFIO_MODE            (AFIO_FUN_SCTM)
#define BUZZER_GPIO_CLK(CK)         (CK.Bit.PA)

#define BUZZER_TM_CLK(CK)           (CK.Bit.SCTM2)
#define BUZZER_TM                   (HT_SCTM2)
#define BUZZER_TM_CHANNEL           (TM_CH_0)
#define BUZZER_IRQn                 (SCTM2_IRQn)
/**
  * @}
  */

/** @addtogroup HT32F52341_SK_COM
  * @{
  */
#define COM_NUM                     (1)

#define COM1_CLK(CK)                (CK.Bit.UART1)
#define COM1_PORT                   (HT_UART1)
#define COM1_IRQn                   (UART1_IRQn)
#define COM1_IRQHandler             (UART1_IRQHandler)

#define COM1_TX_GPIO_ID             (GPIO_PA)
#define COM1_TX_AFIO_PIN            (AFIO_PIN_4)
#define COM1_TX_AFIO_MODE           (AFIO_FUN_USART_UART)

#define COM1_RX_GPIO_ID             (GPIO_PA)
#define COM1_RX_AFIO_PIN            (AFIO_PIN_5)
#define COM1_RX_AFIO_MODE           (AFIO_FUN_USART_UART)

typedef enum
{
  COM1 = 0,
  COM2 = 1
} COM_TypeDef;
/**
  * @}
  */

/** @addtogroup HT32F52341_SK_SPI_FLASH
  * @{
  */
#define FLASH_SPI_CLK(CK)           (CK.Bit.SPI1)
#define FLASH_SPI                   (HT_SPI1)

#define FLASH_SPI_SCK_GPIO_ID       (GPIO_PA)
#define FLASH_SPI_SCK_AFIO_PIN      (AFIO_PIN_0)
#define FLASH_SPI_SCK_AFIO_MODE     (AFIO_FUN_SPI)

#define FLASH_SPI_MOSI_GPIO_ID      (GPIO_PA)
#define FLASH_SPI_MOSI_AFIO_PIN     (AFIO_PIN_1)
#define FLASH_SPI_MOSI_AFIO_MODE    (AFIO_FUN_SPI)

#define FLASH_SPI_MISO_GPIO_ID      (GPIO_PA)
#define FLASH_SPI_MISO_AFIO_PIN     (AFIO_PIN_2)
#define FLASH_SPI_MISO_AFIO_MODE    (AFIO_FUN_SPI)

#define FLASH_SPI_SEL_GPIO_ID       (GPIO_PB)
#define FLASH_SPI_SEL_GPIO_PIN      (GPIO_PIN_5)
#define FLASH_SPI_SEL_AFIO_MODE     (AFIO_FUN_GPIO)
#define FLASH_SPI_SEL_CLK(CK)       (CK.Bit.PB)
/**
  * @}
  */

/** @addtogroup HT32F52341_SK_SPI_LCD
  * @{
  */
#define LCD_SPI_CLK(CK)             (CK.Bit.SPI0)
#define LCD_SPI                     (HT_SPI0)

#define LCD_SPI_SCK_GPIO_ID         (GPIO_PB)
#define LCD_SPI_SCK_AFIO_PIN        (AFIO_PIN_3)
#define LCD_SPI_SCK_AFIO_MODE       (AFIO_FUN_SPI)

#define LCD_SPI_MOSI_GPIO_ID        (GPIO_PA)
#define LCD_SPI_MOSI_AFIO_PIN       (AFIO_PIN_10)
#define LCD_SPI_MOSI_AFIO_MODE      (AFIO_FUN_SPI)

#define LCD_SPI_MISO_GPIO_ID        (GPIO_PA)
#define LCD_SPI_MISO_AFIO_PIN       (AFIO_PIN_11)
#define LCD_SPI_MISO_AFIO_MODE      (AFIO_FUN_SPI)

#define LCD_SPI_SEL_GPIO_ID         (GPIO_PB)
#define LCD_SPI_SEL_AFIO_PIN        (AFIO_PIN_2)
#define LCD_SPI_SEL_AFIO_MODE       (AFIO_FUN_SPI)
#define LCD_SPI_SEL_CLK(CK)         (CK.Bit.PB)

#define LCD_SPI_BL_ENABLE           (1)
#define LCD_SPI_BL_GPIO_ID          (GPIO_PB)
#define LCD_SPI_BL_GPIO_PIN         (GPIO_PIN_6)
#define LCD_SPI_BL_AFIO_MODE        (AFIO_FUN_GPIO)
#define LCD_SPI_BL_CLK(CK)          (CK.Bit.PB)

#define LCD_SPI_RST_GPIO_ID         (GPIO_PB)
#define LCD_SPI_RST_GPIO_PIN        (GPIO_PIN_1)
#define LCD_SPI_RST_AFIO_MODE       (AFIO_FUN_GPIO)
#define LCD_SPI_RST_CLK(CK)         (CK.Bit.PB)
/**
  * @}
  */

/** @addtogroup HT32F52341_SK_I2C_EEPROM
  * @{
  */
#define EEPROM_I2C_CLK(CK)          (CK.Bit.I2C1)
#define EEPROM_I2C                  (HT_I2C1)

#define EEPROM_I2C_SCL_GPIO_ID      (GPIO_PB)
#define EEPROM_I2C_SCL_AFIO_PIN     (AFIO_PIN_15)
#define EEPROM_I2C_SCL_AFIO_MODE    (AFIO_FUN_I2C)

#define EEPROM_I2C_SDA_GPIO_ID      (GPIO_PC)
#define EEPROM_I2C_SDA_AFIO_PIN     (AFIO_PIN_0)
#define EEPROM_I2C_SDA_AFIO_MODE    (AFIO_FUN_I2C)
/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------------------------------------*/
/** @defgroup HT32F52341_SK_Exported_Functions HT32F52341 Starter kit exported functions
  * @{
  */
#define HT32F_DVB_USBConnect()      USBD_DPpullupCmd(ENABLE)
#define HT32F_DVB_USBDisConnect()   USBD_DPpullupCmd(DISABLE)
#define HT32F_DVB_GPxConfig         AFIO_GPxConfig

#define HT32F_DVB_BuzzerInit(hFreq, bDuty)    HT32F_DVB_BuzzerFun(hFreq, bDuty, 0);
#define HT32F_DVB_BuzzerConfig(hFreq, bDuty)  HT32F_DVB_BuzzerFun(hFreq, bDuty, 1);


void HT32F_DVB_LEDInit(LED_TypeDef HT_LEDn);
void HT32F_DVB_LEDOn(LED_TypeDef HT_LEDn);
void HT32F_DVB_LEDOff(LED_TypeDef HT_LEDn);
void HT32F_DVB_LEDToggle(LED_TypeDef HT_LEDn);

void HT32F_DVB_PBInit(BUTTON_TypeDef BUTTON_x, BUTTON_MODE_TypeDef BUTTON_MODE_x);
u32 HT32F_DVB_PBGetState(BUTTON_TypeDef BUTTON_x);

void HT32F_DVB_COMInit(COM_TypeDef COMn, USART_InitTypeDef* USART_InitStructure);

void HT32F_DVB_BuzzerFun(u16 hFreq, u8 bDuty, u32 mode);
void HT32F_DVB_BuzzerOutputCmd(ControlStatus Control);
/**
  * @}
  */


/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#include "common/i2c_eeprom.h"
#include "common/spi_flash.h"
#include "common/spi_lcd.h"

#ifdef __cplusplus
}
#endif

#endif
