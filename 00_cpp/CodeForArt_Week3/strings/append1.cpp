#include <iostream>
#include <string>
using namespace std;

int main () 
{
    string str = "Hello";
    cout << "str is : " << str << endl;
    str += ",";
    str += ' ';
    cout << "str is : " << str << endl;

    string s;
    s = str + "World";
    cout << "s is : " << s << endl;

    char ch = '!';
    s += ch;
    cout << "s is : " << s << endl;

    return 0;
}
