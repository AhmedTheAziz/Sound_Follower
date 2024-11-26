This Code Implements the next:

1-config.h: 
	To configure and set GPIO's RCC
2- op.h:
	Set GPIOS' PINS as GEN output or AFIO.
	Set GPIOS's PINS as input to recieve a certain data
3- motor.h:
4- control.h:
5-** i2c.h:
6- FreeRTOSConfig.h:
7- FreeRTOS.h:
**8- ultrasonic.h
	Includes measuredistance, calculate distance, ISR, TIM2, to control trigger and ECHO pins
**9- servo.h:
	set servo to rotate continously from 0 to 180 back and forth, using TIM2
10- mic.h:
	Set mics[i] and fetch values of each mic[i] and its index to measure the angle of the signal
11- gyro.h:
	Set MPU6050 and read rawdata from its gyto as degree, when desired angle is achivied sind ISR.