#ifndef _DHT11_H_
#define _DHT11_H_


#include "ht32.h"
#include "delay.h"
#include "ht32_board.h"
#include "ht32_board_config.h"

//定义与DHT11通信使用的引脚
#define dou_dht11_GPIOx			GPIO_PA
#define dou_dht11_HT_GPIOx	HT_GPIOA
#define dou_dht11_GPIO_PIN	GPIO_PIN_0


// dou_dht11 API **************************************************************
//数据定义:
extern uint8_t T_H;    //温度高8位
extern uint8_t T_L;    //温度低8位
extern uint8_t H_H;       //湿度高8位
extern uint8_t H_L;       //湿度低8位

void dou_dht11_init(void);      //初始化函数
void dou_dht11_get_data(void);  //更新数据函数
//void dou_dht11_test(void);      //测试函数（死循环）



#endif
