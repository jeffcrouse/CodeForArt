#include "testApp.h"

/*
 In this program I show examples of how to use "vectors",
 which are very similar to arrays.
 Check out the "testApp.h" file.
 */

//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(24);
	ofBackground(255,255,255);
	ofSetWindowShape(1024,768);
}

//--------------------------------------------------------------
void testApp::update(){
	
	for(int i=0; i<positions.size(); i++)
	{
		ages[i]++;
		a[i] = 255 - ages[i];
		positions[i] += velocities[i];
		
		if(positions[i].x > ofGetWidth()-radii[i]) {
			positions[i].x = ofGetWidth()-radii[i];
			velocities[i].x *= -1;
		}
		
		if(positions[i].y > ofGetHeight()-radii[i]) {
			positions[i].y = ofGetHeight()-radii[i];
			velocities[i].y *= -1;
		}
		
		if(positions[i].x < radii[i]) {
			positions[i].x = radii[i];
			velocities[i].x *= -1;
		}
		
		if(positions[i].y < radii[i]) {
			positions[i].y = radii[i];
			velocities[i].y *= -1;
		}
		
		if(ages[i] > 200)
		{
			positions.erase( positions.begin() + i );
			velocities.erase( velocities.begin() + i );
			radii.erase( radii.begin() + i );
			r.erase( r.begin() + i );
			g.erase( g.begin() + i );
			b.erase( b.begin() + i );
			a.erase( a.begin() + i );
			ages.erase( ages.begin() + i );
		}
		
		
	}
}

//--------------------------------------------------------------
void testApp::draw(){

	ofSetColor(0,0,0);

	for (int i=0; i<positions.size(); i++)
	{
		ofSetColor(r[i], g[i], b[i], a[i]);
		ofCircle(positions[i].x, positions[i].y, radii[i]);
		
		ofSetColor(0, 0, 0);
		ofDrawBitmapString(ofToString(ages[i]), positions[i].x, positions[i].y);
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

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	ofPoint pos;
	pos.x = x;
	pos.y = y;
	positions.push_back( pos );
	
	ofPoint vel;
	vel.x = ofRandom(-10, 10);
	vel.y = ofRandom(-10, 10);
	velocities.push_back( vel );
	
	float radius = ofRandom(10, 50);
	radii.push_back( radius );
	
	int red = ofRandom(0, 255);
	r.push_back( red );
	
	int green = ofRandom(0, 255);
	g.push_back( green );
	
	int blue = ofRandom(0, 255);
	b.push_back( blue );
	
	int alpha = ofRandom(0, 255);
	a.push_back( alpha );

	int age = 0;
	ages.push_back( age );
	
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

