// Section CSC160 - Computer Science I: C++

// File Name: listTest.cpp

// Student: Johnny Olmedo

// Homework Number: 9

// Description: this program deals with arrays

// Last Changed: 4/28/2020

#include <iostream>
#include <cstdlib>
#include "list.h"

using namespace std;

int main()
{ /*start main	
	char ans; // declare answer for while loop (if the user wants to run program)
	// explain what this program is doing to the user
	cout << "this program computes Standard Deviation of an array" << endl;
	cout << "would you like to continue?" << endl; // ask if the user would like to continue or not
	cout << "please press Y for yes and N for no: " << endl; // direct the user how to respond
	cin >> ans; // take the user input
	while ( ans == 'y' || ans == 'Y') // while the user answered y for yes
	{*/
	
		List testList; // initilize testList as an instanceof the class List
		int temp; // set temp as an integer
		// tell the user to enter in up to 50 numbers in a list
		cout << "please enter up to 50 numbers in a list followed by a zero when you are done entering the list: " << endl;
		// while i is < 50 have the user enter in temp  
		for (int i = 0; i < 50; i++) {
			cin >> temp;
			// if temp is less than or equal o zero then break
			if (temp <= 0) {
				break;
			}
		// add the temp entered by the user to the aray in evrey loop	
		testList.addValue(temp); 
		}
		// display the size of the entered array
		cout << "there are " << testList.getSize() << " elements in the list" << endl;
		// display the first element in the array
		cout << "the value of the first element in the list is " << testList.getElement(0) << endl;
		// disply the last element in the array
		cout << "the value of the last element in the list is " << testList.getLast() << endl; 
		// call the function that deletes the last element in the array
		testList.deleteLast();
		// display what the list will look like after the the last elemnt in the array is deleted 
		cout << "If you deleted the last element in the array the array will now look like: " << endl;
		// while int j is less that the size display the elements in the arrat 
		for (int j = 0; j < testList.getSize(); j++) {
			cout << testList.getElement(j) << " ";
		}
		// if the list is full add 100.0 to the end of the array
		while (!testList.full())
	    {
	
	        testList.addValue(100.0);
		}
	
	    /*cout << "\n\nList filled up at size equal to " << testList.getSize() << endl;
	    //ask the user if they would like to run the program again
		cout << "would you like to run the program again?\n"
			 << "if yes press y \n"
			 << "if no press n" << endl;
		//cin >> ans; // allow the user to answer an input 
	//}
	// gracefully exit
	cout << "thank you and goodbye" << endl;
	// allow for system pause */
	system("Pause");
	
	return 0;
}

