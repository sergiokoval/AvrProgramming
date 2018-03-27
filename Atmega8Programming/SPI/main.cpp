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

#define SLAVE_SELECT PORTB &= ~(1 << PINB2)
#define SLAVE_DESELECT PORTB |= (1 << PINB2)

#define EEPROM_READ 0b00000011
#define EEPROM_WRITE 0b00000010 /* write to memory */
#define EEPROM_WRDI 0b00000100 /* write disable */
#define EEPROM_WREN 0b00000110
#define EEPROM_RDSR 0b00000101
 

 void InitSpi()
 {
	// MOSI and SCK to output
	DDRB |= (1 << PINB3)|( 1<< PINB5);

	// SS as output
	DDRB |= (1<< PINB2);

	// enable SPI, Master, set clock rate fck/128
	SPCR |= (1<<SPE)|(1<<MSTR)|(1<<SPR0) | (1<<SPR1);

	//SPCR |= (1<< CPOL);
	//SPCR |= (1<< 2);

	
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

 uint8_t SpiReadByte(uint16_t address)
 {
	SLAVE_SELECT;
	SpiSendByte(EEPROM_READ);
	SpiSend16bitAddress(address);	
	//SpiSendByte(0);	
	SpiSendByte(0);
	SLAVE_DESELECT;
	return SPDR;
 }

 void EEPROM_writeEnable(void) {
	 SLAVE_SELECT;
	 SpiSendByte(EEPROM_WREN);
	 SLAVE_DESELECT;
 }

 uint8_t EEPROM_readStatus(void) {
	 SLAVE_SELECT;
	 SpiSendByte(EEPROM_RDSR);
	 SpiSendByte(0); /* clock out eight bits */
	 SLAVE_DESELECT;
	 return (SPDR); /* return the result */
 }

 void EEPROM_writeByte(uint16_t address, uint8_t byte) {
	 EEPROM_writeEnable();
	 SLAVE_SELECT;
	 SpiSendByte(EEPROM_WRITE);
	 SpiSend16bitAddress(address);
	 SpiSendByte(byte);
	 SLAVE_DESELECT;
	 while (EEPROM_readStatus() & _BV(0)) {;
	 }
 }

int main(void)
{
	UartSerial us;

	us.InitUart(9600);
	InitSpi();

	EEPROM_writeByte(0,0xA);
	//EEPROM_writeByte(1,0x01);
	/*EEPROM_writeByte(2,0xBB);
	EEPROM_writeByte(3,0xCC);
	EEPROM_writeByte(4,0xDD);
	EEPROM_writeByte(5,0xDC);
	EEPROM_writeByte(6,0xAC);*/
	EEPROM_writeByte(7,0x45);

	int count = 0;
    /* Replace with your application code */
    while (1) 
    {
		_delay_ms(50);
		if(count >=512)
		{
			count = 0;
		    us.PrintString("\r\n----------------------------------------------------"); 
		}
		
		if((count % 12)==0)
		   us.PrintString("\r\n");
		
		us.PrintHex(SpiReadByte(count++));
		us.PrintString(" ");

    }
}

