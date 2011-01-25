#include <iostream>
#include <string>
using namespace std;

int main () 
{
    string  str("C++ is best language");
    string  s = "be";
    
    cout << "str is: " << str << endl;

    // search be start from position 2
    // if position is ommited - default is 0
    int n = str.find_first_of(s,2);
    cout << "first 'be' found at position "
    	 << n+1 << endl;

    // same as above but search for character
    n = str.find_first_of('l');
    cout << "first character 'l' found at "
    	 << "position " << n+1 << endl;

    // search 'first of' for the characters in
    // charary
    char charary[] = " bea";
    cout << "charary[] = \" bea\"" << endl;
    n = str.find_first_of(charary,0);
    cout << "first character from charary "
    	 << "found at position " << n+1 << endl;
    cout << "Note: position 4 is space" << endl;

    // same as above but third argumen is
    // number of character from which searching
    // starts
    // this variant of find_first_of dosn't
    // work properly with GNU compiler
    n = str.find_first_of(" bae",0,3);
    cout << "first character from charary "
    	 << "found at position " << n+1 << endl;

    return 0;
}
