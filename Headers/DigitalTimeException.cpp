// Section CSC160 - Computer Science I: C++

// File Name: DigitalTimeException.cpp

// Student: Johnny Olmedo

// Description: this is the implementation file for the DigitalTimeException.h

// Last Changed: 4/11/2020

#include <string>
#include "DigitalTimeException.h"

using namespace std;

DigitalTimeException::DigitalTimeException(int someInt, string someError) 
{
	number = someInt;
	message = someError;
}

int DigitalTimeException::errorNumber()
{
	return number;
}

string DigitalTimeException::errorMessage() 
{
	return message;
}


