#include "testApp.h"

/*
 Things in this program
 1. using velocity/friction to move an object
 2. matrix transformations (sounds scary, but its not)
 3. ofRotate
 4. ofTranslate
 5. Why does the order of matrix operations matter?
 
 
 In-class assignment: 
	- make flames appear behind rocket when key is down
	- make the down key slow the rocket down
	- make the rocket rotate around its center instead of the top
	- Go back to the frogger app and make the frog rotate
	- Use RotateX to create the illusion of an arcade cabinet
 */

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetFrameRate(24);	

	x = ofGetWidth()/2.0;
	y = ofGetHeight()/2.0;
	angle=0;
	friction=.98;
	showFlame=false;
}

//--------------------------------------------------------------
void testApp::update(){

	x += cos(ofDegToRad(angle-90)) * v;
	y += sin(ofDegToRad(angle-90)) * v;
	
	if (abs(v) > .1) {
		v *= friction;
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofSetColor(0, 0, 0);
	ofDrawBitmapString("angle="+ofToString(angle)+" v="+ofToString(v, 2), 20, 20);

	ofPushMatrix();
	
		ofTranslate(x, y);	
		ofRotateZ(angle);
		ofTranslate(0, -105);
	
		// rocket
		ofFill();
		ofTriangle(0, 0, -40, 50, 40, 50);
		ofRect(-40, 50, 80, 160);
		ofTriangle(0, 100, -80, 210, 80, 210);

		if(showFlame)
		{
			ofSetColor(255, 0, 0);
			ofRect(-40, 210, 100, 20);
		}
		
		// bounding box
		ofNoFill();
		//ofRect(-80, 0, 160, 210);
		
	ofPopMatrix();

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

	if(key==OF_KEY_RIGHT)
	{
		angle+=5;
	}
	if(key==OF_KEY_LEFT)
	{
		angle-=5;
	}
	if(key==OF_KEY_UP)
	{
		showFlame=true;
		v += .5;
	}
	if(key==OF_KEY_DOWN)
	{
		v -= .5;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	showFlame=false;
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

