#include "stm32f10x.h"
#include "wwdg.h"
#include "led.h"
#include "SysTick.h"
int main()
{
	WWDG_Init();
	LED_Init();
	SysTick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 
	led1=!led1;
	delay_ms(500);
	while(1)
	{
		led1=1;
	}
}
