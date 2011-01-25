#include <iostream>
#include <string>
using namespace std;

int main () 
{
    string  str("C++ is best language");
    cout << "str is: " << str << endl;

    int n = str.find_first_not_of("aeiouAEIOU");

    cout << "First consonant found at " << n+1
    	 << " position" << endl;
    
    return 0;
}
