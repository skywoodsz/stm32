#include "stm32f10x.h"
#include"led.h"
int main()
{
	LED_Init();
	while(1)
	{
		GPIO_ResetBits(GPIOC,LED_PIN);//��GPIOC����ܽ����õ͵�ƽ������LED
	}
}
