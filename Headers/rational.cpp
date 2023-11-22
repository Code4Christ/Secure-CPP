#include <iostream>
#include <ostream>
#include "rational.h"

// set up contructors for test1, test2, test3
// default contructorfor no arguments
rational::rational() {
	num = 0; 
	dom = 1;
}

// sets numerator if there is only 1 argument in rational test#
rational::rational(int newNum):
	num(newNum)
{
	num = newNum;
	dom = 1;
}

void rational::setTest2(rational test1)
{
	num = test1.num;
}
// sets numerator and denominator if two arguments are pased to rational test 2
rational ::	rational(int newNum, int newDom) :
num(newNum), dom(newDom) {
	// blank
}

//---------------------------------------------------------------------------------------------------------------------------------
// set up the constuctors for the math (+, -, *, /)
// adding obj2 and obj3
rational operator +(rational& obj1, rational& obj2) 
{
	rational temp;
	temp.num = (obj1.num * obj2.dom) + (obj1.dom * obj2.num); 
	temp.dom = obj1.dom * obj2.dom;
	// call the reduce function and pass temp
	temp.reduce();
	// return temp
	return temp;
}

// function for subrtracting
// subtracting obj3 and obj1
rational operator -(rational& obj1, rational& obj2) 
{
	rational temp;
	temp.num = (obj1.num * obj2.dom) - (obj1.dom * obj2.num); 
	temp.dom = (obj1.dom * obj2.dom);
	// call the reduce function and pass temp
	temp.reduce();
	// return temp
	return temp;
}
// function for multiplying
// multiplying obj1 and obj2
rational operator *(rational& obj1, rational& obj2) 
{
	rational temp;
	temp.num = (obj1.num * obj2.num); 
	temp.dom = (obj1.dom * obj2.dom);
	// call the reduce function and pass temp
	temp.reduce();
	// return temp
	return temp;
}

// division
rational operator /(rational& obj1, rational& obj2) 
{
	rational temp;
	temp.num = (obj1.num * obj2.dom); 
	temp.dom = (obj2.num * obj1.dom);
	// call the reduce function and pass temp
	temp.reduce();
	// return temp
	return temp;
}

//----------------------------------------------------------------------------------------------------------------------------------
// greater than operator
bool operator <(rational& obj1, rational& obj2) 
{
	double num1 = (double)obj1.num / (double)obj1.dom;
	double num2 = (double)obj2.num / (double)obj2.dom;
	
	if (num1 < num2)
	{
		return true; // true
	} else
	{
		return false;  // false
	}
	
}

// equals too operator
bool operator ==(rational& obj1, rational& obj2) 
{
	double num1 = (double)obj1.num / (double)obj1.dom; 
	double num2 = (double)obj2.num / (double)obj2.dom;
	
	if(num1 == num2)
	{
		return true; // true
	} else 
	{
		return false; // false
	}
}

// reduce
void rational::reduce()
{	// try the first case where the numerator and denominator are modulo(%) by 2
	// if both the numerator and denomintor modulus 2 equals 0 then the number can be divided by 2 
	while (num % 2 == 0 && dom % 2 == 0){
		num = num / 2;
		dom = dom / 2; 
	}
	// try modulo on the numerator and denominator by 3
	// if both the numerator and denomintor modulus 3 equals 0 then the number can be divided by 3 
	while (num % 3 == 0 && dom % 3 == 0) {
		num = num / 3;
		dom = dom / 3;
	}
	//try modulo on the numerator and denominator by 5
	// if both the numerator and denomintor modulus 5 equals 0 then the number can be divided by 5 
	while (num % 5 == 0 && dom % 5 == 0) {
		num = num / 5;
		dom = dom / 5;
	}
	// try modulo on the numerator and denominator by 7
	// if both the numerator and denomintor modulus 7 equals 0 then the number can be divided by 7 
	while (num % 7 == 0 && dom % 7 == 0) {
	
		num = num / 7;
	
		dom = dom / 7;
	}
	
}


// istream for input and parsing
istream& operator >>(istream& inFile, rational& obj)
{
	char d;
	inFile.get(d);
	inFile >> obj.num;
	// parce threw the parenthesis and comma
	inFile.get(d);
	inFile >> obj.dom;
	inFile.get(d);
	return inFile;
}

// ostream for output
ostream& operator <<(ostream& outFile, const rational& obj)
{
	outFile << "(" << obj.num << "," << obj.dom << ")" << endl;
	return outFile;
}
