#include "testApp.h"

/**
 - Draw a simple circle
 1. ofBackgroundHex
 2. ofSetCircleResolution
 2. ofSetColor
 3. ofCircle
 
 */


//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(24);
	ofSetWindowShape(640, 480);
    ofBackgroundHex(0xEFDC9E);
    
    // Try commenting this out
    ofSetCircleResolution(100);
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(24, 58, 117);
    ofCircle(100, 200, 50);
    
    ofSetColor(23, 142, 39);
    ofCircle(200, 200, 50);
    
    ofSetColor(142, 83, 23);
    ofCircle(300, 200, 50);
    
    ofSetColor(132, 84, 154);
    ofCircle(400, 200, 50);
    
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
