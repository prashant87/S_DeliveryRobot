#ifndef USART_H
#define USART_H
#endif


#include "stm32f10x.h"
#define Target_Num           3     //��3��Ϊ������������4G���ݹ����Ĳ�����
#define USART_REC_LEN  			13  	//�����������ֽ���
static u8 i =0 ;
static u8  USART_RX_BUF[USART_REC_LEN];
void usart_init(u32 bound);
