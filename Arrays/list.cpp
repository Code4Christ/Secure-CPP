// Section CSC160 - Computer Science I: C++

// File Name: list.cpp

// Student: Johnny Olmedo

// Homework Number: 9

// Description: this implementation file for the class List

// Last Changed: 4/28/2020

#include <iostream>
#include <cstdlib>
#include "list.h"

using namespace std;

// default constructor sets array to 0
int List::list()
{
	size = 0;
}

// this function returns the size and subtracts 1 since the last 
// element in an entered array would pressumably be number 0 
double List::getSize() const 
{
	return (size - 1);
}

// this function adds elements to the array
void List::addValue(int tempArg) 
{
	// if the array is not full
	if (!(full())) {
		// set the temp argument equal to list size
		List[size-1] = tempArg;
		size = size + 1;
	}
	// else its full
	else {
		full();
	}
}

// this function deletes the last elements in the array
void List::deleteLast()
{
	size = size - 1;
}

// this function obtains the last element in the array
double List::getLast()
{
	return (List[size - 2]); // subtract 2 since 0 is the last element 
}

// this function determines if the function is full or not 
bool List::full() const
{
	return (size == MAX_LIST_SIZE);	
}

// this function obtains any element in the array
double List::getElement(int position) const
{
	// if the position being asked for is greater than or less than range of the array
	if( (position >= size) || (position < 0) ) {
		// print out an error message
		cout << "error";
		exit(1);
	}
	else { // else returnthe position
		return (List[position]);
	}
}

// output operator 
ostream &operator << (ostream &outs, const List& theObjects) 
{
	for (int i = 0; i < theObjects.size; i++) {
		outs << theObjects.List[i];
		return outs;
	}		
		
}
