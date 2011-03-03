/*
 *  Windmill.h
 *  windmill
 *
 *  Created by Jeffrey Crouse on 3/1/11.
 *  Copyright 2011 Eyebeam. All rights reserved.
 *
 */
#include "ofMain.h"

class Windmill {
public:
	
	void draw();
	void update();
	
	ofPoint pos;
	ofPoint vel;
	int r, g, b, a;
	float angle, wavelength, rotateSpeed, scale;
};