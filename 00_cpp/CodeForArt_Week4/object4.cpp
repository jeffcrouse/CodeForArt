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

void beep(sBicycle &bike) {
	cout << "The " << bike.color << " bike beeps!" << endl;
}

struct sMountainBike : sBicycle {
	int numGears;
	int currentGear;
};

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
	void beep() {
		cout << "The " << color << " bike beeps!" << endl;
	}
};


class cMountainBike : cBicycle {
public:
	int numGears;
	int currentGear;
};

int main () {

	//
	// THE STRUCT WAY
	//
	sMountainBike myBike;
	myBike.color = "green";
	myBike.speed = 3;
	speedUp(myBike);
	cout << "The " << myBike.color << " bike is going " << myBike.speed << "mph" << endl;
	beep(myBike);
	

	//
	// THE CLASS WAY
	//	
	cMountainBike yourBike;
	yourBike.color = "red";
	yourBike.speed = 12;
	yourBike.speedUp();
	cout << "The " << yourBike.color << " bike is going " << yourBike.speed << "mph" << endl;
	yourBike.beep();
}