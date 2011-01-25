#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(36);


}

//--------------------------------------------------------------
void testApp::update(){
	
	// Calculate a force exerted by "attractor" on "thing"
	ofPoint f = a.calcGravForce(t);
	// Apply that force to the thing
	t.applyForce(f);
	// Update the positions of both objects
	t.update();
}

//--------------------------------------------------------------
void testApp::draw(){

	a.draw();
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

