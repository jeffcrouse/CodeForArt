#include <iostream>
using namespace std;

int main() { 

	int someNumber = 5;
	int* pointerToSomeNumber; // Pointer declaration
	
	pointerToSomeNumber = &someNumber;
	
	
	cout << pointerToSomeNumber << endl;
	
	// Dereference
	*pointerToSomeNumber = 6;
	
	cout << pointerToSomeNumber << endl;
	
} 
