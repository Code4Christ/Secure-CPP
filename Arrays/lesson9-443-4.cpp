// Section CSC160 - Computer Science I: C++

// File Name: StudentTest.cpp

// Student: Johnny Olmedo

// Homework Number: 9

// Description: this program deals with arrays

// Last Changed: 4/20/2020

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

double getAverage(double sum, int& totalUsed); 
// this function get the average or mean of all the numbers entered by the user
// Pre Condition: the function recieves the sum of the all number entered by the user
// and the total amout of numbers inputed by the user.
// Pst Condtion: the function takes the sum and dives it by the TotalUsed and returns the average.

void standardDeviation(int scores[], double average, int& totalUsed, double sum);
// this function determines the standard deviation of the array entred by the user
// PRE-CONDITION: this function recieves the average of the array, the array, the array size, and the sum of the array
// POST-CONDITION: determines the standard deviation of the array entered by the user  


int main ()
{//start main	
	char ans; // declare answer for while loop (if the user wants to run program)
	// explain what this program is doing to the user
	cout << "this program computes Standard Deviation of an array" << endl;
	cout << "would you like to continue?" << endl; // ask if the user would like to continue or not
	cout << "please press Y for yes and N for no: " << endl; // direct the user how to respond
	cin >> ans; // take the user input
	while ( ans == 'y' || ans == 'Y') // while the user answered y for yes
	{
		int size = 10; // set size = 10 to represent the max amount of array size
		int scores[10]; // initilize the array
		int totalUsed = 0;
		int next = 0;
		int i = 0;
		double sum = 0; 
		double average; // average of the array
		// ask the user to enter up to 10 values 
		cout << "please enter up to 10 values (when finished use a negative number e.g: a b c -1) " << endl;
		cin >> next; // get user input
		
		// while user input is greater than zero and less than 10
		while ((next > 0) && (i < size))
		{
			scores[i] = next; // set the array element to the uer input
			sum = sum + next;  // add user input each time to sum of the array
			i++; // increment i to keep track of number of inputs given by the user
			cin >> next; // allow the user to enter another input 
		}
		totalUsed = i; // set total used equal to i to keep track of user input
		// call the getAverage function that will obtain the average of the array
		average = getAverage(sum, totalUsed);
		// call the standard deviation function that will output 
		standardDeviation(scores, average, totalUsed, sum);
		
		//ask the user if they would like to run the program again
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
} // end main 


double getAverage(double sum, int& totalUsed) 
{	
	double tempAverage;
	tempAverage = sum /totalUsed;
	cout << "average is: " << tempAverage << endl;
	return tempAverage;
}

void standardDeviation(int scores[], double average, int& totalUsed, double sum)
{
	int i = 0;
	double deviation = 0;
	double stdDeviation;
	double avg = 0;
    
    for(int i = 0; i < totalUsed; i++)
    {
        deviation += pow(scores[i] - average, 2);
        stdDeviation = sqrt(deviation / totalUsed);
	}
	// print out the standard deviation fr the user
	cout << "the standard deviation is " << stdDeviation << endl;
}
