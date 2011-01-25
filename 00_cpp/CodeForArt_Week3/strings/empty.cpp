#include <iostream>
#include <string>
using namespace std;

int main () 
{
    string str = "*******";

    while ( ! str.empty() )
    {
    	cout << str << endl;
    	str.erase(str.end()-1);
    }
    cout << endl;

    return 0;
}
