#include <iostream>
#include <string>
using namespace std;

int main () 
{
    string str = "STL is created from Dennis Ritchie";
    string s1  = "was";
    string s2  = "developed";
    string s3  = "Stepanov alexander";
    cout << "str is: " << str << endl;

    cout << "replace 'is' for 'was'" << endl;
    str.replace(4, // start position in str
            2,     // how many characters
            s1);   // source for replasment
    
    cout << "str is: " << str << endl;
    
    cout <<"replace 'created' for 'developed'" << endl;
    int n = str.find('c'); // pos of 'created'
    int x = str.find("from") -1;

    str.replace(str.begin()+n,// start pointer
            str.begin()+x,    // end pointer
            s2);              // source
    
    cout << "str is: " << str << endl;

    cout << "replace 'Dennis' for 'alexander'" << endl;
    int x1 = str.find('D'); // search Dennis
    int x2 = str.find(' ',x1+1); // space after
    int y1 = s3.find("alex"); // search 'alex'
    int y2 = strlen("alexander");

    str.replace(x1, // start position in str
            x2-x1,  // how characters to replace
            s3,     // source for replacement
            y1,     // start positio from source
            y2);    // how chracter start from y1
    
    cout << "str is: " << str << endl;

    cout << "replace 'from' for 'by'" << endl;
    char ary[] = "bytes";
    n = str.find("from");

    // same variant possible with iterators
    // instead of number of position
    str.replace(n, // start position in str
            4,     // how many characters
            ary,   // source
            2);    // first 2 characters from source
    
    cout << "str is: " << str << endl;

    cout << "replace 'a' for 'A' (alexander)" << endl;
    n = str.find("alexander");

    str.replace(n,  // start position in str
            1,      // how character(s)
            1,      // how many copies of character
            'A');   // character for replasment
    cout << "str is: " << str << endl;

    cout << "replace 'Ritchie' for 'Stepanov'" << endl;
    x1 = str.find('R');
    y1 = s3.find(' ');

    str.replace(str.begin()+x1, // start pointer
            str.end(), // to the end of str
            s3.begin(), // start pointer from source
            s3.begin()+y1 // end pointer from
            );              // source
    cout << "str is: " << str << endl;

    return 0;
}
