#include "stm32f10x.h"
#include "buz.h"
#include "led.h"
#include "SysTick.h"
#include "system.h"
int main()
{
	unsigned int i=0;
	SysTick_Init(72);
	BEEP_Init();
	LED_Init();
	//GPIO_SetBits(GPIOB,GPIO_Pin_5);
	//GPIO_ResetBits(GPIOB,GPIO_Pin_5);
	while(1)
	{
		i++;
		if(i%20000==0)
		{
			LED=!LED;
			//i=0;
		}
		if(i%10==0)
		beep=!beep;//无源蜂鸣器，需震荡信号
		delay_us(10);//必须 
	}
}
