#include "Magic.h"

void Magic_IO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
}
u8 ReadMagicValue(void)
{
	u8 readvalue=0;
	readvalue = (GPIO_ReadInputData(GPIOA)&0X00f0);//高四位：A7 A6 A5 A4
	readvalue =readvalue|((GPIO_ReadInputData(GPIOB)&0Xf000)>>12);//低四位：B15 B14 B13 B12
  return readvalue;
}
u16 MagicPID(u8 readvalue)
{
	u8 Bias;
	u16 pwm;
	u16 Integral_bias;
	u8 Last_Bias;
	Bias = readvalue - 24;
	Integral_bias += Bias;
	pwm = KP*Bias + KI*Integral_bias + KD*(Bias-Last_Bias);
	Last_Bias = Bias;
	return pwm;
	
}
u8 Filter(u8 data)
{	
	if(data ==3 | data == 6 |  data ==12 | data ==24 | data ==48 | data == 96 |  data ==192)
	{
		last_data = data;
	}
	return last_data;
}
u8 Findmidle(void)
{
	if(24 == Filter(ReadMagicValue()))//如果找到中线了，返回1，没有就返回0；
		return 1;
	else
		return 0;
		
}