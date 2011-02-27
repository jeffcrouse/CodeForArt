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

/**************************** Spline Template Class ****************************/
#pragma once


#include "ofMain.h"
#include "ofxVectorMath.h"

#include "ofxMSASplineInterpolationTypes.h"

template <typename Type> class ofxMSASpline {
public:
	ofxMSASpline() {
		setInterpolation(OFX_MSA_SPLINE_CUBIC);
		setUseDistance(false);
	}
	
	
	// use catmull rom interpolation to re-sample At normT position along the spline
	// where normT: 0....1 based on length of spline
	Type sampleAt(float t) {
		int numItems = size();
		if(numItems == 0) {
			ofLog(OF_LOG_ERROR, "*** ofxMSASpline: Attempting to sampleAt( " + ofToString(t) + " ) while spline is empty ***\n");
			return Type();
		}
		
		if(t>0.9999) t = 0.9999;
		else if(t<0) t=0;
		int i0, i1, i2, i3;
		float mu;
		findPosition(t, i1, mu);
		
		switch(_interpolationMethod) {
			case OFX_MSA_SPLINE_CUBIC:
				i0 = i1 - 1;
				i2 = i1 + 1;
				i3 = i2 + 1;
				
				if(i0 < 0) i0 = 0;
				if(i3 >= numItems) i3 = numItems-1;
				
				return cubicInterpolate(at(i0), at(i1), at(i2), at(i3), mu);
				break;
				
			case OFX_MSA_SPLINE_LINEAR:
				i2 = i1 + 1;
				if(i2 >= numItems) i2 = numItems-1;
				return linearInterpolate(at(i1), at(i2), mu);
				break;
		}
	}
	
	void setInterpolation(int i) {
		_interpolationMethod = i;
	}
	
	int getInterpolation() {
		return _interpolationMethod;
	}
	
	void setUseDistance(bool b) {
		_useDistance = b;
	}
	
	bool getUseDistance() {
		return _useDistance;
	}
	
	// drawing methods dependant on <Type>
	virtual void drawRaw(int dotSize, int lineWidth) {}
	virtual void drawSmooth(int numSteps, int dotSize, int lineWidth) {}
	
	
	/******************* stl::vector wrapper functions *******************/
	void push_back(const Type& newData) {
		_data.push_back(newData);						// add data
		
		if(size() > 1) {
			int prevIndex	= _dist.size()-1;
			Type distT		= newData - _data.at(prevIndex);	// get offset to previous node
			float dist		= fabs(distT);						// actual distance to node
			_dist.push_back(dist + _dist.at(prevIndex));		// push last nodes distance + current distance 
		} else {
			_dist.push_back(0);
		}
	}
	
	int size() {
		return _data.size();
	}
	
	void reserve(int i) {
		_data.reserve(i);
		_dist.reserve(i);
	}
	
	void clear() {
		_data.clear();
		_dist.clear();		
	}
	
	const Type& at(int i) {
		return _data.at(i);
	}
	
	vector<Type> getData() {
		return _data;
	}
	
	
	
protected:
	int _interpolationMethod;
	bool _useDistance;
	vector<Type> _data;				// vector of all data
	vector<float> _dist;			// vector of cumulative distances from i'th data point to beginning of spline
	
	
	// given t(0...1) find the node index directly to the left of the point
	void findPosition(float t, int &leftIndex, float &mu) {
		int numItems = size();
		if(_useDistance) {									// need to use 
//			printf("findPosition: %.4f\n", t);
			float totalDistanceOfSpline = _dist.at(numItems-1);
			float tDist = totalDistanceOfSpline * t;			// the distance we want to be from the start
			int startIndex = floor(t * (numItems - 1));			// start approximation here
			int i1 = startIndex;
			int limitLeft = 0;
			int limitRight = numItems-1;

			float distAt1, distAt2;
			do {
//				printf("startIndex: %i, i1: %i, limitLeft: %i, limitRight: %i\n", startIndex, i1, limitLeft, limitRight);
				distAt1 = _dist.at(i1);
				if(distAt1 <= tDist) {							// if distance at i1 is less than desired distance (this is good)
					distAt2 = _dist.at(i1+1);
					if(distAt2 > tDist) {
						leftIndex = i1;
						mu = (tDist - distAt1) / (distAt2-distAt1);
						return;
					} else {
						limitLeft = i1;
					}
				} else {
					limitRight = i1;
				}
				i1 = (limitLeft + limitRight)>>1;
				
			} while(true);
			
		} else {
			float actT = t * (numItems - 1);
			leftIndex = floor(actT);
			mu = actT - leftIndex;
		}
	}
	
	
	Type linearInterpolate(const Type& y1, const Type& y2, float mu) {
		return (y2-y1) * mu + y1;
	}
	
	
	// this function is from Paul Bourke's site
	// http://local.wasp.uwa.edu.au/~pbourke/miscellaneous/interpolation/
	Type cubicInterpolate(const Type& y0, const Type& y1, const Type& y2, const Type& y3, float mu) {
		float mu2 = mu * mu;
		Type a0 = y3 - y2 - y0 + y1;
		Type a1 = y0 - y1 - a0;
		Type a2 = y2 - y0;
		Type a3 = y1;
		
		return(a0 * mu * mu2 + a1 * mu2 + a2 * mu + a3);
	}
};
