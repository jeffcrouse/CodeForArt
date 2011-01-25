#include <iostream>
#include <string>
using namespace std;

int main () 
{
    string str = "C++ is best computer language";

    string::size_type cap;
    cap = str.capacity();

    cout << "Capacity of str is: " << cap << endl;
    cout << "Size of str is    : " << str.size() 
         << endl;
    cout << "Length of str is  : " << str.length() 
         << endl;

    cout << "Resize the str for 50 character" << endl;
    str.resize(50);
    cap = str.capacity();
    
    cout << "Capacity of str is: " << cap << endl;
    cout << "Size of str is    : " << str.size() 
         << endl;
    cout << "Length of str is  : " << str.length() 
         << endl;

    return 0;
}
