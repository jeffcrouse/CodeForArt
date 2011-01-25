#include <iostream>
#include <string>
using namespace std;

int main () 
{
    string str = "First Name: Robert";
    char fname[255];
    cout << "str is: " << str << endl;

    int n = str.find(':');

    str.copy(fname, // copy to array
            n+1,    // how many char
            0);     // start position from str
    
    // must terminate fname with '\0';
    fname[n+1] = 0;
    
    cout << "fname is: " << fname << endl;

    return 0;
}
