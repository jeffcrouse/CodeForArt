/*
 *  Particle.cpp
 *  opencvExample
 *
 *  Created by Jeffrey Crouse on 10/12/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 */

#include "Particle.h"

void Particle::setup() {
	boundingBox.x = ofRandomWidth();
	boundingBox.y = ofRandomHeight();
	boundingBox.width = ofRandom(10, 50);
	boundingBox.height = ofRandom(10, 50);
	
	r = ofRandom(0, 255);
	g = ofRandom(0, 255);
	b = ofRandom(0, 255);
	
	velocity.x = ofRandom(-2, 2);
	velocity.y = ofRandom(-2, 2);
}

bool Particle::isColliding(ofRectangle a, ofRectangle b)
{
    int left1 = a.x;
    int left2 = b.x;
    int right1 = a.x + a.width;
    int right2 = b.x + b.width;
    int top1 = a.y;
    int top2 = b.y;
    int bottom1 = a.y + a.height;
    int bottom2 = b.y + b.height;
    if (bottom1 < top2) return false;
    if (top1 > bottom2) return false;
    if (right1 < left2) return false;
    if (left1 > right2) return false;
    return true;
}

void Particle::update(vector<ofRectangle> blobs) {

	// see if any of the blobs are colliding with boundingBox of this particle
	for(int i=0; i<blobs.size(); i++)
	{
		if(Particle::isColliding(blobs[i], boundingBox))
		{
			velocity += ofRandom(-1, 1);
			velocity *= 1.5;
		}
	}
	
	if(boundingBox.x < 0 || boundingBox.x+boundingBox.width > ofGetWidth())
	{
		velocity.x *= -1.1;
	}
	
	if(boundingBox.y < 0 || boundingBox.y+boundingBox.height > ofGetHeight())
	{
		velocity.y *= -1.1;
	}
	
	boundingBox.x += velocity.x;
	boundingBox.y += velocity.y;
	
	
	// Friction??
	velocity *= .9;
}

void Particle::draw() {

	ofFill();
	ofSetColor(r, g, b);
	ofRect(boundingBox.x, boundingBox.y, boundingBox.width, boundingBox.height);
}