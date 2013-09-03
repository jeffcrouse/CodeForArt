#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    float anchorX, anchorY;             // The position of the bottom circle
    float dist, angle;                  // We will use dist and angle (in radians) to determine the position of the top circle
    float targetAngle;                  // This is the angle where we want the top circle to be (the dist will always stay the same)
    float topX, topY, topRadius;        // Every frame, we will use the dist and angle to calculate the x,y position of the top
    bool dragging;                      // Are we dragging the circle?
    
    
};
