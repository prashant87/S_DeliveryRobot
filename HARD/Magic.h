#ifndef MAGIC_H
#define MAGIC_H
#endif

#include "stm32f10x.h"
#define KP 1
#define KI 1
#define KD 1
static u16 pwm;
static u8 last_data = 24;

u8 ReadMagicValue(void);
u16 MagicPID(u8 readvalue);
void Magic_IO_Init(void);
u8 Filter(u8 data);
u8 Findmidle(void);

