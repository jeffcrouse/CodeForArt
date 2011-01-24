/*
 *  Attractor.h
 *  attractor
 *
 *  Created by Jeffrey Crouse on 3/30/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 */

#ifndef ATTRACTOR_H
#define ATTRACTOR_H

#include "ofMain.h"
#include "Thing.h"

class Attractor {
public:
	Attractor();
	
	ofPoint calcGravForce(Thing t);
	void draw();
	void clicked(int x, int y);
	void rollover(int x, int y);
	void stopDragging();
	void drag(int x, int y);
	
	float mass;    // Mass, tied to size
	float G;       // Gravitational Constant
	ofPoint loc;   // Location
	bool bDragging; // Is the object being dragged?
	bool bRollover; // Is the mouse over the ellipse?
	ofPoint dragoff;  // holds the offset for when object is clicked on
	
	
};

#endif