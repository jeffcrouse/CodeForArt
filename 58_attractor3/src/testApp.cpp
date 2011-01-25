#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(36);
	doCapture = false;
	framenum = 1;
	
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
	capture();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	if(key=='c') doCapture = !doCapture;
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

//--------------------------------------------------------------
void testApp::capture() {
	if(doCapture && ofGetFrameNum() % 4 == 0)
	{
		char fin[255];
		sprintf(fin, "frame%05d.png", framenum++);
		ofSaveScreen(fin);
	}
}
