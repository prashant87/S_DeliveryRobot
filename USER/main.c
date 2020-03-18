#include "stm32f10x.h"
#include "Magic.h"
#include "time.h"
#include "moto.h"
#include "usart.h"

int main(void)
{
	Direction_Init();
	Magic_IO_Init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�жϷ���2��
  usart_init(9600);
	TIM3_Int_Init(4999,7999);//��ʱ500ms�ж�һ�Ρ�
	TIM4_PWM_Init(7199,0);//72000000/(7199+1)/(0+1)=10000Hz
	
	while(1)
	{
	 USART_SendData(USART2,ReadMagicValue());//���ԣ�
	 Delay(9000000);	
	 USART_SendData(USART1,0x55);//���ԣ�
	}
}

