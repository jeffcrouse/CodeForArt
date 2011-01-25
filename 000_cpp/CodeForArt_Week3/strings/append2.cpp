#include <iostream>
#include <string>
using namespace std;

int main () 
{
    string str = "Nobody is perfect";
    string s   = ""; // empty string
    char *ch   = "abcdef";

    // append string str at the end of s; 
    // return s
    
    // appends at the end of s a copy of the n characters
    // in str, starting at position pos; if n is too
    // large, characters are copied only until the end  
    // of str is reached;
    // returns s
    s.append(str,0,6);
    cout << "s is : " << s << endl;

    // appends copies of the characters in the range [inpIt1,
    // inpIt2] to s; returns s
    string::iterator inpIt1 = str.begin()+6;
                    //start from ' is'
    string::iterator inpIt2 = str.end();

    s.append(inpIt1,inpIt2);
    cout << "s is : " << s << endl;

    // appends three !
    s.append(3,'!');
    cout << "s is : " << s << endl;
    
    // appends the first n characters in ch at the end
    // of s; returns s
    s.append(ch,3);
    cout << "s is : " << s << endl;
    
    // appends charArray at the end of s; returns s
    s.append(ch,3);
    cout << "s is : " << s << endl;

    return 0;
}
