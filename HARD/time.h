#ifndef TIME_H
#define TIME_H
#endif


#include "stm32f10x.h"
#define EN_USART1_RX 1

void TIM4_PWM_Init(u16 arr,u16 psc);//TIM4����PWM����
void TIM3_Int_Init(u16 arr,u16 psc);//TIM3����������ʱ�жϣ�Ҳ���ǿ������ڡ�
void Delay(u32 count);
