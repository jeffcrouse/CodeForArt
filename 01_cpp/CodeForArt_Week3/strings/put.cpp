#include <iostream>
#include <string>
using namespace std;

int main () 
{
    string str;

    cout << "Enter string for testing : ";
    cin  >> str;
    cout << "\nString is : " << str << endl;

    cout << "Enter string for testing "
    	 << "(d to quit) : ";
    while ( cin >> str )
    {
    	cout << endl;
    	cout << "String is : " << str << endl;
    	cout << "Enter string for testing "
             << "(d to quit) : ";
    }

    return 0;
}
