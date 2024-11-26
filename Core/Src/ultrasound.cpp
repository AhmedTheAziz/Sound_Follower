/*
 * ultrasound.cpp
 *
 *  Created on: Nov 26, 2024
 *      Author: AHMED ABDELAZIZ
 */
#include"ultrasound.h"

    float Distance =0.0;
    uint8_t ecFlag;
    edges_  edgeDir = Rising;
    uint32_t R_E_C_V=0; //Rising Edge Count Value
    uint32_t F_E_C_V=0; //Falling Edge Count Value


    UltraSound::UltraSound(US_Config *config)
    {
    	Init();
    	Timer4_Init();
    }
    void  UltraSound::Init()
    {
    	Config_->T.OFF();
    	con.AFIOP();

    }
 /*   void  UltraSound::EXTI_Init()
    {

    }*/
  /*  void UltraSound::EXTI_IRQHandler()
    {
    }*/
    void UltraSound::Timer4_Init()
    {
    	Clock72 clk;
        // Enable clock for TIM2
        RCC->APB1ENR |= (1 << 2); // Enable TIM5 clock
        // Set prescaler and auto-reload value for measuring time
        TIM4->CR1=0x0000;
       TIM4->PSC = 72-1; // Prescaler for 1 MHz timer (72 MHz / 72 = 1 MHz)
        TIM4->ARR = 0xFFFF; // Maximum value for auto-reload
        TIM4->CR1 |= (1 << 0); // Enable TIM4
    }

    // External interrupt handler for TIM2 input capture
    extern "C" void TIM4_IRQHandler(void)
    {
        if( (TIM4->SR & (1 << 2)))
        {
        	// Check if the capture/compare interrupt flag is set
            if (edgeDir == Rising)
            {
            	R_E_C_V = TIM4->CCR3; // Capture rising edge
                edgeDir = Falling; // Switch to falling edge
            }
            else
            {
            	F_E_C_V = TIM4->CCR3; // Capture falling edge
                edgeDir = Rising; // Switch back to rising edge
                ecFlag = HC_SR04_ECHOCAPTURE_COMPLETE; // Set flag to indicate capture is complete
            }
            TIM4->SR &= ~(1 << 2); // Clear interrupt flag
        }
    }
    void UltraSound::Trigger()
    {
    	Config_->T.ON();
    	delay.delay_us(10);
    	Config_->T.OFF();
    }

    float UltraSound::Read_Distance()
    {
        // Trigger the ultrasonic sensor
    	Trigger();

        // Wait for echo to be received
        ecFlag = HC_SR04_ECHOCAPTURE_RESET; // Reset the echo capture flag
        while (ecFlag == HC_SR04_ECHOCAPTURE_RESET)
        {
            // Wait for echo to be captured
        }

        // Calculate the distance
        if (F_E_C_V > R_E_C_V)
        {
                Distance = ((F_E_C_V - R_E_C_V) * SpeedofSound);

        } else {
            Distance = 0; // Invalid distance
        }

        // Prepare the distance string for UART transmission

           // sprintf(uartBuffer, "Distance = %.1f cm\r\n", distance);

        return Distance;
        // Transmit the distance over UART
       // UART_Transmit(uartBuffer);
    }

    UltraSound::~UltraSound()
    {

    }
