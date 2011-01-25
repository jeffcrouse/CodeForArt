// str.subsr(pos,n); // returns a copy of the substring consisting // of n characters from str, beginning at position pos // (default value 0); if n is too large or is omitted, // characters are copied only until the end of s is // reached

#include <iostream>
#include <string>
using namespace std;

int main () 
{
    string str = "We go step by step to the target";
    cout << "str is: " << str << endl;

    int n = str.find("step");
    
    string s = str.substr(n);
    cout << "s   is: " << s << endl;

    s = str.substr(n,12);
    cout << "s   is: " << s << endl;
    
    return 0;
}
