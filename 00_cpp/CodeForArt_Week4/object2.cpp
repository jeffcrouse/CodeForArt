#include <iostream>
using namespace std;

//
// THE STRUCT WAY
//
struct sBicycle {
	string color;
	int speed;
};

void speedUp(sBicycle &bike) {
	bike.speed++;
}

//
// THE CLASS WAY
//
class cBicycle {
public:
	string color;
	int speed;
	void speedUp() {
		speed++;
	}
};


int main () {

	sBicycle myBike;
	myBike.color = "green";
	myBike.speed = 3;
	speedUp(myBike);
	cout << "The " << myBike.color << " bike is going " << myBike.speed << "mph" << endl;
	
	cBicycle yourBike;
	yourBike.color = "red";
	yourBike.speed = 12;
	yourBike.speedUp();
	cout << "The " << yourBike.color << " bike is going " << yourBike.speed << "mph" << endl;
}