#include "iwdg.h"
void Iwdg_Init(uint pre,uint rlr)
{
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);//ȡ��д����
	IWDG_SetPrescaler(pre);//����Ԥ��Ƶϵ����0~6��
	IWDG_SetReload(rlr);//������װֵ��<0xfff��
	IWDG_Enable();//ʹ��
}
void Iwdg_ToFeedDog()
{
	IWDG_ReloadCounter();
}
