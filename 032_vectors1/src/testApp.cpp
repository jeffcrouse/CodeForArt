#include "testApp.h"

/*
 In this app:
 1. Introducing: vector
 */

//--------------------------------------------------------------
void testApp::setup(){

	ofSetFrameRate(24);
	ofBackground(255, 255, 255);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

	ofSetColor(0, 0, 0);
	ofBeginShape();
	
	// Why do we use less-than here?
	for(int i=0; i<xs.size(); i++)
	{
		ofVertex(xs[i], ys[i]);
	}
	
	ofEndShape(true);
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
	//cout << "Inserting " << x << ", " << y << endl;
	//xs.push_back( x );
	//ys.push_back( y );
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

	cout << "Inserting " << x << ", " << y << endl;
	xs.push_back( x );
	ys.push_back( y );
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

