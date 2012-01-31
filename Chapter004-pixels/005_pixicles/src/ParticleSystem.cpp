/*
 *  ParticleSystem.cpp
 *  flock
 *
 *  Created by Jeffrey Crouse on 3/29/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 */

#include "ParticleSystem.h"


ParticleSystem::ParticleSystem() {
	origin.x = ofGetWidth()/2;
	origin.y = ofGetHeight()/2;
}

void ParticleSystem::applyForce(ofPoint force) {
	for(int i=0; i<particles.size(); i++) {
		particles[i].applyForce(force);
	}
}


void ParticleSystem::applyRandomForce() {
	for(int i=0; i<particles.size(); i++) {
		ofPoint f(ofRandom(-10, 10), ofRandom(-10, 10));
		particles[i].applyForce(f);
	}
}

void ParticleSystem::update() {
	for(int i=0; i<particles.size(); i++) {
		particles[i].update();
		if(particles[i].dead()) {
			particles.erase( particles.begin()+i );
		}
	}
}

void ParticleSystem::draw() {
	ofFill();
	for(int i=0; i<particles.size(); i++) {
		particles[i].draw();
	}
}

void ParticleSystem::addParticle(float x, float y, int r, int g, int b) {
	Particle p;
	p.r = r;
	p.g = g;
	p.b = b;
	p.loc.x = x;
	p.loc.y = y;
	p.vel = 0;
	particles.push_back( p );
}


bool ParticleSystem::dead() {
	if(particles.size() == 0) {
		return true;
	} else {
		return false;
	}
}