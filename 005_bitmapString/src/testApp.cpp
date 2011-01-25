#include "testApp.h"

/*
 In this app:
 1. ofDrawBitmapString()
 2. variables: int, float, string
	- integer math vs floating point math
 3. functions: arguments, return
 4. loops (for, while)
 5. comparison operators (>, <, >=, <=, ==)
 */

string msg;

//--------------------------------------------------------------
void testApp::setup(){

	ofBackground(0, 0, 0);
	ofSetFrameRate(24);
	ofSetWindowShape(640, 480);
	ofSetColor(255, 255, 255);
	
	msg = "Hello, World!";
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	
	msg = "Frame: " + ofToString( ofGetFrameNum() );
	ofDrawBitmapString(msg, ofGetWidth()/2.0, ofGetHeight()/2.0);
	
	
	for(int y=0; y<ofGetHeight(); y+=14)
	{
		ofDrawBitmapString(msg, 10, y);
	}
	
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

