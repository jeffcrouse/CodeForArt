#include "testApp.h"


bool shouldRemove(Star& p) {
    return p.age > 240;
}

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    ofBackgroundHex(0xEFDC9E);
    ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::update(){
    
    
    ofSetWindowTitle("fps="+ofToString(ofGetFrameRate())+" stars="+ofToString(stars.size()));
    
    for(int i=0; i<stars.size(); i++)
    {
        stars[i].updateMe(stars);
    }
    
    stars.erase( remove_if(stars.begin(), stars.end(), shouldRemove), stars.end() );
    
    mouse.set(mouseX, mouseY);
    mouseVel = mouse-mousePrev;
    mousePrev = mouse;

}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackgroundGradient(ofColor::white, ofColor::black);
	ofEnableAlphaBlending();
    
    
	for (int i=0; i<stars.size(); i++)
	{
		stars[i].drawMe();
	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    if(key=='f')ofToggleFullscreen();
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    Star b;
    b.radius = ofRandom(5, 20);
    b.mass = b.radius;
    b.age = 0;
    b.r = ofRandom(0, 255);
    b.g = ofRandom(0, 255);
    b.b = ofRandom(0, 255);
    b.a = 255;
    b.position.x = mouseX;
    b.position.y = mouseY;
    b.sides = (int)ofRandom(3,10)*2;
    b.starishness = ofRandom(2, 4);
    b.rotate_speed = ofRandom(-20, 20);
    b.velocity = mouseVel * 5;
    
    stars.push_back( b );
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
