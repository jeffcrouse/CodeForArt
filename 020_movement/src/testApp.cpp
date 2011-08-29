#include "testApp.h"


/*
 IN THIS APP:
 1. Moving an element from one spot to another
 2. Moving an element smoothly (without diagonal/straight line crap)
 3. Using ofPoint to represent positions
 
 
 ASSIGNMENT
 1. Use matrix transformations to move the ball.
 2. Change the ball to something
 */

//--------------------------------------------------------------
void testApp::setup(){

	ofSetFrameRate(60);
	ofBackground(255, 255, 255);
	ofEnableSmoothing();
	
	radius =50;
	
	pos.x = click.x = 0;
	pos.y = click.y = ofGetHeight() / 2.0;
	
}

//--------------------------------------------------------------
void testApp::update(){

	ofPoint diff = click - pos;
	ofPoint change = diff / 30.0;

	pos += change;

	
	
	/*
	float x_diff = click_x - pos_x;
	float y_diff = click_y - pos_y;
	
	float x_change = x_diff / 30.0;
	float y_change = y_diff / 30.0;
	
	pos_x += x_change;
	pos_y += y_change;
	 */
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

