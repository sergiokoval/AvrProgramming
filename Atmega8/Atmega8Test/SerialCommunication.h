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
//variables
public:
protected:
private:

//functions
public:
	void InitUart(unsigned int);
	void SendChar( unsigned char data );
	void SendString(const char * str);
	SerialCommunication();
	~SerialCommunication();
protected:
private:
	SerialCommunication( const SerialCommunication &c );
	SerialCommunication& operator=( const SerialCommunication &c );

}; //SerialCommunication

#endif //__SERIALCOMMUNICATION_H__
