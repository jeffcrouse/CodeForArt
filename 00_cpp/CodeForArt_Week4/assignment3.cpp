#include <iostream>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;


// Given a character, it will give a random word that starts with that char
// Will return "?" if there are no words that start with the char
// eg: (':', '*', '/') will return ?
// Or returns a string containing one space if ' ' is given.
string getRandomWordStartingWith(char c) {
	if(c == ' ') return " ";
	c = tolower(c);
	vector<string> words;
	string word;
	ifstream indata;
	indata.open("/usr/share/dict/words"); 
	if(!indata) {
		cerr << "Error: couldn't open word list." << endl;
		exit(1);
	}
	indata >> word;
	while ( !indata.eof() ) {
		if(tolower(word[0])==c)
			words.push_back(word);
		indata >> word;
	}
	indata.close();
	if(words.size() == 0) {
		return "?";
	}
	int r = rand() % words.size();
	return words[r];
}


int main()
{
	srand ( time(NULL) );

	string input;
	
	cout << "Please enter a word: " << endl;
	getline(cin, input);

	cout << endl << endl;
	for(int i=0; i<input.length(); i++) {
		if(input[i] == ' ') {
			cout << endl;
		} else {
			string word = getRandomWordStartingWith(input[i]);
			word[0] = toupper(word[0]);
			cout << (char)toupper(input[i]) << " - " << word << endl;
		}
	}
	cout << endl << endl;
}