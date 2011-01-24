#include <iostream>
#include <string>
using namespace std;

int main () 
{
    string s = "Nobody is perfect";

    // Returns s[pos]
    for ( int pos = 0; pos < s.length(); ++pos )
    	cout << s.at(pos) << " ";
    cout << endl;

    return 0;
}
