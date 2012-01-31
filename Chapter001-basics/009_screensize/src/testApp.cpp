#include "testApp.h"


int circleX;
int circleY;
int circleRadius;

//--------------------------------------------------------------
void testApp::setup(){

	ofSetFrameRate(24);
	ofBackground(255,255,255);
	
	ofSetWindowShape(400, 400);
	

	circleRadius = 200;
	
	ofEnableSmoothing();
	
	ofSetCircleResolution(100);
	
}

//--------------------------------------------------------------
void testApp::update(){

	circleX = ofGetWidth() / 2.0;
	circleY = ofGetHeight() / 2.0;
	
}

//--------------------------------------------------------------
void testApp::draw(){

	ofSetColor(255, 0, 0);
	ofCircle(circleX, circleY, circleRadius);
	
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

