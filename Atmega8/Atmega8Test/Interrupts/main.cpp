/*
 * Interrupts.cpp
 *
 * Created: 3/12/2018 1:38:25 PM
 * Author : Serge
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>


int main(void)
{
	sei(); // set global interrupts
	
	DDRB |= (1 << PORTB0);
	
	PORTB &= ~(1 << PINB0);
	
	// Timer/Counter Control Register B
	// set scale mode to 64
	// Clear Timer on Compare Match (CTC) mode - WGM12
	TCCR1B |= (1 << CS10) | (1 << CS11) | (1 << WGM12);
	
	// Timer Interrupt Mask Register
	//  OCIE1A: Timer/Counter1, Output Compare A Match Interrupt Enable
	TIMSK = (1 << OCIE1A );	
	
	//timer Output Compare Registers	
	OCR1A = 15624; // 1 MHz / 64(scale)
	
    /* Replace with your application code */
    while (1) 
    {
    }
}


ISR(TIMER1_COMPA_vect)
{
	PORTB ^= (1 << PINB0);
}


