#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int values[100]; // Note that if the user enters more than 100 numbers, error!
int nCount=0;
int input;

int main ()
{
	do {
		cout << "Enter a number or 0 to finish: ";
		cin >> input;
		values[nCount] = input;
		nCount++;
	} while(input != 0);


	for(int i=0; i<nCount; i++) {
		cout << (char)(values[i]+65);
	}
	cout << endl;
}


