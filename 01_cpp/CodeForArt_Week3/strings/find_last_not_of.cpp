#include <iostream>
#include <string>
using namespace std;

int main () 
{
    string  str("C++ is best language");
    string  s  = "langue";
    int pos = str.length()-1;
    cout << "str is: " << str << endl;
    
    // returns the highest position <= pos of a character
    // in str that does not match any charcter in s; 
    // returns nopos if there  is  no such position:
    // npos is the default value for pos
    int n =  str.find_last_not_of(s, pos);
    cout << "last_not_of 'langue' found at position "
    	 << n+1 << endl;

    // same as above but search for single character
    n = str.find_last_not_of('e');
    cout << "last_not_of 'e' found at position "
    	 << n+1 << endl;

    char ary[] = "be";
    // seawrch for occurence last_not_of
    // from pattern ary in str
    n = str.find_last_not_of(ary);
    cout << "last_not_of 'be' found at position "
    	 << n+1 << endl;
    
    return 0;
}
