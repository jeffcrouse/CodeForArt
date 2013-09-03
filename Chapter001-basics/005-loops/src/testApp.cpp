#include "testApp.h"

/**
 Things to notice:
 - Notice that we use loops to draw several circles
 - You can't achieve motion using only a loop in draw
 */

//--------------------------------------------------------------
void testApp::setup(){
    
	ofSetFrameRate(24);
	ofSetWindowShape(640, 480);
    ofBackgroundHex(0xEFDC9E);
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    // Loop 1 - blue
    ofFill();
    ofSetColor(24, 58, 117);
    for(int i=0; i<32; i++)
    {
        ofCircle(20+i*20, 10, 10);
    }
    
    
    // Loop 2 - green
    ofSetColor(23, 142, 39);
    for(int x=10; x<ofGetWidth(); x+=20)
    {
        ofCircle(x, ofGetHeight()-20, 10);
    }
    
    
    // Loop 3 - brown
    ofSetColor(142, 83, 23);
    float centerX = ofGetWidth()/2.0;
    float centerY = ofGetHeight()/2.0;
    for(float a=0; a<360; a+=15)
    {
        float t = ofDegToRad(a);
        float x = centerX + cos(t) * 100;
        float y = centerY + sin(t) * 100;
        ofCircle(x, y, 10);
    }
    
    
    // Loop 4 - purple
    ofNoFill();
    ofSetColor(132, 84, 154);
    ofBeginShape();
    for(int a=0; a<360; a+=15)
    {
        float t = ofDegToRad(a);
        float r = (a % 10==0) ? 100 : 200;
        float x = centerX + cos(t) * r;
        float y = centerY + sin(t) * r;
        ofVertex(x, y);
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
