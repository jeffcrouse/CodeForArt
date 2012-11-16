#include "testApp.h"

/*

 1. The update() function
 2. Using & changing variables to make things move
 3. if statement
 4. How can you make it go faster?
 
*/


float circleX;
float circleY;

//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(60);
	ofSetWindowShape(640, 480);
    ofBackgroundHex(0xEFDC9E);
    
    circleX = 20;
    circleY = 240;
}

//--------------------------------------------------------------
void testApp::update(){
    
    circleX++;
    // "++" same as:
    // circleX = circleX+1;
    
    if(circleX > 640)
    {
        circleX = 0;
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(24, 58, 117);
    ofCircle(circleX, circleY, 20);
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