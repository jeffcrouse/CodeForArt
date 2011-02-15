#include "testApp.h"


int rectX;
int rectY;
int rectWidth;
int rectHeight;


//--------------------------------------------------------------
void testApp::setup(){

	ofSetFrameRate(24);
	ofBackground(255, 255, 255);
	
	rectX=50;
	rectY=50;
	rectWidth=300;
	rectHeight=400;
	
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

	ofSetColor(200, 100, 150);
	ofRect(rectX, rectY, rectWidth, rectHeight);
	
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

	if(x>rectX && y> rectY && x < rectX+rectWidth && y < rectY+rectHeight)
	{
		cout << "Clicked in Rectangle" << endl;
	} else {
		cout << "Not in Rectangle" << endl;
	}

	
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

