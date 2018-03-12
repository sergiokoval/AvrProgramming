/*
 * KnowledgeCheck.cpp
 *
 * Created: 3/12/2018 7:47:46 PM
 * Author : Serge
 */ 

 // Knowledge check - write timer with interrupt on Compare Match event

#define F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


int main(void)
{
	sei();

	DDRB |= (1 << PINB0);
	PORTB &= ~(1 << PINB0);

	TCCR1B |= (1 << CS11) | (1 << CS10) | (1 << WGM12); // CTC clear timer on compare
	TIMSK |= (1 << OCIE1A);
	OCR1A = 15624;
    
    while (1) 
    {
		
    }
}

ISR(TIMER1_COMPA_vect)
{
	PORTB ^= (1 << PINB0);
}

