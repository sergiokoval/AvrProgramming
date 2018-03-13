/*
 * PWM.cpp
 *
 * Created: 3/13/2018 12:10:19 PM
 * Author : E0475141
 */ 

#include <avr/io.h>


int main(void)
{
	DDRB = 0xFF;
	
	TCCR1A |= (1<<WGM11) | (1<<COM1A1) |(1<<COM1A0);
	TCCR1B |= ( 1<<WGM13 ) | ( 1<<WGM12 ) | (1<<CS10);
	
	ICR1 = 19999;
	OCR1A = ICR1 - 2000;
	
    /* Replace with your application code */
    while (1) 
    {
    }
}

