#include "testApp.h"

/*
 Create a particle system.
 
 In this program
 1. adding to and updating arrays

 In-class assignment:  
	- Make the particles bounce off of the sides of the screen.
 
 */


//--------------------------------------------------------------
void testApp::setup(){

	ofSetFrameRate(24);
	ofBackground(255, 255, 255);
	ofSetWindowShape(600, 400);
	
}

//--------------------------------------------------------------
void testApp::update(){
if (ofGetFrameNum()%5==0) {

	int new_x_pos = ofRandom(0, ofGetWidth());
	x_pos.push_back(new_x_pos);
	
	int new_y_pos= ofRandom(0, ofGetHeight());
	y_pos.push_back(new_y_pos);
	
	int new_x_velocity = ofRandom(-20, 20)+1.5;
	x_velocity.push_back(new_x_velocity);
	
	int new_y_velocity = ofRandom(-20, 20)+1.5;
	y_velocity.push_back(new_y_velocity);
	
	
	int new_radius= ofRandom(0, ofGetHeight()*.02);
	radius.push_back(new_radius);
	
	age.push_back(0);
}
}

//--------------------------------------------------------------
void testApp::draw(){
	ofEnableAlphaBlending();
	ofSetColor(205, 25, 20);
	for (int i=0; i<x_pos.size(); i++) {
		if(age[i]>480)
		{
			x_pos.erase(x_pos.begin()+i);
			y_pos.erase(y_pos.begin()+i);
			radius.erase(radius.begin()+i);
			age.erase(age.begin()+i);
			x_velocity.erase(x_velocity.begin()+i);
			y_velocity.erase(y_velocity.begin()+i);
			
		}		
		else {
			
			x_pos[i] = x_pos[i]+x_velocity[i];
			y_pos[i] = y_pos[i]+y_velocity[i];
			
			float alpha= ofMap(age[i], 0, 40, 255, 0);
			ofSetColor(205, 25, 20, alpha);
			
			if (x_pos[i]>ofGetWidth()-radius[i]/2) {
			   x_pos[i] = ofGetWidth()-radius[i]/2;
				x_velocity[i]*=-1;
			}
				if(x_pos[i]<0+radius[i]/2){
					x_pos[i] = 0+radius[i]/2;
					x_velocity[i]*=-1;				}
	
			if ((y_pos[i]>ofGetHeight()-radius[i]/2)){
					y_pos[i]= ofGetHeight()-radius[i]/2;
				y_velocity[i] *=-1;
				}
				if (y_pos[i]<0+radius[i]/2) {
					y_pos[i]= 0+radius[i]/2;
					y_velocity[i] *=-1;
				}
		}
		
		
		ofCircle(x_pos[i], y_pos[i], radius[i]);
		age[i]++;
		
}
	ofDisableAlphaBlending();
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
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

