/*
 * mics.h
 *
 *  Created on: Nov 22, 2024
 *      Author: AHMED ABDELAZIZ
 */

#ifndef INC_MICS_H_
#define INC_MICS_H_

#include"main.h"
//#include "mpu.h

struct mic_confi
{

};
class Mics {
public:
    Mics(GPIO_TypeDef* port, uint16_t pins);
    float detectSoundSource();
    void turnToAngle(float targetAngle);
private:
    GPIO_TypeDef* _port;
    uint16_t _pins; // Mask for microphone pins
};





#endif /* INC_MICS_H_ */
