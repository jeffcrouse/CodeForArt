#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string cars[] = {"volvo", "buick", "toyota", "mazda", "honda"};

int main ()
{
	for(int i=0; i<5; i++) {
		cout << "My other car is a " << cars[i] << "." << endl;
	}
	
}


