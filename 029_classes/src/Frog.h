/*
 *  Frog.h
 *  01_classes
 *
 *  Created by Jeffrey Crouse on 10/5/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 */

#include "ofMain.h"

class Frog {
public:
	
	int x;
	int y;
	int angle;
	int scale;
	
	void setup(int _x, int _y, int _scale, int _angle);
	void draw();
	void moveTowards(int xpos, int ypos);
	bool isHappy();
};