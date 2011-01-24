#include <iostream>
using namespace std;

int main() { 
	
	// Initialize an array as a local variable.
	int scoresArray[7] = {90, 80, 65, 76, 100, 75, 82};
	
	int* scoresPtr = new int[7];
	for(int i=0; i<7; i++) {
		scoresPtr[i] = scoresArray[i];
	}
	
	
	
	
} 