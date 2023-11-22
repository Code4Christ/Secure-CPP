#include <iostream>
#include <ostream>
using namespace std;

// introduce class rational for rational numbers 
class rational {

	public:
		rational(); // default
		// this function accepts a single int as an argument
		rational(int newNum);
		// this function sets test2 as the numertor of test1
		void setTest2(rational test1); 
		// this function accepts two integers as an argument
		rational(int newNum, int newDom);

		// this function adds fractions
		friend rational operator +(rational& obj1, rational& obj2);
		// this function subtracts fractions
		friend rational operator -(rational& obj1, rational& obj2);
		// this function mulitplies fractions	
		friend rational operator *(rational& obj1, rational& obj2);
		// this function divides fractions	
		friend rational operator /(rational& obj1, rational& obj2);
		
		// this function tells which fraction is greater than the other
		friend bool operator <(rational& obj1, rational& obj2);
		// this function tells whether the fractions are even or not
		friend bool operator ==(rational& obj1, rational& obj2);
		// this reduces any fraction if possible 
		void reduce(); 
		// this will be used for parsing and input 
		friend istream& operator >>(istream& inFile, rational& obj);
		// this will be used for output 
		friend ostream& operator <<(ostream& outFile, const rational& obj);		
	
	private:
		int num;
		int dom;
};
