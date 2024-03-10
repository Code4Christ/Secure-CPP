// Section CSC160 - Computer Science I: C++

// File Name: lesson5-697-11.cpp

// Student: Johnny Olmedo

// Homework Number: 7

// Description: this program does add, sub, mul, div math with fractions using operators and seperate compilation  

// Last Changed: 4/4/2020

#include <iostream>
#include <string>
using namespace std;

// declare an un-named namespace 
namespace 
{
	string password = " ";
	
	bool isValid() 
	{
		// if the password entered is greater than or equal to 8 characters long
		if(password.length() >= 8)
		{
			int i;
			// increment i for every instance i is less than password length 
			for(i = 0; i < password.length(); i++) 
			{
				// if the password contains a digit
				if(isdigit(password.at(i)))
				{
					// return isValid() as true
					return true;
				}
			} 
		} 	return false; // return false bcause there was no digit found in the password
	}
}

// call namepace "Authenticate" to givefunction definitions 
namespace Authenticate 
{
	// function allows userinput of password
	void inputPassword()
	{
		do
		{	
			// ask the user for a password
			cout << "please enter a password (at least 8 characters and 1 non-letter): ";
			cin >> password; // allow the user to enter the password
		} while (!(isValid())); // keep asking while isValid() returns false
	}
	
	// this function returns the value of userName
	string getPassword() 
	{
		return password;
	}
}
