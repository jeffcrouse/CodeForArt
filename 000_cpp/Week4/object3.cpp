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


int main () {

	//
	// THE STRUCT WAY
	//
	sBicycle myBike;
	myBike.color = "green";
	myBike.speed = 3;
	speedUp(myBike);
	cout << "The " << myBike.color << " bike is going " << myBike.speed << "mph" << endl;
	beep(myBike);
	

	//
	// THE CLASS WAY
	//	
	cBicycle yourBike;
	yourBike.color = "red";
	yourBike.speed = 12;
	yourBike.speedUp();
	cout << "The " << yourBike.color << " bike is going " << yourBike.speed << "mph" << endl;
	yourBike.beep();
}