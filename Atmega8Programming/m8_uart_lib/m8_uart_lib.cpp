/*
 * m8_uart_lib.cpp
 *
 * Created: 3/23/2018 7:49:58 PM
 * Author : Serge
 */ 

#include <avr/io.h>
#include "m8_uart_lib.h"

void UartSerial::InitUart(unsigned int baudRate)
{
	// set for baud rate 5200
	// (F_CPU/16/5200) - 1 = 11
	unsigned int usartBaudRateRegisterValue= (1000000 / 16 / (baudRate / 2)) - 1;

	UBRRL =  (unsigned char) usartBaudRateRegisterValue;
	UBRRH = (unsigned char) (usartBaudRateRegisterValue >> 8);

	// using x2 speed, giving 0.2% error at 9600bps, yay!
	UCSRA = (1 << U2X);

	// universal control and status registers
	// REGISTeR B
	// 8 Data bits, receive and transmit enabled, receive complete interrupt enabled
	UCSRB = (( 1 << TXEN ) | (1<< RXEN) | (1 << RXCIE));

	// REGISTER C
	// Set the most used serial settings: asynchronous, no parity, 8 bit, 1 stop bit.
	// The ATmega8 uses an URSEL bit, which is not present on newer chips.
	UCSRC = (1 << URSEL) | (1 << UCSZ1) | ( 1 << UCSZ0); /* 8 data bits, 1 stop bit */
}

void UartSerial::PrintChar(unsigned char data)
{
	// If UDRE is one, the buffer is empty, and therefore ready to be written
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) )  // UDRE (USART Data Register Empty)
	;
	/* Put data into buffer, sends the data */
	UDR = data;
}

void UartSerial::PrintString(const char * str)
{
	while(*str)
	{
		PrintChar(*str);
		str++;
	}
}

void UartSerial::TransmitByte(uint8_t data) {
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) )  // UDRE (USART Data Register Empty)
	;
	UDR = data;                                            /* send data */
}

void UartSerial::PrintByte(uint8_t byte) {
	/* Converts a byte to a string of decimal text, sends it */
	TransmitByte('0' + (byte / 100));                        /* Hundreds */
	TransmitByte('0' + ((byte / 10) % 10));                      /* Tens */
	TransmitByte('0' + (byte % 10));                             /* Ones */
}

char UartSerial::nibbleToHexCharacter(uint8_t nibble) 
{
	/* Converts 4 bits into hexadecimal */
	if (nibble < 10) {
		return ('0' + nibble);
	}
	else {
		return ('A' + nibble - 10);
	}
}

void UartSerial::PrintHex(uint8_t byte) {
	/* Prints a byte as its hexadecimal equivalent */
	uint8_t nibble;
	nibble = (byte & 0b11110000) >> 4;
	TransmitByte(nibbleToHexCharacter(nibble));
	nibble = byte & 0b00001111;
	TransmitByte(nibbleToHexCharacter(nibble));
}
