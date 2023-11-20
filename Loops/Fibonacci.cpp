// Section CSC160 - Computer Science I: C++
// File Name:  lesson2-176-6
// Student: Johnny Olmedo
// Homework Number:  Lab 2, Page 176, Question 6
// Description: program uses fibonici loop to figure out the population of crud in a pond
// Last Changed: 2/9/2020

#include <iostream>
using namespace std;
// declare crudPoundFunc as an int
int crudPoundFunc(int, int); // declare the two variables you will be passing as arguments 
// function that calculates pounds of green crud in pool
int main() // start main
{
	char ans; // declare answer for while loop (if the user wants to run program)
	// explain what this program is doing to the user
	cout << "this program tells how much green crud there is in a pond" << endl;
	cout << "would you like to continue?" << endl; // ask if the user would like to continue or not
	cout << "please press Y for yes and N for no: " << endl; // direct the user hw to respond
	cin >> ans; // take the user input
	while ( ans == 'y' || ans == 'Y') // while the user answered y for yes
	{
		int crudPop = 0; // initilize the crudPopulation very as an int and set it equal to zero
		int crudDays = 0; // declare crudDays as an integer and set it equal to zero 
		int crudPound; // declare crudPound as an integer
		// ask the user to enter the starting weight of the crud population in pounds
		cout << "please enter the initial size of the green crud population in pounds: ";
		cin >> crudPop; // allow the user to answer the question above
		// ask the user to input the number of days the green crud has to reproduce
		cout << "please enter the amount of days the crud has to reproduce: ";
		cin >> crudDays; // allow the user to input the number of days the green crud has to reproduce
		// call the function that will determine the pounds 
		crudPound = crudPoundFunc(crudPop, crudDays); // pass the crudPopulation variable and the crudDays varible
		// print out how many pounds of crud there should be after x amount of days
		cout << "after " << crudDays << " days, there should be " << crudPound << " pounds of green scum in the pond"<< endl;
		// ask the user if they would like to calculate the volume of another sphere 
		cout << "would you like to run the program again?\n"
			 << "if yes press y \n"
			 << "if no press n" << endl;
		cin >> ans; // allow the user to answer an input
	}
	cout << "thank you and goodbye " << endl; // exit gracefully 
	system("pause"); // allow for system pause
	return 0; // return
    
} // end main

// this function will except the intial amount of crud in pounds
// except the number of days given by the user
// and return the amount of crud in pounds after x amount of days
int crudPoundFunc (int pounds,int days) 
{
	int i = 0; // declare i as an integer and set it equal to zero
	int j = pounds; // declare j as an integer and set it equal to the amount of crud in pounds
	int k = pounds; // declare k as an integer and set it equal to the amount of crud in pounds
	int sum = 0; // declare sum and an integer and set it equal to zero
	int copy = 0; // declare copy as interger and set it equal to zero 
	// declare period as an integer
	int period = days / 5; // set period equal to days (divided by 5(time period of 5))
	// while i is less then or equal to the period
	while(i <= period)
    {
		copy = j; // take a copy of j
		sum=j+k; // set the sum equal to j+k
		j=k; // set j equal to k
		k=sum; // set k equal to the sum 
		i++; // add 1 to i each time
	}
	return copy; // return the final copy of j 
}
