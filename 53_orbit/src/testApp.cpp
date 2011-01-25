#include "testApp.h"

/*************
 *	In this application: 
 *	1. Make the ball orbit around the mouse
 *
 */

//--------------------------------------------------------------
void testApp::setup(){

	ofSetFrameRate(24);
	ofBackground(255, 255, 255);
	ofEnableSmoothing();
	
	radius = 20;
	pos.x = 30;
	pos.y = ofGetHeight()/2.0;
}

//--------------------------------------------------------------
void testApp::update(){
	float wavelength = 10.0;
	float amplitude = 200.0;

	
	pos.x = amplitude * cos(ofGetFrameNum() / wavelength ) + mouseX;
	pos.y = amplitude * sin(ofGetFrameNum() / wavelength ) + mouseY;
}

//--------------------------------------------------------------
void testApp::draw(){

	ofFill();
	ofSetColor(0, 0, 0);
	ofCircle(pos.x, pos.y, radius);
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

