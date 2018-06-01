#include "key.h"
//��ʼ��KEY GPIO
void KEY_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	//ʱ��ʹ��GPIOA,GPIOE
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOE,ENABLE);
	//��ʼ��KEY_UP(GPIOA 0)Ϊ�������룬50MHz
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPD;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	//��ʼ��KEY1 2 3(GPIOE 2 3 4)Ϊ�������룬50MHz
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOE,&GPIO_InitStructure);
}
//����ɨ�裺mode==1ʱ֧������������mode==0ʱ��֧����������
uchar KEY_Scan(uchar mode)
{
		static uchar key=1;//�ڲ�֧����������ģʽ�� static ����
		if(key==1&&(KEY_UP==1||KEY_LEFT==0||KEY_DOWN==0||KEY_RIGHT==0))//����⵽��������
		{
			delay_ms(10);//����
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
		else if(KEY_UP==0&&KEY_LEFT==1&&KEY_DOWN==1&&KEY_RIGHT==1)//��δ��⵽��������
		{
			key=1;
		}
		if(mode==1)//mode�ı�
		{
			key=1;
		}
		return 0;
}
