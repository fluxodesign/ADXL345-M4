/*
 * pins.c
 *
 *  Created on: 17Sep.,2017
 *      Author: viper
 */

#include "pins.h"

void pinSetup(GPIO_InitTypeDef iopin, uint32_t pin, GPIOMode_TypeDef mode, GPIOSpeed_TypeDef speed, GPIOOType_TypeDef oType, GPIOPuPd_TypeDef pupd, GPIO_TypeDef * port) {
	iopin.GPIO_Pin = pin;
	iopin.GPIO_Mode = mode;
	iopin.GPIO_Speed = speed;
	iopin.GPIO_OType = oType;
	iopin.GPIO_PuPd = pupd;
	GPIO_Init(port, &iopin);
}

uint32_t getSystemClock() {
	RCC_ClocksTypeDef systemClock;
	RCC_GetClocksFreq(&systemClock);
	uint32_t multiplier = systemClock.HCLK_Frequency / 4000000;
	return multiplier;
}

/**
 * "while" loop takes 4 cycles - for 1 microsecond delay, we need to divide with 4 million
 */
void sleep_seconds(uint32_t seconds) {
	volatile uint32_t sStart = t_seconds;
	while ((t_seconds - sStart) < seconds) {
		asm volatile("nop");
	}
}

void sleep_milis(uint32_t miliseconds) {
	volatile uint32_t msStart = t_miliseconds;
	while ((t_miliseconds - msStart) < miliseconds) {
		asm volatile("nop");
	}
}
