// Section CSC160 - Computer Science I: C++
// Student: Johnny Olmedo
// Description: printing all prime numbers from 3-100
// Last Changed: 2/8/2020

#include <iostream>
#include <math.h>
using namespace std;

int main() // start main
{
	char ans; // declare answer for do while loop (if the user wants to run program again)
	cout << "this program prints out all prime numbers from 3-100" << endl;
	cout << "would you like to continue? ";
	cin >> ans;
	while (ans == 'y' || ans == 'Y')// do at least once
	{
		int outNum=0; // declare outNum as an integer and set equal to zero
		bool isPrime=true; // declare isPrime as a boolean and set it equal to true
		// for loop to loop threw every number from 3-100 
		// set outterNumber equal to 3
		// allow the computer to loop threw as long as outterNumber is less than 100
		for (outNum = 3; outNum <= 100; outNum++) // increment outNum every time the program loops threw
		{	
			int inNum; // declare innerNumber as an integer 
			isPrime=true; // set isPrime variable equal to two
			// nested for loop to compare every single number from 3-100 
			// set innerNumber equal to 3
			// run the loop if the innerNumber is less than the outterNumber 
			for (inNum = 3; inNum < outNum; inNum++)  // increment innrNumber each loop iteration
			{	// if the outNum modulo inNum leaves no remainder and gives a solid number
				if (outNum % inNum == 0)
				{
					isPrime=false;	
					break; // then leave it and break out
				}
			} //if the isPrime variable is true then this means the number is prime
			if (isPrime == true)
			{ // print out which number is prime (in this case outNum since inNum must be less that outNum)
				cout << outNum << " is a prime number" << endl;
			}
		}
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
