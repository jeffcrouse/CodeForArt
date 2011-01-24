#include <iostream>
#define NUM_GRAINS_SAND 50000
#define SPANISH
using namespace std;

int main()
{
  int numgrains;

#ifdef SPANISH
  cout << "¿Cuántos granos de arena en la playa?"; // i don't speak spanish :(
#else
  cout << "How many grains of sand are on the beach?";
#endif

  cin >> numgrains;
  if( numgrains == NUM_GRAINS_SAND ) {
     cout << "wrong!" << endl;
  } else {
     cout << "yep!" << endl;
  }
}