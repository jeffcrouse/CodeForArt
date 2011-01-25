#include <iostream>
#include <string>
using namespace std;

int main () 
{
    string  str("C++ is best language");
    string  s = "C++";
    
    cout << "str is: " << str << endl;
    
    // search character from pattern 
    // using the first x characters in pattern.
    // the value position must be given
    int n = str.find_first_not_of("CBCD",0,3);
    cout << "first not 'C' is found at position "
    	 << n+1 << endl;
    
    // search first not of 
    // pattern is string
    n = str.find_first_not_of(s);
    cout << "first not of C++ is found "
    	 << "at position " << n+1 << endl;
    
    return 0;
}
