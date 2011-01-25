#include <iostream>
#include <string>
using namespace std;

int main () 
{
    string str = "C++ language";
    string s   = "is best";
    char ch[]  = "C++ language";
    
    cout << "str is: " << str << endl;
    cout << "s   is: " << s   << endl;
    cout << "ch  is: " << s   << endl;
    
    // insert a copy of s into str
    // at position pos;
    string::size_type pos = 4;
    str.insert(pos,s);
    cout << "str is: " << str << endl;
    
    // insert a copy of ch into str at
    // the position specified by iterator
    // return an iterator positioned at
    // this copy
    int n = str.find('l');
    str.insert(str.begin() + n,' ');
    cout << "str is: " << str << endl;
    
    // like above but n x copies of char
    str.insert(str.end(),3,'!');
    cout << "str is: " << str << endl;
    
    // insert 4 char from ch into s
    // at the position 0
    s.insert(0,ch,4);
    cout << "s   is: " << s   << endl;
    
    // insert 8 characters from str
    // start from position n ('langu...')
    // into s at position x (end string)
    n = str.find('l');
    int x = s.length();
    s.insert(x,str,n,8);
    cout << "s   is: " << s   << endl;
    
    n = s.find('l');
    s.insert(s.begin()+n,' ');
    cout << "s   is: " << s   << endl;
    
    // insert range (begin - begin+7) of str 
    // into s at position begin+4
    s.insert(s.begin()+4,str.begin(),str.begin()+7);
    cout << "s   is: " << s   << endl;
    return 0;
}
