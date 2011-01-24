#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main ()
{
	int numFlavors = 12;
	long milliseconds = 2147483648;
	float temperature = 98.6;
	double moleculeSize = 12.3332999999999995;
	char letterGrade = 'C';

	// Casting a float to an int
	cout << "Is the temperature " << temperature << " or " << (int)temperature << "?" << endl;

	// Out of curiosity...
	cout << "The maximum value of an int is " << INT_MAX << endl;

	// Casting a long to an int
	cout << "Casting 2147483648 to an int gives you: " << (int)milliseconds << endl;
	
	// Casting an int to a char
	cout << "The letter " << letterGrade << " has a value of " << (int)letterGrade << endl;
}


