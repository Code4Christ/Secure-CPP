// Section CSC160 - Computer Science I: C++
// File Name: lesson4-375-10
// Student: Johnny Olmedo
// Description: this program searches for names in a file
// Last Changed: 3/1/2020
 
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main( )
{ // start main	
	char ans; // declare answer for while loop (if the user wants to run program)
	// explain what this program is doing to the user
	cout << "this program searches for top 1000 male or femle names " << endl;
	cout << "would you like to continue?" << endl; // ask if the user would like to continue or not
	cout << "please press Y for yes and N for no: " << endl; // direct the user how to respond
	cin >> ans; // take the user input
	while ( ans == 'y' || ans == 'Y') // while the user answered y for yes
	{
		ifstream in1; // delcare in1 as your ifstream for reading files
		string name; // declare name as a string
		int rank = 0; // declare rank as an int
		string male; // declare male as a string
		string female; // declare female as a string
		int maleRank = 0; // delcare maleRank as an int and set it equal to zero
		int femaleRank = 0; // delcare femaleRank as an int and set it equal to zero
		bool foundMale = false; // declare foundMale as a bool
		bool foundFemale = false; // declare foundFemale as a bool
		// asl the user to enter in a name to search for
		cout << "please enter in a name(capatalize first letter of name): ";
		cin >> name; // allow the user to enter the name
		//open the file 
		in1.open("babynames2012.txt");
		// if the file cannot be opened
		if (in1.fail()) {
			// tell the user it failed
			cout << "input file opening failed";
			exit(1);
		}
		// while the file opens
		cout << " file opened" << endl;
		// while its not the end of file
		while (!in1.eof()){
			// in1 will read the rank, the maleName, then the femaleName
			in1 >> rank >> male >> female;
			// if a female name matches the name given
			if (female == name) {
				// set the female rank equal to the rank found in the file
				femaleRank = rank;
				foundFemale = true; // set foundFemale = true
			}
			// if a male name matches the name given
			if (male == name) {
				// set the male rank equal to the rank found in the file
				maleRank = rank;
				// set foundMale = true
				foundMale = true;
			}
		}
		in1.close(); // close the file 
		// possible outcomes to the work above 
		// if a male name was found
		// print out what the name is ranked
		if (foundMale) {
			cout << name << " is ranked " << maleRank << " among top 1000 male names" << endl;
		}
		// tell the user the name was not found
		else {
			cout << name << " is not ranked among the top 1000 male names" << endl;
		}
		// if a female name was found
		// tell the user which name was found
		if (foundFemale) {
			cout << name << " is ranked " << femaleRank << " among top 1,000 female names" << endl;
		}
		// else tell the user the name was not found
		else {
			cout << name << " is not ranked among the top 1000 female names" << endl;
		}

		// ask the user if they would like find another name
		cout << "would you like to enter another name to see where it stands in the top 1,000 male or female names?\n"
			 << "if yes press y \n"
		 	<< "if no press n" << endl;
		cin >> ans; // allow the user to answer an input
	}
	cout << "thank you and goodbye " << endl; // exit gracefully 
	system("Pause");

    return 0;
} //end main
