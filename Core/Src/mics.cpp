/*
 * mics.cpp
 *
 *  Created on: Nov 22, 2024
 *      Author: AHMED ABDELAZIZ
 */


#include "mics.h"


Mics::Mics(GPIO_TypeDef* port, uint16_t pins) : _port(port), _pins(pins) {}

float Mics::detectSoundSource()
{
    int firstMicIndex = -1;
    int secondMicIndex = -1;

    // Check which microphones are triggered
    for (int i = 0; i < 6; i++) {
        if (_port->IDR & (1 << (i + _pins))) { // Check if microphone i is triggered
            if (firstMicIndex == -1) {
                firstMicIndex = i; // First triggered microphone
            } else {
                secondMicIndex = i; // Second triggered microphone
                break; // We only need the first two triggered microphones
            }
        }
    }

    // Calculate the angle based on the positions of the microphones
    if (firstMicIndex == -1 || secondMicIndex == -1) {
        return -1; // No microphones triggered
    }

    // Calculate the angle based on the positions of the microphones
    float angle = 0;
    if (firstMicIndex == secondMicIndex) {
        angle = (firstMicIndex * 60); // If the same mic is triggered, return its angle
    } else {
        // Calculate the average angle between the two microphones
        angle = (firstMicIndex + secondMicIndex) * 30; // 30 degrees between each mic
        angle = angle / 2; // Average the angle
    }

    return angle; // Return the calculated angle
}

/*
    while (1) {
        int angle = mics.detectSoundSource(); // Calculate the angle based on microphone input
		turntoAngle(angle);
        if (angle != -1) {
            float targetAngle = static_cast<float>(angle); // Convert to float for precision
            turnToAngle(targetAngle); // Turn to the target angle
        }
        delay(100); // Small delay to avoid rapid triggering
    }
}
*/

void Mics::turnToAngle(float targetAngle)
{
	/*
	 float currentAngle ;//= mpu.getAngle(); // Get current angle from MPU6050

    while (fabs(currentAngle - targetAngle) > 1.0) { // Check if within 1 degree
        if (currentAngle < targetAngle) {
           // Motor_Right(); // Turn right
        } else {
           // Motor_Left(); // Turn left
        }
       // currentAngle = mpu.getAngle(); // Update current angle
    }
    // Stop motors after reaching the target angle
    // Add code to stop motors here
    */
}
