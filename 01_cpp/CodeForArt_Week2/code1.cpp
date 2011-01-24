#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int value1;
int value2;
int value3;
int value4;
int value5;
int value6;

/**
*  Takes a set of integers and converts it into letters.
*/
int main ()
{

	cout << "Enter a number: ";
	cin >> value1;

	cout << "Enter a number: ";
	cin >> value2;
	
	cout << "Enter a number: ";
	cin >> value3;
	
	cout << "Enter a number: ";
	cin >> value4;
	
	cout << "Enter a number: ";
	cin >> value5;
	
	cout << (char)(value1+65) << (char)(value2+65) << (char)(value3+65) << (char)(value4+65) << (char)(value5+65) << endl;

}


