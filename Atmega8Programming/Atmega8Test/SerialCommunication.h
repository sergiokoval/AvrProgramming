/* 
* SerialCommunication.h
*
* Created: 3/10/2018 11:22:15 PM
* Author: Serge
*/


#ifndef __SERIALCOMMUNICATION_H__
#define __SERIALCOMMUNICATION_H__


class SerialCommunication
{

//functions
public:
	void InitUart(unsigned int);
	void SendChar( unsigned char data );
	void SendString(const char * str);

}; //SerialCommunication

#endif //__SERIALCOMMUNICATION_H__
