#include "key.h"
//初始化KEY GPIO
void KEY_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	//时钟使能GPIOA,GPIOE
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOE,ENABLE);
	//初始化KEY_UP(GPIOA 0)为下拉输入，50MHz
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPD;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	//初始化KEY1 2 3(GPIOE 2 3 4)为上拉输入，50MHz
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOE,&GPIO_InitStructure);
}
//按键扫描：mode==1时支持连续按键，mode==0时不支持连续按键
uchar KEY_Scan(uchar mode)
{
		static uchar key=1;//在不支持连续按键模式下 static 必须
		if(key==1&&(KEY_UP==1||KEY_LEFT==0||KEY_DOWN==0||KEY_RIGHT==0))//若检测到按键按下
		{
			delay_ms(10);//消抖
			key=0;
			if(KEY_UP==1)
			{
				return K_UP;
			}
			if(KEY_LEFT==0)
			{
				return K_LEFT;
			}
			if(KEY_DOWN==0)
			{
				return K_DOWN;
			}
			if(KEY_RIGHT==0)
			{
				return K_RIGHT;
			}
		
		}
		else if(KEY_UP==0&&KEY_LEFT==1&&KEY_DOWN==1&&KEY_RIGHT==1)//若未检测到按键按下
		{
			key=1;
		}
		if(mode==1)//mode改变
		{
			key=1;
		}
		return 0;
}
