// Section CSC160 - Computer Science I: C++

// File Name: CDAccount.cpp

// Student: Johnny Olmedo

// Description: this program gives account information for a CD Account

// Last Changed: 3/8/2020

#include <iostream>
using namespace std; 
// declare class CDAccount
class CDAccount 
{
	private: 
  		double balance; // initialize balance
    	double interestRate; // interest rate in percentage
    	int term;//months until maturity
    public: 
    	// default constructor
		CDAccount(){
    		balance = 100;
    		interestRate = 10;
    		term = 6;
		}
    	// initializer list
		CDAccount(double balance, double interestRate, int term): balance(balance), interestRate(interestRate), term(term) {
		}
		// setInitialBalance should set the old balance the user enterest into to this newBalance 
		void setInitialBalance(double balance);
		// this function should allow the user to input the balance, interest rate, and term
		void setAllParams(istream &input);
		// this function prints out the results of all the CD information
		void getAllParams(ostream &output);
    	// this function returns the balance of the CD
		double getInitialBalance();
    	// this function calculates what the balance maturity will be at the end of the term 
		double getBalanceMaturity();
    	// this function returns the interest rate
		double getInterestRate();
    	// this function returns the term
		int getTerm();
    	
};

int main() 
{// start main	
	char ans; // declare answer for while loop (if the user wants to run program)
	// explain what this program is doing to the user
	cout << "this program gives account information for a CD Account" << endl;
	cout << "would you like to continue?" << endl; // ask if the user would like to continue or not
	cout << "please press Y for yes and N for no: " << endl; // direct the user how to respond
	cin >> ans; // take the user input
	while ( ans == 'y' || ans == 'Y') // while the user answered y for yes
	{
		// set default accountOne and pass in default arguments
		CDAccount accountOne(1000.0,4.0,8);
		// account two will allow test cases for the user entry 
		CDAccount accountTwo;
		// print out account 2 to show that the CD runs with default arguments
		cout << "account Two default:" << endl;
		accountTwo.getAllParams(cout); 
		// promt the user on what kind of responses you would like
		cout << "enter in the initial balance, interest rate, and term: " << endl;
		// call this function allow the user to set the balance, interest rate, and term for accountTwo
		accountTwo.setAllParams(cin); 
		// this should print out all default params from account one 
		cout << "account One hard code arguments:" << endl;
		accountOne.getAllParams(cout);
		cout << "account Two user input arguments:" << endl;
		accountTwo.getAllParams(cout);
		// ask the user if they would like to run the program again
		cout << "would you like to run the program again?\n"
			 << "if yes press y \n"
			 << "if no press n" << endl;
		cin >> ans; // allow the user to answer an input
	}
	cout << "thank you and goodbye" << endl;
	system("Pause");
	
	return 0;	
} // end main

// Member function definitions

// Setter function to set initial balance
void CDAccount::setInitialBalance(double balance) {
    this->balance = balance;
}

// Function to set all CD account parameters based on user input
void CDAccount::setAllParams(istream &input) {
    input >> balance >> interestRate >> term;
}

// Function to display all CD account information
void CDAccount::getAllParams(ostream &output) {
    output << "CD Account initial balance: " << balance << endl;
    output << "CD Account interest rate: " << interestRate << endl;
    output << "CD Account term: " << term << " months" << endl;
    output << "CD Account balance at maturity: " << getBalanceMaturity() << endl;
}

// Getter function to retrieve initial balance
double CDAccount::getInitialBalance() {
    return balance;
}

// Function to retrieve interest rate
double CDAccount::getInterestRate() {
    return interestRate;
}

// Function to retrieve term
int CDAccount::getTerm() {
    return term;
}


double CDAccount::getBalanceMaturity()
{
	double rateFraction, interest, newBalance;
	// Calculate interest based on rate and term
    // set up a rate fraction to hold the percentage is decimal form
	rateFraction = interestRate/100.0;
    // interest rate = balance*rateFraction*(term/12Months)
	interest = balance*rateFraction*(term/12.0);
    // new balance is the interest plus the old balance
	newBalance = balance + interest;
	// reurn the newBalance
    return newBalance; 
}


