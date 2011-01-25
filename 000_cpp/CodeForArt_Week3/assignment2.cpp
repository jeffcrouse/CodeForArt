#include <iostream> 
using namespace std;

int main()
{

	int x = 0;
	int y = 4;
	char input;
	bool didMove = true;
	
	string rooms[10][6];
	
	/***********
	0000000000
	0000000000
	0000000000
	000X000000
	XXXX000000
	0000000000
	************/
	
	
	// Make up all of your rooms here.
	rooms[0][4] = "You are in the hallway.";
	rooms[1][4] = "You are on the far side of the hallway.";
	rooms[2][4] = "Still in the hallway.  Wow, this is a long hallway.";
	rooms[3][4] = "You are now at the end of the hallway.  To the north is the living room.";
	rooms[3][3] = "The Living Room.\nThis room is all Ikea.";

	cout << "Welcome to my house" << endl;
	do {
		if(didMove) {
			cout << rooms[x][y] << endl;
			didMove = false;
		}
		
		cout << "what do you want to do now? (n, s, e, w): " << endl;
		cin >> input;
		
		int tempx = x;
		int tempy = y;
		
		switch(input) {
			case 'n':
				tempy--;
				break;
			case 's':
				tempy++;
				break;
			case 'e':
				tempx++;
				break;
			case 'w':
				tempx--;
				break;
		}
		
		if(x<0 || y<0 || rooms[tempx][tempy].empty()) {
			cout << "You can't go that way." << endl;
		} else {
			x = tempx;
			y = tempy;
			didMove = true;
		}
	} while(true);
}
