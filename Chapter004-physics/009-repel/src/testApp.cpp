#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(36);
	ofBackground(200, 200, 200);
    
	gravity.y = 0.01;
	
	for(int i=0; i<10; i++) {
		repellers.push_back(new Repeller());
	}
}

//--------------------------------------------------------------
void testApp::update(){
	ps.applyForce(gravity);
	ps.applyRepellers(repellers);
	ps.update();
	
	if(ps.particles.size() < 200)
		ps.addParticle();
}

//--------------------------------------------------------------
void testApp::draw(){
	ps.draw();
	for(int i=0; i<repellers.size(); i++) {
		repellers[i]->draw();
	}
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
	for(int i=0; i<repellers.size(); i++) {
		repellers[i]->drag(mouseX, mouseY);
	}
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	for(int i=0; i<repellers.size(); i++) {
		repellers[i]->clicked(x, y);
	}
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	for(int i=0; i<repellers.size(); i++) {
		repellers[i]->stopDragging();
	}
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