#include <iostream>
#include <string>
using namespace std;

int main () 
{
    string str = "C++ is best computer language";
    cout << "str is: " << str << endl;

    // usual iterator doesn't work
    string::reverse_iterator It = str.rbegin();
    while ( It != str.rend() )
        cout << *It++;
    cout << endl;

    return 0;
}
