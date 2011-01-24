#include "testApp.h"

bool sortDead(ofxChipmunkBaseShape A){
	if( A.dead )return true;
	return false;
}

//--------------------------------------------------------------
void testApp::setup() {
	
	ofSetFrameRate(24);
	
	ofBackground(10, 10, 10);
	ofSetVerticalSync(true);
	
	physics.setup(10, ofPoint(0, 600));
	
	//create a floor
	ofxChipmunkRect r;
	r.setup(ofGetWidth()/2, ofGetHeight()-(50/2), ofGetWidth(), 50, 50, .3, .5, true); 
	
	
	rects.push_back( r );
	physics.addShape( &r );
	
}

//--------------------------------------------------------------
void testApp::update() {
	
	physics.update(6);
	
	//if the bubbles go off screen - kill them!!!
	for(int i=0; i<bubbles.size(); i++) {
		//bounds
		if(bubbles[i].getPosition().y > ofGetHeight())  bubbles[i].kill();
		if(bubbles[i].getPosition().y < 0)				bubbles[i].kill();
		if(bubbles[i].getPosition().x > ofGetWidth())	bubbles[i].kill();
		if(bubbles[i].getPosition().x < 0)				bubbles[i].kill();
	}
	
	//sort the bubbles vector so that dead bubbles are at the begining
	if( bubbles.size() ){
		bubbles.erase( bubbles.begin(), partition(bubbles.begin(), bubbles.end(), sortDead) );
	}
}

//--------------------------------------------------------------
void testApp::draw() {
		
	ofSetColor(0, 35, 33);
	ofNoFill();
	ofRect(0, 0, ofGetWidth(), ofGetHeight());
	
	ofSetColor(0xffffff);
	ofFill();
	for(int i=0; i<bubbles.size(); i++) {
		
		ofSetColor(255, 0, ofRandom(0,255));
		ofCircle(bubbles[i].body->p.x, bubbles[i].body->p.y, bubbles[i].radius);
		//bubbles[i].draw();
	}
	
	for(int i=0; i<rects.size(); i++) {
		rects[i].draw();
	}
	
	//debug info
	ofSetColor(0xff00ff);
	string str = "";
	str += "FPS: "+ofToString(ofGetFrameRate()) + "\n";
	str += "Bubbles Count: " + ofToString((int)bubbles.size()) + "\n";
	
	ofDrawBitmapString(str, 20, 20);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	for(int i=0; i<50; i++) {
		float radius = ofRandom(3, 10);
		
		bubbles.push_back(ofxChipmunkCircle());
		bubbles.back().setup(mouseX + ofRandom(-radius, radius), mouseY+ ofRandom(-radius, radius), radius, radius, .5, .2, false);
		physics.addShape(&bubbles.back());
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	float radius = ofRandom(3, 10);
	
	bubbles.push_back(ofxChipmunkCircle());
	bubbles.back().setup(x, y, radius, radius, .5, .2, false);
	physics.addShape(&bubbles.back());
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button) {
	
	float radius = ofRandom(3, 10);
	
	bubbles.push_back(ofxChipmunkCircle());
	bubbles.back().setup(x, y, radius, radius, 0.5, .2, false);
	physics.addShape(&bubbles.back());
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(){

}


