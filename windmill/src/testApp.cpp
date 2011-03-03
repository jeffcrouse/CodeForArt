#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(0, 0, 0);
	ofSetFrameRate(24);
	ofEnableSmoothing();
	
	//pos.x = 400;
	//pos.y = 500;
	
	ofPoint pos1;
	pos1.x = 200;
	pos1.y = 300;
	
	ofPoint pos2;
	pos2.x = 500;
	pos2.y = 600;
	
	positions.push_back( pos1 );
	positions.push_back( pos2 );
	
	r = ofRandom(0, 150);
	g = ofRandom(100, 255);
	b = 255;
	wavelength = 20.0;
	rotateSpeed = 10;
	scale = .4;
}

//--------------------------------------------------------------
void testApp::update(){
	angle += rotateSpeed;
	a = (255/2.0) * cos(ofGetFrameNum()/wavelength) + (255/2.0);
}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetColor(255, 255, 255);
	ofDrawBitmapString("alpha="+ofToString(a, 2), 20, 20);
	ofDrawBitmapString("speed="+ofToString(rotateSpeed, 2), 20, 40);
	
	
	for(int i=0; i<positions.size(); i++)
	{
		ofSetColor(r, g, b, a);
		ofFill();
		
		ofPushMatrix();
		ofTranslate(positions[i].x, positions[i].y);
		ofRotateZ(angle);
		ofScale(scale, scale);
		
			ofEnableAlphaBlending();
			
			ofBeginShape();
				ofVertex(-20, -140);
				ofVertex(80, -140);
				ofVertex(0, 100);
				ofVertex(20, 140);
				ofVertex(-80, 140);
				ofVertex(10, -100);
			ofEndShape(true);
			
			ofDisableAlphaBlending();
		
		ofPopMatrix();
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
	//rotateSpeed = ofDist(x, y, pos.x, pos.y) / 10.0;
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

