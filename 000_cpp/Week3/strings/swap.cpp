#include <iostream>
#include <string>
using namespace std;

int main () 
{
    string str1 = "Robert";
    string str2 = "Forest";
    cout << "str1 is: " << str1 << endl;
    cout << "str2 is: " << str2 << endl;
    cout << endl;

    cout << "str1.swap(str2)" << endl;
    cout << endl;

    str1.swap(str2);
    cout << "str1 is: " << str1 << endl;
    cout << "str2 is: " << str2 << endl;
    
    return 0;
}
