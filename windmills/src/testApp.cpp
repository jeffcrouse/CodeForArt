#include "testApp.h"

#define NUM_WINDMILLS 1500

//--------------------------------------------------------------
void testApp::setup(){

	ofBackground(0, 0, 0);
	ofSetFrameRate(24);
	ofEnableSmoothing();
	//ofSetBackgroundAuto(false);

	
	for(int i=0; i<NUM_WINDMILLS; i++)
	{
		Windmill w;
		w.pos.x = ofRandomWidth();
		w.pos.y = ofRandomHeight();
		//w.vel.x = ofRandom(-10, 10);
		//w.vel.y = ofRandom(-10, 10);
		
		w.r = ofRandom(0, 255);
		w.g = ofRandom(50, 255);
		w.b = ofRandom(100, 255);
		w.wavelength = ofRandom(5, 20);
		w.rotateSpeed = 10;
		w.scale = ofRandom(.05, .4);
		
		windmills.push_back( w );
	}
}

//--------------------------------------------------------------
void testApp::update(){
	
	for(int i=0; i<NUM_WINDMILLS; i++)
	{
		windmills[i].update();
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	for(int i=0; i<NUM_WINDMILLS; i++)
	{
		windmills[i].draw();
	}
	
	ofSetColor(255, 255, 255);
	ofDrawBitmapString("fps: "+ofToString(ofGetFrameRate(), 2), 20, 20);
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
	ofPoint pos(x, y);
	
	for(int i=0; i<NUM_WINDMILLS; i++)
	{
		windmills[i].rotateSpeed = ofDist(x, y, windmills[i].pos.x, windmills[i].pos.y) / 30.0;
		windmills[i].vel += (pos-lastPos) / 100.0;
		windmills[i].vel *= .9;
	}
	
	lastPos = pos;
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

