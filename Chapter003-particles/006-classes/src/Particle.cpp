//
//  Particle.cpp
//  classes
//
//  Created by Jeffrey Crouse on 9/23/13.
//
//

#include "Particle.h"


// ----------------------------------
void Particle::initialize(float x, float y, float xvel, float yvel)
{
    radius = ofRandom(10, 20);
    born = ofGetElapsedTimef();
    pos.set(x, y);
    vel.set(xvel, yvel);
    color.setHsb(ofRandom(255), 200, 200);
}


// ----------------------------------
void Particle::updateMe()
{
    pos += ofGetLastFrameTime() * vel;
    
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

