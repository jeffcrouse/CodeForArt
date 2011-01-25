#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofSetFrameRate(24);
	
	attractor.x = ofGetWidth()/2.0;
	attractor.y = ofGetHeight()/2.0;
	mass = 50;
}

//--------------------------------------------------------------
void testApp::update(){
	
	ofPoint force;
	
	// Direction
	ofPoint dir = attractor - t.loc;
	
	// Distance
	float d = ofDist(t.loc.x, t.loc.y, attractor.x, attractor.y);
	
	// Normalize direction vector
	ofPoint normalizedDir = dir / d;
	
	// Multiply direction by mass
	force = normalizedDir * (mass / 100);
	
	t.applyForce(force);
	
	t.update();
	
}

//--------------------------------------------------------------
void testApp::draw(){

	ofSetColor(0, 0, 0);
	ofCircle(attractor.x, attractor.y, mass);
	
	
	t.draw();
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
	attractor.x = x;
	attractor.y = y;
	
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

