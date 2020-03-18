#ifndef USART_H
#define USART_H
#endif


#include "stm32f10x.h"
#define Target_Num           3     //以3号为例，将来是由4G传递过来的参数。
#define USART_REC_LEN  			13  	//定义最大接收字节数
static u8 i =0 ;
static u8  USART_RX_BUF[USART_REC_LEN];
void usart_init(u32 bound);
