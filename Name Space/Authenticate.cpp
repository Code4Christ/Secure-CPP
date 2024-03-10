// Section CSC160 - Computer Science I: C++

// File Name: lesson7-739-5.cpp

// Student: Johnny Olmedo

// Homework Number: 7

// Description: dealing with un-named namespaces 

// Last Changed: 4/2/2020

#include <iostream>
#include <string>
using namespace std;
// create a nameSpace "Authenticate" and declare its functions 
namespace Authenticate
{
	void inputUserName();
	void inputPassword();
	string getUserName();
	string getPassword(); 
} 

using namespace Authenticate;
int main() 
{   // start main	
	char ans; // declare answer for while loop (if the user wants to run program)
	// explain what this program is doing to the user
	cout << "this program allows the user to enter a username and password and reads it back to you" << endl;
	cout << "would you like to continue?" << endl; // ask if the user would like to continue or not
	cout << "please press Y for yes and N for no: " << endl; // direct the user how to respond
	cin >> ans; // take the user input
	while (ans == 'y' || ans == 'Y') // while the user answered y for yes
	{
		// call the function that allows the user to type a userName
		inputUserName();
		// call the function that allows the user to enter 
		inputPassword(); 
		// display the userName and Password entered by the user
		cout << "username entered: " << getUserName() << endl; 
		cout << "password entered: " << getPassword() << endl;
	
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
