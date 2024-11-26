/*
 * systik.h
 *
 *  Created on: Nov 24, 2024
 *      Author: AHMED ABDELAZIZ
 */

#ifndef INC_SYSTIK_H_
#define INC_SYSTIK_H_
#include "main.h"
#include "STM32F1xx.h"
#define OSC     72000000  // 72 Mhz
#define usec	72000 	 // 1000
class Delay
{
public:
	Delay();
	void Init();

void SysTick_Handler();//from startup>>startup_stm32f103c8tx000.s
void delay_us(uint32_t us);
void SysTick_Enable();
void SysTick_Disable();
private:
 volatile uint32_t ticks; //volatile for ticks cause ticks is unused as optimized so voaltile
uint32_t us_;

};

#endif /* INC_SYSTIK_H_ */
