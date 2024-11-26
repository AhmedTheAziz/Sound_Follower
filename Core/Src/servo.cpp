/*
 * servo.cpp
 *
 *  Created on: Nov 22, 2024
 *      Author: AHMED ABDELAZIZ
 */


#include"servo.h"
Servo::Servo()
{
	OIP serv(GPIOA,2,MODE::AF);

}
	void Servo::Servo_SetAngle(uint8_t angle)
	{

    // Calculate pulse width based on angle
   // uint32_t duty;
    if (angle > 180) angle = 180; // Limit to maximum angle
    float pulseWidth = (angle / 180.0f) + 1.0f; // Pulse width in ms

    // Calculate duty cycle (20 ms period)
    float dutyCycle = (pulseWidth / 20.0f) * 100.0f; // Duty cycle in %
    // Map angle to pulse width (1.5 ms for 90 degrees, 1.7 ms for 150 degrees)
  //  duty = 1 + (angle/ 180); //(angle - 90) * 1000 / 60 + 1500; // Convert angle to pulse width in microseconds
   // uint32_t timerCounts = (pulseWidth  *(72000000 / 1000000)); // Convert to timer counts
   tim2.pwmWrite3(dutyCycle);
    //TIM2->CCR3 =pulseWidth;
}
void Servo::lookout()
{
	for(auto angle=0; angle<180;angle++)
	{
		Servo_SetAngle(angle);
		delay.delay_us(10000);
	}

for(auto angle=180; angle>0;angle--)
{
	Servo_SetAngle(angle);
	delay.delay_us(10000);
}
}

void Servo::testservo()
{
	float angle=45 +0.0f;
	Servo_SetAngle(angle);

	/*
	for(auto angle=1000; angle<2000;angle++)
	{
		TIM2->CCR3=angle;
		delay.delay_ms(10);
	}

for(auto angle=2000; angle>1000;angle--)
{
	TIM2->CCR3=angle;
	delay.delay_ms(10);
}
*/
}

