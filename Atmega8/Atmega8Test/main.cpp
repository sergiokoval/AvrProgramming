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


int main(void)
{
	LedDriver ledDriver(&PORTB, &DDRB);
	SerialCommunication serialPort;

	ledDriver.SetOutputPin(Pin0);	
	
	// set for baud rate 5200
	// (1000000/16/5200) - 1 = 11
	serialPort.InitUart(11);


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

