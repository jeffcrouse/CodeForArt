/*
 *  Thing.cpp
 *  forces
 *
 *  Created by Jeffrey Crouse on 3/30/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 */

#include "Thing.h"

Thing::Thing() {
	max_vel = 3.0;
	mass = ofRandom(1, 3);
	bounce = 1.2;
	loc.x = ofRandomWidth();
	loc.y = ofRandomHeight();
}

void Thing::update() {
    vel += acc;
    vel.x = ofClamp(vel.x, -max_vel, max_vel);
	vel.y = ofClamp(vel.y, -max_vel, max_vel);
    loc += vel;
    acc = 0;
	
    if (loc.y > ofGetHeight()) {
		vel.y *= -bounce;
		loc.y = ofGetHeight();
    }
    if ((loc.x > ofGetWidth()) || (loc.x < 0)) {
		vel.x *= -bounce;
    }    
    //if (loc.x < 0)     loc.x = ofGetWidth();
    //if (loc.x > ofGetWidth()) loc.x = 0;
	
}

// Renders a vector object 'v' as an arrow and a location 'loc'
void Thing::drawVector(float scayl) {
	
	float angle = (float)atan2(-vel.y, vel.x);
    float theta =  -1.0*angle;
	float heading2D = ofRadToDeg(theta);
	float mag = sqrt(vel.x*vel.x + vel.y*vel.y);
	
	ofSetColor(0x000000);
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


void Thing::applyForce(ofPoint force) {
	force /= mass;
	acc += force;
}

void Thing::draw() {
	ofFill();
	ofSetColor(0x999999);
	ofCircle(loc.x, loc.y, mass*5);
	drawVector(10);
}