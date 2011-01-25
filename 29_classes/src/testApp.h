#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "Frog.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);

		// Frog = Class
		// pablo = an object of type (or Class) "Frog"
		//Frog pablo;
	
		vector<Frog> myFrogs;
	
		// int is the type
		// food_x is an int
		int food_x;
		int food_y;	
};

#endif
