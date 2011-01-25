#include "testApp.h"

bool sortDead(ofxChipmunkBaseShape A){
	if( A.dead )return true;
	return false;
}

//--------------------------------------------------------------
void testApp::setup() {
	
	ofBackground(10, 10, 10);
	ofSetVerticalSync(true);
	
	physics.setup(10, ofPoint(0, 600));
	
	//create a floor
	rects.push_back(ofxChipmunkRect());
	rects.back().setup(ofGetWidth()/2, ofGetHeight()-(50/2), ofGetWidth(), 50, 50, .3, .5, true);
	physics.addShape(&rects.back());
	
	//create some other rectangles and give them rotation
	rects.push_back(ofxChipmunkRect());
	rects.back().setup(315, 300, 200, 20, 50, .3, .5, true);
	rects.back().setRotation(45);	
	physics.addShape(&rects.back());
	
	rects.push_back(ofxChipmunkRect());
	rects.back().setup(500, 300, 200, 20, 50, .3, .5, true);
	rects.back().setRotation(-45);	
	physics.addShape(&rects.back());	

	//some other angluar rects
	rects.push_back(ofxChipmunkRect());
	rects.back().setup(450, 440, 100, 5, 50, .3, .5, true);
	rects.back().setRotation(40);	
	physics.addShape(&rects.back());	

	rects.push_back(ofxChipmunkRect());
	rects.back().setup(360, 440, 100, 5, 50, .3, .5, true);
	rects.back().setRotation(-40);	
	physics.addShape(&rects.back());	

	//left wall
	rects.push_back(ofxChipmunkRect());
	rects.back().setup(10, ofGetHeight()/2, 10, ofGetHeight()-100, 50, .3, .5, true);
	physics.addShape(&rects.back());	
	
	//right wall
	rects.push_back(ofxChipmunkRect());
	rects.back().setup(ofGetWidth()-10, -30 +  ofGetHeight()/2, 10, ofGetHeight()-100, 50, .3, .5, true);
	physics.addShape(&rects.back());	
	
	//obstacle
	rects.push_back(ofxChipmunkRect());
	rects.back().setup(ofGetWidth() * 0.75, ofGetHeight()-100, 10, 100, 50, .3, .5, true);
	physics.addShape(&rects.back());		
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
		bubbles[i].draw();
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


