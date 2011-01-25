#include <iostream>
#include <string>
#include <sstream>
using namespace std;


int values[100];
int count=0;
int input;



int main ()
{

	do {
	
		cout << "Enter a number or 0 to finish: ";
		cin >> input;
		
		values[count] = input;
		
		count++;
	} while(input != 0);


	for(int i=0; i<count; i++) {
		cout << (char)(values[i]+65);
	}
	
	cout << endl;
	
}


