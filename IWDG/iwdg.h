#ifndef _IWDG_H_
#define _IWDG_H_

#include "stm32f10x.h"
#define uint unsigned int
	
void Iwdg_Init(uint pre,uint rlr);
void Iwdg_ToFeedDog(void);
#endif
