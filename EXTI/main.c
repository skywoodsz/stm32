#include "stm32f10x.h"
#include "SysTick.h"
#include "system.h"
#include "key.h"
#include "led.h"
void Exit()
{
	///GPIO_InitTypeDef GPIO_InitStruct;
	EXTI_InitTypeDef EXTI_InitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;
	//还需要？不需要，已经初始化过了
	/*GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_3;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOE,&GPIO_InitStruct);
	*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//开复用时钟，使GPIO映射到中断线上
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource3);//映射中断线
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource0);
	//设置中断线3
	EXTI_InitStruct.EXTI_Line=EXTI_Line3;//设置中断线
	EXTI_InitStruct.EXTI_LineCmd=ENABLE;//使能
	EXTI_InitStruct.EXTI_Mode=EXTI_Mode_Interrupt;//选择事件or中断
	EXTI_InitStruct.EXTI_Trigger=EXTI_Trigger_Falling;//选择中断触发方式
	EXTI_Init(&EXTI_InitStruct);//外部中断初始化
	
	NVIC_InitStruct.NVIC_IRQChannel=EXTI3_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitStruct);//开总中断
	//设置中断线0
	EXTI_InitStruct.EXTI_Line=EXTI_Line0;//设置中断线
	EXTI_InitStruct.EXTI_LineCmd=ENABLE;//使能
	EXTI_InitStruct.EXTI_Mode=EXTI_Mode_Interrupt;//选择事件or中断
	EXTI_InitStruct.EXTI_Trigger=EXTI_Trigger_Rising;//选择中断触发方式
	EXTI_Init(&EXTI_InitStruct);//外部中断初始化
	
	NVIC_InitStruct.NVIC_IRQChannel=EXTI0_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=0;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=0;
	NVIC_Init(&NVIC_InitStruct);//开总中断

}
void EXTI3_IRQHandler()
{
	if(EXTI_GetITStatus(EXTI_Line3)==1)
	{
		delay_ms(10);
		if(KEY_DOWN==0)
		{
			while(1)
			{
				led2=!led2;
				delay_ms(500);
			}
		}
	}
	EXTI_ClearITPendingBit(EXTI_Line3);
}
void EXTI0_IRQHandler()
{
	if(EXTI_GetITStatus(EXTI_Line0)==1)
	{
		delay_ms(10);
		if(KEY_UP==1)
		{
			EXTI_ClearITPendingBit(EXTI_Line3);
			while(1)
			{
				led3=!led3;
				delay_ms(500);
			}
		}
	}
	EXTI_ClearITPendingBit(EXTI_Line0);
}
int main()
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	SysTick_Init(72);
	KEY_Init();
	LED_Init();
	Exit();
	while(1)
	{
		led1=!led1;
		delay_ms(500);
	}
}
