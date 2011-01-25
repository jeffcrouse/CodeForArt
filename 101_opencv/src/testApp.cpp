#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	cam.initGrabber(320, 240);
	
	colorImg.allocate(320, 240);
	grayImg.allocate(320, 240);
}

//--------------------------------------------------------------
void testApp::update(){
	
	cam.grabFrame();
	
	if(cam.isFrameNew()) {
		
		colorImg.setFromPixels(cam.getPixels(), 320, 240);
		colorImg.convertRgbToHsv();
		
		unsigned char* camPix = colorImg.getPixels();
		unsigned char* grayPix = grayImg.getPixels();
		
		int j = 0;
		for(int i=0; i<320*240*3; i+=3)
		{
			int h = camPix[i+0];
			int s = camPix[i+1];
			int v = camPix[i+2];
			
			int target_h = (59.0/360.0) * 255;
			int h_diff = abs(h - target_h);
			
			if(h_diff < 20 && s/255.0 > .5 && v/255.0 > .5) {
				grayPix[j] = 255;
			} else {
				grayPix[j] = 0;
			}
			j++;
		}
		
		grayImg.setFromPixels(grayPix, 320, 240);
		
		
	}
}

//--------------------------------------------------------------
void testApp::draw(){

	cam.draw(20, 20);
	colorImg.draw(350, 20);
	grayImg.draw(680, 20);
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

