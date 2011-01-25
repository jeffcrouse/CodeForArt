/*
 *  Boid.h
 *  boid
 *
 *  Created by Jeffrey Crouse on 3/29/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 */

#ifndef BOID_H
#define BOID_H

#include "ofMain.h"
#include "Path.h"

class Boid {
public:
	Boid(ofPoint l, float ms, float mf);
	
	void update();
	void draw();
	void seek(ofPoint target);
	void arrive(ofPoint target);
	ofPoint steer(ofPoint target, bool slowdown);
	
	void follow(Path* p);
	ofPoint getNormalPoint(ofPoint p, ofPoint a, ofPoint b);
	
	ofPoint loc;
	ofPoint vel;
	ofPoint acc;
	
	ofPoint predictLoc;
	ofPoint target;
    ofPoint dir;
	float record;
	
	float r;
	float maxforce;
	float maxspeed;
	bool debug;
};

#endif