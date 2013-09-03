#include "testApp.h"

/**
 pos1 actually orbits the mouse
 pos2 tries to approach pos1
 */

//--------------------------------------------------------------
void testApp::setup(){
    
	ofSetFrameRate(24);
	ofBackground(255, 255, 255);
	
	pos1.x = pos2.x = 30;
	pos1.y = pos2.x = ofGetHeight()/2.0;
}

//--------------------------------------------------------------
void testApp::update(){
	float wavelength = 10.0;
	float amplitude = 200.0;
    
	pos1.x = amplitude * cos(ofGetFrameNum() / wavelength ) + mouseX;
	pos1.y = amplitude * sin(ofGetFrameNum() / wavelength ) + mouseY;
    
    pos2 += (pos1-pos2) / 10.0;
}

//--------------------------------------------------------------
void testApp::draw(){
    
	ofFill();
    ofSetColor(100);
    ofCircle(pos1.x, pos1.y, 5);
    
	ofSetColor(0, 0, 0);
	ofCircle(pos2.x, pos2.y, 20);
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