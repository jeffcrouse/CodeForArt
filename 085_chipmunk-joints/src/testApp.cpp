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
	
	//create a floor with a line
	floor.setup(0, ofGetHeight()-10, ofGetWidth(), ofGetHeight()-10, 1, 1.0, 0.9);
	physics.addShape(&floor);
	
	ofxChipmunkRect fixedRect;
	ofxChipmunkRect freeRect;
	ofxChipmunkRect freeRect2;
	ofxChipmunkRect freeRect3;
	
	fixedRect.setup(400, 200, 50, 50, 50, 0.5, 0.5, true);
	freeRect.setup(500, 200, 100, 20, 20, 0.5, 0.5, false);
	freeRect2.setup(610, 200, 100, 20, 20, 0.5, 0.5, false);
	freeRect3.setup(720, 200, 100, 20, 20, 0.5, 0.5, false);
	
	physics.addShape(&fixedRect);
	physics.addShape(&freeRect);
	physics.addShape(&freeRect2);
	physics.addShape(&freeRect3);

	physics.addJoint(&freeRect, &fixedRect, ofPoint(-50, -0), ofPoint(0, 0));	
	physics.addJoint(&freeRect, &freeRect2, ofPoint(50, -0), ofPoint(-50, 0));	
	physics.addJoint(&freeRect2, &freeRect3, ofPoint(50, -0), ofPoint(-50, 0));	
	
	rects.push_back(fixedRect);
	rects.push_back(freeRect);
	rects.push_back(freeRect2);
	rects.push_back(freeRect3);
	
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
		
	
	
	
	ofSetColor(0xffffff);
	floor.draw();
	
	ofFill();
	for(int i=0; i<rects.size(); i++) {
		rects[i].draw();
	}
	for(int i=0; i<bubbles.size(); i++) {
		bubbles[i].draw();
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
	
	//lets create circles and connect them together
	int numPointsInJoint = ofRandom(2, 3.99);
	
	//the center of the group is our mouse pos
	ofPoint center(x, y);
	
	//calcuate the angle steps - ie the angle betwen each circle
	float angleStep = TWO_PI / numPointsInJoint;
	float angle = ofRandom(0, PI);
	float dist = ofRandom(50, 100);
	
	//loop through and create the circles
	for(int i = 0; i < numPointsInJoint; i++){
		float radius = ofRandom(3, 13);
		
		//position relative to the center point based on angle
		float xPos = cos(angle) * dist;
		float yPos = sin(angle) * dist;
		
		//create our circle
		bubbles.push_back(ofxChipmunkCircle());
		bubbles.back().setup(center.x + xPos, center.y + yPos,  radius, radius, 0.8, .8, false);
		physics.addShape(&bubbles.back());
		
		//if we are not the first circle - create a joint between me and the previous circle
		if( i > 0 )physics.addJoint(&bubbles[bubbles.size()-2], &bubbles.back());
		
		angle += angleStep;
	}
	
	//finally we need to connect the first circle to the last circle so there is a joint between each point
	physics.addJoint(&bubbles[bubbles.size()-numPointsInJoint], &bubbles.back());
	
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(){

}


