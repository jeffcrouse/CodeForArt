#include "testApp.h"

/*
 In this app:
 1. Putting variables in their proper place (testApp.h)
 
 */

float h=0;
int hx;
int hy;

float m=0;
int mx;
int my;

int origin_x = 320;	// We should use ofGetWidth 
int origin_y = 240;	// and ofGetHeight here



//--------------------------------------------------------------
void testApp::setup(){

	ofSetFrameRate(24);
	ofBackground(0, 0, 0);
	ofSetWindowShape(640, 480);
	ofSetColor(0xFFFFFF);
	
	

}

//--------------------------------------------------------------
void testApp::update(){

	// Increment our hour hand counter
	h += .01;
	
	hx = 40 * cos( h );
	hy = 40 * sin( h );
	
	// Increment the minute hand counter
	m += (.01 * 12);
	
	mx = 120 * cos( m );
	my = 120 * sin( m );
}

//--------------------------------------------------------------
void testApp::draw(){
	

	
	ofLine(origin_x, origin_y, origin_x+hx, origin_y+hy);
	ofLine(origin_x, origin_y, origin_x+mx, origin_y+my);
	
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

