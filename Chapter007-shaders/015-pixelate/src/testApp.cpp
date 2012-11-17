#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    cam.initGrabber(640, 480);

	shader.load("shaders/pixelate");
    
	divisor.set(20, 20);
}

//--------------------------------------------------------------
void testApp::update(){
    cam.update();
    
}

//--------------------------------------------------------------
void testApp::draw(){

    shader.begin();
    shader.setUniform2f("sampleDivisor", divisor.x, divisor.y);
    ofSetColor(255, 255, 255);
    cam.draw(0, 0, 1024, 768);
    shader.end();
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

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}