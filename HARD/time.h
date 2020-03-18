#ifndef TIME_H
#define TIME_H
#endif


#include "stm32f10x.h"
#define EN_USART1_RX 1

void TIM4_PWM_Init(u16 arr,u16 psc);//TIM4产生PWM波；
void TIM3_Int_Init(u16 arr,u16 psc);//TIM3用来产生定时中断，也就是控制周期。
void Delay(u32 count);
