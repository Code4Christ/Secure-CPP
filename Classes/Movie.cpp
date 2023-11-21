// Section CSC160 - Computer Science I: C++

// File Name: Movie.cpp

// Student: Johnny Olmedo

// Description: this program gives Movie rating useing classes

// Last Changed: 3/8/2020

#include <iostream>
#include <string>
using namespace std;
// define class Movie
class Movie {
	public: 
		Movie();
		Movie(string _Name, string _mpaaRating);
		string getName();
		string getRating();
		void setName(string _Name);
		void setRating(string _Rating);
		void addRatings(int score);
		double getAvg();
	private:
		string movieName;
		string mpaaRating;
		int terribleRatings;
		int badRatings;
		int okRatings;	
		int goodRatings;
		int greatRatings;	
};

int main() 
{ // start main	
	char ans; // declare answer for while loop (if the user wants to run program)
	// explain what this program is doing to the user
	cout << "this program gives ratings on movies" << endl;
	cout << "would you like to continue?" << endl; // ask if the user would like to continue or not
	cout << "please press Y for yes and N for no: " << endl; // direct the user how to respond
	cin >> ans; // take the user input
	while ( ans == 'y' || ans == 'Y') // while the user answered y for yes
	{
		Movie movie1; // calls default
		// give Movie 1 a name
		movie1.setName("The Adjustment Bureue");
		// give set Movie 1 a rating
		movie1.setRating("PG-13");
		// give the Movie ratings for Movie 1
		movie1.addRatings(5);
		movie1.addRatings(4);
		movie1.addRatings(5); 
		movie1.addRatings(4);
		movie1.addRatings(5); 
		// give Movie 2 a name and give it its rating
		Movie movie2("I am Number 4", "PG-13"); 
		// add the customer ratings up
		movie2.addRatings(2); 
		movie2.addRatings(2);
		movie2.addRatings(3);
		movie2.addRatings(3);
		movie2.addRatings(2);
		// display the average rating for Movie 1
		cout << movie1.getName() << " " << movie1.getRating() << " " << "average rating is " << movie1.getAvg() << endl; 
		// display the average rating for Movie 2
		cout << movie2.getName() << " " << movie2.getRating() << " " << "average rating is " << movie2.getAvg() << endl; 
		// ask the user if they would like to run the program again
		cout << "would you like to run the program again?\n"
			 << "if yes press y \n"
			 << "if no press n" << endl;
		cin >> ans; // allow the user to answer an input	
	}
	cout << "thank you and goodbye" << endl;
	system("Pause");
 
    return 0;

}



// this is the default constructor
Movie::Movie() {
	movieName = " ";
	mpaaRating = " ";
	terribleRatings = 0;
	badRatings = 0;
	okRatings = 0;
	goodRatings = 0;
	greatRatings = 0;
}

Movie::Movie(string _Name, string _mpaaRating){
movieName = _Name;
mpaaRating = _mpaaRating;
terribleRatings = 0;
badRatings = 0;
okRatings = 0;
goodRatings = 0;
greatRatings = 0;
}
// this function returns the name of a Movie
string Movie::getName(){
	return movieName;
}

string Movie::getRating() {
	return mpaaRating;
}

void Movie::setName(string _Name) {
	movieName = _Name;
}

void Movie::setRating(string _mpaaRating){
	mpaaRating = _mpaaRating;
}

// this function keeps track of the Movie ratings 
void Movie::addRatings(int score){
	switch(score)
	{
		case 1:
			terribleRatings++;
			break;
		case 2:
			badRatings++;
			break;
		case 3:
			okRatings++;
			break;
		case 4:
			goodRatings++;
			break;
		case 5:
			greatRatings++;
			break;
	}
}

double Movie::getAvg(){
 // to get the average add everything together and divide by the number of variables 
 return (terribleRatings + 2 * badRatings + 3 * okRatings + 4 * goodRatings + 5 * greatRatings) / double (terribleRatings + badRatings + okRatings + goodRatings + greatRatings); 
}





		
	

