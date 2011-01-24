#include <iostream>
#include <string>
using namespace std;

int main () 
{
    string str = "We go step by step to the target";
    string::size_type size = str.size();

    cout << "str is: " << str << endl;
    cout << "size of str = " << size << endl;
    
    return 0;
}
