#include "testApp.h"

bool sortDead(ofxChipmunkBaseShape A){
	if( A.dead )return true;
	return false;
}

static void makeShapeWithNumPoints(ofxChipmunkPoly & poly, int numPts, float radius1, float radius2 = 0){
	if(numPts < 3)return;
	
	float angle = 0;
	
	if( numPts %2 == 0)numPts++;
	numPts *= 2;
	
	float step = TWO_PI / (numPts);
	
	if( radius2 == 0)radius2 = radius1;
	
	for(int i = 0; i < numPts; i++){
		if( i % 2 == 0 ){
			poly.addVertex(cos(angle) * radius1, sin(angle) * radius1 );
		}else{
			poly.addVertex(cos(angle) * radius2, sin(angle) * radius2 );
		}
		angle += step;
	}
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
	rects.back().setup(450, 460, 100, 5, 50, .3, .5, true);
	rects.back().setRotation(40);	
	physics.addShape(&rects.back());	

	rects.push_back(ofxChipmunkRect());
	rects.back().setup(360, 460, 100, 5, 50, .3, .5, true);
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
	for(int i=0; i<polys.size(); i++) {
		printf("[%i] is %f %f\n", i, polys[i].getPosition().x, polys[i].getPosition().y);
	
		//bounds
		if(polys[i].getPosition().y > ofGetHeight())  polys[i].kill();
		if(polys[i].getPosition().y < 0)				polys[i].kill();
		if(polys[i].getPosition().x > ofGetWidth())	polys[i].kill();
		if(polys[i].getPosition().x < 0)				polys[i].kill();
		
	}
	
	//sort the bubbles vector so that dead bubbles are at the begining
	if( polys.size() ){
		polys.erase( polys.begin(), partition(polys.begin(), polys.end(), sortDead) );
	}
}

//--------------------------------------------------------------
void testApp::draw() {
		
	ofSetColor(0, 35, 33);
	ofNoFill();
	ofRect(0, 0, ofGetWidth(), ofGetHeight());
	
	ofSetColor(0xffffff);
	ofFill();
	for(int i=0; i<polys.size(); i++) {
		polys[i].draw();
	}
	for(int i=0; i<rects.size(); i++) {
		rects[i].draw();
	}
	
	//debug info
	ofSetColor(0xff00ff);
	string str = "";
	str += "FPS: "+ofToString(ofGetFrameRate()) + "\n";
	str += "Polys Count: " + ofToString((int)polys.size()) + "\n";
	
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
	
		float radius1 = ofRandom(5, 10);
		float radius2 = ofRandom(5, 20);
		
		polys.push_back(ofxChipmunkPoly());
		
		makeShapeWithNumPoints(polys.back(), ofRandom(5, 9), radius1, radius2);
		polys.back().makePolyShape(mouseX + ofRandom(-radius1*2, radius1*2), mouseY+ ofRandom(-radius1, radius1), ofRandom(5, 40), ofRandom(0.2, 0.94), ofRandom(0.3, 0.8), false);
		polys.back().setRotation( ofRandom(0, 360));
		physics.addPolyShape(&polys.back());
		
}

//--------------------------------------------------------------
void testApp::mouseReleased(){

}


