#include <iostream>
#include <string>
using namespace std;

int main () 
{
    string str = "We go step by step to the target";
    string s1  = "step";
    cout << "str is: " << str << endl;
    cout << "s1  is: " << s1  << endl;

    cout << "int n1 = str.find(s1)" << endl;
    int n1 = str.find(s1);
    cout << "n1 = " << n1+1 << endl;
    
    cout << "int n2 = str.rfind(s1)" << endl;
    int n2 = str.rfind(s1);
    cout << "n2 = " << n2+1 << endl;
    
    cout << "n3 = str.rfind(s1,n2-1)" << endl;
    int n3 = str.rfind(s1,n2-1);
    cout << "n3 = " << n3+1 << endl;

    cout << "n1 = str.rfind('t')" << endl;
    n1 = str.rfind('t');
    cout << "n1 = " << n1+1 << endl;
    
    cout << "n2 = str.rfind('t',n1-1)" << endl;
    n2 = str.rfind('t',n1-1);
    cout << "n2 = " << n2+1 << endl;
    
    char ch[] = "step";
    cout << "char ch[] = \"step\"" << endl;
    cout << "n1 = str.rfind(ch)" << endl;
    n1 = str.rfind(ch);
    cout << "n1 = " << n1+1 << endl;
    
    cout << "n2 = str.rfind(\"stabc\",10,2)" << endl;
    n2 = str.rfind("stabc", // pattern
            10,             // start position
            2);             // for first 2 char
                            // in pattern
    cout << "n2 = " << n2+1 << endl;
    
    return 0;
}
