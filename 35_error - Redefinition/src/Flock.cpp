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

void Flock::update(Flock* other) {
	for(int i=0; i<boids.size(); i++) {
		boids[i]->update(boids, other->boids);
	}
}

void Flock::draw() {
	ofSetColor(red, 0, 0);
	for(int i=0; i<boids.size(); i++) {
		boids[i]->draw();
	}
}

void Flock::addBoid() {
	boids.push_back( new Boid() );
}