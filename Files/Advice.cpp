// File Name: lesson4-371-5.cpp

// Student: Johnny Olmedo

// Description: this program takes advice from the user and writes/appends it into a file for the next user to read

// Last Changed: 3/1/2020

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
 
int main( )
{	
	char ans; // declare answer for while loop (if the user wants to run program)
	// explain what this program is doing to the user
	cout << "this program gives advice from user to user using files" << endl;
	cout << "would you like to continue?" << endl; // ask if the user would like to continue or not
	cout << "please press Y for yes and N for no: " << endl; // direct the user how to respond
	cin >> ans; // take the user input
	while ( ans == 'y' || ans == 'Y') // while the user answered y for yes 
	{
		ifstream in1; // declare in1 as your ifstream for reading the file
		ofstream out1; // declare out1 as your ofstream for reading the file
		char currentEntry; // declare currententry as a char as it will take the current user input
		char lastEntry; // declare lastEntry as a char as this is the last user input
		char advice; // declare advice as a car s it will hold a block of text as a char
		// open the file
		in1.open("hw4pr2input.txt");
		// if the file cannot be opened 
		if (in1.fail()){
			// let the user know it failed
			cout << "could not open file";
			exit(1);
		}
		// display the previous user advice
		cout << "previous user advice: " << endl;
		// while its not the end of file
		while (!in1.eof()) { 
			// go threw the space by space 
			in1.get(advice); 
			// and print out the last user advice/ whatever text was in the file
			cout << advice;
		}
		// close the file
		in1.close(); 
		// open the of stream file
		// the commented "ios::app" allows for appending of the user advice instread of overwritting.
		// I am leaving this for Dianne to play with!
		out1.open("hw4pr2input.txt"/*,ios::app*/); 
		// tell the user to enter in new advice of their own
		cout << "enter new advice :" << endl;
		// pass in the user entry to the file as the user types their advice
		cin.get(currentEntry);
		// while its not the end of file as the user hasn't hit enter twice 
		while (!out1.eof() && !(currentEntry == '\n' && lastEntry == '\n')){
			// pass the currentEntry into the file for reading
			out1 << currentEntry;
			// make the last entry the current entry to keep track of enters
			lastEntry = currentEntry;
			// go threw the file space by space 
			cin.get(currentEntry);
		}
		// close writing file
		out1.close(); 
		// ask the user if they would like to run the program again
		cout << "would you like to run the program again?\n"
			 << "if yes press y \n"
			 << "if no press n" << endl;
		cin >> ans; // allow the user to answer an input
	}
	cout << "thank you and goodbye " << endl; // exit gracefully 
	system("Pause"); // allow for system pause

    return 0;
} // end main
