// File Name: Reverse_String
// Student: Johnny Olmedo
// Description: Printing Strings Backwards
// Last Changed: 11/22/2022

#include <iostream>
#include <ostream>
//#include <bits/stdc++.h>
using namespace std;

// reverse function that reverses string
void reverse(string str)
{
    int len = str.length();
    int n = len;
    // while loop to reverse and print out string
    while(n--)
        cout << str[n];
}

int main() // start main
{
    
	char ans; // declare answer for do while loop (if the user wants to run program again)
	cout << "this program prints out 3 strings in reverse" << endl;
	cout << "would you like to continue? ";
	cin >> ans;
	while (ans == 'y' || ans == 'Y')// do at least once
	{  
        // declare variables
        string user_string;
        int count = 0;
        // for loop to get 3 inputs from user
        for (count=0; count < 3; count++)
        {
            cout << "Please Enter any String Input: ";
            cin >> user_string;
            reverse(user_string);
            cout << endl;
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