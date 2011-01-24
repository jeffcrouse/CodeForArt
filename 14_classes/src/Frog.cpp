/*
 *  Frog.cpp
 *  01_classes
 *
 *  Created by Jeffrey Crouse on 10/5/10.
 *  Copyright 2010 Eyebeam. All rights reserved.
 *
 */

#include "Frog.h"


void Frog::setup(int x, int y, int scale, int angle) {
	
	this->x = x;
	this->y = y;
	this->scale = scale;
	this->angle = angle;
}


bool Frog::isHappy() {
	
	if(ofRandom(0, 2)==1)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

void Frog::moveTowards(int xpos, int ypos) {

	float speed = 10 * scale;
	
	int dist_x = xpos - x;
	x += dist_x / speed;
	
	int dist_y = ypos - y;
	y += dist_y / speed;
}

void Frog::draw() {
	
	ofPushMatrix(); // save translation matrix
	
	ofTranslate(x, y);
	ofRotateZ(angle);
	ofScale(scale, scale, 1);
	ofTranslate(-11, -7);	// translate back 1/2 of size of frog
	
	//ofNoFill();
	//ofRect(0, 0, 22, 15);
	
	
	// Draw frog body
	ofSetColor(32, 219, 36);
	ofFill();
	ofBeginShape();
	ofVertex(9, 1);
	ofVertex(13, 1);
	ofVertex(14, 4);
	ofVertex(17, 6);
	ofVertex(18, 5);
	ofVertex(18, 1);
	ofVertex(21, 3);
	ofVertex(19, 4);
	ofVertex(19, 8);
	ofVertex(16, 7);
	ofVertex(19, 9);
	ofVertex(20, 10);
	ofVertex(21, 14);
	ofVertex(18, 15);
	ofVertex(18, 11);
	ofVertex(15, 10);
	ofVertex(13, 13);
	ofVertex(8, 13);
	ofVertex(7, 11);
	ofVertex(5, 10);
	ofVertex(4, 15);
	ofVertex(1, 13);
	ofVertex(3, 11);
	ofVertex(4, 8);
	ofVertex(6, 9);
	ofVertex(6, 7);
	ofVertex(3, 7);
	ofVertex(3, 4);
	ofVertex(1, 3);
	ofVertex(5, 1);
	ofVertex(4, 6);
	ofVertex(8, 4);
	ofVertex(9, 1);
	ofEndShape();
	
	// Draw yellow spot on back
	ofSetColor(248, 235, 21);
	ofBeginShape();
	ofVertex(10, 3);
	ofVertex(12, 3);
	ofVertex(14, 11);
	ofVertex(9, 11);
	ofVertex(14, 11);
	ofVertex(8, 5);
	ofVertex(9, 3);
	ofEndShape();
	
	// Draw eyes
	ofSetColor(253, 3, 217);
	ofCircle(7, 3, 2);
	ofCircle(15, 3, 2);
	
	
	ofPopMatrix();	
}