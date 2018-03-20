/*
 * 16BitTimer_PWM.cpp
 *
 * Created: 3/14/2018 12:09:05 AM
 * Author : Serge
 */ 

 #define  F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    /* Replace with your application code */
	DDRB |= (1<<PINB1);
	DDRB &= ~(1<<PINB2);

	PORTB |= (1<< PINB2);

	TCCR1A |= (1<<WGM11);
	TCCR1B |= (1<<WGM12) | (1<<WGM13);

	TCCR1A |= (1<<COM1A1) | (1<<COM1A0);

	TCCR1B |= (1<< CS10);

	ICR1 = 5000;
	OCR1A = 0;

    while (1) 
    {
		
		ICR1 = 500;
		_delay_ms(100);
		ICR1 = 1000;
		_delay_ms(100);
		ICR1 = 1500;
		_delay_ms(100);
		ICR1 = 300;
		_delay_ms(100);

		//if()
		//OCR1A = ICR1 - 700;
		//_delay_ms(1500);
		//OCR1A = ICR1 - 2200;
		//_delay_ms(1500);
    }
}

