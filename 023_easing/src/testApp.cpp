#include "testApp.h"

/*************
 *	In this application:
 *	1. Ease the ball from one side to the other
 *	2. Add a "tail"
 *
 *************/

//--------------------------------------------------------------
void testApp::setup(){

	ofSetFrameRate(24);
	ofBackground(255, 255, 255);
	ofEnableSmoothing();
	
	radius = 20;
	pos.x = click.x = 30;
	pos.y = click.y = ofGetHeight()/2.0;
}

//--------------------------------------------------------------
void testApp::update(){
	
	// Calculate the distance from ideal to pos
	// click - pos
	
	// Add a portion of that distance to the position.
	
	ofPoint dist;
	dist.x = click.x - pos.x;
	dist.y = click.y - pos.y;
	
	pos.x += dist.x / 5.0;
	pos.y += dist.y / 5.0;
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
	click.x = x;
	click.y = y;
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

