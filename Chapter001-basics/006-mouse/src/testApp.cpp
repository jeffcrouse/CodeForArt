#include "testApp.h"

/*
 - Draw a ball that follows the mouse
 - Make the ball follow only when the mouse is held down
 
 Things in this program
 1. mouseMoved
 2. mouseDragged
 3. mousePressed
 4. mouseReleased
 */


bool mouseIsDown;
bool mouseIsOver;
int ballX=0;
int ballY=0;

//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(24);
	ofSetWindowShape(640, 480);
	ofBackground(255, 255, 255);
	ofEnableSmoothing();
	
	//ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	
	if(mouseIsDown)
	{
		ofRect(10, 10, 500, 500);
	}
	
	
	if(mouseIsDown)
	{
		ofSetColor(0, 155, 155);
	}
	
    if(mouseIsOver)
	{
		ofSetColor(255, 0, 0);
	}
	else
	{
		ofSetColor(0, 0, 0);
	}
	
	
	ofNoFill();
	ofSetLineWidth(5);
	
	ofCircle(ballX, ballY, 20);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	if(ofDist(ballX, ballY, x, y) < 20)
    {
		mouseIsOver=true;
	}
	else
    {
		mouseIsOver=false;
	}
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	ballX = x;
	ballY = y;
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    mouseIsDown=true;
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    mouseIsDown=false;
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