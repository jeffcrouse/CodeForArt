#include <iostream>
#include <string>
using namespace std;

int main () 
{
    string str = "Nobody is perfect";
    string s   = "";
    char *ch   = "Robert Frost";

    // assigns a copy of str to s; returns s
    s.assign(str);
    cout << "s is : " << s << endl;

    
    // assigns to s a copy of the n characters in str, start�
    // ing at position 10: if n is too large, characters are
    // copied only until the end of str is reached: returns s
    s.assign(str,10,7); // perfect
    cout << "s is : " << s << endl;

    // assigns to s a string consisting of the first n charac�
    // ters in ch: returns s
    s.assign(ch,6);
    cout << "s is : " << s << endl;

    // assigns to s a copy of ch: returns s
    s.assign(ch);
    cout << "s is : " << s << endl;

    // assigns  to s a string consisting of the characters in
    // the range str.begin(), str.end(); returns s
    s.assign(str.begin(),str.end());
    cout << "s is : " << s << endl;

    // assigns to s a string consisting of n copies of ch;
    // returns s
    s.assign(17,'*');
    cout << "s is : " << s << endl;

    return 0;
}
