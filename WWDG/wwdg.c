#include "wwdg.h"
#include "led.h"
//���ü�����ֵ��Ĭ����������뿴WWDG_CR�Ĵ�����
uchar WWDG_CNT=0x7f;
void WWDG_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG,ENABLE);//ʹ��ʱ��
	WWDG_SetPrescaler(WWDG_Prescaler_8);//���÷�Ƶϵ��
	WWDG_SetWindowValue(0x5f);//���ô���ֵ�����ޣ�
	//WWDG_CNT=WWDG_CNT&tr;//�������λΪ01
	WWDG_Enable(WWDG_CNT);//ʹ�ܲ��������ֵ
	
	WWDG_ClearFlag();//��������жϱ�־λ
	WWDG_EnableIT();//���������жϣ�0x4f��
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel=WWDG_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0;
	NVIC_Init(&NVIC_InitStructure);//�����ж�
}
void WWDG_IRQHandler()
{
	WWDG_SetCounter(WWDG_CNT);
	WWDG_ClearFlag();
	led2=!led2;
}
