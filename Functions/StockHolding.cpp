// Section CSC160 - Computer Science I: C++

// File Name: StockHolding.cpp

// Student: Johnny Olmedo

// Description: this program calculates the value of a stock holding in dollars and cents

// Last Changed: 2/16/2020

 

#include <iostream>

using namespace std;

void stockInformation();
// this function accepts no arguments
// this function retrives needed stock information

double stockPrice(double& dollarPrice, double& numerator, double& denominator);
// declare interestDue as a double
// this functionshould except initial balance, interest rate, and period of bill in months
// it should return the interest due on the credit card

double shareValFunc(double shares, double singleStock);
// this function excepts singleStock as an argument
// the function asks the user for the number of shares they hold
// it then multiplies the singleStock by the number of shares
// the function returns the share value

void display(int shares, double& dollarPrice, double& numerator, double& denominator, double& shareValue);
// this function displays the stock information to the user

double dollarPrice; // declare dollarPrice as a double
double numerator; // declare numerator as a double
double denominator; // declare denominator as a double

int main( )
{	
	char ans; // declare answer for while loop (if the user wants to run program)
	// explain what this program is doing to the user
	cout << "this program calculates the value of a stock holding in dollars and cents" << endl;
	cout << "would you like to continue?" << endl; // ask if the user would like to continue or not
	cout << "please press Y for yes and N for no: " << endl; // direct the user how to respond
	cin >> ans; // take the user input
	while ( ans == 'y' || ans == 'Y') // while the user answered y for yes
	{
		double singleStock; // declare singleStock as a double
		double shareValue ; // declare a shareValueFunction as a double
		double shares;
		// call the function that will retrieve all the user input and stock information
		stockInformation();
		
		// call the function that will calculate the interest due on the credit card
		singleStock = stockPrice(dollarPrice, numerator, denominator);
	
		// ask the user how many shares they own
		cout << "please enter in the number of shares held: ";
		cin >> shares; // pass in user input
		
		// call the function that will ask the user for the number of shares they hold
		// the function takes the number of shares and multiplies it by the singleStock value
		shareValue = shareValFunc(shares, singleStock);
		
		// call the function that will display the stock information
		display(shares, dollarPrice, numerator, denominator, shareValue);

		// ask the user if they would like to calculate the interest of anothr credit card
		cout << "would you like to calculate another stock value?\n"
			 << "if yes press y \n"
			 << "if no press n" << endl;
		cin >> ans; // allow the user to answer an input
	}
	cout << "thank you and goodbye " << endl; // exit gracefully 
	system("Pause");
	return 0;
}

void stockInformation()
{
// ask the user for the whole dollar value of the stock
cout << "enter the whole dollar value of the stock: ";
cin >> dollarPrice; // user answers the question
// ask the user to enter the numerator of the fractional share 
cout << "enter the numerator of fractional share: ";
cin >> numerator; // user responds
// ask the user for the denominator
cout << "enter the denominator of the fractional share: ";
cin >> denominator; // allow user to answer
}

double stockPrice(double& dollarPrice, double& numerator, double& denominator)
{	
	double singleShare; // declare singleShare as a double
	double fraction; // declare fraction as a double
	// do the fraction calculation which divides the numerator by the denominator
	fraction = numerator / denominator ;
	// a single share equals the dollar price plus the fraction
	singleShare = dollarPrice + fraction; 
	// return the single share Value
	return singleShare;	
}

double shareValFunc(double shares, double singleStock)
{
	// multiply the shares the user has by the single stock value
	return shares * singleStock;
}

void display(int shares, double& dollarPrice, double& numerator, double& denominator, double& shareValue)
{
	// print out how much the shares are worth
	cout << shares << " shares of stock with a dollar value of $" << dollarPrice 
		<< " with a fractional share value of " << numerator<< "/" << denominator
		<< " has a value of $" << shareValue << endl;
}

