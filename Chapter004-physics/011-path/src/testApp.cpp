#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(36);
	ofBackground(255, 255, 255);
	
	newPath();
	
	boid0 = new Boid(ofPoint(0, ofGetHeight()/2), 3.0, 0.5);
	boid1 = new Boid(ofPoint(0, ofGetHeight()/2), 5.0, 1.0);
}

//--------------------------------------------------------------
void testApp::update(){
	// The boids follow the path
	boid0->follow(path);
	boid1->follow(path);
	// Call the generic run method (update, borders, display, etc.)
	boid0->update();
	boid1->update();
	
}

//--------------------------------------------------------------
void testApp::draw(){
    
    path->draw();
	boid0->draw();
	boid1->draw();
    
	// Instructions
	ofDrawBitmapString("Hit space bar to toggle debugging lines.\nClick the mouse to generate a new path.",10,ofGetHeight()-30);

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
	newPath();
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

//--------------------------------------------------------------
void testApp::newPath() {
	// A path is a series of connected points
	// A more sophisticated path might be a curve
	path = new Path();
	path->addPoint(0,ofGetHeight()/2);
	path->addPoint(ofRandom(0,ofGetWidth()/2), ofRandomHeight());
	path->addPoint(ofRandom(ofGetWidth()/2, ofGetWidth()), ofRandomHeight());
	path->addPoint(ofGetWidth(),ofGetHeight()/2);
}

