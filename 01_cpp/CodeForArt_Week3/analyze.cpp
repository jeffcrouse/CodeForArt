#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct stringInfo {
	int num_as;
	int num_es;
	int num_is;
};

stringInfo analyzeString(string s);

int main()
{
	cout << "Enter a string: ";
	string input;
	
	getline(cin, input);
	stringInfo myStringInfo;
	
	myStringInfo = analyzeString(input);
	
	cout << "The letter 'a' appears " << myStringInfo.num_as << " times" << endl;
	cout << "The letter 'e' appears " << myStringInfo.num_es << " times" << endl;
	cout << "The letter 'i' appears " << myStringInfo.num_is << " times" << endl;
	
}


stringInfo analyzeString(string myString) {
	stringInfo si;
	si.num_as = 0;
	si.num_es = 0;
	si.num_is = 0;
	
	for(int i=0; i<myString.length(); i++) {
	
		// How else could I have done this?
		if(myString[i] == 'a') {
			si.num_as++;
		}
		if(myString[i] == 'e') {
			si.num_es++;
		}
		if(myString[i] == 'i') {
			si.num_is++;
		}
	}
	return si;

}