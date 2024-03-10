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
	string username = " ";
	
	bool isValid() 
	{
		// if the userName entered is exactly 8 characters long
		if(username.length() == 8)
		{
			// return isValid() as true
			return true;
		} 
		// else the userName is more or less than 8 characters long
		else
		{
			// return isValid() as false 
			return false;
		}
	}
}

// call the namespace "Authenticate" to give the the function definitions 
namespace Authenticate 
{
	// function allows userinput of userName
	void inputUserName()
	{
		do
		{	
			// ask the user for a username
			cout << "please enter a username: ";
			cin >> username; // allow the user to enter the userName
		} while (!(isValid())); // keep asking while isValid() returns false
	}
	
	// this function returns the value of userName
	string getUserName() 
	{
		return username;
	}
}
