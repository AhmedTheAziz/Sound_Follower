/*
 * timer2.h
 *
 *  Created on: Nov 21, 2024
 *      Author: AHMED ABDELAZIZ
 */

#ifndef INC_TIMER2_H_
#define INC_TIMER2_H_

#include "main.h"
#include "clock72.h"

class Timer2
{
public:
	/// <Constructor>
	Timer2()=default;
Timer2(unsigned int  PERIOD);
	// Initiate Timer 3 CH 1&3 , Activate PWM.
void Tim2_Init(unsigned int  PERIOD);
void pwmWrite();
void pwmWrite(unsigned int duty);
void pwmWrite4(unsigned int duty);
void pwmWrite3(unsigned int duty);
void pwmWrite3(float duty);

//void enable_interrupt(IRQn_Type IRQn);
//void disable_interrupt(IRQn_Type IRQn);
	///<Destructor>
~Timer2();

private:
static unsigned int PERIOD/*=550*/;
unsigned int Duty/*=50*/;
static uint8_t Counttim;


};





#endif /* INC_TIMER2_H_ */
