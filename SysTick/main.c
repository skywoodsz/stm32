#include "stm32f10x.h"
#include "led.h"
#include "system.h"
#include "SysTick.h"
int main()
{
	LED_Init();
	SysTick_Init(72);
	while(1)
	{
		led0=!led0;
		delay_ms(500);
		led0=!led0;
		delay_ms(500);
	}
}
