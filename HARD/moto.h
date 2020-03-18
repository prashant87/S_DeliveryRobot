#ifndef MOTO_H
#define MOTO_H
#endif

#include "stm32f10x.h"
void Direction_Init(void);
void P_Right_Moto(u16 p);
void N_Right_Moto(u16 p);
void P_Left_Moto(u16 p);
void N_Left_Moto(u16 p);
void Moto_Stop(void);
void turn_right(void);
void turn_left(void);

