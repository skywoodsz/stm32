#include "stm32f10x.h"
#include "system.h"
#include "SysTick.h"
#include "key.h"
#include "led.h"
int main()//��Ϊvoid main()��MDK����������ԭ����
{
	uchar key;
	SysTick_Init(72);
	KEY_Init();
	LED_Init();
	while(1)
	{
		key=KEY_Scan(0);
		switch(key)
		{
			case(K_UP):    led1=!led1;break;//������Ϩ��led1
			case(K_DOWN):  led2=!led2;break;//������Ϩ��led2
			case(K_LEFT):  led3=!led3;break;//������Ϩ��led3
			case(K_RIGHT): led4=!led4;break;//������Ϩ��led4
		}
	}
}
