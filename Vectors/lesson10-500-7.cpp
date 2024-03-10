// Section CSC160 - Computer Science I: C++
// File Name: lesson10-500-7.cpp 
// Student: Johnny Olmedo
// Homework Number: 10
// Description: this fucntion gives names in pig latin
// Last Changed: 4/30/2020

#include <iostream>
#include <string>
using namespace std;


// this function check to see if the program has properly opened the file
string pigLatin(string name, string pigName);
//PRE-CONDITION: the function excepts two string variables; name and pigName
//POST-CONDITION: the function will deterine the pigName and return the pigName


int main( )
{	// start main	
	char ans; // declare answer for while loop (if the user wants to run program)
	// explain what this program is doing to the user
	cout << "this program gives pig latin names" << endl;
	cout << "would you like to continue?" << endl; // ask if the user would like to continue or not
	cout << "please press Y for yes and N for no: " << endl; // direct the user how to respond
	cin >> ans; // take the user input
	while ( ans == 'y' || ans == 'Y') // while the user answered y for yes
	{
		
		// initilize firstName, lastName, pigName, pigLast as strings
		string firstName, lastName, pigFirst, pigLast;
		
		// ask the user to enter their first name
		cout << "please enter youre fist name: ";
		cin >> firstName; // take user input
		// run a for loop to go threw every element in the firstName string
		// and set it all to lower case
		for(int i = 0; i < firstName.length(); i++)
	    {
	        firstName[i] = tolower(firstName[i]);
	    }
		
		// ask the user to enter their last name
		cout << "please enter your last name: ";
		cin >> lastName; // take user input
		// run a for loop to go threw every element in the lastName string
		// and set it all to lower case
		for(int i = 0; i < lastName.length(); i++)
	    {
	        lastName[i] = tolower(lastName[i]);
	    }
	
		// use pigFirst to call the pig latin function and obtain
		// the pig latin version of the users first name
		pigFirst = pigLatin(firstName, pigFirst); // pass in stings firstName and pigFirst 
		// use pigFirst to call the pig latin function and obtain
		// the pig latin version of the users last name 
		pigLast = pigLatin(lastName, pigLast); // pass the strings lastName and pigLast
		
		// set the first Letter of the users first name to a capital letter
		firstName[0] = toupper(firstName[0]);
		// set the first Letter of the users last name to a capital letter
		lastName[0] = toupper(lastName[0]);
		
		// print out the users first name
		cout << "your first name is: " << firstName << endl;
		// print out the users last name
		cout << "your last name is: " << lastName << endl;
		// print out the users whole name is pig latin
		cout << "your name in pig latin is: " << pigFirst << " " << pigLast << endl;
		
		// ask the user if they would like to run the program again
		cout << "would you like to run the program again?\n"
			 << "if yes press y \n"
			 << "if no press n" << endl;
		cin >> ans; // allow the user to answer an input
	}
	// gracefully exit
	cout << "thank you and goodbye" << endl;
	system("Pause"); // allow system pause
    return 0;
}

string pigLatin(string name, string pigName)
{
	string holding; // initilize holding as a string
	// check if the first name is a vowel
	if (name.at(0) == 'a'|| name.at(0) == 'e'|| name.at(0) == 'i'|| name.at(0) == 'o'|| name.at(0) == 'u') {
		pigName = name + "way"; // if it is add "way" to the end of the name 
	}
	// else its a consonant
	else {
		holding = name.at(0); // take the first letter in name
		name.erase(0,1); // erase it from the name
		pigName = name + holding + "ay"; // add the first letter of the name plus "ay" to the end of the new name
	}
	pigName[0] = toupper(pigName[0]); // set the first letter in the name to s capital
	return pigName; // return the pigName
}
