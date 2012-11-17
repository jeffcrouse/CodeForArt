#include "testApp.h"



//--------------------------------------------------------------
void testApp::setup(){
    
    glEnable(GL_DEPTH_TEST);
}

//--------------------------------------------------------------
void testApp::update(){

    rotate.x = cos(ofGetElapsedTimef() / M_TWO_PI) * 360;
    rotate.y = sin(ofGetElapsedTimef() / M_TWO_PI) * 360;
    rotate.z = sin(ofGetElapsedTimef() / M_TWO_PI) * 360;
}

//--------------------------------------------------------------
void testApp::draw(){

    ofPushMatrix();
    ofTranslate(ofGetWidth()/2.0, ofGetHeight()/2.0);
    ofRotateX(rotate.x);
    ofRotateY(rotate.y);
    ofRotateZ(rotate.z);
    {
        ofFill();
        ofSetColor(100, 200, 100);
        ofBox(0, 0, 200);
        
        ofNoFill();
        ofSetColor(0);
        ofBox(0, 0, 200);
    }
    ofPopMatrix();
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