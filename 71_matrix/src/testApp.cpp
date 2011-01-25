#include "testApp.h"

/*
 In this app: Move the frogger around the screen
 1. ofPushMatrix
 2. ofPopMatrix
 3. ofTranslate
 4. ofScale
 
 Exercise: 
	- Create pacman-style screen boundaries
	- Uncomment #define MOVE_DISTANCE in the header file and use it to move the frog
 */


//--------------------------------------------------------------
void testApp::setup(){

	ofSetFrameRate(24);
	ofBackground(255,255,255);
	ofSetWindowShape(640, 480);

	
	x = 320;
	y = 380;
}

//--------------------------------------------------------------
void testApp::update(){


	
}

//--------------------------------------------------------------
void testApp::draw(){

	ofSetColor(0, 0, 0);
	string msg = "x=" + ofToString(x) + " y=" + ofToString(y);
	ofDrawBitmapString(msg, 10, 20);
	
	
	drawFrog(x, y);
	

	if(y>ofGetHeight()-20)
	{
		drawFrog(x, ofGetHeight()-y-20);
	}
}

void testApp::drawFrog(int x, int y) {
	
	ofPushMatrix();
	ofTranslate(x, y);
	ofScale(2, 2, 2);
	
	// Draw frog body
	ofSetColor(32, 219, 36);
	ofBeginShape();
	ofVertex(9, 1);
	ofVertex(13, 1);
	ofVertex(14, 4);
	ofVertex(17, 6);
	ofVertex(18, 5);
	ofVertex(18, 1);
	ofVertex(21, 3);
	ofVertex(19, 4);
	ofVertex(19, 8);
	ofVertex(16, 7);
	ofVertex(19, 9);
	ofVertex(20, 10);
	ofVertex(21, 14);
	ofVertex(18, 15);
	ofVertex(18, 11);
	ofVertex(15, 10);
	ofVertex(13, 13);
	ofVertex(8, 13);
	ofVertex(7, 11);
	ofVertex(5, 10);
	ofVertex(4, 15);
	ofVertex(1, 13);
	ofVertex(3, 11);
	ofVertex(4, 8);
	ofVertex(6, 9);
	ofVertex(6, 7);
	ofVertex(3, 7);
	ofVertex(3, 4);
	ofVertex(1, 3);
	ofVertex(5, 1);
	ofVertex(4, 6);
	ofVertex(8, 4);
	ofVertex(9, 1);
	ofEndShape();
	
	// Draw yellow spot on back
	ofSetColor(248, 235, 21);
	ofBeginShape();
	ofVertex(10, 3);
	ofVertex(12, 3);
	ofVertex(14, 11);
	ofVertex(9, 11);
	ofVertex(14, 11);
	ofVertex(8, 5);
	ofVertex(9, 3);
	ofEndShape();
	
	// Draw eyes
	ofSetColor(253, 3, 217);
	ofCircle(7, 3, 2);
	ofCircle(15, 3, 2);	
	
	ofPopMatrix();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

	if(key==OF_KEY_UP)
	{
		y-=10;
		if(y < -20)
		{
			y= ofGetHeight()-10;
		}
	}
	if(key==OF_KEY_DOWN)
	{
		y+=10;
		if(y > ofGetHeight())
		{
			y= 0;
		}
	}
	if(key==OF_KEY_LEFT)
	{
		x-=10;
	}
	if(key==OF_KEY_RIGHT)
	{
		x+=10;
	}
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

