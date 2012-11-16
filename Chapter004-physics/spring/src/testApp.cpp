#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(24);
	
	
	loc.x = ofGetWidth()/2.0;
	loc.y = ofGetHeight()/2.0;
	
	origin.x = ofGetWidth()/2.0;
	origin.y = ofGetHeight()/2.0;
	
	radius = 40;
	dragging = false;
}

//--------------------------------------------------------------
void testApp::update(){
    
	if(!dragging)
	{
		velocity += (origin-loc);
		velocity *= .75;
		loc += velocity;
	}
}

//--------------------------------------------------------------
void testApp::draw(){
    
	ofNoFill();
	ofSetColor(0, 0, 0);
	ofCircle(loc.x, loc.y, radius);
	
	ofLine(origin.x, origin.y, loc.x, loc.y);
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
	if(dragging)
	{
		loc.x = x;
		loc.y = y;
	}
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	float d = ofDist(loc.x, loc.y, x, y);
	if(d < radius)
	{
		dragging = true;
	}
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    dragging = false;
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