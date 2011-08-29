#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(36);
	
	a.loc.x = ofGetWidth()/2;
	a.loc.y = ofGetHeight()/2;
	
	for(int i=0; i<10; i++) {
		Thing t;
		things.push_back( t );
	}
}

//--------------------------------------------------------------
void testApp::update(){
	
	for(int i=0; i<things.size(); i++) {
		// Calculate a force exerted by "attractor" on "thing"
		ofPoint f = a.calcGravForce(things[i]);
		// Apply that force to the thing
		things[i].applyForce(f);
		// Update the positions of both objects
		things[i].update();
	}
}

//--------------------------------------------------------------
void testApp::draw(){

	a.draw();
	for(int i=0; i<things.size(); i++) {
		things[i].draw();
	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	a.rollover(x, y);	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	a.drag(x, y);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	a.clicked(x, y);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	a.stopDragging();
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

