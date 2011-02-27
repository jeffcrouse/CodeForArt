#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofSetFrameRate(24);
	
	path.setInterpolation(OFX_MSA_SPLINE_CUBIC);
	
	path.push_back(ofxVec2f(0, 0));
	for (int i=0; i<5; i++)
	{
		path.push_back(ofxVec2f(ofRandomWidth(), ofRandomHeight()));
	}
	path.push_back(ofxVec2f(ofGetWidth(), ofGetHeight()));
	
	// start at 0
	pct=0;
}

//--------------------------------------------------------------
void testApp::update(){

	// cycle from 0->100, then reset to 0
	pct = (pct+1) % 100;
}

//--------------------------------------------------------------
void testApp::draw(){

	ofSetColor(255, 0, 0);
	path.drawRaw(5, 1);
	
	ofSetColor(0, 255, 0);
	ofNoFill();
	path.drawSmooth(100, 2, 1);
	
	
	ofPoint p = path.sampleAt((float)pct/100.0);
	
	ofFill();
	ofSetColor(0, 0, 255);
	ofCircle(p.x, p.y, 10);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

	if(path.getInterpolation()==OFX_MSA_SPLINE_LINEAR)
	{
		path.setInterpolation(OFX_MSA_SPLINE_CUBIC);
	}
	else {
		path.setInterpolation(OFX_MSA_SPLINE_LINEAR);
	}

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

