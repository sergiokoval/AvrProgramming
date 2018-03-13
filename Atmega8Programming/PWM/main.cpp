/*
 * PWM.cpp
 *
 * Created: 3/13/2018 12:10:19 PM
 * Author : E0475141
 */ 

 #define  F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int fadingDirection = 1;

int main(void)
{
	DDRB |= (1<<PINB3);

	// set to fast pwm
	TCCR2 |= (1<<WGM21) | (1<< WGM20);  
	/*
	 Clear OC2 on Compare Match, set OC2 at BOTTOM,
	 (non-inverting mode)
	*/
	TCCR2 |= (1<<COM21);	
	
	TCCR2|= (1<<CS22) ;//64 prescale
	
	//duty cycle
	OCR2 = 50; // 156 is 100%

	// second timer setup
	sei();
	//setup another timer for interrupts on every 10ms
	TCCR1B |= (1 << CS10) | (1 << CS11) | (1 << WGM12);

	// Timer Interrupt Mask Register
	//  OCIE1A: Timer/Counter1, Output Compare A Match Interrupt Enable
	TIMSK = (1 << OCIE1A );
	
	//timer Output Compare Registers
	OCR1A = 156;// 15624; // 1 MHz / 64(scale)

	while(1)
	{
		
	}

}

ISR(TIMER1_COMPA_vect)
{	
	if(OCR2 == 155)
	{
		fadingDirection = -1;
	}
	else if (OCR2 == 0)
	{
		fadingDirection = 1;
	}

	OCR2 += fadingDirection;
}

