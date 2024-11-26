/*
 * ultrasound.h
 *
 *  Created on: Nov 20, 2024
 *      Author: AHMED ABDELAZIZ
 */

#ifndef INC_ULTRASOUND_H_
#define INC_ULTRASOUND_H_
#include "main.h"
#include "op.h"
#include "timer2.h"
#include"systik.h"
#define HC_SR04_ECHOCAPTURE_RESET     0U
#define HC_SR04_ECHOCAPTURE_COMPLETE  1U
#define SpeedofSound 0.0343/2
struct US_Config
{
	OIP T;
	OIP E;
};

typedef enum edges
{
	Rising, Falling ,UNKNOWN
}edges_;

class UltraSound {
public:
    UltraSound(US_Config *config);
    void Timer4_Init();
    void Trigger();
    float Read_Distance();
    ~UltraSound();
	  void TIM4_IRQHandler();

private:
    void Init();
    US_Config *Config_;
    config con;
    Timer2 tim2;
    Delay delay;
    /*
    float distance =0.0;
    float SpeedofSound=0.0343 /2;
    uint8_t ecFlag;
    edges_ edgeDir= Rising;
    uint32_t R_E_C_V=0; //Rising Edge Count Value
    uint32_t F_E_C_V=0; //Falling Edge Count Value
*/
};

// EXTI Interrupt Handler
	extern "C" void TIM4_IRQHandler();


#endif /* INC_ULTRASOUND_H_ */
