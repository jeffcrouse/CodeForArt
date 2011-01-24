#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){

	ofSetFrameRate(24);

	#ifdef _USE_LIVE_VIDEO
        vidGrabber.setVerbose(true);
        vidGrabber.initGrabber(320,240);
	#else
        vidPlayer.loadMovie("fingers.mov");
        vidPlayer.play();
	#endif

    colorImg.allocate(320,240);
	grayImage.allocate(320,240);
	grayBg.allocate(320,240);
	grayDiff.allocate(320,240);

	bLearnBakground = true;
	threshold = 80;
	
	// Set up the particles -- JC
	for(int i=0; i<100; i++)
	{
		particles.push_back( Particle() );
		particles[i].setup();
	}
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
            colorImg.setFromPixels(vidGrabber.getPixels(), 320,240);
	    #else
            colorImg.setFromPixels(vidPlayer.getPixels(), 320,240);
        #endif

        grayImage = colorImg;
		if (bLearnBakground == true){
			grayBg = grayImage;		// the = sign copys the pixels from grayImage into grayBg (operator overloading)
			bLearnBakground = false;
		}

		// take the abs value of the difference between background and incoming and then threshold:
		grayDiff.absDiff(grayBg, grayImage);
		grayDiff.threshold(threshold);

		// find contours which are between the size of 20 pixels and 1/3 the w*h pixels.
		// also, find holes is set to true so we will get interior contours as well....
		contourFinder.findContours(grayDiff, 20, (340*240)/3, 10, true);	// find holes
	}

	// We need to make a vector of Rectangles and scale them up to screen-size
	vector<ofRectangle> boundingBoxes;
	for (int i = 0; i < contourFinder.blobs.size(); i++)
	{
		ofRectangle blobBox = contourFinder.blobs[i].boundingRect;
		blobBox.x = (blobBox.x / 320) * ofGetWidth();
		blobBox.y = (blobBox.y / 240) * ofGetHeight();
		blobBox.width = (blobBox.width / 320) * ofGetWidth();
		blobBox.height = (blobBox.height / 240) * ofGetHeight();
		boundingBoxes.push_back( blobBox );
	}
	
	
	// Update the particles, passing them all of the blob locations/sizes -- JC
	for(int i=0; i<particles.size(); i++)
	{
		particles[i].update( boundingBoxes );
	}
}

//--------------------------------------------------------------
void testApp::draw(){

	// draw the incoming, the grayscale, the bg and the thresholded difference
	ofSetColor(0xffffff);
	//colorImg.draw(20,20);
	//grayImage.draw(360,20);
	//grayBg.draw(20,280);
	//grayDiff.draw(360,280);

	// then draw the contours:

	//ofFill();
	//ofSetColor(0x333333);
	//ofRect(360,540,320,240);
	ofSetColor(0xffffff);

	// we could draw the whole contour finder
	//contourFinder.draw(360,540);

	// or, instead we can draw each blob individually,
	// this is how to get access to them:
	ofNoFill();
	contourFinder.draw(0, 0, ofGetWidth(), ofGetHeight());

	
	// Draw the particles -- JC
	for(int i=0; i<particles.size(); i++)
	{
		particles[i].draw();
	}
	
	
	
	// finally, a report:

	ofSetColor(0xffffff);
	char reportStr[1024];
	sprintf(reportStr, "bg subtraction and blob detection\npress ' ' to capture bg\nthreshold %i (press: +/-)\nnum blobs found %i, fps: %f", threshold, contourFinder.nBlobs, ofGetFrameRate());
	ofDrawBitmapString(reportStr, 20, 600);

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

