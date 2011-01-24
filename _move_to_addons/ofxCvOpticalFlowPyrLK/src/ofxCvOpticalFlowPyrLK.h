/* 
 * Copyright (c) 2009, Rui Madeira
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * http://creativecommons.org/licenses/LGPL/2.1/
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#pragma once

#include "ofxOpenCv.h"
#include "ofxCvFlowPoint.h"
#define MAX_CORNERS 500


class ofxCvOpticalFlowPyrLK{
protected:
	IplImage* eigImg, *tempImg, *pyrPrev, *pyrCurr;
	int width, height;
	float invWidth, invHeight;
	CvPoint2D32f * cornersPrev, *cornersCurr;
	char featuresFound[MAX_CORNERS];
	float featuresErrors[MAX_CORNERS];
	CvSize windowSize;
	vector<ofxCvFlowPoint>flowPoints;
public:
	
	ofxCvOpticalFlowPyrLK();
	~ofxCvOpticalFlowPyrLK();
	
	void init(int _imgWidth, int _imgHeight, int _windowWidth = 5, int _windowHeight = 5);
	void calc(ofxCvGrayscaleImage& currentFrame, ofxCvGrayscaleImage& prevFrame);
	void draw(float x = 0.0f, float y = 0.0f); 
	void clear();
	vector<ofxCvFlowPoint>& getFlowPoints();
	int getNumFlowPoints();
	void scalePointsLocalToGlobal();
	void scalePoints(float scaleX, float scaleY);
	void scalePointsToScreen();
	void normalizePoints();
	void filterPoints(float minFlow, float maxFlow);
	ofPoint getAverageFlow();
};
