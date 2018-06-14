#ifndef _LED_H
#define _LED_H

#include "stm32f10x.h"

#define led0 PCout(0)
#define LED_PIN GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7
void LED_Init(void);

#endif
