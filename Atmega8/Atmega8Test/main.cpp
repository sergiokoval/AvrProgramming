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

// todo: extract button driver with lambda as action, upd no need, pass ports by address


int main(void)
{
	LedDriver driver(&PORTB, &DDRB);
	driver.SetOutputPin(Pin0);

	SerialCommunication sc;
	sc.InitUart(25);

	DDRB &= ~(1 << PINB1);
	PORTB |= (1<< PINB1);

	int isButtonPressed = 0;
	int buttonPressedSampling = 0;
	int buttonReleasedSampling = 0;

    /* Replace with your application code */
    while (1) 
    {
		if(bit_is_clear(PINB,PINB1))
		{
			buttonPressedSampling++;

			if(buttonPressedSampling > 1500)
			{
				if(isButtonPressed==0)
				{
					driver.TogglePin(Pin0);
					isButtonPressed = 1;
					
					char buff[10];

					itoa(buttonPressedSampling,buff,10);

					sc.SendString("\r\n Button pressed. \r\n");
					sc.SendString(buff);
					
				}
				buttonPressedSampling = 0;
			}	
		}
		else
		{
			//buttonReleasedSampling ++
			if(isButtonPressed)
			{
			//driver.TogglePin(Pin0);
				isButtonPressed = 0;
				//_delay_ms(200);
			}
		}
    }
}

