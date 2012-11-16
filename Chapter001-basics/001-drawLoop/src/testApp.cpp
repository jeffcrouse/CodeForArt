#include "testApp.h"

/*
 Things in this program
 1. Comments - 2 different kinds
 2. setup, update, draw, keyPressed, keyReleased
 3. cout -- prints to console (how to find the console)
 4. ofSetWindowShape
 5. ofBackground
 6. ofSetFrameRate
 7. ofGetFrameNum
 8. ofToggleFullscreen
 */


//--------------------------------------------------------------
// Stuff in here runs before the window shows up -- before any drawing happens.
void testApp::setup(){
	cout << "setup was called\n";
	
	ofSetWindowShape(640, 480);
	ofBackground(255,255,255);
	ofSetFrameRate(2); // set very low just to illustrate the draw loop.  Typically you'd want 24, 30, 60, etc
}

//--------------------------------------------------------------
// Stuff in here happens once every frame, right before draw()
void testApp::update(){
    cout << "update was called\n";
	
}

//--------------------------------------------------------------
// Stuff in here happens once every frame, right after update()
void testApp::draw(){
	cout << "draw was called" << endl;
    
    cout << "frame number = " << ofGetFrameNum() << endl;
    cout << "fps = " << ofGetFrameRate() << endl;
}

//--------------------------------------------------------------
// Stuff in here happens when a key is pressed down.  It might be held down!
void testApp::keyPressed(int key){
	cout << "keyPressed was called\n";
	
	
}

//--------------------------------------------------------------
// This gets called when a key is released.  Use this for most keyboard interaction.
void testApp::keyReleased(int key){
	cout << "keyReleased was called\n";
	
	ofToggleFullscreen();
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