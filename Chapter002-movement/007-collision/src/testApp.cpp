#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(24);
	
	ball_x = 40;
	ball_y = 40;
	ball_r = 20;
	
	ball_x_vel = 15;
	ball_y_vel = 11;
	
	rect_x = 400;
	rect_y = 400;
	rect_w = 200;
	rect_h = 150;
}

//--------------------------------------------------------------
void testApp::update(){
    
	ball_x += ball_x_vel;
	ball_y += ball_y_vel;
	
	if(ball_x > rect_x-ball_r &&
	   ball_x < rect_x+rect_w+ball_r &&
	   ball_y > rect_y-ball_r &&
	   ball_y < rect_y+rect_h+ball_r)
	{
		//ball_x_vel *= -1;
		ball_y_vel *= -1;
	}
	
}

//--------------------------------------------------------------
void testApp::draw(){
	ofFill();
	ofSetColor(0, 0, 0);
	
	ofCircle(ball_x, ball_y, ball_r);
	ofRect(rect_x, rect_y, rect_w, rect_h);
	
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