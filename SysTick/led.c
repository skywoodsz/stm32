#include"led.h"
void LED_Init()
{
	GPIO_InitTypeDef GPIO_InitStruct;//定义GPIO工作模式
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);//使GPIOC管脚时钟使能
	GPIO_InitStruct.GPIO_Pin=LED_PIN;//定义管脚
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;//推挽输出
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;//设置传输速度

	GPIO_Init(GPIOC,&GPIO_InitStruct);//对GPIOC的定义管脚初始化
	GPIO_SetBits(GPIOC,LED_PIN);//对GPIOC定义管教设置高电平，熄灭LED
}
