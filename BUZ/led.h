#ifndef _LED_H
#define _LED_H
#include "system.h"
#include "stm32f10x.h"
#define LED PCout(0)
#define LED_PIN GPIO_Pin_0
void LED_Init(void);
#endif
