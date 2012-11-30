#pragma once

#include "ofMain.h"
#include "aubioAnalyzer.h"


#define BUFFER_SIZE 256

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
        void audioIn(float * input, int bufferSize, int nChannels);
        
        float pitch;
        
        // Object for fetching sound
        ofSoundStream soundStream;
        
        // buffers
        float left[BUFFER_SIZE];
        float right[BUFFER_SIZE];
        
        // can analyze one channel of sound
        aubioAnalyzer AAleft;
        aubioAnalyzer AAright;
};
