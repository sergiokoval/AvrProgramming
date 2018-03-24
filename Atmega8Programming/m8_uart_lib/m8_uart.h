/*
 * m8_uart.h
 *
 * Created: 3/23/2018 7:51:29 PM
 *  Author: Serge
 */ 


#ifndef M8_UART_H_
#define M8_UART_H_

class UartSerial 
{
	public:
		void InitUart(unsigned int baudRate);
		void SendChar( unsigned char data );
		void SendString(const char * str);
};



#endif /* M8_UART_H_ */