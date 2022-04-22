#ifndef _DHT11_H_
#define _DHT11_H_


#include "ht32.h"
#include "delay.h"
#include "ht32_board.h"
#include "ht32_board_config.h"

//������DHT11ͨ��ʹ�õ�����
#define dou_dht11_GPIOx			GPIO_PA
#define dou_dht11_HT_GPIOx	HT_GPIOA
#define dou_dht11_GPIO_PIN	GPIO_PIN_0


// dou_dht11 API **************************************************************
//���ݶ���:
extern uint8_t dou_dht11_temperature_data_h;    //�¶ȸ�8λ
extern uint8_t dou_dht11_temperature_data_l;    //�¶ȵ�8λ
extern uint8_t dou_dht11_humidity_data_h;       //ʪ�ȸ�8λ
extern uint8_t dou_dht11_humidity_data_l;       //ʪ�ȵ�8λ
extern uint8_t dht11_data[4];

void dou_dht11_init(void);      //��ʼ������
void dou_dht11_get_data(void);  //�������ݺ���
//void dou_dht11_test(void);      //���Ժ�������ѭ����



#endif
