//
//  Particle.h
//  classes
//
//  Created by Jeffrey Crouse on 9/23/13.
//
//

#pragma once
#include "ofMain.h"

class Particle
{
public:
    
    void initialize(float x, float y, float xvel, float yvel);
    void updateMe();
    void drawMe();
    
    ofPoint pos;
    ofPoint vel;
    ofColor color;
    float radius;
    float born;
};

