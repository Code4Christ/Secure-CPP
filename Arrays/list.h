// Section CSC160 - Computer Science I: C++

// File Name: list.h

// Student: Johnny Olmedo

// Homework Number: 9

// Description: this the header for the class List

// Last Changed: 4/28/2020

#include <iostream>
#include <istream>

using namespace std;

const int MAX_LIST_SIZE = 50;

class List
{
	public: 
		list(); // default contructor
	    double getSize() const; // takes the size of the array
		void addValue(int tempArg); // adds an element to an array
		bool full() const;
		double getElement(int position) const; // can get element in an array
		void deleteLast(); // deltes last elemnt in an arry
		double getLast(); // retrieves last element in an array
		friend ostream& operator << (ostream& outs, const List& theObjects); // output operator
	private:	
		double List[MAX_LIST_SIZE]; // declaration for list
		int size; // set size as an int
};
