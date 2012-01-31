#include "testApp.h"

/*************
 *	In this application:
 *	1. 
 *
 *
 ************/

//--------------------------------------------------------------
void testApp::setup(){

	ofSetFrameRate(24);
	ofBackground(255, 255, 255);
	ofEnableSmoothing();
	
	radius = 20;
	pos.x = ofGetWidth()/2.0;
	pos.y = 20;
	
	vel.x = 0;
	vel.y = 0;
	
	acceleration.x = 0;
	acceleration.y = .8;
}

//--------------------------------------------------------------
void testApp::update(){
	
	vel += acceleration;
	pos += vel;
	
	
	 // gravity
	if(pos.y >= ofGetHeight()-radius)
	{
		pos.y = ofGetHeight()-radius;
		vel.y *= -0.7;
	}
}

//--------------------------------------------------------------
void testApp::draw(){

	ofFill();
	ofSetColor(0, 0, 0);
	ofCircle(pos.x, pos.y, radius);
	
	// Shows velocity
	ofSetColor(255, 0, 0);
	ofLine(pos.x, pos.y, pos.x+vel.x, pos.y+vel.y);

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

