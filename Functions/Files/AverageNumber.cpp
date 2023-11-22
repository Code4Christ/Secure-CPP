// File Name: AverageNumbers.cpp

// Student: Johnny Olmedo

// Description: this program determines the average numbers in a file

// Last Changed: 3/1/2020

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main( )
{ 	
	char ans; // declare answer for while loop (if the user wants to run program)
	// explain what this program is doing to the user
	cout << "this program determines the average numbers in a file" << endl;
	cout << "would you like to continue?" << endl; // ask if the user would like to continue or not
	cout << "please press Y for yes and N for no: " << endl; // direct the user how to respond
	cin >> ans; // take the user input
	while ( ans == 'y' || ans == 'Y') // while the user answered y for yes
	{
		ifstream inStream; // declare inStream as an ifstream
		double sum = 0; // declare sum as a double and set sum equal to zero
		double average = 0; // declare average as a double and set it equal to zero
		double next; // declare next as a double
		int count = 0; // delcare count as an integr and set it = 0
		char fileName[16]; // declare fileName as a char
		double sumValue;
	    // ask the user to enter the name of a file 
		cout << "please enter the name of a file: ";
	    cin >> fileName; // allow user to respond
		// open the numbers file
	    inStream.open(fileName);
	   // if the file is not opened
	   if (inStream.fail())
		{
			cout << "input file opening failed"; // tell the user it failed
			exit(1); // exit
		}
		cout << "file was opened" << endl; // if the file opens
		// run line by line and add the value of each line to the value of the sum
		while (inStream >> next) { 
			sum = sum + next;
			count++; // increment count each time to keep track of how many numbers are in the file
		}
		// close the file
		inStream.close();
		// the average is equal to the sum of all the numbers in the file divided by the numbers in the file
		average = sum / count;
		// tell the user how many numbers were found and the average
		cout <<"there were " << count << " numbers found in the file.The average of " << count << " numbers is " << average << endl;
		// ask the user if they would like to run the program again
		cout << "would you like to run the program again?\n"
			 << "if yes press y \n"
			 << "if no press n" << endl;
		cin >> ans; // allow the user to answer an input
	}
    cout << "thank you and goodbye" << endl;
	system("Pause");
 
    return 0;

} // end main

