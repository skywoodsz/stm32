#ifndef _LED_H
#define _LED_H

#include "stm32f10x.h"
#include "SysTick.h"
#include "system.h"

#define LED_PIN GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7

#define led1 PCout(0)
#define led2 PCout(1)
#define led3 PCout(2)
#define led4 PCout(3)

void LED_Init(void);
#endif
