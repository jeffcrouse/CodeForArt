#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(24);
    ofBackground(255,255,255);
    
    pos.x = ofGetWidth()/2.0;
    pos.y = ofGetHeight()/2.0;
    
    vel.x = ofRandom(-10, 10);
    vel.y = ofRandom(-10, 10);
    
    angle=0;
}

//--------------------------------------------------------------
void testApp::update(){
    pos += vel;
    if(pos.x > ofGetWidth()-100 || pos.x < 100)
        vel.x *= -1;
    if(pos.y > ofGetHeight()-100 || pos.y < 100)
        vel.y *= -1;
    
    
    angle = atan2(pos.y - mouseY, pos.x - mouseX) * (180 / PI) - 90;
    rotate += (angle-rotate)/10.0;
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(0,0,0);
    
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofRotateZ(rotate);
    ofTriangle(0, 0, -50, 100, 50, 100);
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