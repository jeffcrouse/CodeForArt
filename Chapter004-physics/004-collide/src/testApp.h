#pragma once

#include "ofMain.h"

#define NUM_PARTICLES 500

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
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
        ofPoint acc;
        float friction;
    
        ofPoint pos[NUM_PARTICLES];
        ofPoint vel[NUM_PARTICLES];
        float radius[NUM_PARTICLES];
        ofColor color[NUM_PARTICLES];
};
