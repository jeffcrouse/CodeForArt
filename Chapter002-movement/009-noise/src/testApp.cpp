#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    
    
    for(int i=0; i<20; i++) {
        p[i].x = ofMap(i, 0, 20, 30, ofGetWidth());
        p[i].y = ofGetHeight() / 2.0;
        offset[i] = 0;
    }
}

//--------------------------------------------------------------
void testApp::update(){
    for(int i=0; i<20; i++) {
        float x = ofGetFrameNum() / 50.0;
        float y = i / 20.0;
        offset[i] = ofSignedNoise(x, y) * 200;
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0, 0, 0);
    ofSetColor(255, 255, 255);
    
    for(int i=0; i<20; i++) {
        ofCircle(p[i].x, p[i].y + offset[i], 20);
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

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}