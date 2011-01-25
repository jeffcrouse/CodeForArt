/*
 *  ParticleSystem.h
 *  flock
 *
 *  Created by Jeffrey Crouse on 3/29/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 */


#ifndef PARTICLE_SYSYTEM_H
#define PARTICLE_SYSYTEM_H

#include "ofMain.h"
#include "Particle.h"
#include "Repeller.h"

class ParticleSystem {
public:
	ParticleSystem();
	
	void applyForce(ofPoint force);
	void applyRepellers(vector<Repeller*> repellers);
	void update();
	void draw();
	void addParticle();
	bool dead();
	
	vector<Particle> particles;
	ofPoint origin;
	
	
};

#endif