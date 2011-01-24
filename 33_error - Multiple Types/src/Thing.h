/*
 *  Thing.h
 *  forces
 *
 *  Created by Jeffrey Crouse on 3/30/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 */

#ifndef THING_H
#define THING_H

#include "ofMain.h"

class Thing{
public:
	Thing();
	
	void draw();
	void update();
	void applyForce(ofPoint force);
	void drawVector(float scayl);
	ofPoint calcGravForce(Thing* t);
	
	ofPoint loc, vel, acc;
	
	float G, mass, max_vel, bounce;  // How "elastic" is the object
};

#endif