#ifndef _ESP8266_H_
#define _ESP8266_H_


#define WIFI_Clr() GPIO_ClearOutBits(HT_GPIOC,GPIO_PIN_9)//CS
#define WIFI_Set() GPIO_SetOutBits(HT_GPIOC,GPIO_PIN_9)


#define REV_OK		0	//接收完成标志
#define REV_WAIT	1	//接收未完成标志

#define SEND_OK 0
#define SEND_ERROR 1


#define ESP8266_RST GPIO_PIN_9


unsigned char *ESP8266_GetIPD(unsigned short timeOut);

void ESP8266_Init(void);

void ESP8266_Clear(void);

void ESP8266_SendData(unsigned char *data, unsigned short len);

_Bool ESP8266_WaitRecive(void);

_Bool ESP8266_SendCmd(char *cmd, char *res);

#endif
