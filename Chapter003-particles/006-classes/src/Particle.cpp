//
//  Particle.cpp
//  classes
//
//  Created by Jeffrey Crouse on 11/16/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Particle.h"

// ----------------------------------
void Particle::initialize(float x, float y)
{
    radius = ofRandom(10, 20);
    born = ofGetElapsedTimef();
    pos.set(x, y); 
    vel.set(ofRandom(-10, 10), ofRandom(-10, 10));
    color.setHsb(ofRandom(255), 200, 200); 
}


// ----------------------------------
void Particle::updateMe()
{
    pos += vel;
    
    // bounce off walls
    if(pos.x > ofGetWidth()-radius) {
        pos.x = ofGetWidth()-radius;
        vel.x *= -1;
    }
    if(pos.x < radius) {
        pos.x = radius;
        vel.x *= -1;
    }
    if(pos.y > ofGetHeight()-radius) {
        pos.y = ofGetHeight()-radius;
        vel.y *= -1;
    }
    if(pos.y < radius) {
        pos.y = radius;
        vel.y *= -1;
    }
    
    float age = ofGetElapsedTimef() - born;
    color.a = ofMap(age, 0, 5, 255, 0);
}


// ----------------------------------
void Particle::drawMe()
{
    ofSetColor(color);
    ofCircle(pos, radius);
}


