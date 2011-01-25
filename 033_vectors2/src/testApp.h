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
	
	vector<float> x_pos;
	vector<float> y_pos;
	vector<float> radius; 
	vector<int> age;
	vector<float> x_velocity;
	vector<float> y_velocity;
	//vector<string> words;
	//vector<int> numbers;

};

#endif
