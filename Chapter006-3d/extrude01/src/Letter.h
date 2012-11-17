//
//  Letter.h
//  extrude
//
//  Created by Jeffrey Crouse on 10/24/12.
//
//

#pragma once
#include "ofMain.h"

class Letter {
public:
    ofMesh front;
    ofMesh back;

    void setup(ofPath letter, float depth);
    void draw();
};