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
extern uint8_t T_H;    //�¶ȸ�8λ
extern uint8_t T_L;    //�¶ȵ�8λ
extern uint8_t H_H;       //ʪ�ȸ�8λ
extern uint8_t H_L;       //ʪ�ȵ�8λ

void dou_dht11_init(void);      //��ʼ������
void dou_dht11_get_data(void);  //�������ݺ���
//void dou_dht11_test(void);      //���Ժ�������ѭ����



#endif
