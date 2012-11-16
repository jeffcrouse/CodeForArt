#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(24);
	ofSetWindowShape(1024,768);
}

//--------------------------------------------------------------
void testApp::update(){
    
	for (int i=0; i<stars.size(); i++)
	{
		stars[i].updateMe(stars);
		
		if(stars[i].age > 240)
		{
			stars.erase( stars.begin() + i );
		}
	}
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
    b.velocity.x = ofRandom(-10, 10);
    b.velocity.y = ofRandom(-10, -20);
    
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