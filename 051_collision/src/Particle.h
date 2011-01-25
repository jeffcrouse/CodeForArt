/*
 *  Particle.h
 *  opencvExample
 *
 *  Created by Jeffrey Crouse on 10/12/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 */

#include "ofMain.h"
#include "ofxCvBlob.h"


class Particle {
public:
	
	// functions
	void setup();
	void draw();
	void update(vector<ofRectangle>  blobs);
	static bool isColliding(ofRectangle a, ofRectangle b);
	
	// variables
	ofRectangle boundingBox;
	int r, g, b;
	ofPoint velocity;
	
};