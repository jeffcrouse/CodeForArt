#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct movie {
  string title;
  string director;
  int year;
};

// Inheritance!
struct horrorMovie : movie {
	float goreRating;
	int evilClowns;
};

int main ()
{
	movie movie1;
	movie1.title = "Rush Hour 2";
	movie1.year = 2001;
	movie1.director = "Brett Ratner";
  	cout << "You entered: " << movie1.title;
  	cout << " (" << movie1.year << ") by " << movie1.director << endl;


	horrorMovie movie2;
	movie2.title = "Nightmare On Elm Street";
	movie2.director = "Wes Craven";
	movie2.year = 1985;
	movie2.goreRating = 4.5;
	movie2.evilClowns = 0;
	cout << "You entered: " << movie2.title;
  	cout << " (" << movie2.year << ") by " << movie2.director << ".  ";
	cout << "It has a gore rating of " << movie2.goreRating << endl;
	
}



