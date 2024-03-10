// Section CSC160 - Computer Science I: C++

// File Name: ListDynamic.cpp

// Student: Johnny Olmedo

// Homework Number: 11

// Description: this program works with dynamic list manipulation

// Last Changed: 5/7/2020

#include<iostream>
#include<cstdlib>

using namespace std;

typedef double* doubleArrayPtr;


class DynamicList
{
	public:
		DynamicList();// Default constructor
		
		~DynamicList();// Destructor
		
		DynamicList(const DynamicList &copy);// copying function
		
		double getSize() const; // the size of the array that was given, make it a const
		
		double getLast(); // this fnction finds the last Element in the array
		
		double getElement(int position) const; // this function gets any Element in the array
		
		void operator =(const DynamicList &copy);// overloaded equal operator
		
		void addValue(double someDouble); // this function adds an element to the array
		
		void deleteLast(); // this function deletes the last number in the array
		
		bool full() const; // this function sees if the list is full
		
		friend ostream& operator <<(ostream& outs, const DynamicList& theObject); // overloaded output operator
		
	private:
		// delcare the ptr as a list
		doubleArrayPtr list;
		int capacity; // declare capacity as an int
		// delcare size as an int
		int size;//Number of the array spots filled
};

int main()
{	// start main
	char ans; // declare answer for while loop (if the user wants to run program)
	// explain what this program is doing to the user
	cout << "this program works with dynamic list manipulation and is an enhanced version" << endl;
	cout << "of the list project seen in homework 9" << endl;
	cout << "would you like to continue?" << endl; // ask if the user would like to continue or not
	cout << "please press Y for yes and N for no: " << endl; // direct the user how to respond
	cin >> ans; // take the user input
	while ( ans == 'y' || ans == 'Y') // while the user answered y for yes
	{
		DynamicList testList; // create an instance of the the DynamicList called testList
		double temp; // declare temp as a double
		// tell the user to enter in up to 50 numbers in a list
		cout << "please enter up to 50 numbers in a list followed by a zero when you are done entering the list: " << endl;
		cout << "enter a Value: ";
		cin >> temp; // allow user entry
		// while temp is great than zero continue to ask the user for input 
		while(temp > 0)
		{
			// call the addValue function to add each user input to the dynamic list
			testList.addValue(temp);
			cout << "enter a Value: "; // retain user input
			cin >> temp;
		}
		// display the size of the entered list
		cout << "There are " << testList.getSize() << " values on the list" << endl;
		// display the first element in the list
		cout << "The first value on the list is " << testList.getElement(0) << endl;
		// display the last element in the list
		cout << "The last value on the list is " << testList.getLast() << endl;
		// delete the last element in the array before zero
		testList.deleteLast();
		// display what this new list is after deleting the last element in the array 
		cout << "After deleting last value, there are " << testList.getSize() << " values left" << endl;
		cout << "The new list is: " << endl << testList;
		// if the list is full add 100.0 to the end of the array
		while (!testList.full())
	    {
	        testList.addValue(100.0);
		}
		// display what the number the list gets filled up at (number of elements)
	    cout << "List filled up at size equal to " << testList.getSize() << endl;
		//ask the user if they would like to run the program again
		cout << "would you like to run the program again?\n"
			 << "if yes press y \n"
			 << "if no press n" << endl;
		cin >> ans; // allow the user to answer an input 
	}
	// gracefully exit
	cout << "thank you and goodbye" << endl;
	// allow for system pause */
	system("Pause");
	return 0; // return 0
} // end main

//default
DynamicList::DynamicList() 
{	
	size = 0; // set size to 0
	capacity = 50; // set capacity to 50
	list = new double[capacity]; // new instance of the list
}

// deconstructor 
DynamicList::~DynamicList()
{
	delete [] list;
}

// copy 
DynamicList::DynamicList(const DynamicList &copy)
{
	capacity = copy.capacity; // take a copy of the capacity
	size = copy.size; // take copy of size
	// resize list
	list = new double [copy.capacity];
	// for lop to go thre every element in the array and set to the the copied verion
	for(int i = 0; i < copy.size; i++)
	{
		list[i] = copy.list[i];
	}
}

// equals operator
void DynamicList::operator =(const DynamicList &copy)
{
	capacity = copy.capacity;
	size = copy.size;
	doubleArrayPtr temp = new double[copy.capacity];
	for(int i = 0; i < size; i++)
	{
		temp[i] = copy.list[i];
	}
	delete [] list;
	list = temp;
}

// getSize function
double DynamicList::getSize() const
{
	return size;
}

// get last function
double DynamicList::getLast() 
{
	return(list[size - 1]);
}

// getElement function
double DynamicList::getElement(int position) const
{
	// if the argument passsed is greater than the list size or smaller than zero
	if((position >= size) || (position < 0))
	{
		// print out an error message
		cout << "Error: reading an empty list position. \n";
		exit(1);
	}else
	{
		return(list[position]); // return the position
	}
}

// full function determines whether the List is full or not
bool DynamicList::full() const
{
	return(size == capacity);
}

// output operator <<
ostream& operator <<(ostream& outs, const DynamicList& theObject)
{
	for(int i = 0; i < theObject.size; i++)
		outs << theObject.list[i] << endl;
	return outs;
}

// addValue function that adds elements the the array
void DynamicList::addValue(double someDouble)
{
	// check if the list is full
	if(full() )
	{
		// if its not increase the capacity for new elements
		doubleArrayPtr temp = new double [capacity + 50];
		for(int i = 0; i < size; i++)
		{
			temp[i] = list[i];
		}
		delete [] list;
		list = temp;
		capacity += 50;	
	}
	// else assign the argument to make a new list size
	list[size] = someDouble;
	size = size + 1; // increment 
}

// this function deletes the last element in the array.
void DynamicList::deleteLast()
{
	size = size - 1;
}
