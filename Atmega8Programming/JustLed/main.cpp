/*
 * JustLed.cpp
 *
 * Created: 5/18/2019 8:40:36 PM
 * Author : serge
 */ 
#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB |= (1 << DDRB1);
	PORTB |= (1 << PORTB1);	 
		
    while (1) 
    {
		_delay_ms(500);
		PORTB ^= (1 << PORTB1);
    }
}

