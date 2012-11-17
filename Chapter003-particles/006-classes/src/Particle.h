//
//  Particle.h
//  classes
//
//  Created by Jeffrey Crouse on 11/16/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#pragma once
#include "ofMain.h"

class Particle
{
public:
    
    void initialize(float x=ofRandomWidth(), float y=ofRandomHeight());
    void updateMe();
    void drawMe();

    ofPoint pos;
    ofPoint vel;
    ofColor color;
    float radius;
    float born;
};

