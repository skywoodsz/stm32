#ifndef _KEY_H
#define _KEY_H

#include "stm32f10x.h"
#include "SysTick.h"
#include "system.h"

#define uchar unsigned char
#define KEY_UP PAin(0) 
#define KEY_LEFT PEin(2) 
#define KEY_DOWN PEin(3) 
#define KEY_RIGHT PEin(4) 
//主函数中对应switch语句
#define K_UP 1
#define K_LEFT 2 
#define K_DOWN 3
#define K_RIGHT 4 

void KEY_Init(void);
uchar KEY_Scan(uchar mode);
#endif
