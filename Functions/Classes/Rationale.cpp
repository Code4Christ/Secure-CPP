// Section CSC160 - Computer Science I: C++

// File Name: Rationale.cpp

// Student: Johnny Olmedo

// Description: this program does add, sub, mul, div math with fractions

// Last Changed: 3/8/2020

#include <iostream>
#include <ostream>
using namespace std;

class Rational {

	public:
		Rational(); // default
		// this function accepts two integers as an argument
		Rational(int newNum, int newDom);
		// this function accepts a single int as an argument
		Rational(int newNum); 
		// this function adds fractions
		void add(Rational u);
		// this function subtracts fractions
		void sub(Rational u);
		// this function mulitplies fractions	
		void mul(Rational u);
		// this function divides fractions	
		void div(Rational u);
		// this function tells
		void less(Rational u);
		// this function tells whether the fractions are even or not
		void eq(Rational u);
		// this function turns fractions into their negative version
		void neg(Rational u);
		// this function is used for user input
		void input (istream& infile);
		// this functon is used for screen output
		void output(ostream &outfile);
		// this function sets the 3rd Rational number to the numerator of the 1st Rational number
		void setTest3(Rational test1);
		// this reduces any fraction if possible
		void reduce();
	private:
		int num;
		int dom;
};

int main()
{  // start main	
	char ans; // declare answer for while loop (if the user wants to run program)
	// explain what this program is doing to the user
	cout << "this program does add,sub,mult,div with Rational numbers using classes" << endl;
	cout << "would you like to continue?" << endl; // ask if the user would like to continue or not
	cout << "please press Y for yes and N for no: " << endl; // direct the user how to respond
	cin >> ans; // take the user input
	while ( ans == 'y' || ans == 'Y') // while the user answered y for yes
	{
		
		Rational test1;
		Rational test2;
		Rational test3;
		// ask the user to enter in two int for a fraction
		cout << "enter two non zero numbers for a Rational: ";
		test1.input(cin); // allow user to enter input
		// take the time now to set Rational number 3 to the numerator of Rational number 1
		test3.setTest3(test1);
		// ask the user to enter a "x/y? fraction including the slash
		cout << "enter a Rational number (eg. 'x/y'): ";
		test2.input(cin);
		
		// Rational number 1 is:
		cout << "Rational number 1 is: " << endl;
		test1.output(cout);
		
		// Rational number 2 is :
		cout << "Rational number 2 is: " << endl;
		test2.output(cout);
		
		// Rational number 3 is:
		cout << "Rational number 3 is: " << endl;
		test3.output(cout);
		
		// display the negative version of test1 
		cout << "The negative version of Test 1 is: ";
		test1.neg(test2);
		cout << " " << endl;
		
		// display the results of test1 * test2	
		cout << "Test1 * Test2 : ";
		test1.mul(test2);
		
		// display the reults of test 1 / test3
		cout << "Test1 / Test3: ";
		test1.div(test3);
		
		// display the results of test 2 + test 3
		cout << "Test2 + Test3: ";
		test2.add(test3);
		
		// display the results of test3 - test1
		cout << "Test3 - Test1: ";
		test3.sub(test1);
		
		// display which fractions are greater than which
		// test1 and test2
		cout << "Test1 ";
		test1.less(test2);
		cout << "Test2" << endl;
		// test2 and test3
		cout << "Test2 ";
		test2.less(test3);
		cout << "Test3" << endl;
		// test3 and test1
		cout << "Test3 ";
		test2.less(test3);
		cout << "Test1" << endl;
		
		// display whether test1 and test2 are equal
		cout << "Test1 ";
		test1.eq(test2);
		cout << "Test2" << endl;
		
		cout << "Equality operator is working!" << endl;
	
		// ask the user if they would like to run the program again
		cout << "would you like to run the program again?\n"
			 << "if yes press y \n"
			 << "if no press n" << endl;
		cin >> ans; // allow the user to answer an input
	}
	// gracefully exit
	cout << "thank you and goodbye" << endl;
	// allow for system paue
	system("Pause");
 	
    return 0; // return 0

} // end main

Rational::Rational() {
	num = 0; 
	dom = 1;
}

// what does this class do?
Rational ::	Rational(int newNum, int newDom) :
num(newNum), dom(newDom) {
	// blank
}

void Rational::add(Rational u) 
{
	Rational temp;
	temp.num = (num * u.dom) + (dom * u.num); 
	temp.dom = dom * u.dom;
	// call the reduce function and pass temp
	temp.reduce();
	// call the output function to display 
	temp.output(cout);
}

void Rational::sub(Rational u)
{
	Rational temp;
	temp.num = num * u.dom - dom * u.num;
	temp.dom = dom * u.dom;
	// call the reduce function and pass temp
	temp.reduce();
	// call output function
	temp.output(cout);
}

void Rational::mul(Rational u) {
	Rational temp;
	temp.num = num * u.num;
	temp.dom = dom * u.dom;
	// call the reduce function and pass temp
	//temp.reduce();
	// call the output function
	temp.output(cout);
}

void Rational::div(Rational u) {
	Rational temp;
	temp.num = num * u.dom;
	temp.dom = u.num * dom;
	// call the reduce function and pass temp
	temp.reduce();
	// call output function
	temp.output(cout);
}

void Rational::less(Rational u) {
	Rational temp;
	temp.num = num * u.dom;
	temp.dom = u.num * dom;
	
	if (temp.num > temp.dom) {
		cout << "is greater than or equal to ";
	}
	else {
		cout << "is less than or equal to ";
	}
}

void Rational::eq(Rational u) {
	Rational temp;
	temp.num = num * u.dom;
	temp.dom = dom * u.num;
	
	if (temp.num == temp.dom) {
		cout << "is equal to ";
	}
	else {
		cout << "is not equal to ";
	}
}

void Rational::neg(Rational u) {
	Rational temp;
	temp.num = num * -1;
	temp.dom = dom;
	// call the reduce function and pass temp
	temp.reduce();
	cout << temp.num << "/" << temp.dom;
}

void Rational::setTest3(Rational test1)
{
	num = test1.num;
}

void Rational::reduce()
{	// try the first case where the numerator and denominator are modulo(%) by 2
	// if both the numerator and denomintor modulus 2 equals 0 then the number can be divided by 2 
	if (num % 2 == 0 && dom % 2 == 0){
		num = num / 2;
		dom = dom / 2; 
	}
	// try modulo on the numerator and denominator by 3
	// if both the numerator and denomintor modulus 3 equals 0 then the number can be divided by 3 
	else if (num % 3 == 0 && dom % 3 == 0) {
		num = num / 3;
		dom = dom / 3;
	}
	// try modulo on the numerator and denominator by 5
	// if both the numerator and denomintor modulus 5 equals 0 then the number can be divided by 5 
	else if (num % 5 == 0 && dom % 5 == 0) {
		num = num / 5;
		dom = dom / 5;
	}
	//try modulo on the numerator and denominator by 7
	// if both the numerator and denomintor modulus 7 equals 0 then the number can be divided by 7 
	else if (num % 7 == 0 and dom % 7 == 0)
		num = num / 7;
		dom = dom / 7;
	}

void Rational::input(istream&infile) {
	char d;
	infile >> num;
	infile.get(d);
	infile >> dom;
}

void Rational :: output(ostream &outfile) {
	outfile << num << "/" << dom << endl;
}

