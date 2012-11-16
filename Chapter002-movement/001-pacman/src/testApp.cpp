#include "testApp.h"

/**
 1. preprocessor statement (#define)
 2. ofSetVerticalSync
 3. mod operator (%)
 */

//--------------------------------------------------------------
void testApp::setup(){
    
	ofSetFrameRate(48);
	ofBackground(0,0,0);
    ofSetCircleResolution( 50 );
    ofSetVerticalSync(true);

	
	pac_x = INITIAL_X;
	pac_y = ofGetHeight()/2.0;
	mouth=40;
}

//--------------------------------------------------------------
void testApp::update(){
    
	// Introducing: the mod (remainder) operator!
	mouth = (mouth+5) % 50;
	
	// 55 % 50 = 5;
	// 80 % 50 = 30
	
	// Move pacman forward!
	pac_x += 10;
	
	// But if he is completely gone, reset him.
	if(pac_x>ofGetWidth()+100)
	{
		pac_x = INITIAL_X;
	}
}

//--------------------------------------------------------------
void testApp::draw(){
    
	// Draw some pacpills
	ofSetColor(255, 255, 255);
	for(int i=0; i<ofGetWidth(); i+=50)
	{
		if(i>pac_x || i <pac_x-400)
		{
			ofCircle(i, ofGetHeight()/2., 10);
		}
	}
	
	// Draw the yellow circle
	ofSetColor(255, 255, 0);
	ofCircle(pac_x, pac_y, 100);
	
	// Draw his eye and mouth.
	// Notice how I calculate the positions...
	ofSetColor(0, 0, 0);
	ofCircle(pac_x+30, pac_y-50, 15);
	ofTriangle(pac_x, pac_y, pac_x+100, pac_y-mouth, pac_x+100, pac_y+mouth);
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