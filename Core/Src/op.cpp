/*
 * op.cpp
 *
 *  Created on: Sep 11, 2024
 *      Author: AHMED ABDELAZIZ
 */
#include "op.h"

uint8_t OIP::CountA;
uint8_t OIP::CountB;
uint8_t OIP::CountC;
uint8_t OIP::CountAF;

const unsigned int  Pause=0;
//OutPut
OIP::OIP(GPIO_TypeDef * GPIO, uint8_t pin, MODE mode) : Port_{GPIO}, Pin_{pin}, mode_{mode} //Output
	{
			config port;

		if(GPIO == GPIOA)
		{
			if(mode == MODE::Gen)

		{
			if(CountA ==0)
			{
			port.ENPA();//enable RCC for port A
				Port_->CRL = 0x00000000;
				Port_->CRH = 0x00000000;
			}
			CountA++;
			if(Pin_<PIN_per_REG)
			{
				Port_->CRL	|=(OP_50MHZ<<(Pin_ * BIT_per_PIN));
			}
			else
			{
				Port_->CRH |=(OP_50MHZ<<((Pin_ * BIT_per_PIN)-BIT_per_REG));
			}
		}

		else if (mode == MODE::AF)
		{
			if(CountAF==0)
			{
				//config port;
				port.AFIOP();
			CountAF++;
			}
			if(CountA ==0)
			{
				port.ENPA();//enable RCC for port A
				Port_->CRL = 0x00000000;
				Port_->CRH = 0x00000000;
			}
			CountA++;
			if(Pin_<PIN_per_REG)
			{
				Port_->CRL	|=(OP_AF50MHZ<<(Pin_ * BIT_per_PIN));
			}
			else
			{
				Port_->CRH |=(OP_AF50MHZ<<((Pin_ * BIT_per_PIN)-BIT_per_REG));
			}
		}

	}
		else if(GPIO == GPIOB)
	{

		if(mode == MODE::Gen)

	{
		if(CountB ==0)
		{
			//config port;
			port.ENPB();//enable RCC for port B
			Port_->CRL = 0x00000000;
			Port_->CRH = 0x00000000;
		}
		CountB++;
		if(Pin_<PIN_per_REG)
		{
			Port_->CRL	|=(OP_50MHZ<<(Pin_ * BIT_per_PIN));
		}
		else
		{
			Port_->CRH |=(OP_50MHZ<<((Pin_ * BIT_per_PIN)-BIT_per_REG));
		}
	}

	else if (mode == MODE::AF)
	{
		if(CountAF==0)
		{
			//config port;
			port.AFIOP();
			CountAF++;
		}
		if(CountB ==0)
		{
			config port;
			port.ENPB();//enable RCC for port B
			Port_->CRL = 0x00000000;
			Port_->CRH = 0x00000000;
		}
		CountB++;
		if(Pin_<PIN_per_REG)
		{
			Port_->CRL	|=(OP_AF50MHZ<<(Pin_ * BIT_per_PIN));
		}
		else
		{
			Port_->CRH |=(OP_AF50MHZ<<((Pin_ * BIT_per_PIN)-BIT_per_REG));
		}
	}
	}
	else if(GPIO == GPIOC)
		{

			if(mode == MODE::Gen)

		{
			if(CountC ==0)
			{
				//config port;
				port.ENPC();//enable RCC for port C
				Port_->CRL = 0x00000000;
				Port_->CRH = 0x00000000;
			}
			CountC++;
			if(Pin_<PIN_per_REG)
			{
				Port_->CRL	|=(OP_50MHZ<<(Pin_ * BIT_per_PIN));
			}
			else
			{
				Port_->CRH |=(OP_50MHZ<<((Pin_ * BIT_per_PIN)-BIT_per_REG));
			}
		}

		else if (mode == MODE::AF)
		{
			if(CountAF==0)
			{
				//config port;
				port.AFIOP();
				CountAF++;
			}
			if(CountC ==0)
			{
				config port;
				port.ENPC();//enable RCC for port C
				Port_->CRL = 0x00000000;
				Port_->CRH = 0x00000000;
			}
			CountC++;
			if(Pin_<PIN_per_REG)
			{
				Port_->CRL	|=(OP_AF50MHZ<<(Pin_ * BIT_per_PIN));
			}
			else
			{
				Port_->CRH |=(OP_AF50MHZ<<((Pin_ * BIT_per_PIN)-BIT_per_REG));
			}
		}

}

			OFF();
		}
void OIP::ON()
	{
		Port_->ODR|=(1<<Pin_);
	}
void OIP::OFF()
	{
		Port_->ODR&=~(1<<Pin_);
	}
void OIP::TOGGLE()
	{
		Port_->ODR ^=(1<<Pin_);
	}
void OIP::PWMON()
{
	tim3.pwmWrite();
}
void OIP::PWMOFF()
{
	tim3.pwmWrite(Pause);
}
//INPUT
OIP::OIP(GPIO_TypeDef *GPIO, uint8_t Pin) : Port_(GPIO), Pin_(Pin) //Input
{
	config port;
	if(GPIO == GPIOA)
	{
	if(CountA ==0)
	{
	port.ENPA();//enable RCC for port A
	Port_->CRL = 0x00000000;
	Port_->CRH = 0x00000000;
	}
	CountA++;

	if(Pin_< PIN_per_REG)
	{
		Port_->CRL |=(IP_Floating<<(Pin_ * BIT_per_PIN));
	}
	else
	{
		Port_->CRH |=(IP_Floating<<((Pin_ * BIT_per_PIN)-BIT_per_REG));
	}
}
	if(GPIO == GPIOB)
	{
	if(CountB ==0)
	{
	port.ENPB();//enable RCC for port B
	Port_->CRL = 0x00000000;
	Port_->CRH = 0x00000000;
	}
	CountB++;

	if(Pin_< PIN_per_REG)
	{
		Port_->CRL |=(IP_Floating<<(Pin_ * BIT_per_PIN));
	}
	else
	{
		Port_->CRH |=(IP_Floating<<((Pin_ * BIT_per_PIN)-BIT_per_REG));
	}
}
	if(GPIO == GPIOC)
	{
	if(CountC ==0)
	{
	port.ENPC();//enable RCC for port C
	Port_->CRL = 0x00000000;
	Port_->CRH = 0x00000000;
	}
	CountC++;

	if(Pin_< PIN_per_REG)
	{
		Port_->CRL |=(IP_Floating<<(Pin_ * BIT_per_PIN));
	}
	else
	{
		Port_->CRH |=(IP_Floating<<((Pin_ * BIT_per_PIN)-BIT_per_REG));
	}
}
	}
uint32_t OIP::read()
{
	return Port_->IDR &(1<<Pin_);
}

OIP::~OIP()
	{
		OFF();
	}



