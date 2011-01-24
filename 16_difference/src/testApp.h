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

	
		ofImage img1;
		ofImage img2;
		ofImage result;
	
		int mode;
		int numPix;
		unsigned char* img1Pix;
		unsigned char* img2Pix; // an array of 0-255 values 
								// length = width * height * 3
	
		
};

#endif
