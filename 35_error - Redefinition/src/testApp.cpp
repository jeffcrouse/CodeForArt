#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	framenum=0;
	doCapture=false;
	
	ofSetFrameRate(36);
	ofBackground(200, 200, 200);
	
	
	f1.red = 255;
	f2.red = 0;

	
	for(int i=0; i<80; i++) {
		f1.addBoid();
		f2.addBoid();
	}
}

//--------------------------------------------------------------
void testApp::update(){
	f1.update(&f2);
	f2.update(&f1);
}



//--------------------------------------------------------------
void testApp::draw(){
	f1.draw();
	f2.draw();
	capture();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	if(key=='c') doCapture = !doCapture;
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

//--------------------------------------------------------------
void testApp::capture() {
	if(doCapture && ofGetFrameNum() % 4 == 0)
	{
		char filename[255];
		sprintf(filename, "frame%05d.png", framenum++);
		ofSaveScreen(filename);
	}
}