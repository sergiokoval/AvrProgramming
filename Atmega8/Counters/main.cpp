/*
 * Counters.cpp
 *
 * Created: 3/12/2018 12:35:40 PM
 * Author : E0475141
 */ 

#include <avr/io.h>


int main(void)
{
	DDRB = 0b01111111;	
	PORTB = 0;
	
	int ledPosition = 1;
	
	// scaling set to 64
	TCCR1B |= (1 <<CS11) | (1 << CS10);	
	
	
    while (1) 
    {
		if(TCNT1 > 2232)
		{
			TCNT1 = 0;
			PORTB = (1 << ledPosition);
			
			if(ledPosition > 6)
			{
				ledPosition = 0;
			}
		}
    }
}

