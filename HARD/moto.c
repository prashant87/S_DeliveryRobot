#include "moto.h"
void Direction_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14|GPIO_Pin_15;//C14 C15 INA1 INB1
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;//A0 A1 INA2 INB2
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
}

void P_Right_Moto(u16 p)
{
	GPIO_ResetBits(GPIOC,GPIO_Pin_14);	
  GPIO_SetBits(GPIOC,GPIO_Pin_15);
	TIM_SetCompare1(TIM4,p);
}
void N_Right_Moto(u16 p)
{
	GPIO_ResetBits(GPIOC,GPIO_Pin_15);	
  GPIO_SetBits(GPIOC,GPIO_Pin_14);
	TIM_SetCompare1(TIM4,p);
}
void P_Left_Moto(u16 p)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_0);	
  GPIO_SetBits(GPIOA,GPIO_Pin_1);
	TIM_SetCompare2(TIM4,p);
}

void N_Left_Moto(u16 p)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_1);	
  GPIO_SetBits(GPIOA,GPIO_Pin_0);
	TIM_SetCompare2(TIM4,p);
}
void Moto_Stop(void)
{
	GPIO_ResetBits(GPIOC,GPIO_Pin_15);	
  GPIO_ResetBits(GPIOC,GPIO_Pin_14);
	TIM_SetCompare1(TIM4,0);
	
	GPIO_ResetBits(GPIOA,GPIO_Pin_1);	
  GPIO_ResetBits(GPIOA,GPIO_Pin_0);
	TIM_SetCompare2(TIM4,0);
}
void turn_right(void)
{
	P_Left_Moto(1000);
	N_Right_Moto(1000);
}

void turn_left(void)
{
	P_Right_Moto(1000);
	N_Left_Moto(1000);
}
