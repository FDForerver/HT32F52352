#ifndef _KEY_H_
#define _KEY_H_

#include "ht32f5xxxx_ckcu.h"
#include "ht32f5xxxx_gpio.h"
#include "ht32f5xxxx_01.h"

//����ʹ�ö˿�
#define HT_GPIO_GROUP     (HT_GPIOB)

//���Ŷ���
#define GPIO_PIN   				(GPIO_PIN_2|GPIO_PIN_4)
//���巽ʽ
#define GPIO_PR           (GPIO_PR_DOWN)
//����ģʽ
#define GPIO_FIFO_MODE    (AFIO_FUN_GPIO)

void Key_Init(void);
void Key_Scans(void);


#endif


