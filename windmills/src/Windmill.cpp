/*
 *  Windmill.cpp
 *  windmill
 *
 *  Created by Jeffrey Crouse on 3/1/11.
 *  Copyright 2011 Eyebeam. All rights reserved.
 *
 */

#include "Windmill.h"

void Windmill::update()
{
	angle += rotateSpeed;
	a = 80 * cos(ofGetFrameNum()/wavelength) + 80;
	
	pos += vel;
	
	if(pos.y > ofGetHeight()) {
		pos.y = ofGetHeight();
		vel.y *= -1;
	}
	if(pos.x > ofGetWidth()) {
		pos.x = ofGetWidth();
		vel.x *= -1;
	}
	if(pos.x < 0) {
		pos.x=0;
		vel.x *= -1;
	}
	if(pos.y < 0) {
		pos.y = 0;
		vel.y *= -1;
	}
}

void Windmill::draw()
{
	ofSetColor(r, g, b, a);
	ofFill();
	ofPushMatrix();
	ofTranslate(pos.x, pos.y);
	ofRotateZ(angle);
	ofScale(scale, scale);
	
	ofEnableAlphaBlending();
	
	ofBeginShape();
	ofVertex(-20, -140);
	ofVertex(80, -140);
	ofVertex(0, 100);
	ofVertex(20, 140);
	ofVertex(-80, 140);
	ofVertex(10, -100);
	ofEndShape(true);
	
	ofDisableAlphaBlending();
	
	ofPopMatrix();
}