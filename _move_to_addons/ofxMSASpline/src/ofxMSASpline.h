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

/**************************** Spline Classes ****************************
Usage:
	ofxMSASpline<float>			mySpline1;		// create spline of floats
	ofxMSASpline<myDataType>	mySpline2;		// create spline of custom data types (more info below)
 
// OR use preset classes:
 
	ofxMSASpline1D				mySpline1D;		// create spline of floats (1D)
	ofxMSASpline2D				mySpline2D;		// create spline of ofxVec2f (2D)
	ofxMSASpline3D				mySpline3D;		// create spline of ofxVec3f (3D)
 

// splines wrap basic functionality of stl::vector:
	mySpline.size();				// return number of data elements
	mySpline.reserve(int count);	// if you know how many elements up front it will improved performance when adding (you can still add more than this number of elements)
	mySpline.at(int i);				// return data at i'th index
	mySpline.clear();				// remove all elements
	mySpline.push_back(data1);		// add some data to the spline
	mySpline.push_back(data2);

	mySpline.sampleAt(float t);		// (e.g. t:0.34 =>) samples along 34% of the whole spline using the current interpolation method and options

	setInterpolation(i);			// set interpolation type, see ofxMSASplineInterpolationTypes.h (currently cubic catmull rom and linear)
	int getInterpolation();			// get interpolation type
 
	setUseDistance(bool b);			// whether to use distance or not. using distance is slightly slower than not using (depending on number of data points)
	bool getUseDistance();			// if useDistance is true, sampleAt(0.57) means sample at 57% along the physical length of the spline (using the non interpolation spline for distance calculation)
									// if useDistance is false, the %t refers to % along the data points. If data points are evenly spaced its no problem, but if they are randomly spaced, the interpolation will not be uniform
 
 
	mySpline.drawRaw(int dotSize, int lineWidth);					// draws raw data with dotSize and lineWidth (make either zero to not draw dots or lines)
	mySpline.drawSmooth(int numSteps, int dotSize, int lineWidth);	// draws smoothed data in  (make either zero to not draw dots or lines)
 
Using custom data type:
	ofxMSASpline<myDataType>	mySpline2;		// create spline of custom data types (more info below)
	myDataType has to be a scalar or class with the overloaded operators:
		+  (myDataType&)
		-  (myDataType&)
		== (myDataType&)
		=  (myDataType&)
		*  (float)
	
	and also overload the global function fabs(myDataType&) to return a scalar float value depicting the 'magnitude' of the data type (used in calculating distance)

 
*************************************************************************/

#pragma once

#include "ofxMSASplineInterpolationTypes.h"
#include "ofxMSASplineTemplate.h"
#include "ofxMSASpline1D.h"
#include "ofxMSASpline2D.h"
#include "ofxMSASpline3D.h"
#include "ofxMSASurface3D.h"


