#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main () 
{
    string  str("C++ is best language");
    int pos1, pos2; // size_t or size_type 
                    // work not correct
    // search for first string "best" inside of str
    // default position is 0
    pos1 = str.find ("best");
    cout << "Word best is found on position " << pos1+1 
         << endl;
    
    // if pattern is not found - return -1
    pos2 = str.find ("best",pos1+1);
    cout << "Word best is found on position " << pos2+1 
         << endl;

    // search for first occurrence of character
    pos1 = str.find('g');
    cout << "First character 'g' found on position " 
         << pos1
    	 << endl;

    // search for first occurrence of string
    string s = "is";
    pos1 = str.find (s);
    cout << "Word 'is' is found on position " << pos1+1 
         << endl;
    
    return 0;
}
