// Section CSC160 - Computer Science I: C++

// File Name: StudentTest.cpp

// Student: Johnny Olmedo

// Homework Number: 8

// Description: this program deals with exception handling

// Last Changed: 4/11/2020

#include <string>
#include <iostream>
#include "Student.h"
#include "StudentException.h"

using namespace std;

int main() // this is the main
{   // start main	
	char ans; // declare answer for while loop (if the user wants to run program)
	// explain what this program is doing to the user
	cout << "this program enrolls students into classes using exception handling" << endl;
	cout << "would you like to continue?" << endl; // ask if the user would like to continue or not
	cout << "please press Y for yes and N for no: " << endl; // direct the user how to respond
	cin >> ans; // take the user input
	while ( ans == 'y' || ans == 'Y') // while the user answered y for yes
	{
		try
		{
			cout << "Testing the Handling of Student Exception" << endl;
			// try enrolling student 1 into the class CSC-160-500
			try {
				Student testStudent1("S00000001"); 
				testStudent1.enroll("CSC-160-500");
			}
			catch(StudentException a) {
				cout << a.errorMessage() << endl;
			}
		
			try {
				Student testStudent2("S00000002"); 
				testStudent2.enroll("CSC-161-400");
			}
			catch(StudentException b) {
				cout << b.errorMessage() << endl;
			}
		
			try {
				Student testStudent3("S00000003"); 
				testStudent3.enroll("PHI-112-500");
			}
			catch(StudentException c) {
				cout << c.errorMessage() << endl;
			}
		}
		catch(...) {
			cout << "I'm not sure what went wrong" << endl;
		}
		// ask the user if they would like to run the program again
		cout << "would you like to run the program again?\n"
			 << "if yes press y \n"
			 << "if no press n" << endl;
		cin >> ans; // allow the user to answer an input
	}
	// gracefully exit
	cout << "thank you and goodbye" << endl;
	// allow for system paue
	system("Pause");
	
	return 0;
}
