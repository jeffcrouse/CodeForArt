#include "testApp.h"

/******************
 *	In this application:
 *	1. Calculate the difference between two images
 *	2. Replace one of the images with the live camera image
 */

//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(24);
	ofBackground(200, 200, 200);
	
	mode = 1;

	img1.loadImage("busey.jpg");
	img2.loadImage("brando.jpg");
	result.allocate(img1.width, img1.height, OF_IMAGE_COLOR);
	
	img1Pix = img1.getPixels();
	img2Pix = img2.getPixels();

	numPix = img1.width * img1.height * 3;
}

//--------------------------------------------------------------
void testApp::update(){

	
	unsigned char resultPix[numPix];
	
	// Set the pixels to black
	for (int i=0; i<numPix; i+=3)
	{
		
		// Get the R, G, B, values for img1 and img2
		int img1Red = img1Pix[ i + 0 ];
		int img1Green = img1Pix[ i + 1 ];
		int img1Blue = img1Pix[ i + 2 ];
		
		// Get the R, G, B, values for img1 and img2
		int img2Red = img2Pix[ i + 0 ];
		int img2Green = img2Pix[ i + 1 ];
		int img2Blue = img2Pix[ i + 2 ];
		
		
		resultPix[ i + 0 ] = img1Red - img2Red;
		resultPix[ i + 1 ] = img1Green - img2Green;
		resultPix[ i + 2 ] = img1Blue - img2Blue;
	}
	
	// Loop through all of the pixels.
	
		
	
		// Put some values into resultPix
	
		// Mode 1 = color difference.
			// r = r1 - r2
	
		// Mode 2 = abs difference
			// ie: if the pixels are different enough, black pixel, otherwise, white
	
		// Mode 3 = blend 
		
	// Put the resultPix into the ofImage "result"
	result.setFromPixels(resultPix, img1.width, img1.height, OF_IMAGE_COLOR);

}

//--------------------------------------------------------------
void testApp::draw(){
	ofPushMatrix();
	ofTranslate(230, 200, 0);
	
	img1.draw(30, 0);
	img2.draw(220, 0);
	result.draw(410, 0);

	ofPopMatrix();

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

	if(key == '1') mode = 1;
	if(key == '2') mode = 2;
	if(key == '3') mode = 3;
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