#include <iostream>
using namespace std;

struct sBicycle {
   string color;
   int speed;
};

class cBicycle {
public:
   string color;
   int speed;

};


int main () {

	sBicycle myBike;
	myBike.color = "green";
	myBike.speed = 3;
	cout << "The " << myBike.color << " bike is going " << myBike.speed << "mph" << endl;
	
	cBicycle yourBike;
	yourBike.color = "red";
	yourBike.speed = 12;
	cout << "The " << yourBike.color << " bike is going " << yourBike.speed << "mph" << endl;
}