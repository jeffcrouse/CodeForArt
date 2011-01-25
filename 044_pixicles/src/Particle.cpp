/*
 *  Particle.cpp
 *  flock
 *
 *  Created by Jeffrey Crouse on 3/29/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 */

#include "Particle.h"

Particle::Particle() {
	acc = ofPoint(0,0);
    timer = 255.0;
    maxspeed = 10.0;
	mass = 1.0;
}

void Particle::update() {
	vel += acc;
	vel.x = ofClamp(vel.x, -maxspeed, maxspeed);
	vel.y = ofClamp(vel.y, -maxspeed, maxspeed);
	loc += vel;
	acc = 0;
	if(abs((long)vel.x) > 0.5 || abs((long)vel.y) > 0.5)
		timer-=4;
}

void Particle::applyForce(ofPoint force) {
	force /= mass;
	acc += force;
}

void Particle::draw() {
	ofPushMatrix();
	ofTranslate(loc.x, loc.y);
	ofEnableAlphaBlending();
	ofSetColor(r, g, b, timer);
	ofRect(0, 0, 2, 2);
	ofPopMatrix();
}

bool Particle::dead() {
	if(timer <= 0.0) {
		return true;
	} else {
		return false;
	}
}