#ifndef __TJC_H
#define __TJC_H 			   
#include "ht32f5xxxx_usart.h"
#include "ht32f5xxxx_01.h"
#include "ht32.h"

void tjc_show(void);
void tjc_jdt(unsigned char max_val,unsigned char j_x,unsigned char j_val);
void tjc_num(unsigned char n_x,unsigned char n_val);
void tjc_txt(unsigned char t_x,u8 *t_txt);
//void tjc_button(void);


/*
typedef struct s_TJC
{
	unsigned char *sTJC_jdt;
	unsigned char *sTJC_num;
	char sTJC_txt;
	
	
}
str_TJC;

*/

#endif

