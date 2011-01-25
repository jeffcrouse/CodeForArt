// if <=s.size(), truncates rightmost // character in s to make it of size n; otherwise, adds // copies of character ch to end of s to increase it size // to n, or adds a default character value (usually a // blank) if ch is omitted; return type is void


#include <iostream>
#include <string>
using namespace std;

int main () 
{
    string str = "Alexander Stepanov";
    cout << "str is: " << str << endl;
    cout << "size of str is: "
         << str.size() << endl;

    str.resize(11);

    cout << "after str.resize(11)" << endl;
    cout << "str is: " << str << endl;
    cout << "size of str is: "
         << str.size() << endl;

    str.resize(20,'.');

    cout << "after str.resize(20,'.')" << endl;
    cout << "str is: " << str << endl;
    cout << "size of str is: "
         << str.size() << endl;

    return 0;
}
