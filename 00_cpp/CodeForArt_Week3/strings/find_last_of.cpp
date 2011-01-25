#include <iostream>
#include <string>
using namespace std;

int main () 
{
    string  str("C++ is best language");
    string  s  = "g";
    cout << "str is: " << str << endl;
    cout << "s   is: " << s   << endl;

 	int n = str.find_last_of(s);
 	cout << "last_of '" << s << "' faund"
 		 << " at position " << n+1 << endl;

    n = str.find_last_of(' ');
    cout << "last_of ' ' faund"
    	 << " at position " << n+1 << endl;

    n = str.find_last_of(" la");
    cout << "last_of \" la\" faund"
    	 << " at position " << n+1 << endl;
    
    return 0;
}
