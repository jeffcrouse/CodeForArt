/*
 *  Attractor.cpp
 *  attractor
 *
 *  Created by Jeffrey Crouse on 3/30/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 */

#include "Attractor.h"



Attractor::Attractor(){
	bDragging = false;
	bRollover = false;
	
	loc.x = ofRandomWidth();
	loc.y = ofRandomHeight();
	dragoff = loc;
	mass = 20;
	G = 0.4;
}



ofPoint Attractor::calcGravForce(Thing t){
    ofPoint dir = loc - t.loc;							// Calculate direction of force
    float d = ofDist(loc.x, loc.y, t.loc.x, t.loc.y);   // Distance between objects
    d = ofClamp(d,5.0,25.0);							// Limiting the distance to eliminate "extreme" results for very close or very far objects
    dir /=d ;											// Normalize vector (distance doesn't matter here, we just want this vector for direction)
    float force = (G * mass * t.mass) / (d * d);		// Calculate gravitional force magnitude
    dir *= force;										// Get force vector --> magnitude * direction
    return dir;
}


void Attractor::draw(){
    ofFill();
    if(bDragging) ofSetColor(50, 50, 50);
    else if (bRollover) ofSetColor(100, 100, 100);
    else ofSetColor(180, 180, 180);
    ofCircle(loc.x,loc.y,mass*2);
	ofNoFill();
	ofSetColor(50, 50, 50);
	ofCircle(loc.x, loc.y, mass*2);
}


void Attractor::clicked(int x, int y){
	float d = ofDist(x, y, loc.x, loc.y);
    if (d < mass) {
		bDragging = true;
		dragoff.x = loc.x-x;
		dragoff.y = loc.y-y;
    }	
}


void Attractor::rollover(int x, int y){
	float d = ofDist(x,y,loc.x,loc.y);
    if (d < mass) {
		bRollover = true;
    } else {
		bRollover = false;
    }
}


void Attractor::stopDragging(){
	bDragging = false;
}


void Attractor::drag(int x, int y){
	if (bDragging) {
		loc.x = x + dragoff.x;
		loc.y = y + dragoff.y;
    }
}

