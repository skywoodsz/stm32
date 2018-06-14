#include "wwdg.h"
#include "led.h"
//设置计数初值（默认最大，详情请看WWDG_CR寄存器）
uchar WWDG_CNT=0x7f;
void WWDG_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG,ENABLE);//使能时钟
	WWDG_SetPrescaler(WWDG_Prescaler_8);//设置分频系数
	WWDG_SetWindowValue(0x5f);//设置窗口值（上限）
	//WWDG_CNT=WWDG_CNT&tr;//设置最高位为01
	WWDG_Enable(WWDG_CNT);//使能并设计数初值
	
	WWDG_ClearFlag();//清除唤醒中断标志位
	WWDG_EnableIT();//开启唤醒中断（0x4f）
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel=WWDG_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0;
	NVIC_Init(&NVIC_InitStructure);//开总中断
}
void WWDG_IRQHandler()
{
	WWDG_SetCounter(WWDG_CNT);
	WWDG_ClearFlag();
	led2=!led2;
}
