#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct movie {
  string title;
  string director;
  int year;
};

int main ()
{
  movie amovie;

  cout << "Enter title: ";
  getline (cin, amovie.title);

  cout << "Enter year: ";
  cin >> amovie.year;
  cin.ignore();
  
  cout << "Enter director:";
  getline(cin, amovie.director);

  cout << "You entered: " << amovie.title;
  cout << " (" << amovie.year << ") by " << amovie.director << endl;
  return 0;
}


