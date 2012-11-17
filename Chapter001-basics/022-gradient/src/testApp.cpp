#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

    

    float maxDist = ofDist(0, 0, ofGetWidth()/2.0, ofGetHeight()/2.0);
    
    for(int y=0; y<ofGetHeight(); y++)
    {
        for(int x=0; x<ofGetWidth(); x++)
        {
            float dist = ofDist(x, y, mouseX, mouseY);
            if(dist < 300)
            {
                float grey = ofMap(dist, 0, 300, 255, 0);
                ofSetColor(grey);
                ofRect(x, y, 4, 4);
            }
        }
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