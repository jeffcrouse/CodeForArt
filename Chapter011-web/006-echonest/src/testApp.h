#pragma once

#include "ofMain.h"
#include "ofxJSONElement.h"
#include <hashlibpp.h>

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
		
        ofTrueTypeFont font;
        ofSoundPlayer songPlayer;
        ofxJSONElement profile, analysis;
    
        string artist, title, analysis_url;
        bool complete;
    
        int bar, beat, section, segment, tatum;
        int barA, beatA, sectionA, segmentA, tatumA;
};
