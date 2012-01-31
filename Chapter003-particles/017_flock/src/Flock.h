/*
 *  Flock.h
 *  flock
 *
 *  Created by Jeffrey Crouse on 3/30/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 */

#ifndef FLOCK_H
#define FLOCK_H

#include "ofMain.h"
#include "Boid.h"

class Flock {
public:
	Flock();
	void update();
	void draw();
	void addBoid();
	
	vector<Boid*> boids;
};

#endif