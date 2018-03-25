/*
 * SPI.cpp
 *
 * Created: 3/20/2018 7:57:41 PM
 * Author : Serge
 */ 

 #define  F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>
#include "..\m8_uart_lib\m8_uart_lib.h"
 

int main(void)
{
	UartSerial us;

	us.InitUart(9600);

    /* Replace with your application code */
    while (1) 
    {
		_delay_ms(1000);
		us.SendString("Tick\r\n");
    }
}

