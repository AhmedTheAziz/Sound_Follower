/*
 * servo.h
 *
 *  Created on: Nov 22, 2024
 *      Author: AHMED ABDELAZIZ
 */

#ifndef INC_SERVO_H_
#define INC_SERVO_H_
#include "main.h"
#include "timer2.h"
#include "op.h"
#include "systik.h"

class Servo
{
public:
//Servo() = default;
Servo();
void Servo_SetAngle(uint8_t angle);
void lookout();
void testservo();
private:
Timer2 tim2;
Delay delay;
};

#endif /* INC_SERVO_H_ */
