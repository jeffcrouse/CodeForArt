#include <iostream>
using namespace std;

void printNumStudents() {
	cout << "There are " << numStudents << " students" << endl; // BAD!
}


int main() {
	int numStudents = 16;
	printNumStudents();

}

