/*
 * op.h
 *
 *  Created on: Sep 11, 2024
 *      Author: AHMED ABDELAZIZ
 */

#ifndef INC_OP_H_
#define INC_OP_H_
#include "main.h"
#include "config.h"
#include "utils.h"
#include "timer3.h"
//OUTPUT
static constexpr uint32_t OP_50MHZ=3;
static constexpr uint32_t OP_AF50MHZ=0x0B;
enum class MODE :uint32_t
{
	Gen = OP_50MHZ,
	AF = OP_AF50MHZ
};
//INPUT
static constexpr uint32_t IP_Floating =4;
class OIP
{
public:
	OIP()=default;
	OIP(GPIO_TypeDef * GPIO, uint8_t pin, MODE mode);
	void ON();
	void OFF();
	void TOGGLE();
	void PWMON();
	void PWMOFF();
	//INPUT
	OIP(GPIO_TypeDef *GPIO, uint8_t Pin);
	uint32_t read();
	~OIP();
private:
	GPIO_TypeDef * Port_;
	uint8_t Pin_;
	MODE mode_ ;
	static uint8_t CountA;
	static uint8_t CountB;
	static uint8_t CountC;
	static uint8_t CountAF;
	Timer3 tim3;
};




#endif /* INC_OP_H_ */
