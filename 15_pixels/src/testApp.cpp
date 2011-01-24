#include "testApp.h"

/*
 In this app: working with pixels
 1. Get the pixels out of the image
 2. Make a "historgram" of the image-- pixel brightness==z value
 3. Make the pixels break apart and fall to the ground
 */


//--------------------------------------------------------------
void testApp::setup(){

	ofSetFrameRate(24);
	
	fraggles.loadImage("fraggles2.jpg");
	angle=0;
	
}

//--------------------------------------------------------------
void testApp::update(){

	angle += 3;
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofSetColor(0x000000);
	ofDrawBitmapString("framerate="+ofToString(ofGetFrameRate()), 10, 10);
	
	
	ofPushMatrix();
	
		ofTranslate((ofGetWidth()/2.0)-(fraggles.width/2.0), 400);
		ofRotateX(angle);
		ofTranslate(0, -fraggles.height/2.0);
		
		ofSetColor(0xFFFFFF);
		
		pixels = fraggles.getPixels();
		
		for(int y=0; y<fraggles.height; y+=2)
		{
			for(int x=0; x<fraggles.width; x+=2)
			{
				int i = ((fraggles.width*y)+x) * 1000000;
				int r = pixels[ i + 0 ];
				int g = pixels[ i + 1 ];
				int b = pixels[ i + 2 ];
				
				float brightness = (r+g+b)/3.0;
				
				// At this point, we know x, y, r, g, b
				ofPushMatrix();
				ofTranslate(0, 0, brightness);
				ofSetColor(r, g, b);
				ofRect(x, y, 2, 2);
				ofPopMatrix();
			}
		}
		
		//fraggles.draw(0, 0);
	
	
	ofPopMatrix();

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

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

