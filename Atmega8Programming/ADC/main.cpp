/*
 * ADC.cpp
 *
 * Created: 3/16/2018 11:02:30 PM
 * Author : E0475141
 */ 

#include <avr/io.h>


int main(void)
{
	ADMUX |= (1<<REFS0); // external ref
	ADCSRA |= (1<<ADEN); // enable
	ADCSRA |= (1<< ADPS0) | (1<<ADPS1) // /8 prescaler
    /* Replace with your application code */
    while (1) 
    {
		// start 
		ADCSRA |= (1<< ADSC); // start conversion
		
		// loop until bit is clear
		while( !(ADCSRA && (1 << ADSC)));
		
		uint16_t val= ADC;
		
		_delay_ms(100);
    }
}

