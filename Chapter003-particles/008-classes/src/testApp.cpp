#include "testApp.h"

bool shouldRemove(Particle& p) {
    return p.color.a < 10;
}

//--------------------------------------------------------------
void testApp::setup(){

    ofSetFrameRate(24);
    ofBackgroundHex(0xEFDC9E);
    ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::update(){
    
    for(int i=0; i<particles.size(); i++)
    {
        particles[i].updateMe();
    }
    
    particles.erase( remove_if(particles.begin(), particles.end(), shouldRemove), particles.end() );
}

//--------------------------------------------------------------
void testApp::draw(){
    
    for(int i=0; i<particles.size(); i++)
    {
        particles[i].drawMe();
    }
    
    ofSetColor(0);
    ofDrawBitmapString("particles="+ofToString(particles.size()), 10, 20);
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
void testApp::mouseDragged(int x, int y, int button) {
    
    Particle p;
    p.initialize(x, y);
    particles.push_back(p);
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