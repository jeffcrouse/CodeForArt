#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main () 
{
    string str;
    cout << "Enter string (EOL = $) : ";
    getline (cin, str, '$');
    cout << "Str is : " << str << endl;

    ifstream In("data.dat");
    vector v;

    cout << endl << "Read data from file" << endl;
    while ( ! In.eof() )
    {
    	getline (In, str);
    	v.push_back(str);
    }

    copy (v.begin(),v.end(),
    		ostream_iterator(cout,"\n"));
    cout << endl;
    	

    return 0;
}
