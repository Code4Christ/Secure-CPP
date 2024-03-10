// Section CSC160 - Computer Science I: C++

// File Name: lesson5-697-11.cpp

// Student: Johnny Olmedo

// Homework Number: 7

// Description: this program does add, sub, mul, div math with fractions using operators and seperate compilation  

// Last Changed: 4/4/2020

#include <iostream>
#include <ostream>
#include "rational.h"

int main()
{   // start main	
	char ans; // declare answer for while loop (if the user wants to run program)
	// explain what this program is doing to the user
	cout << "this program does add,sub,mult,div with rational numbers using operators" << endl;
	cout << "would you like to continue?" << endl; // ask if the user would like to continue or not
	cout << "please press Y for yes and N for no: " << endl; // direct the user how to respond
	cin >> ans; // take the user input
	while ( ans == 'y' || ans == 'Y') // while the user answered y for yes
	{
		rational test1; // defualt contstructor
		rational test2(10); // one argument
		rational test3(1,2); // two arguments
		rational mult; // multiplied fractions
		rational div; // divided fractions
		rational add; // added fractions
		rational sub; // name for subtracted fractions
		void reduce(); // reduces fractions
		
		// ask the user to enter in two int for a fraction
		cout << "enter two non zero numbers for a rational: ";
		cin >> test1; // allow user to enter input
		// set test 2 to the numerator of test 1
		test2.setTest2(test1);
		// ask the user to enter in a rational number
		cout << "enter rational number: "; 
		cin >> test3; // allow for user input
		
		// take the time now to reduce the user inputs
		test1.reduce(); // test 1 reduced
		test2.reduce(); // test 2 reduced
		test3.reduce(); // test 3 reduced
			
		//test1.reduce();
		cout << "Test1 equals " << test1;
		cout << "Test2 equals " << test2;
		cout << "Test3 equals " << test3;
		// set mult to test1 * test2
		mult = test1 * test2;
		// display test1 * test2
		cout << "Test1 * Test2 equals " << mult;
		
		// set div to test1 / test3
		div = test1 / test3;
		// display test1 * test3
		cout << "Test1 / Test3 equals " << div;
		
		// set add equal to test2 + test3
		add = test2 + test3;
		// display test2 * test3
		cout << "Test2 + Test3 equals " << add;
		
		// set sub to test3 - test1
		sub = test3 - test1;
		// display test1 * test3
		cout << "Test3 - Test1 equals " << sub;
		//--------------------------------------------------------------------------------------------------
		// testing less than operator with test 1 and test 2
		if(test1 < test2) 
		{
			cout << "Test1 is less than Test2" << endl;
		}
		else 
		{
			cout << "Test1 is greater than Test2" << endl;
		}
		// test if the equal operator works
		if(test1 == test2)
		{
			cout << "Test1 is equal to Test2";
		}
		//---------------------------------------------------------------------------------------------
		// testing less than operator with test2 and test3
		if(test2 < test3) 
		{
			cout << "Test2 is less than Test3" << endl;
		}
		else 
		{
			cout << "Test2 is greater than Test3" << endl;
		}
		// test if the equal operator works
		if(test2 == test3)
		{
			cout << "Test2 is equal to Test3";
		}
		//-------------------------------------------------------------------------------------------
		// testing less than operator with test2 and test3
		if(test3 < test1) 
		{
			cout << "Test3 is less than Test1" << endl;
		}
		else 
		{
			cout << "Test3 is greater than Test1" << endl;
		}
		// test if the equal operator works
		if(test3 == test1)
		{
			cout << "Test3 is equal to Test1";
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
