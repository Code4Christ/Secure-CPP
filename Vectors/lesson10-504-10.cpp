// Section CSC160 - Computer Science I: C++
// File Name:  lesson10-504-10.cpp
// Student: Johnny Olmedo
// Homework Number: 10
// Description: This program deals with files and vector manipulation 
// Last Changed: 4/30/2020

#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
using namespace std;

// this function check to see if the program has properly opened the file
void openFile(ifstream &iPut);
//PRE-CONDITION: the function recieves an ifstream with a call by reference to iPut
//POST-CONDITION: the function will either open the file or it will give an error

// this function gets data from a file and initilizes it into a vector
void initilizeVector(ifstream &iPut,vector<int>&test); 
//PRE-CONDITION: the function should recieve two aguments; ifstream with a call by reference to iPut
// and it should recieve a recieve a call by reference to the vector test
//POST-CONDITION: the function will initilize the vector 

// this funtion sorts data using the selection sort algorithm
void sort_Array(vector<int> &test);
//PRE-CONDITION: the function recieves a vector with a call by reference
//POST-CONDITION: the function will sort the array from greatest to least 

// this function determines which numbers are in the vector and the number of times that number appears 
void repeatNumbers(vector<int> &test); 
//PRE-CONDITION: the function should recieve a call by reference to the vector 
//POST-CONDITION: the function should print out the numbers found in the vector and the number of times it appears.

int main( )
{	
	// start main	
	char ans; // declare answer for while loop (if the user wants to run program)
	// explain what this program is doing to the user
	cout << "This program deals with files and vector manipulation" << endl;
	cout << "would you like to continue?" << endl; // ask if the user would like to continue or not
	cout << "please press Y for yes and N for no: " << endl; // direct the user how to respond
	cin >> ans; // take the user input
	while ( ans == 'y' || ans == 'Y') // while the user answered y for yes
	{
		ifstream iPut; // intilizing iPut as an ifstream
		vector<int>test; // initilize test and an in vector
		cout << "opening file" << endl;
		iPut.open("hw10input.txt"); // open the file
		// check if the files opens
		openFile(iPut);
		cout << "file succesfully opened" << endl; 
		// call the initilize vector function 
		initilizeVector(iPut, test); // pass iPut and test
		// call the sort_Array function
		sort_Array(test); // pass test
		// call the repeatNumbers function 
		repeatNumbers(test); // pass test
		iPut.close(); // close the file
	
		// ask the user if they would like to run the program again
		cout << "would you like to run the program again?\n"
			 << "if yes press y \n"
			 << "if no press n" << endl;
		cin >> ans; // allow the user to answer an input
	}
	// gracefully exit
	cout << "thank you and goodbye" << endl;	
    system("Pause");
    return 0;
}

void openFile (ifstream &iPut)
{	
   // if the file is not opened
	   if (iPut.fail())
		{
			cout << "input file opening failed"; // tell the user it failed
			exit(1); // exit
		}
}

void initilizeVector(ifstream &iPut, vector<int> &test)
{
	int temp; // initilize temp as an int
	for (int i = 0; i < 29; i++) {
		iPut >> temp;
		test.push_back(temp); // add an element to the vector 
	}
}

void sort_Array(vector<int> &test)
{
	int i, j, temp;
	int first;
	for (i = 28; i > 0; i--) {
		first = 0;
		for (j = 1; j<=i; j++) {
			if (test[j] < test[first]){
				first = j;
			}
		}
	 temp = test[first];	
	 test[first] = test[i];
	 test[i] = temp;
	}
	
}

void repeatNumbers(vector<int> &test)
{
	for (int i = 0; i < 29; i++) {
		int count = 0;
		int flag = 1;
		
		for (int j = 0; j < i; j++) {
			if (test[i] == test[j])
				flag += 1;	
		}
		
		if (flag == 1) {
			for (int k = 0; k < 29; k++) {
				if (test[i] == test[k])
					count += 1;
			}
			// tell the user which number was found and how many times it was found
			cout << "number found:" << test[i] << endl << test[i] << " is found " << count  << " times in this file"<< endl;	
		}
	}

} 
