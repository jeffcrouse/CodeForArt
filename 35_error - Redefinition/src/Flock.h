/*
 *  Flock.h
 *  flock
 *
 *  Created by Jeffrey Crouse on 3/30/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 */


#include "ofMain.h"
#include "Boid.h"

class Flock {
public:
	Flock();
	void update(Flock* f);
	void draw();
	void addBoid();
	
	int red;
	vector<Boid*> boids;
};
