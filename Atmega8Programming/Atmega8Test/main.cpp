/*
 * Atmega8Test.cpp
 *
 * Created: 3/9/2018 10:37:11 PM
 * Author : Serge
 */ 
# define F_CPU 1000000UL

#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include "LedDriver.h"
#include "Pins.h"
#include "SerialCommunication.h"

//TODO: extract button driver with lambda as action, upd no need, pass ports by address

class led
{
	public:
	// Use convenient class-specific typedefs.
	typedef uint8_t port_type;
	typedef uint8_t bval_type;
	// The led class constructor.
	led(const port_type p,
	const bval_type b) : port(p),
	bval(b)
	{
		// Set the port pin value to low.
		*reinterpret_cast<volatile bval_type*>(port) &= static_cast<bval_type>(~bval);
		// Set the port pin direction to output.
		// Note that the address of the port direction
		// register is one less than the address
		// of the port value register.
		const port_type pdir = port - 1U;
		*reinterpret_cast<volatile bval_type*>(pdir) |= bval;
	}
	void toggle() const
	{
		// Toggle the LED via direct memory access.
		*reinterpret_cast<volatile bval_type*>(port)
		^= bval;
	}
	private:
	// Private member variables of the class.
	const port_type port;
	const bval_type bval;
};
namespace {
const led led_b5
{
	PORTB,
	5
};
}


int main(void)
{
	led_b5.toggle();
	
	LedDriver ledDriver(&PORTB, &DDRB);
	SerialCommunication serialPort;

	ledDriver.SetOutputPin(Pin0);	
		
	serialPort.InitUart(9600);
	
	// extract below into button driver
	DDRB &= ~(1 << PINB1);
	PORTB |= (1<< PINB1);

	int isButtonPressed = 0;
	int buttonPressedSampling = 0;
	int buttonReleasedSampling = 0;

    while (1) 
    {
		if(bit_is_clear(PINB,PINB1))
		{
			buttonPressedSampling++;

			if(buttonPressedSampling > 1500)
			{
				if(isButtonPressed==0)
				{
					ledDriver.TogglePin(Pin0);
					isButtonPressed = 1;
					
					char buff[10];

					itoa(buttonPressedSampling,buff,10);

					serialPort.SendString("\r\n Button pressed. \r\n");
					serialPort.SendString(buff);					
				}

				buttonPressedSampling = 0;
			}	
		}
		else
		{
			buttonReleasedSampling ++;

			if (buttonReleasedSampling > 1500)
			{
				if(isButtonPressed)
				{					
					isButtonPressed = 0;
					serialPort.SendString("\r\n Button Released. \r\n");					
				}
			}
			
		}
    }
}

