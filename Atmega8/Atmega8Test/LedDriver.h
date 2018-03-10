/* 
* LedDriver.h
*
* Created: 3/9/2018 11:03:09 PM
* Author: Serge
*/


#ifndef __LEDDRIVER_H__
#define __LEDDRIVER_H__

#include <avr/io.h>

class LedDriver
{
//variables
public:
protected:
private:	
	volatile uint8_t* _port;
	volatile uint8_t* _ddRegister;

//functions
public:
	void SetOutputPin(short pin);
	void TogglePin(short pin);
	LedDriver(volatile uint8_t *port, volatile uint8_t *ddRegister);
	~LedDriver();
protected:
private:
	LedDriver( const LedDriver &c );
	LedDriver& operator=( const LedDriver &c );

}; //LedDriver

#endif //__LEDDRIVER_H__
