/*
 * systik.cpp
 *
 *  Created on: Nov 24, 2024
 *      Author: AHMED ABDELAZIZ
 */

#include "systik.h"

extern volatile uint32_t ticks;
	Delay::Delay()
{
		Init();
}
void Delay::Init()
{
	SysTick->CTRL =0;
	//SysTick->LOAD =8000 -1; // Flag Operation takes 1 tick so -1 is set so that flag is the last tick
   // SysTick->VAL = 0; // Clear the current value register
	SysTick->CTRL =(1<<2) |(1<<1);
	SysTick->LOAD =(OSC/usec)-1;
	SysTick->CTRL |=(1<<0); // enable at last as a safety pattern

}
//INTERRUPT Handler (don't have to write it in stm32f1xx_it.c) okay if it's deleted or delete
//or delete void SysTick_handler() function;
//written in c not c++ may cause errors so it better be removed
extern "C" void Delay::SysTick_Handler()  //from startup>>startup_stm32f103c8tx000.s
{
	//do something every 1ms..
	if(ticks!=0)
	{
		ticks--;
	}
}

void Delay::delay_us(uint32_t us)
{
	ticks = us;
	while(ticks)
	{
		SysTick_Handler();
	//__WFI();
	}
}

void Delay::SysTick_Enable()
{
	SysTick->CTRL =(1<<2) |(1<<1);
	SysTick->LOAD =(OSC/usec)-1;
	SysTick->CTRL |=(1<<0); // enable at last as a safety pattern

}
void Delay::SysTick_Disable()
{
	SysTick->CTRL =0;
}
