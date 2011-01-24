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

#include "ofxCvOpticalFlowPyrLK.h"

ofxCvOpticalFlowPyrLK::ofxCvOpticalFlowPyrLK(){
	eigImg = tempImg = pyrPrev = pyrCurr = NULL;
	cornersPrev = cornersCurr = NULL;
	invWidth = invHeight = 0.0f;
}

ofxCvOpticalFlowPyrLK::~ofxCvOpticalFlowPyrLK(){
	clear();
}

void ofxCvOpticalFlowPyrLK::init(int _imgWidth, int _imgHeight, int _windowWidth, int _windowHeigth){
	clear();
	width = _imgWidth;
	height = _imgHeight;
	invWidth = 1.0f/(float)width;
	invHeight = 1.0f/(float)height;
	windowSize = cvSize(_windowWidth, _windowHeigth);
	cornersPrev = new CvPoint2D32f[MAX_CORNERS];
	cornersCurr = new CvPoint2D32f[MAX_CORNERS];
	CvSize _size = cvSize(width, height);
	eigImg = cvCreateImage(_size, IPL_DEPTH_32F, 1);
	tempImg = cvCreateImage(_size, IPL_DEPTH_32F, 1);
	CvSize _pyrSize = cvSize(width+8, height/3);
	pyrPrev = cvCreateImage(_pyrSize, IPL_DEPTH_32F, 1);
	pyrCurr = cvCreateImage(_pyrSize, IPL_DEPTH_32F, 1);
	flowPoints.reserve(MAX_CORNERS);
}

void ofxCvOpticalFlowPyrLK::calc(ofxCvGrayscaleImage& prevFrame, ofxCvGrayscaleImage& currentFrame){
	int cornerCount = MAX_CORNERS;
	cvGoodFeaturesToTrack(prevFrame.getCvImage(), eigImg, tempImg, cornersPrev, &cornerCount, 0.01, 5.0, 0, 3, 0, 0.04);
	
	cvFindCornerSubPix(prevFrame.getCvImage(), cornersPrev, cornerCount, 
					   windowSize, cvSize(-1,-1), 
					   cvTermCriteria(CV_TERMCRIT_ITER|CV_TERMCRIT_EPS, 20, 0.03));

	cvCalcOpticalFlowPyrLK(prevFrame.getCvImage(), currentFrame.getCvImage(), pyrPrev, 
						   pyrCurr, cornersPrev, cornersCurr, cornerCount, windowSize, 
						   5, featuresFound, NULL,
						   cvTermCriteria(CV_TERMCRIT_ITER|CV_TERMCRIT_EPS, 20, 0.03), 0);
	
	flowPoints.clear();
	for(int i=0; i<cornerCount; i++){
		if(featuresFound[i] == 0){
			continue;
		}
		flowPoints.push_back(ofxCvFlowPoint(cornersPrev[i].x, cornersPrev[i].y, cornersCurr[i].x, cornersCurr[i].y));
	}
}

void ofxCvOpticalFlowPyrLK::draw(float x, float y){
	vector<float> coords;
	for(int i=0; i<flowPoints.size(); i++){
		coords.push_back(flowPoints[i].x+x);
		coords.push_back(flowPoints[i].y+y);
		coords.push_back(flowPoints[i].oldPosition.x+x);
		coords.push_back(flowPoints[i].oldPosition.y+y);
	}
	glColor3f(1.0f, 1.0f, 1.0f);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2, GL_FLOAT, 0, &coords[0]);
	glDrawArrays(GL_LINES, 0, flowPoints.size());
	
	glColor3f(1.0f, 0.0f, 0.0f);
	ofFill();
	for(int i=0; i<coords.size(); i+=4){
		ofCircle(coords[i], coords[i+1], 1);
	}
	
}

void ofxCvOpticalFlowPyrLK::clear(){
	if(cornersPrev)delete[] cornersPrev;
	if(cornersCurr)delete[] cornersCurr;
	if(eigImg)cvReleaseImage(&eigImg);
	if(tempImg)cvReleaseImage(&tempImg);
	if(pyrPrev)cvReleaseImage(&pyrPrev);
	if(pyrCurr)cvReleaseImage(&pyrCurr);
	flowPoints.clear();
}

int ofxCvOpticalFlowPyrLK::getNumFlowPoints(){
	return flowPoints.size();	
}

vector<ofxCvFlowPoint>& ofxCvOpticalFlowPyrLK::getFlowPoints(){
	return flowPoints;
}

void ofxCvOpticalFlowPyrLK::normalizePoints(){
	for(int i=0; i<flowPoints.size(); i++){
		flowPoints[i].x *= invWidth;
		flowPoints[i].y *= invHeight;
		flowPoints[i].oldPosition.x *= invWidth;
		flowPoints[i].oldPosition.y *= invHeight;
		flowPoints[i].difference.x *= invWidth;
		flowPoints[i].difference.y *= invHeight;
	}
}

void ofxCvOpticalFlowPyrLK::scalePoints(float scaleX, float scaleY){
	for(int i=0; i<flowPoints.size(); i++){
		flowPoints[i].x *= scaleX;
		flowPoints[i].y *= scaleY;
		flowPoints[i].oldPosition.x *= scaleX;
		flowPoints[i].oldPosition.y *= scaleY;
		flowPoints[i].difference.x *= scaleX;
		flowPoints[i].difference.y *= scaleY;
	}
}

void ofxCvOpticalFlowPyrLK::scalePointsToScreen(){
	float scaleX = (float)ofGetWidth() / (float)width;
	float scaleY = (float)ofGetHeight() / (float)height;
	scalePoints(scaleX, scaleY);
}	

void ofxCvOpticalFlowPyrLK::filterPoints(float minFlow, float maxFlow){
	float minFlowSQ = minFlow*minFlow;
	float maxFlowSQ = maxFlow*maxFlow;
	float distSQ;
	vector<ofxCvFlowPoint>filtered;
	for(int i=0; i<flowPoints.size(); i++){
		distSQ = flowPoints[i].getDistanceSquared();
		if(distSQ > minFlowSQ and distSQ < maxFlowSQ){
			filtered.push_back(flowPoints[i]);
		}
	}
	flowPoints.clear();
	flowPoints = filtered;
}

ofPoint ofxCvOpticalFlowPyrLK::getAverageFlow(){
	ofPoint avg;
	for(int i=0; i<flowPoints.size(); i++){
		avg += flowPoints[i].difference;
	}
	avg /= flowPoints.size();
	return avg;
}

