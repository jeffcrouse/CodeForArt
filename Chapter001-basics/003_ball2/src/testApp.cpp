#include "testApp.h"

/*
 - Draw a ball that moves on its own
 - Draw a ball that bounces off of the sides of the screen
 
 Things in this program
 1. if statement
 */

float ballX=0;
float ballY=0;
float radius=20;

float xSpeed;	
float ySpeed;	

float xAccel;
float yAccel;

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetFrameRate(60);
	//ofSetWindowShape(640, 480);
	ofBackground(255, 255, 255);
	ofEnableSmoothing();
	
	ballX = ofGetWidth()/2;
	ballY = ofGetHeight()/2;
	
	xSpeed = ofRandom(-10, 10);
	ySpeed = ofRandom(-10, 10);
	
	xAccel = 0;
	yAccel = 3;
	
	ofSetCircleResolution(60);
}

//--------------------------------------------------------------
void testApp::update(){

	xSpeed += xAccel;
	ySpeed += yAccel;
	
	ballX += xSpeed;
	ballY += ySpeed;
	
	if(ballX > ofGetWidth()-radius) {
		xSpeed *= -1;
		ballX = ofGetWidth()-radius;
	}
	if(ballY > ofGetHeight()-radius) {
		ySpeed *= -1;
		ballY = ofGetHeight()-radius;
	}
	if(ballX < radius) {
		xSpeed *= -1;
		ballX = radius;
	}
	if(ballY < radius) {
		ySpeed *= -1;
		ballY = radius;
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofSetColor(255, 0, 0);
	ofNoFill();
	ofSetLineWidth(5);
	
	ofCircle(ballX, ballY, radius);
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

