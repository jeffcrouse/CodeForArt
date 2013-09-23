#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(24);
    ofBackgroundHex(0xEFDC9E);
    
    
    for(int i=0; i<NUM_PARTICLES; i++)
    {
        radius[i] = ofRandom(10, 20);
        pos[i].x = ofRandom(radius[i], ofGetWidth()-radius[i]);
        pos[i].y = ofRandom(radius[i], ofGetHeight()-radius[i]);
        vel[i].x = ofRandom(-100, 100);
        vel[i].y = ofRandom(-100, 100);
        color[i].setHsb(ofRandom(255), 200, 200);
    }
}

//--------------------------------------------------------------
void testApp::update(){
    for(int i=0; i<NUM_PARTICLES; i++)
    {
        pos[i] += ofGetLastFrameTime() * vel[i];
        
        // bounce
        if(pos[i].x > ofGetWidth()-radius[i]) {
            pos[i].x = ofGetWidth()-radius[i];
            vel[i].x *= -1;
        }
        if(pos[i].x < radius[i]) {
            pos[i].x = radius[i];
            vel[i].x *= -1;
        }
        if(pos[i].y > ofGetHeight()-radius[i]) {
            pos[i].y = ofGetHeight()-radius[i];
            vel[i].y *= -1;
        }
        if(pos[i].y < radius[i]) {
            pos[i].y = radius[i];
            vel[i].y *= -1;
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    for(int i=0; i<NUM_PARTICLES; i++)
    {
        ofSetColor(color[i]);
        ofCircle(pos[i], radius[i]);
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
