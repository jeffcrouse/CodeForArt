#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
	
	vid_w = 320;
	vid_h = 240;
	
	
	#ifdef _USE_LIVE_VIDEO
        vidGrabber.setVerbose(true);
        vidGrabber.initGrabber(vid_w, vid_h);
	#else
        vidPlayer.loadMovie("fingers.mov");
        vidPlayer.play();
	#endif

    colorImg.allocate(vid_w, vid_h);
	grayImage.allocate(vid_w,vid_h);
	prevFrame.allocate(vid_w, vid_h);
	grayBg.allocate(vid_w,vid_h);
	grayDiff.allocate(vid_w,vid_h);
	flow.init(vid_w, vid_h);
	flow.filterPoints(-40, 40);
	
	bLearnBakground = true;
	threshold = 80;
	

}

//--------------------------------------------------------------
void testApp::update(){
	ofBackground(100,100,100);

    bool bNewFrame = false;

	#ifdef _USE_LIVE_VIDEO
       vidGrabber.grabFrame();
	   bNewFrame = vidGrabber.isFrameNew();
    #else
        vidPlayer.idleMovie();
        bNewFrame = vidPlayer.isFrameNew();
	#endif

	if (bNewFrame){

		#ifdef _USE_LIVE_VIDEO
            colorImg.setFromPixels(vidGrabber.getPixels(), vid_w, vid_h);
	    #else
            colorImg.setFromPixels(vidPlayer.getPixels(), vid_w, vid_h);
        #endif

		colorImg.mirror(false, true);
        grayImage = colorImg;
		
		if (bLearnBakground == true){
			grayBg = grayImage;		// the = sign copys the pixels from grayImage into grayBg (operator overloading)
			bLearnBakground = false;
		}

		
		
		// take the abs value of the difference between background and incoming and then threshold:
		prevFrame = grayDiff;
		grayDiff.absDiff(grayBg, grayImage);
		grayDiff.threshold(threshold);
		
		if(ofGetFrameNum()>1)
			flow.calc(grayDiff, prevFrame);
		
		// find contours which are between the size of 20 pixels and 1/3 the w*h pixels.
		// also, find holes is set to true so we will get interior contours as well....
		//contourFinder.findContours(grayDiff, 20, (340*240)/3, 10, true);	// find holes
	}

}


// Renders a vector object 'v' as an arrow and a location 'loc'
void testApp::drawVector(ofPoint loc, ofPoint vel, float scayl) {
	
	float angle = (float)atan2(-vel.y, vel.x);
    float theta =  -1.0 * angle;
	float heading2D = ofRadToDeg(theta);
	float mag = sqrt(vel.x*vel.x + vel.y*vel.y);
	
	
	ofNoFill();
	
	ofPushMatrix();
	float arrowsize = 5;
	// Translate to location to render vector
	ofTranslate(loc.x,loc.y);
	// Call vector heading function to get direction (note that pointing up is a heading of 0) and rotate
	ofRotate(heading2D);
	// Calculate length of vector & scale it to be bigger or smaller if necessary
	float len = mag*scayl;
	// Draw three lines to make an arrow (draw pointing up since we've rotate to the proper direction)
	ofLine(0,0,len,0);
	ofLine(len, 0, len-arrowsize, +arrowsize/2);
	ofLine(len, 0, len-arrowsize, -arrowsize/2);
	ofPopMatrix();
}

//--------------------------------------------------------------
void testApp::draw(){

	
	// draw the incoming, the grayscale, the bg and the thresholded difference
	ofSetColor(0xffffff);
	ofPushMatrix();
	ofTranslate((ofGetWidth()/2)-320, 300, 0);
	
	//ofScale(ofGetWidth()/(float)vid_w, ofGetHeight()/(float)vid_h, 1);
	
	colorImg.draw(0,0);
	//grayImage.draw(0, 0);
	flow.draw(0, 0);
	
	
	ofPoint avg = flow.getAverageFlow();
	avg *= 2.0;
	
	
	ofPoint dir = avg - globalDir;
	float dist = ofDist(avg.x, avg.y, globalDir.x, globalDir.y);
	dist = ofClamp(dist, 0, 25.0);
	globalDir += dir / 30.0;
	
	
	ofTranslate(320, 0);
	
	ofSetColor(0x000000);
	ofNoFill();
	ofRect(0, 0, 320, 240);	
	for(int x=20; x<320; x+=20) {
		ofLine(x, 0, x, 240);
	}
	for(int y=20; y<240; y+=20) {
		ofLine(0, y, 320, y);
	}
	
	
	
	ofSetColor(0xffffff);
	char reportStr[1024];
	sprintf(reportStr, "press ' ' to capture bg\nthreshold %i (press: +/-)\nfps: %f", threshold, ofGetFrameRate());
	ofDrawBitmapString(reportStr, 20, 200);
	ofTranslate(160, 120);
	
	ofSetColor(255, 0, 0);
	drawVector(ofPoint(0, 0), globalDir, 10);
	

	ofPopMatrix();
}


//--------------------------------------------------------------
void testApp::keyPressed  (int key){

	switch (key){
		case ' ':
			bLearnBakground = true;
			break;
		case '+':
			threshold ++;
			if (threshold > 255) threshold = 255;
			break;
		case '-':
			threshold --;
			if (threshold < 0) threshold = 0;
			break;
	}
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

