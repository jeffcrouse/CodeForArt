/*
 *  Repeller.h
 *  flock
 *
 *  Created by Jeffrey Crouse on 3/29/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 */

#ifndef REPELLER_H
#define REPELLER_H

#include "Particle.h"

class Repeller {
public:
	Repeller();
	void draw();
	
	void pushParticle(Particle* p);
	void clicked(int x, int y);
	void rollover(int x, int y);
	void stopDragging();
	void drag(int x, int y);
	
	float g;
	ofPoint loc;
	ofPoint oldloc;
	bool bDragging;
	bool bRollover;
	float r;

		
};

#endif