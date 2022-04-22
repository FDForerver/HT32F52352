#ifndef _KEY_H_
#define _KEY_H_

#include "ht32f5xxxx_ckcu.h"
#include "ht32f5xxxx_gpio.h"
#include "ht32f5xxxx_01.h"

//定义使用端口
#define HT_GPIO_GROUP     (HT_GPIOB)

//引脚定义
#define GPIO_PIN   				(GPIO_PIN_2|GPIO_PIN_4)
//定义方式
#define GPIO_PR           (GPIO_PR_DOWN)
//定义模式
#define GPIO_FIFO_MODE    (AFIO_FUN_GPIO)

void Key_Init(void);
void Key_Scans(void);


#endif


