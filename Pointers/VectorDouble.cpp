// Section CSC160 - Computer Science I: C++

// File Name: VectorDouble.cpp

// Student: Johnny Olmedo

// Homework Number: 11

// Description: this program works with dynamic pointer Vector manipulation

// Last Changed: 5/7/2020

#include <iostream>
#include <cstdlib>

using namespace std;

typedef double* doublePtr;

class VectorDouble
{
	public:
		VectorDouble(); // default initilizer
		~VectorDouble(); // deconstructor 
		// overloaded Vector double function that accecpts a new capacity
		// this function changes the capacity to the new capacity in the pointer 
		VectorDouble(int newCapacity); 
		// this function overloads the VectorDouble function and accepts a copy of another vector
		VectorDouble(const VectorDouble &copy);	
		// this function gets the size of the pointer array
		int getSize();
		// this function obtains the capacity of the vector size
		int getCapacity();
		// this function can retrieve the value of any element in the array
		double valueAt(int initial); // recieves any int as an argument
		// this function can change the value of any element in the array
		void changeValueAt(int initial, double value); // recieves int then double as an argument
		// operator equal 
		void operator =(const VectorDouble &copy);
		// this function cab reset/set the array to any size
		void resize(int newSize); // takes any int as an argument
		// this function sets the capacity of elements for the vector
		void reserve(int spots); // takes int as an arguement
		// this push_back function can add new values to the size of the array 
		void push_back(int push); // takes int as an arguement
		// equal equal operator 
		bool operator==(VectorDouble &other); // can compare vectors
		
	private:
		// set the pointer to the name pointer
		doublePtr pointer;
		int capacity; // make capacity an int
		int size; // make size an int
		
};

