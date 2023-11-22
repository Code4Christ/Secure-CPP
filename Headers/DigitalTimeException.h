// Section CSC160 - Computer Science I: C++

// File Name: DigitalTimeException.h

// Student: Johnny Olmedo

// Description: this is the DigitalTimeEcxeption class

// Last Changed: 4/11/2020

#include <string>

using namespace std;

class DigitalTimeException 
{
	public:
		// digitalTimeException function accepts an int and a string as arguments 
		DigitalTimeException(int someInt, string someMessage); 
		int errorNumber(); // errorNumber function
		string errorMessage(); // errorNumber function
	private:
		int number; // error number
		string message; // error message
};

