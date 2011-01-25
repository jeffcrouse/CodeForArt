#ifndef _TEST_APP
#define _TEST_APP


#define OF_ADDON_USING_OFXOPENCV

#include "ofMain.h"
#include "ofxOpenCv.h"


//this is not part of the addon yet
//so include it seperately

#include "ofxCvHaarFinder.h"

class testApp : public ofSimpleApp{

	public:

		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased();

      
		ofVideoGrabber 		vidGrabber;
        
        ofxCvColorImage			colorImg;
        
        ofxCvGrayscaleImage 	grayImage;
		
		ofxCvHaarFinder			haarFinder;

		
		
};

#endif
