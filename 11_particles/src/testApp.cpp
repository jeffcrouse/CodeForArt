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
	ofSetWindowShape(1024, 768);

}

//--------------------------------------------------------------
void testApp::update(){


	if (ofGetFrameNum()%2==0)
	{
		
		int new_x_pos = ofRandom(0, ofGetWidth());
		x_pos.push_back( new_x_pos );
		
		int new_y_pos = ofRandom(0, ofGetHeight());
		y_pos.push_back( new_y_pos );
		
		int new_x_vel = ofRandom(-30, 30);
		x_vel.push_back( new_x_vel );
		
		int new_y_vel = ofRandom(-30, 30);
		y_vel.push_back( new_y_vel );
		

		float radius = ofRandom(10, 30);
		radii.push_back( radius );
		
		age.push_back( 0 );
	}
}

//--------------------------------------------------------------
void testApp::draw(){

	ofEnableAlphaBlending();
	for(int i=0; i<x_pos.size(); i=i+1)
	{
		if(age[i] > 200)
		{
			x_pos.erase( x_pos.begin()+i );
			y_pos.erase( y_pos.begin()+i );
			x_vel.erase( x_vel.begin()+i );
			y_vel.erase( y_vel.begin()+i );
			radii.erase( radii.begin()+i );
			age.erase( age.begin()+i );
		}
		else 
		{
			x_pos[i] = x_pos[i] + x_vel[i];
			y_pos[i] = y_pos[i] + y_vel[i];
			
			if(x_pos[i]>ofGetWidth()-(radii[i]/2.) || x_pos[i]<0+(radii[i]/2.))
			{
				x_vel[i] *= -1;
			}
			if(y_pos[i]>ofGetHeight()-(radii[i]/2.) || y_pos[i]<0+(radii[i]/2.))
			{
				y_vel[i] *= -1;
			}
			
			// Same as above
			// x_pos[i] += x_vel[i];
			// y_pos[i] += y_vel[i];
			
			
			float alpha = ofMap(age[i], 0, 48, 255, 0);
			ofSetColor(0, 0, 0, alpha);
			
			ofCircle(x_pos[i], y_pos[i], radii[i]);
			age[i]++;
		}
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

