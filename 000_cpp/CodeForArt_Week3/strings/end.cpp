#include <iostream>
#include <string>
using namespace std;

int main () 
{
    string s;
    string str = "*************************";
    size_t pos = str.length();

    while ( pos )
    {
    	s.assign ( str.begin(),str.end() - pos+1);
    	cout << s << endl;
    	pos -= 5;
    }

    return 0;
}