int main()
{  //start main	
	char ans; // declare answer for while loop (if the user wants to run program)
	// explain what this program is doing to the user
	cout << "this program deals with dynamic vectors and enhanced manipulation" << endl;
	cout << "would you like to continue?" << endl; // ask if the user would like to continue or not
	cout << "please press Y for yes and N for no: " << endl; // direct the user how to respond
	cin >> ans; // take the user input
	while ( ans == 'y' || ans == 'Y') // while the user answered y for yes
	{
		// create an instance of the vector double class called v1
	    VectorDouble v1;
	    // create an instance of the vector double class called v2
	    VectorDouble v2(33); // pass 33 as a test argument
	    // create an instance of the vector double class called v3
	    VectorDouble v3(v2); // pass v2 as an argument
		// create an instance of the vector double class called v4
		VectorDouble v4(50);
		// print out the capacity for v1
	    cout << "The capacity of new_vector1 is : " << v1.getCapacity() << endl;
	    // print out the capacity for v2
	    cout << "The capacity of new_vector2 is : " << v2.getCapacity() << endl; 
	    // print out the capacity for v3
	    cout << "The capacity of new_vector3 is : " << v3.getCapacity() << endl;
	    // print out the capacity for v3
	    cout << "The capacity of new_vector4 is : " << v4.getCapacity() << endl;
		
		// set v1 = v2
	    v1 = v2;
	    // print out the new capacity for v1
		cout << "The new capacity of new_vector1 is : " << v1.getCapacity() << endl;
		// make 12 the first element in v1
	    v4.push_back(21);
	    // print out what the first element is in v1 (should be 12)
	    cout << "The first value in new_vector4 is : " << v4.valueAt(0) << endl;
	
		// if v1 is equal to v2
	    if(v4 == v3)
	    {
	        // print out that they are equal
			cout << "Vectors 4 and 3 are Equal" << endl;
	    }else // else
	    {
	        // print out that they are not equal
			cout << "Vectors 4 and 3 are not Equal" << endl;
	    }
	
		// print out the current  capacity of v2
	    cout << "again the capacity of v2 : " << v2.getCapacity() << endl;
	    // add 55 elements to the capacity
	    v2.reserve(55);
	    // print out what the new capacity for v2 is
	    cout << "After the reserve function the capacity of v2 is : " << v2.getCapacity() << endl;
	    // reset the capacity of v2 to 20 elements
		v2.resize(20);
		// now print out the new capacity of v2
	    cout << "After the resize function the new capacity of v2 is now :" << v2.getCapacity() << endl;
		
		// for loop goes threw and adds elements 1-60 into the vector 
	    for(int i = 0; i < 60; i++)
	    {
	        v1.push_back(i); // call push_back function to add a value each time 
	    }
	    // print out the new capacity of v1 
	    cout << "The total Capacity of v1 is : " << v1.getCapacity() << endl; 
	    // output the total size of v1
	    cout << "The total Size of v1 is (the amount of spots used) : " << v1.getSize() << endl;
		
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
}

// default constructor
VectorDouble::VectorDouble()
{
	size = 0;
	capacity = 50;
	pointer = new double[capacity];
}

// deconstructor
VectorDouble::~VectorDouble()
{
	delete [] pointer;
}

// overloaded function accepts 
VectorDouble::VectorDouble(int newCapacity)
{
	size = 0;
	capacity = newCapacity;
	pointer = new double[capacity];
}

// copy constructor
VectorDouble::VectorDouble(const VectorDouble &copy) 
{
	capacity = copy.capacity;
	size = copy.size;
	pointer = new double[capacity];
	for (int i = 0; i < copy.size; i++)
	{
		pointer[i] = copy.pointer[i];
	}
}

// getSize function
int VectorDouble::getSize()
{
	return size;
}

// get capacity function
int VectorDouble::getCapacity()
{
	return capacity;
}

// valueAt function
double VectorDouble::valueAt(int initial)
{
	return(pointer[initial]);
}

// changeValueAt function
void VectorDouble::changeValueAt(int initial, double value)
{
	// directly setting the vector position equal to the argument 
	pointer[initial] = value;
}

// equal operator 
void VectorDouble::operator =(const VectorDouble &copy)
{
	capacity = copy.capacity; // take copy of capacity
	size = copy.size; // set size equal to the copy of size
	// setting the vector equal to a new copy
	doublePtr temp = new double[copy.capacity];
	// go threw and set every ith element in the pointer equal to the ith element in the copied pointer
	for (int i = 0; i < copy.size; i++)
	{
		pointer[i] = copy.pointer[i];
	}
	delete [] pointer;
	pointer = temp;
}

// resize function tht can change the complete capacity of a vector
void VectorDouble::resize(int newSize)
{	
	doublePtr temp = new double[newSize];
	// if the argument is geater than the size
	if (newSize > size)
	{
		// go threw and set every temp element equal to the element of the pointer 
		for(int i = 0; i <size; i++)
		{
			temp[i] = pointer[i];
		}
		capacity = newSize; // set new capacity equal to argument
		delete[] pointer;
		pointer = temp; // at the end reset the pointer to the adjusted size
	}
	else 
	{
		// go threw and set every temp element equal to the element of the pointer 
		for(int i = 0; i <newSize; i++)
		{
			temp[i] = pointer[i];
		}
		capacity = newSize; // set new capacity equal to argument
		size = newSize; // change the old size to the argument
		delete[] pointer;
		pointer = temp;	// reset temp back to the old pointer
	}
} 

// reserve function that can change the capacity of a vector
void VectorDouble::reserve(int spots)
{	
	// if the capacity is already bigger than the argument 
	if(capacity > spots)
	{
		return; // the jus return no need to do anything
	}
	else // if the cpapcity is smaller than the argument 
	{
		// resize the argument so the vector can hold the right about of spots
		resize(capacity + spots);
	}
}

// push back function
void VectorDouble::push_back(int push)
{
	// if the size is equal to the capacity
	if(size == capacity)
	{
		// increase the temp capacity
		doublePtr temp = new double[capacity + 50];
		// load up the temp vector by making every element value
		// in the pointer vector an element value in temp
		for (int i = 0; i < size; i++)
		{
			temp[i] = pointer[i];
		}
		delete [] pointer;
		pointer = temp; // reset the pointer vector to the temp vector 
		capacity += 50; // increase the capacity
	}
	// set the pointer size equal to the argument
	pointer[size] = push;
	size = size + 1; // increment size
}

// equal equaloperator
bool VectorDouble::operator==(VectorDouble &other)
{
	if(size == other.size)
	{
		for(int i = 0; i < size; i++)
		{
			if(pointer[i] != other.pointer[i])
				return false;
		}
		return true;
	} else
	{
		return false;
	}
}
