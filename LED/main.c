#include "stm32f10x.h"
#include"led.h"
int main()
{
	LED_Init();
	while(1)
	{
		GPIO_ResetBits(GPIOC,LED_PIN);//对GPIOC定义管教设置低电平，点亮LED
	}
}
