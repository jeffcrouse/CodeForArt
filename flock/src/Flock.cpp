/*
 *  Flock.cpp
 *  flock
 *
 *  Created by Jeffrey Crouse on 3/30/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 */

#include "Flock.h"

Flock::Flock() {

}

void Flock::update() {
	for(int i=0; i<boids.size(); i++) {
		boids[i]->update(boids);
	}
}

void Flock::draw() {
	ofSetColor(0, 0, 0);
	for(int i=0; i<boids.size(); i++) {
		boids[i]->draw();
	}
}

void Flock::addBoid() {
	boids.push_back( new Boid() );
}