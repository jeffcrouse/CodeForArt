#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    ofBackgroundHex(0xEFDC9E);
    
    
    for(int i=0; i<NUM_PARTICLES; i++)
    {
        radius[i] = ofRandom(10, 20);
        x_pos[i] = ofRandom(radius[i], ofGetWidth()-radius[i]);
        y_pos[i] = ofRandom(radius[i], ofGetHeight()-radius[i]);
        x_vel[i] = ofRandom(-100, 100);
        y_vel[i] = ofRandom(-100, 100);
        color[i] = ofRandom(0xFFFFFF);
    }
}

//--------------------------------------------------------------
void testApp::update(){
    ofSetWindowTitle("fps="+ofToString(ofGetFrameRate()));
    
    for(int i=0; i<NUM_PARTICLES; i++)
    {
        x_pos[i] += ofGetLastFrameTime() * x_vel[i];
        y_pos[i] += ofGetLastFrameTime() * y_vel[i];
        
        // bounce
        if(x_pos[i] > ofGetWidth()-radius[i]) {
            x_pos[i] = ofGetWidth()-radius[i];
            x_vel[i] *= -1;
        }
        if(x_pos[i] < radius[i]) {
            x_pos[i] = radius[i];
            x_vel[i] *= -1;
        }
        if(y_pos[i] > ofGetHeight()-radius[i]) {
            y_pos[i] = ofGetHeight()-radius[i];
            y_vel[i] *= -1;
        }
        if(y_pos[i] < radius[i]) {
            y_pos[i] = radius[i];
            y_vel[i] *= -1;
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for(int i=0; i<NUM_PARTICLES; i++)
    {
        ofSetHexColor(color[i]);
        ofCircle(x_pos[i], y_pos[i], radius[i]);
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
