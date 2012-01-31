/*
 *  Repeller.cpp
 *  flock
 *
 *  Created by Jeffrey Crouse on 3/29/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 */

#include "Repeller.h"

Repeller::Repeller() {
	bDragging = false;
	bRollover = false;
	
	
	r = 5;
	g = 100;
	loc.x = ofRandom(0, ofGetWidth());
	loc.y = ofRandom(0, ofGetHeight());
	oldloc = loc;
}

void Repeller::draw() {
	ofSetColor(0x000000);
	if(bDragging) {
		ofFill();
	} else {
		ofNoFill();
	}
	ofCircle(loc.x, loc.y, r*2);
}


void Repeller::pushParticle(Particle* p) {

	
	ofPoint dir = loc - p->loc;							// Calculate direction of force
	float d = ofDist(p->loc.x, p->loc.y, loc.x, loc.y);	// Distance between objects
	
	dir /= d;											// Normalize vector (distance doesn't matter here, we just want this vector for direction)
	//cout << dir.x << ", " << dir.y << endl;
	d = ofClamp(d, -50.0, 50.0);							// Keep distance within a reasonable range
	float force = -1.0 * g / (d * d);					// Repelling force is inversely proportional to distance
								
	
	p->applyForce(dir * force);	// Get force vector --> magnitude * direction
}


void Repeller::clicked(int x, int y) {
	float d = ofDist(x, y, loc.x, loc.y);
	if(d < r) {
		bDragging = true;
		
		oldloc.x = loc.x-x;
		oldloc.y = loc.y-y;
	}
}


void Repeller::rollover(int x, int y) {
	float d = ofDist(x, y, loc.x, loc.y);
	if (d < r) {
		bRollover = true;
    } 
    else {
		bRollover = false;
    }
	
}


void Repeller::stopDragging() {
	bDragging = false;
}


void Repeller::drag(int x, int y) {
	if (bDragging) {
		loc.x = x + oldloc.x;
		loc.y = y + oldloc.y;
    }	
}