#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(24);
	ofSetWindowShape(640, 480);
    ofBackgroundHex(0xEFDC9E);
	
    radius = 20;
    pos.set(ofGetWidth()/2.0, 20);
    vel.set(0, 0);
	acc.set(0, 900); // circle accelerates at 900 pixels/second
}

//--------------------------------------------------------------
void testApp::update(){
    vel += acc * ofGetLastFrameTime();
    pos += vel * ofGetLastFrameTime();
    
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
    ofSetColor(24, 58, 117);
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

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
