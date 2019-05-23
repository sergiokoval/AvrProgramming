/* 
* LedDriver.cpp
*
* Created: 3/9/2018 11:03:09 PM
* Author: Serge
*/


#include "LedDriver.h"
#include <avr/io.h>

void LedDriver::SetOutputPin(short pin)
{	
	(*_ddRegister) |= (1 << pin);
	(*_port) &= ~(1 << pin);
}

void LedDriver::TogglePin(short pin)
{
	*_port ^= (1 << pin);
}

// default constructor
LedDriver::LedDriver(volatile uint8_t *port, volatile uint8_t * ddRegister)
{
	this->_port = port;
	this->_ddRegister = ddRegister;
}

// default destructor
LedDriver::~LedDriver()
{
} //~LedDriver
