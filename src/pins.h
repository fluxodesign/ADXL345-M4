/*
 * pins.h
 *
 *  Created on: 17Sep.,2017
 *      Author: viper
 */

#ifndef PINS_H_
#define PINS_H_

#include "stm32f4xx_conf.h"

#define MilisecondsIT 1000

volatile uint32_t t_miliseconds;
volatile uint32_t t_seconds;

void pinSetup(GPIO_InitTypeDef, uint32_t, GPIOMode_TypeDef, GPIOSpeed_TypeDef, GPIOOType_TypeDef, GPIOPuPd_TypeDef, GPIO_TypeDef *);
void sleep_seconds(uint32_t);
void sleep_milis(uint32_t);
uint32_t getSystemClock();

#endif /* PINS_H_ */
