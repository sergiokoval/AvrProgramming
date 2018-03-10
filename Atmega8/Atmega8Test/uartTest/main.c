/*
 * uartTest.c
 *
 * Created: 3/10/2018 12:16:03 PM
 * Author : Serge
 */ 
 #define F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"

int main(void)
{
	DDRB |= (1<< PINB0);
	PORTB &= ~(1<<PINB0);
	UART_init();
	UART_puts("Init complete\r\n");

	int val  = SREG;
   
    while (1) 
    {
		_delay_ms(1000);

		unsigned char bytesAvailable = UART_rbuflen() ; 
		if(bytesAvailable > 0)
		{
			UART_puts( "Got some BYTES\r\n");	
			//UART_puts(bytesAvailable);
		}

		volatile uint8_t *port = &PORTB;

		*port ^= (1<< PINB0);
		*port &= ~(1<< PINB0);


		UART_puts("Tick\r\n");	

		char buff[10];

		//sprintf(buff,"r\n PORTB %d\r\n",PORTB);
		//sprintf(buff,"r\n PORTB %c\r\n",PORTC);

		

		UART_puts(buff);
		 
		
    }
}

