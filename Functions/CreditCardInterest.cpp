// Section CSC160 - Computer Science I: C++

// File Name: lesson3-246-6.cpp

// Student: Johnny Olmedo

// Description: this program determines interest accumilated on a credit card

// Last Changed: 2/14/2020

 

#include <iostream>
#include <math.h>
using namespace std;

void accountInformation();
// this function accepts no arguments
// this function retrives needed information about a credit card bill

 double interestDue(double& initialBalance,double& interestRate,double& billMonths);
 // declare interestDue as a double
 // this functionshould except initial balance, interest rate, and period of bill in months
 // it should return the interest due on the credit card

double initialBalance; // declare initialBalance as a double
double interestRate; // declare interestRate as a double
double billMonths; // declare billMonths as a double

int main( ) // start of main
{	
	char ans; // declare answer for while loop (if the user wants to run program)
	// explain what this program is doing to the user
	cout << "this program tells how much interest a credit card has accumilated" << endl;
	cout << "would you like to continue?" << endl; // ask if the user would like to continue or not
	cout << "please press Y for yes and N for no: " << endl; // direct the user how to respond
	cin >> ans; // take the user input
	while ( ans == 'y' || ans == 'Y') // while the user answered y for yes
	{
		double paymentDue; // declare paymentDue as a double
		// call the function that will retrieve and store credit card account information
		accountInformation(); 
		// call the function that will calculate the interest due on the credit card
		paymentDue = interestDue(initialBalance, interestRate, billMonths);
		// print out how much interest has been accumilated on the card
		cout << "interest accumilated is: "<< paymentDue << endl;
		// ask the user if they would like to calculate the interest of anothr credit card
		cout << "would you like to calculate the interest of another credit card?\n"
			 << "if yes press y \n"
			 << "if no press n" << endl;
		cin >> ans; // allow the user to answer an input
	}
	cout << "thank you and goodbye " << endl; // exit gracefully 
	system("Pause"); // allow for pause
	// return 0		
	return 0;
} // end main

void accountInformation()
{
// ask the user for the initial credit card balance
cout << "enter the initial credit card balance: ";
cin >> initialBalance; // allow user to respond 
// ask the user for the interest rate of the credit card
cout << "enter the interest rate of the credit card: ";
cin >> interestRate; // allow the user to answer
// ask the user for the duration of the billing periods e.g 12 for 12 months
cout << "enter the duration of the billing period in months: ";
cin >> billMonths; // allow user to respond
}

double interestDue(double& initialBalance,double& interestRate,double& billMonths)
{	
	// payDue will be the final interest due on the card
	double payDue; // declare payDue as a double 
	
	// decimal rate is the interest rate divided by 100
	double decimalRate; // declare decimalRate as a double
	
	// initialBalanceCopy is the copy of the first initial balance given by the user
	double initialBalanceCopy; // declare initialBalanceCopy as a double
	
	// this multiplied the decimalRate by the billMonths
	double rOvern;  //declare r over n as a double
	
	int interval = 12; // declare interval as an integer and set it equal to 12 (12 months)
	// balance will be the final interest on the card returned in the function
	double balance; // declare balance as a double
	// set an increment counter for the do while loop.
	int i = 0; // delcare i as an int and set it equal to zero
	// decimal rate is the interest rate divided by 100
	//  this multiplied the decimalRate by the period of months for billing 
	decimalRate = interestRate / 100;
	// make the calculation on how much interest is due
	// a = p(1 + r/n)^nt 
	//a == total amount, p == initialBalance, r== decimalRate, t == billMonths 
	
	rOvern = decimalRate/interval; //  divide decimalRate by interal (12) (r/n)
	// take a copy of the initial balance entered by the user
	initialBalanceCopy = initialBalance;
	do // do at least once
	{	
		// payDue will be the final interest due
		// set payDue equal to the initialBalance(P) and multiply it by 1 * r/n set the power of interval(n) multiplied by billMonths divided by 12(12 months)
		payDue = initialBalance * pow(1 + rOvern, interval * (billMonths/interval)); // a = p(1 + r/n)^nt 		
		initialBalance = payDue; // set the new balance to the payDue
		i++; // increment i
	} while (i < billMonths); // do this while i is less than billing period entered by user
	// balance is the interest due independentaly
	balance = payDue - initialBalanceCopy; 
	// setting decimal place for output
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	// return balance
	return balance;	
}
