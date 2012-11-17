/*
 *  Thing.cpp
 *  forces
 *
 *  Created by Jeffrey Crouse on 3/30/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 */

#include "Thing.h"

//--------------------------------------------------------------
Thing::Thing() {
	max_vel = 8.0;
	mass = 1;
	radius = mass * 10;
	bounce = 0.8;
    reset();
}

//--------------------------------------------------------------
void Thing::reset() {
    loc.x = ofGetWidth()/2;
	loc.y = 20.0;
    vel.x=0;
    vel.y=0;
}

//--------------------------------------------------------------
void Thing::update() {
    vel += acc;
    vel.x = ofClamp(vel.x, -max_vel, max_vel);  // if first arg is less than second arg, return secodn arg.  if greater, return third arg
	vel.y = ofClamp(vel.y, -max_vel, max_vel);
    loc += vel;
    acc.set(0, 0);
	
	
    if (loc.y > ofGetHeight() - radius) {
		vel.y *= -bounce;
		loc.y = ofGetHeight() - radius;
    }
    if (loc.x > ofGetWidth() - radius) {
		vel.x *= -bounce;
		loc.x = ofGetWidth() - radius;
    }    	
	if(loc.x < radius) {
		vel.x *= -bounce;
		loc.x = radius;
	}
}

//--------------------------------------------------------------
void Thing::applyForce(ofPoint force) {
	//force /= mass;
	acc += force;
}

//--------------------------------------------------------------
void Thing::draw() {
	ofFill();
	ofSetHexColor(0x999999);
	ofCircle(loc.x, loc.y, radius);
	//drawVector(loc, vel, 5);
    
    ofSetHexColor(0x000000);
    ofDrawArrow(loc, loc+vel*5, 5);
}


//--------------------------------------------------------------
// Renders a vector object 'v' as an arrow and a location 'loc'
void Thing::drawVector(ofPoint loc, ofPoint vel, float scayl) {
	
	float angle = (float)atan2(-vel.y, vel.x);
    float theta =  -1.0 * angle;
	float heading2D = ofRadToDeg(theta);
	float mag = sqrt(vel.x*vel.x + vel.y*vel.y);
	
	ofSetHexColor(0x000000);
	ofNoFill();
	
	ofPushMatrix();
	float arrowsize = 4;
	// Translate to location to render vector
	ofTranslate(loc.x,loc.y);
	// Call vector heading function to get direction (note that pointing up is a heading of 0) and rotate
	ofRotate(heading2D);
	// Calculate length of vector & scale it to be bigger or smaller if necessary
	float len = mag*scayl;
	// Draw three lines to make an arrow (draw pointing up since we've rotate to the proper direction)
	ofLine(0,0,len,0);
	ofLine(len, 0, len-arrowsize, +arrowsize/2);
	ofLine(len, 0, len-arrowsize, -arrowsize/2);
	ofPopMatrix();
}
