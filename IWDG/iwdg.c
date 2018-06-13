#include "iwdg.h"
void Iwdg_Init(uint pre,uint rlr)
{
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);//取消写保护
	IWDG_SetPrescaler(pre);//设置预分频系数（0~6）
	IWDG_SetReload(rlr);//设置重装值（<0xfff）
	IWDG_Enable();//使能
}
void Iwdg_ToFeedDog()
{
	IWDG_ReloadCounter();
}
