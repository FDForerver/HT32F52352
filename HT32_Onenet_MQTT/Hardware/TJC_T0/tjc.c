#include "tjc.h"
#include "delay.h"
#include "usart.h"

unsigned char TJC_NUM[10]={0,5,10,15,20,25,30,35,64,48};
unsigned char TJC_JDT[8]={54,78,24,90,100,45,88,34};
//char TJC_TXT[8][4]={"富强","民主","文明","和谐","自由","平等","公正","法治"};
	

//**************将进度条数值发送给串口屏***************//
void tjc_jdt(unsigned char max_val,unsigned char j_x,unsigned char j_val)
{
	j_val=(100/max_val)*j_val;
	Usart_SendStr(COM1_PORT,"j");
	Usart_Sendbyte(COM1_PORT,j_x+48);// 把整数  int i 转为字符码并发送
	Usart_SendStr(COM1_PORT,".val=");
	Int2Char_Send(j_val);
	USART_SEND_END();
		
}

//****************将文本组件字符发送给串口屏*************//
void tjc_txt(unsigned char t_x,u8 *t_txt)
{
	Usart_SendStr(COM1_PORT,"t");
	Usart_Sendbyte(COM1_PORT,t_x+48);// 把整数  int i 转为字符码并发送
	Usart_SendStr(COM1_PORT,".txt=");
	Usart_Sendbyte(COM1_PORT,34);//引号
	Usart_SendStr(COM1_PORT,t_txt);
	Usart_Sendbyte(COM1_PORT,34);//引号
	
	USART_SEND_END();
}

//****************将数字组件数值发送给串口屏*************//
void tjc_num(unsigned char n_x,unsigned char n_val)
{
	
	Usart_SendStr(COM1_PORT,"n");
	Usart_Sendbyte(COM1_PORT,n_x+48);// 把整数  int i 转为字符码并发送
	Usart_SendStr(COM1_PORT,".val=");
	Int2Char_Send(n_val);
	USART_SEND_END();

}

void tjc_show(void)
{
	unsigned char i=0;
  //	u8 j=0;
	//uint8_t b[4];
	
	for(i=0;i<10;i++)
	{
		if(i<8)
		{tjc_jdt(100,i,TJC_JDT[i]);}
		tjc_num(i,TJC_NUM[i]);
		
		
		/*for(j=0;j<4;j++)
		{
			b[j]=TJC_TXT[i][j];
		}
		tjc_txt(i,b);
		*/
		
		delay(3000);
	}
}


