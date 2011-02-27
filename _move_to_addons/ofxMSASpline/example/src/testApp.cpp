/***********************************************************************
 
 Copyright (c) 2008, 2009, Memo Akten, www.memo.tv
 *** The Mega Super Awesome Visuals Company ***
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of MSA Visuals nor the names of its contributors 
 *       may be used to endorse or promote products derived from this software
 *       without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS 
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE 
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE. 
 *
 * ***********************************************************************/ 

#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	ofSetVerticalSync(true);
	rotateView = true;
	currentRot = 0;
	
	// create a 2D spline with ofxVec2f's
	int numItems = 10;
	int padding = 30;
	float len = (ofGetWidth() - padding*2.0f) / numItems;
	
	spline2D.reserve(numItems);		// not essential, but good habit if you know how big its gonna be
	for(int i=0; i<numItems; i++) {
		ofxVec2f v = ofxVec2f(i * len + padding - ofGetWidth()/2, ofGetHeight()/2 + ofGetHeight()*0.2f * cos(i*0.9));
		spline2D.push_back(v);
	}	
	
	glEnable(GL_DEPTH_TEST);
}


//--------------------------------------------------------------
void testApp::draw() {
	glPushMatrix();
	glTranslatef(ofGetWidth()/2, 0, 0);
	if(rotateView) {
		currentRot += 0.2;
		glRotatef(currentRot, 0, 1, 0);
	} else {
		currentRot = 0;
	}
	
	
	int numSteps = floor(mouseX / (float)ofGetWidth() * 1000);
	if(numSteps<10) numSteps = 10;
	float spacing = 1.0/numSteps;	
	
	// draw raw ofxVec2fs
	ofSetColor(0xFFFFFF);
	spline2D.drawRaw();
	
	// draw cubic interpolated ofxVec2fs
	ofSetColor(0x0000FF);
	spline2D.drawSmooth(numSteps);
	
	// draw raw spline2D
	ofSetColor(0xFFFFFF);
	splineMouse.drawRaw();
	
	// draw cubic interpolated spline2D
	ofSetColor(0xFF0000);
	splineMouse.drawSmooth(numSteps);
	
	glPopMatrix();
	

	ofSetColor(0);
	string uiLin = splineMouse.getInterpolation() == OFX_MSA_SPLINE_LINEAR ? "* " : "  ";
	string uiCub = splineMouse.getInterpolation() == OFX_MSA_SPLINE_CUBIC ? "* " : "  ";
	string uiDist = splineMouse.getUseDistance() ? "* " : "  ";
	ofDrawBitmapString( ofToString(ofGetFrameRate(), 2) + "\n"
					   + "numSteps (resampling resolution - mouseX to change): " + ofToString(numSteps) + "\n"
					   + "mouse click around the area to draw a 3D spline\n"
					   + "\n"
					   + uiLin + "'1' to use linear interpolation\n"
					   + uiCub + "'2' to use cubic (catmull rom) interpolation\n"
					   + "\n"
					   + uiDist + "'d' to toggle 'using distance in interpolation'\n"
					   + "\n"
					   + "'c' to clear 3D spline\n"
					   , 20, 20);
	
}

void testApp::keyPressed(int key) {
	switch(key) {
		case '1':
			splineMouse.setInterpolation(OFX_MSA_SPLINE_LINEAR);
			spline2D.setInterpolation(OFX_MSA_SPLINE_LINEAR);
			break;
		case '2':
			splineMouse.setInterpolation(OFX_MSA_SPLINE_CUBIC);
			spline2D.setInterpolation(OFX_MSA_SPLINE_CUBIC);
			break;
			
		case 'd':
			splineMouse.setUseDistance(!splineMouse.getUseDistance());
			spline2D.setUseDistance(splineMouse.getUseDistance());
			break;
			
		case 'c':
		case 'C':
			splineMouse.clear();
			break;
			
		case 'r':
		case 'R':
			rotateView ^= true;
			break;
	}
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button) {
	ofxVec3f pt;
	pt.set(x-ofGetWidth()/2, y, 0);
	pt.rotate(-currentRot, ofxVec3f(0, 1, 0));
	splineMouse.push_back(pt);
}

