#include "stm32f10x.h"
#include "key.h"
#include "led.h"
#include "iwdg.h"
#include "system.h"
#include "Systick.h"
int main()
{
	SysTick_Init(72);
	KEY_Init();
	LED_Init();
	Iwdg_Init(4,800);
	led1=!led1;
	delay_ms(500);
	while(1)
	{
		if(KEY_UP==1)
		{
			delay_ms(10);
			Iwdg_ToFeedDog();
			led2=0;
		}
		led3=!led3;
		delay_ms(500);
	}
}
