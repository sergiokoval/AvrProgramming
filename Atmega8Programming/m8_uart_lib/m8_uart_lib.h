/*
 * m8_uart.h
 *
 * Created: 3/23/2018 7:51:29 PM
 *  Author: Serge
 */ 


#ifndef M8_UART_LIB_H_
#define M8_UART_LIB_H_

class UartSerial 
{
	char nibbleToHexCharacter(uint8_t nibble);

	public:
		void InitUart(unsigned int baudRate);
		void PrintChar( unsigned char data );
		void PrintString(const char * str);
		void PrintByte(uint8_t byte);
		void TransmitByte(uint8_t data);
		void PrintHex(uint8_t byte);

};



#endif /* M8_UART_H_ */