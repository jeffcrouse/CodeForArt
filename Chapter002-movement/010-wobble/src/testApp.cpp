#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    anchorX = ofGetWidth()/2.0;
    anchorY = ofGetHeight()/2.0;
    dist = 200;
    angle = targetAngle = ofDegToRad(-90);
    topRadius = 30;
    dragging = false;
}

//--------------------------------------------------------------
void testApp::update(){
    // If the user is dragging the top circle, calculate the angle between
    // the mouse and the anchor point
    // Otherwise, move the angle back towards the targetAngle (remember, easing?)
    if(dragging)
    {
        angle = atan2(mouseY-anchorY, mouseX-anchorX);
    }
    else
    {
        angle += (targetAngle-angle) / 10.0;
    }
    
    
    // Determine the position of the top based on the angle and distance
    topX = anchorX + cos(angle) * dist;
    topY = anchorY + sin(angle) * dist;
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofNoFill();
    ofSetColor(0);
    ofCircle(anchorX, anchorY, 40);
    ofCircle(topX, topY, topRadius);
    ofLine(anchorX, anchorY, topX, topY);
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
    float d = ofDist(x, y, topX, topY);
    if(d < topRadius) {
        dragging = true;
    }
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    dragging = false;
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