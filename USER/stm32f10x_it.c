/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"
#include "Magic.h"
#include "usart.h"
#include "moto.h"

/** @addtogroup STM32F10x_StdPeriph_Template
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
}



void USART1_IRQHandler(void)                	//����1�жϷ������,4G
	{		
	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
	{
		USART_ClearFlag(USART1, USART_IT_RXNE);

	}
	}
	
void USART2_IRQHandler(void)                	//����2�жϷ������,RFID
	{		
		
	u8 Res;
  u8 flag =0;//������ɱ�־λ��
	u8 k=0;
	if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)
	{
		USART_ClearFlag(USART2, USART_IT_RXNE);
    Res =USART_ReceiveData(USART2);	//��ȡ���յ�������
		if(i != (USART_REC_LEN-1))//����δ���
			{
			USART_RX_BUF[i]=Res ;
			i++;	
			} 
			else
			{
			USART_RX_BUF[USART_REC_LEN-1]=Res ;//װ�����һ������
			i=0;
			flag =1 ;
			}
///////////////�������////////////////// 
		if(flag == 1)
		{ 
			for( k=0;k<USART_REC_LEN;k++)
			{	USART_SendData(USART2,USART_RX_BUF[i]);}//�ش����һ�·��ĶԲ��ԣ�
			
			if(USART_RX_BUF[10]==(0x30|Target_Num))//�����Ŀ��ֵ��
			{
				Moto_Stop( );//ͣ����
			}
		}
     			
	}
	}
//void TIM4_IRQHandler(void)
//{
//	if(TIM_GetFlagStatus(TIM4,TIM_IT_Update) != RESET)
//	{
//	}
//}
void TIM3_IRQHandler(void)//500ms��ʱ�жϣ�ѭ��PID���ƣ�
{
	u8 readvalue;	
	if(TIM_GetFlagStatus(TIM3,TIM_IT_Update) != RESET)
	{
	  TIM_ClearFlag(TIM3, TIM_FLAG_Update);
		readvalue = ReadMagicValue();
    readvalue = Filter(readvalue);//��ȥ�����ʵ����ݣ�
		pwm = MagicPID(readvalue);	
		P_Right_Moto(2000+pwm);
		P_Left_Moto(2000-pwm);		
	}
}
/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
