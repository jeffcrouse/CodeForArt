#include <iostream>
#include <time.h>
using namespace std;


int main ()
{
  time_t seconds;

  seconds = time(NULL);
  cout << seconds/3600 << " hours since January 1, 1970" << endl;

}