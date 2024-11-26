/*
 * timer2.cpp
 *
 *  Created on: Nov 21, 2024
 *      Author: AHMED ABDELAZIZ
 */


#include "timer2.h"
uint8_t Timer2::Counttim;
unsigned int Timer2::PERIOD=0;

Timer2::Timer2(unsigned int  Period)
{
		PERIOD=Period;

	if(Counttim==0)
	{
		Tim2_Init(PERIOD);
	}
	Counttim++;
	}

void Timer2::Tim2_Init(unsigned int PERIOD)
{

	///<Intiate Clock 72>
	Clock72 clk;
	///<Enable Timer 2 RCC>
	RCC->APB1ENR |= (1<<0);
	///<Reset Control Register just in case>
	TIM2->CR1=0x0000;
	///<Set Pre-scaler>
	TIM2->PSC=71; // 72 / 71 +1 = 1MHZ timer clock speed.
	///<Set Period>
	TIM2->ARR =PERIOD-1;
	///<Select PWM>
	//CH4
	   // TIM2->CCMR2 |= (6 << 12); // PWM mode 1 for channel 4
	    //TIM2->CCMR2 |= (1 << 11); // Preload enable for channel 4
	///<Enable CH's and Polarity (Active-High)>
	 //Enable CH4
	 //TIM2->CCER =(1<<12);
    //<Preload Enable & PWM Mode 1 for CH3>
	 TIM2->CCMR2 |=(8<<0) |(6<<4);
	///<Enable CH's and Polarity (Active-High)>
	 //<Enable CH1 & CH3>
	 TIM2->CCER =(1<<8);
    ///<Enable Control Register>
	 TIM2->CR1|=(1<<0);
}

void Timer2::pwmWrite()
{
	///<Making sure duty stays between 0% & 100%>
	if(Duty < 0)
	{
		Duty =0;
	}
	else if (Duty > 100)
	{
		Duty=100;
	}
	unsigned int PulseWidth = PERIOD * Duty/100;
	TIM2->CCR3=PulseWidth;
}
void Timer2::pwmWrite(unsigned int duty)
{
	Duty=duty;
	///<Making sure duty stays between 0% & 100%>
	if(Duty < 0)
	{
		Duty =0;
	}
	else if (Duty > 100)
	{
		Duty=100;
	}
	unsigned int PulseWidth = PERIOD * Duty/100;
	TIM2->CCR3=PulseWidth;
}
void Timer2::pwmWrite3(unsigned int duty)
{
	Duty=duty;
	///<Making sure duty stays between 0% & 100%>
	if(Duty < 0)
	{
		Duty =0;
	}
	else if (Duty > 100)
	{
		Duty=100;
	}
//	unsigned int PulseWidth =  PERIOD * Duty /100;
	TIM2->CCR3=Duty;
}
void Timer2::pwmWrite3(float duty)
{
	///<Making sure duty stays between 0% & 100%>
	if(duty < 0)
	{
		duty =0;
	}
	else if (duty > 100)
	{
		duty=100;
	}
	float PulseWidth =  PERIOD * duty /100;
	TIM2->CCR3=PulseWidth;
}

/*void Timer2::pwmWrite3(unsigned int duty)
{
	Duty=duty;
	///<Making sure duty stays between 0% & 100%>
	if(Duty < 0)
	{
		Duty =0;
	}
	else if (Duty > 100)
	{
		Duty=100;
	}
	unsigned int PulseWidth = PERIOD * Duty/100;
	TIM2->CCR3=PulseWidth;
}
*/
Timer2::~Timer2()
{

}

