#include <iostream>
#include <string>
using namespace std;

int main () 
{
    string str1 = "string";
    string str2 = "String";
    string str3 = "second string";
    char ch[]   = "first string";

    cout << "string str1 is : " << str1 << endl;
    cout << "string str2 is : " << str2 << endl;
    cout << "char ary ch is : " << ch   << endl;
    cout << "string str3 is : " << str3 << endl;
    cout << endl;

    // compare str1 and str2
    cout << "1." << endl;
    size_t comp = str1.compare(str2);
    cout << "String str1 is ";
    ( comp == 0 ) ? cout << "equal" : cout 
         << "not equal";
    cout << " to string str2" << endl;

    // compare str1 and literal string "string"
    cout << "2." << endl;
    comp = str1.compare("string");
    cout << "String str1 is ";
    ( comp == 0 ) ? cout << "equal" : cout 
        << "not equal";
    cout << " to array of char \"string\"" << endl;

    // 3. and 4. doesn't work with Microsoft 
    // Visual Studio compiler
	
    // compare str3 start from pos 7 to 5
    // with str1
    cout << "3." << endl;
    comp = str3.compare(str1,7,5);
    cout << "Part of string str3 is ";
    ( comp == 0 ) ? cout << "equal" : cout 
        << "not equal";
    cout << " to str1" << endl;

    // compare str3 start from pos 7
    // with literal string "string"
    cout << "4." << endl;
    comp = str3.compare("string",7);
    cout << "Part of string str3 is ";
    ( comp == 0 ) ? cout << "equal" : cout 
        << "not equal";
    cout << " to C string \"string\"" << endl;

    // next 4 'compare' functions
    // doesn't work with GNU compiler
	
    cout << "5." << endl;
    comp = str1.compare(6,10,ch);
    cout << "String str1 is ";
    ( comp == 0 ) ? cout << "equal" : cout 
    << "not equal";
    cout << " to part of char ary \"first string\"" 
    << endl;

    cout << "6." << endl;
    comp = str1.compare(0,3,str3);
    cout << "Part of str1 is ";
    ( comp == 0 ) ? cout << "equal" : cout 
    << "not equal";
    cout << " to string \"second string\"" 
    << endl;

    cout << "7." << endl;
    comp = str1.compare(1,3,str2,1,3);
    cout << "String str1 is ";
    ( comp == 0 ) ? cout << "equal" : cout 
    << "not equal";
    cout << " to part of string \"second string\"" 
    << endl;

    cout << "8." << endl;
    comp = str1.compare(1,3,str2,1,3);
    cout << "String str1 is ";
    ( comp == 0 ) ? cout << "equal" : cout 
    << "not equal";
    cout << " to part of string \"second string\"" 
    << endl;

    return 0;
}
