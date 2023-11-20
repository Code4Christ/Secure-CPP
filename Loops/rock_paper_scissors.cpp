// Section CSC160 - Computer Science I: C++
// File Name:  
// Student: Johnny Olmedo
// Homework Number: 2
// Description: this program lets you play rock, paper, scissors
// Last Changed: 02/03/2020

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main( ) //start main
{ 	char ans; // declare answer for do while loop (if the user wants to run program again)
	do // do at least once
	{
	
	// declare all variables
	char player1 = ' '; //  declare the user input as player1 and set it equal to zero
	char cpu = ' '; // declare the computer variable as cpu and set it equal to zero
	int randCpu = 0; // declare the variable for the random number generated for the computer and set it equal to zero
	int PLAYER1WINS = 0; // declare the variable that will hold the amount of wins player 1 has
	int CPUWINS = 0; // declare the variable that will hold the computer wins
	
	// print out a command that tells the user to choose either rock, paper, or scissors
	cout << "choose rock, paper, or scicssors (i.e rock = R, paper = P, sciccors = S): ";
	cin >> player1; // allow the user to input their choice
	// in this commented section I tried to mess around with input validation but I had a hard time getting it to work correctly with the rest of my code 
	// player1 = toupper(player1); // set all userinputs to upper case letters
	//while(!(player1 = 'P') && (player1 = 'S') && (player1 ='R'));
  	//{
  		//cout << "you choose incorrectly, please use the correct notation (i.e rock = R, paper = P, sciccors = S): ";
		//cin >> player1; // pass userInut
		/*player1 = toupper(player1);*/   	
	//}
	//player1 = toupper(player1); // set all userinputs to upper case letters
	
	// random number generator for computer
	randCpu = rand()%3; // randCPU turns into either 0, 1, 2
	// if the randCPU = 0 
	if (randCpu == 0)
	{
		cpu = 'P'; // set the cpu = P
		
	}
	// if randCpu = 1
	else if (randCpu == 1)
	{
		cpu = 'R'; // set cpu equal to R
	}
	// if randCpu equals 2
	else if (randCpu == 2) 
	{
		cpu = 'S'; // set the cpu variable equal to S
	}
    // criteria for if the players draw a tie
    if (player1 == cpu)
    {
	cout << "tie!" << endl; // print out that their was a tie
	}
    // criteria for if one of the player wins 
    else
    {   // in the cases where we can compare the player1 answer to the computer answers
    	switch(player1)
    	{
		case 'P': // in the case player1 draws a P for paper
			// if the computer chooses R for rock
			if (cpu == 'R') 
			{	// print out that player1 has won
				cout << "player1 wins!" << endl; 
				cout << "paper covers rock" << endl; // print out the basis for the win
				PLAYER1WINS++; // increment player1wins by 1
				cout << "PLAYER1: " << PLAYER1WINS << endl; // print out how many wins player1 has
			}	
			// if the computer chooses scissors
			else
			{	// print out that the computer has won
				cout <<"CPU wins!" << endl;
				cout << "scissors cut paper" << endl; // describe the basis for the computer win
				CPUWINS++; // increment the CPUWINS by 1 
				cout << "CPU: " << CPUWINS << endl; // print out how many wins the computer has won
			} 
			break; // break out of the loop
		// start of case R, in the case tat the player1 chooses R for rock
		case 'R':
  			// if the computer chooses S for scissors
			if (cpu == 'S')
			
			{	// print out that player1 wins
				cout << "player1 wins!" << endl;
				cout << "rock breaks scissors" << endl; // tell the user the basis for the win
				PLAYER1WINS++; // increment player1wins by 1
				cout << "PLAYER1: " << PLAYER1WINS << endl; // print out how many wins player1 has
			}	
			// if the computer chooses P for paper
			else
			{	// print out that the computer has won
				cout <<"CPU wins!" << endl;
				cout <<"paper covers rock" << endl; // explain the basis for the win
				CPUWINS++; // increment the computer wins
				cout << "CPU: " << CPUWINS << endl; // print out how many wins the computer has won
			} 
			break; // break out of the loop
		// start of case S where player 1 draws scissors
		case 'S':
  			// if the computer chooses P for Paper
			if (cpu == 'P') 
			{	// print out that player 1 has won
				cout << "player1 wins!" << endl; 
				cout << "scissors cuts paper" << endl; // staate the premise for the win
				PLAYER1WINS++; // increment player1wins by 1
				cout << "PLAYER1: " << PLAYER1WINS << endl; // print out how many wins player1 has
			}	
			// if the computer chooses R for rock
			else
			{ 	// print out that the computer won
				cout <<"CPU wins!" << endl;
				cout << "rock breaks scissors" << endl; // state the premise for the win
				CPUWINS++; // increment the computer wins
				cout << "CPU: " << CPUWINS << endl; // print out how many wins the computer has won
			} 
			break; // break out of the loop
		}
	} 		// setting decimal place for output
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);
		// ask the user if they want to find another square root
		cout << "would you like to player another rock, paper, scissor game?\n"
			 << "if yes press y \n"
			 << "if no press n" << endl;
		cin >> ans; // allow the user to answer an input
	
	}while ( ans == 'y' || ans == 'Y'); // while the user presses y they can re-run the program
		cout << "thank you and goodbye" << endl; // exit gracefully 
 
	system("Pause"); // allow system pause
    return 0; // return
}
