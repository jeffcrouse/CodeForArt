#include "testApp.h"

/*****************
*	In this application:
*	1. Turn pixels into particles
*
*
******************/


//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(24);
	ofBackground(200, 200, 200);


	img.loadImage("busey.jpg");
	
	numPix = img.width * img.height * 3;
	
	pix = img.getPixels();
	
	makePixicles();
}

//--------------------------------------------------------------
void testApp::makePixicles() {
	
	for(int y=0; y<img.width; y+=2)
	{
		for(int x=0; x<img.width; x+=2)
		{
			
			int i = (y * img.width + x) * 3;
			int r = pix[i + 0];
			int g = pix[i + 1];
			int b = pix[i + 2];
			
			p.addParticle(x, y, r, g, b);
		}
	}	
}

//--------------------------------------------------------------
void testApp::update(){
	p.update();
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofPushMatrix();
	ofTranslate(ofGetWidth()/2-img.width/2, 100, 0);
	p.draw();
	ofPopMatrix();

	
	ofSetColor(0x000000);
	ofDrawBitmapString("framerate: "+ofToString(ofGetFrameRate()), 10, 10);
	ofDrawBitmapString("pixicles: "+ofToString((int)p.particles.size()), 10, 24);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	
	p.applyRandomForce();
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
	if(p.particles.size() < 500)
		makePixicles();
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}
