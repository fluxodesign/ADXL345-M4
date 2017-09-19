/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "pins.h"

void setup(void);

/*
 * For this first version, we are going to play with the User LEDs:
 * - Orange LED (LD3): PD13
 * - Green LED (LD4): PD12
 * - Red LED (LD5): PD14
 * - Blue LED (LD6): PD15
 */
GPIO_InitTypeDef Pin_Green;
GPIO_InitTypeDef Pin_Red;
GPIO_InitTypeDef Pin_Blue;
GPIO_InitTypeDef Pin_Orange;

int main(void) {
	setup();

	while (1) {
		// Blue
		GPIO_SetBits(LED6_GPIO_PORT, LED6_PIN);
		sleep_milis(150);
		GPIO_ResetBits(LED6_GPIO_PORT, LED6_PIN);
		// Red
		GPIO_SetBits(LED5_GPIO_PORT, LED5_PIN);
		sleep_milis(150);
		GPIO_ResetBits(LED5_GPIO_PORT, LED5_PIN);
		// Orange
		GPIO_SetBits(LED3_GPIO_PORT, LED3_PIN);
		sleep_milis(150);
		GPIO_ResetBits(LED3_GPIO_PORT, LED3_PIN);
		// Green
		GPIO_SetBits(LED4_GPIO_PORT, LED4_PIN);
		sleep_milis(150);
		GPIO_ResetBits(LED4_GPIO_PORT, LED4_PIN);
	}
}

void SysTick_Handler() {
	t_miliseconds++;
	if (t_miliseconds % 1000 == 999) {
		t_seconds++;
	}
}

void setup() {
	SystemInit();
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock / MilisecondsIT);

	RCC_AHB1PeriphClockCmd(LED4_GPIO_CLK, ENABLE);
	t_miliseconds = t_seconds = 0;

	pinSetup(Pin_Green, LED4_PIN, GPIO_Mode_OUT, GPIO_Speed_2MHz, GPIO_OType_PP, GPIO_PuPd_UP, LED4_GPIO_PORT);
	pinSetup(Pin_Red, LED5_PIN, GPIO_Mode_OUT, GPIO_Speed_2MHz, GPIO_OType_PP, GPIO_PuPd_UP, LED5_GPIO_PORT);
	pinSetup(Pin_Blue, LED6_PIN, GPIO_Mode_OUT, GPIO_Speed_2MHz, GPIO_OType_PP, GPIO_PuPd_UP, LED6_GPIO_PORT);
	pinSetup(Pin_Orange, LED3_PIN, GPIO_Mode_OUT, GPIO_Speed_2MHz, GPIO_OType_PP, GPIO_PuPd_UP, LED3_GPIO_PORT);
}
