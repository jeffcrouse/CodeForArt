#include "testApp.h"



//--------------------------------------------------------------
void testApp::setup(){

	ofSetFrameRate(200);
	ofBackground(255, 255, 255);
	ofEnableSmoothing();
	
	radius = 20;
	pos.x = 30;
	pos.y = ofGetHeight()/2.0;
}

//--------------------------------------------------------------
void testApp::update(){

	if(click.x > pos.x) 
	{
		pos.x++;
	}
	
	if(click.y > pos.y)
	{
		pos.y++;
	}
	
	if(click.x < pos.x)
	{
		pos.x--;
	}
	
	if(click.y < pos.y) 
	{
		pos.y--;
	}
}

//--------------------------------------------------------------
void testApp::draw(){

	ofFill();
	ofSetColor(0, 0, 0);
	ofCircle(pos.x, pos.y, radius);
	
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
	click.x = x;
	click.y = y;
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

