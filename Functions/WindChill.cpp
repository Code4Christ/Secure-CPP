// Section CSC160 - Computer Science I: C++
// File Name:  
// Student: Johnny Olmedo
// Homework Number: 2
// Description: this program takes dgrees celcius an windspeed to find out the wind chill factor
// Last Changed: 02/03/2020

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;

double windChill(double, double);
// declare the windChill function aa a double 
// this function takes degrees celcius and windspeed and returns the windChill index

void display(double x, double y);
// declare the void display function as a double
// set display as a void functon
// this function accepts the degrees Celcius and windChill Index
// and prints out the windChillIndex to the user

int main( ) //start main
{
	char ans; // declare answer for do while loop (if the user wants to run program again)
	double celcius; // declare celcius as a double
	double windSpeed; // declare windSpeed as a double
	double windChillIndex; // declare WindChillIndex as a double
	// let the user know what this program does
	cout << " this program takes dgrees celcius an windspeed to find out the wind chill factor" << endl;
	cout << "would you like to continue?: "; // ask if they would like to continue
	cin >> ans; // allow user response
	// while the user responds y for yes
	while ( ans == 'y' || ans == 'Y') {
		// ask the user for a temptaure less than or equal to 10 degrees celcius
		cout << "Enter a tempature in degrees celcius(<= 10): " << endl;
		cin >> celcius; // pass in the answer
		cout << "Enter windspeed in meters/second: " << endl;
		cin >> windSpeed; // pass in the windspeed
		// call the function that calculates the windchill Index
		windChillIndex = windChill(celcius, windSpeed); 
		// call the function that will print this new found information to the user
		display(celcius, windChillIndex); 
		// ask the user if they want to find another tempature
		cout << "would you like to run this program again?\n"
			 << "if yes press y \n"
			 << "if no press n" << endl;
		cin >> ans; // allow the user to answer an input
    }
	cout << "thank you and goodbye" << endl; // exit gracefully 
	system("Pause"); // allow system pause
    return 0; // return
} // end main

double windChill(double tempature, double speed)
{
	double windIndex; // declare windIndex as a double
	windIndex = 13.12+0.6215 * tempature - 11.37 * pow(speed, 0.16) + 0.3965 * tempature * pow(speed, 0.016); // perform calculation
	return windIndex; // return windIndex
	
}

void display(double temp, double windChill)
{
	// print out what the windchillIndex will be at the given degree celcius
	cout << "the windchill factor at " << temp << " degrees celcius is " << windChill << endl;
}
