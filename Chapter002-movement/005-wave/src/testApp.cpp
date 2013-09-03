#include "testApp.h"

/*
 *	In this application:
 *	1. Make the ball move in a wave
 *
 *  Assignment
 *  1.  Make the ball cycle back to the left side of the screen
 */

//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(60);
	ofBackground(255, 255, 255);
	ofEnableSmoothing();
	
	radius = 20;
	pos.x = radius;
	pos.y = ofGetHeight()/2.0;
    
	i=0;
}

//--------------------------------------------------------------
void testApp::update(){
    
	float wavelength = 100.0;
	float offset = (ofGetHeight()/2.0);
	float amplitude = 300;
	
	i++;
	
	// Move X along
	// Y = Asin(t/wavelength) + b;
	
	pos.x += 2;
	pos.y = offset + sin(i / wavelength) * amplitude;
}

//--------------------------------------------------------------
void testApp::draw(){
    
	ofFill();
	ofSetColor(0, 0, 0);
	ofCircle(pos.x, pos.y, radius);
	
	string str = ofToString(pos.x, 0)+", "+ofToString(pos.y, 2);
	ofDrawBitmapString(str, pos.x+radius+5, pos.y+5);
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

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}