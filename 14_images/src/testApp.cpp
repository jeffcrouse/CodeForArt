#include "testApp.h"


/*
 In this program
 1. Loading an image
 2. Basic object-oriented concepts
 */

//--------------------------------------------------------------
void testApp::setup(){

	
	car.loadImage("car.png");
	bg.loadImage("map.jpg");
	
	car_x = ofGetWidth()/2.0;;
	car_y = ofGetHeight()/2.0;;
	angle = 0;
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

	bg.draw(0,0);
	
	ofEnableAlphaBlending();
	
	
	ofPushMatrix();
	ofTranslate(car_x, car_y);
	ofScale(.25, .25);
	
	ofRotateZ(angle);
	
	
	car.draw(0, 0);
	ofPopMatrix();
	
	ofDisableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

	if(key == OF_KEY_LEFT) {
		car_x -= 10;
		angle = 180;
	}
	if(key == OF_KEY_RIGHT) {
		car_x += 10;
		angle = 0;
	}
	
	if(key == OF_KEY_UP) {
		car_y -= 10;
		angle=270;
	}
	
	if(key == OF_KEY_DOWN) {
		car_y += 10;
		angle=90;
	}
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

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

