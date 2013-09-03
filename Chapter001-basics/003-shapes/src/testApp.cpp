#include "testApp.h"


/*
 - Draw a bunch of shapes of different colors
 
 Things in this program
 1. int, float
 3. ofSetColor
 4. ofCircle
 5. ofFill vs ofNoFill
 5. ofRectangle
 6. ofLine
 7. ofBeginShape, ofVertex, ofEndShape
 */


//--------------------------------------------------------------
void testApp::setup(){
	ofSetWindowShape(640, 480);
	ofBackground(255, 255, 255);
	ofSetFrameRate(24);
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
	
    ofFill();
	ofSetColor(0, 0, 255);
	ofCircle(320, 240, 20);
    
	
	ofNoFill();
	
	
	ofSetColor(255, 0, 0);
	ofCircle(320, 100, 20);
	
	
	
	ofRect(10, 10, 40, 50);
	
	
	ofSetColor(0, 255, 0);
	ofLine(320, 240, 320, 100);
	
	
	ofBeginShape();
    ofVertex(20, 20);
    ofVertex(200, 20);
    ofVertex(200, 400);
	ofEndShape(true);
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
