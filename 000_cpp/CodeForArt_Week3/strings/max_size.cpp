#include <iostream>
#include <string>
using namespace std;

int main () 
{
    string str = "C++ is best computer language";
    cout << "str is: " << str << endl;

    cout << "max_size of str is: "
         << str.max_size() << endl;

    return 0;
}
