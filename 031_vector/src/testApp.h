#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"

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

		// When declaring a vector, you might expect to see something like:
		// vector circles;
		// So what is the <ofPoint> and <int>?
		// This tells c++ what kind of variables you are going to put into the vector.
		vector<ofPoint>circles;
		vector<int>radii;
};

#endif
