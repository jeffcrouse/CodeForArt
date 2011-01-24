#include "testApp.h"

/*
 In this program I show examples of how to use "vectors",
 which are very similar to arrays.
 Check out the "testApp.h" file.
 */

//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(24);
	ofBackground(255,255,255);
	ofSetWindowShape(640, 480);
}

//--------------------------------------------------------------
void testApp::update(){
	
	// In this app, we have two "vectors", which are just like arrays
	// Each frame, we add a point to one array and an integer (radius) to another

	// Make a random coordinate
	float x=ofRandom(0, ofGetWidth());
	float y=ofRandom(0, ofGetHeight());
	float radius = ofRandom(10, 30);

	// Insert the point at the end of the circles vector
	circles.push_back( ofPoint(x,y) );

	// Insert the radius at the back of the radii vector
	radii.push_back( radius );
}

//--------------------------------------------------------------
void testApp::draw(){

	ofSetColor(0,0,0);

	// Loop through the entire vector and draw a circle
	// circles.size() will give you the number of items in the array
	for(int i=0; i<circles.size(); i++)
	{
		ofCircle(circles[i].x, circles[i].y, radii[i]);
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

