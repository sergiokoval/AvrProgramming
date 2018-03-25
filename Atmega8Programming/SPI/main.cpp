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
 

 void InitSpi()
 {
	// MOSI and SCK to output
	DDRB = (1 << PINB3)|( 1<< PINB5);

	// enable SPI, Master, set clock rate fck/16
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
 }

 void SpiSendByte(uint8_t bData)
 {
	 /* Start transmission */
	 SPDR = bData;
	 /* Wait for transmission complete */
	 while(!(SPSR & (1 << SPIF)))
	 ;
 }

 void SpiSend16bitAddress(uint16_t address)
 {
	SpiSendByte((uint8_t) (address >> 8));
	SpiSendByte((uint8_t) (address));
 }

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

