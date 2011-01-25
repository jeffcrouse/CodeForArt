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

void ParticleSystem::applyRepellers(vector<Repeller*> repellers) {
	for(int i=0; i<particles.size(); i++)
	{
		for(int j=0; j<repellers.size(); j++)
		{
			repellers[j]->pushParticle( &particles[i] );
		}
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
	for(int i=0; i<particles.size(); i++) {
		particles[i].draw();
	}
}

void ParticleSystem::addParticle() {
	Particle p;
	p.loc = origin;
	particles.push_back( p );
}


bool ParticleSystem::dead() {
	if(particles.size() == 0) {
		return true;
	} else {
		return false;
	}
}