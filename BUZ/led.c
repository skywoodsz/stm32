#include"led.h"
void LED_Init()
{
	GPIO_InitTypeDef GPIO_InitStruct;//����GPIO����ģʽ
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);//ʹGPIOC�ܽ�ʱ��ʹ��
	GPIO_InitStruct.GPIO_Pin=LED_PIN;//����ܽ�
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;//�������
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;//���ô����ٶ�

	GPIO_Init(GPIOC,&GPIO_InitStruct);//��GPIOC�Ķ���ܽų�ʼ��
	GPIO_SetBits(GPIOC,LED_PIN);//��GPIOC����ܽ����øߵ�ƽ��Ϩ��LED
}
