#include "testApp.h"

/**
 *  What happens when you resize the window?
 *  How could we change this to make the circle resize *while* the window is being resized?
 */

int circleX;
int circleY;
int circleRadius;

//--------------------------------------------------------------
void testApp::setup(){
    
	ofSetFrameRate(24);
	ofSetWindowShape(640, 480);
    ofBackgroundHex(0xEFDC9E);
    ofSetCircleResolution(100);
    
    
	circleRadius = 200;
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
	ofSetColor(24, 58, 117);
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
	circleX = w / 2.0;
	circleY = h / 2.0;
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}