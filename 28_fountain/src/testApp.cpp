#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofSetFrameRate(36);
	ofBackground(200, 200, 200);
	
	framenum=0;
	doCapture=false;
	
	gravity.y = 0.2;	
}

//--------------------------------------------------------------
void testApp::update(){
	
	ps.applyForce(gravity);
	ps.update();

	for(int i=0; i<10; i++) {
		ps.addParticle(ofGetWidth()/2, ofGetHeight()-10);
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	ps.draw();
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
	//r.drag(x, y);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	//r.clicked(x, y);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	//r.stopDragging();
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