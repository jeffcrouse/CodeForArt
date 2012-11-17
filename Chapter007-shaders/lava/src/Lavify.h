//
//  Lavify.h
//  emptyExample
//
//  Created by Jeffrey Crouse on 7/26/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#pragma once
#include "ofMain.h"

class Lavify {
public:
    Lavify() {
        amount = 4;
        iterations = 4;
        thresh = 0.9;
    }
    void setup(float width, float height);
    void begin();
    void end();
    void draw();
    
    float thresh;
    float amount;
    int iterations;
    ofShader hBlur, vBlur, threshold;
    ofFbo buffer[2];
};