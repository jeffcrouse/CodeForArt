#include "testApp.h"

bool sortDead(ofxChipmunkBaseShape A){
	if( A.dead )return true;
	return false;
}

//--------------------------------------------------------------
void testApp::setup() {
	
	ofBackground(10, 10, 10);
	ofSetVerticalSync(true);
	
	physics.setup(10, ofPoint(0, 2000));
	
	
	//create some other rectangles and give them rotation
	rects.push_back(ofxChipmunkRect());
	rects.back().setup(100, 600, 700, 20, 50, 1, .5, true);
	rects.back().setRotation(30);	
	physics.addShape(&rects.back());
	
	rects.push_back(ofxChipmunkRect());
	rects.back().setup(ofGetWidth()-100, 600, 600, 20, 50, 1, .5, true);
	rects.back().setRotation(-45);	
	physics.addShape(&rects.back());	

}

//--------------------------------------------------------------
void testApp::update() {
	
	physics.update(6);
	
	//if the bubbles go off screen - kill them!!!
	for(int i=0; i<bubbles.size(); i++) {
		//bounds
		if(bubbles[i].getPosition().y > ofGetHeight())  bubbles[i].kill();
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
		bubbles[i].draw();
	}
	ofFill();
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
void testApp::mousePressed(int x, int y, int button) {
	
	int which = ofRandom(0, 2.99);
	
	if(which == 0){
		float radius = ofRandom(3, 13);
	
		bubbles.push_back(ofxChipmunkCircle());
		bubbles.back().setup(x, y, radius, radius, 1, .8, false);
		physics.addShape(&bubbles.back());
	}else if(which == 1){
		float radius = ofRandom(3, 13);
	
		bubbles.push_back(ofxChipmunkCircle());
		bubbles.back().setup(x, y, radius, radius, 1, .8, false);
		physics.addShape(&bubbles.back());

		bubbles.push_back(ofxChipmunkCircle());
		bubbles.back().setup(x+radius*radius*0.6, y, radius, radius, 1, .8, false);
		physics.addShape(&bubbles.back());
		
		physics.addJoint(&bubbles[bubbles.size()-2], &bubbles.back());
	}
	else if(which == 2){
		float radius = ofRandom(9, 25);
	
		rects.push_back(ofxChipmunkRect());
		rects.back().setup(x, y, radius, radius, radius, 1, .8, false);
		physics.addShape(&rects.back());
	}	
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(){

}


