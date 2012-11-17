#include "testApp.h"

//
// a template for receiving face tracking osc messages from
// Kyle McDonald's FaceOSC https://github.com/kylemcdonald/ofxFaceTracker/downloads
//
// 2012 Dan Wilcox danomatika.com
// for the IACD class at the CMU School of Art
//
// adapted from Greg Borenstein's Processing example
// https://gist.github.com/1603230
//

//--------------------------------------------------------------
void testApp::setup(){
    // FaceOSC sends to port 8338 by default
	receiver.setup(8338);
    
	ofBackground(255);
}

//--------------------------------------------------------------
void testApp::update(){
	// check for waiting osc messages
	while(receiver.hasWaitingMessages())
	{
		// get the next message
		ofxOscMessage m;
		receiver.getNextMessage(&m);
        
        // load face from any FaceOSC messages
        face.parseOSC(m);
	}
    
    
    if(face.found > 0)
    {
        cout << face.toString();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    // draw a face
    if(face.found > 0)
    {
        ofPushMatrix();
        ofTranslate(face.posePosition);
        ofScale(face.poseScale, face.poseScale);
        
        ofSetColor(0);
        ofNoFill();
        ofEllipse(-20, face.eyeLeft * -9, 20, 7);
        ofEllipse(20, face.eyeRight * -9, 20, 7);
        ofEllipse(0, 20, face.mouthWidth * 3, face.mouthHeight * 3);
        ofEllipse(-5, face.nostrils * -1, 7, 3);
        ofEllipse(5, face.nostrils * -1, 7, 3);
        
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofFill();
        ofRect(-20, face.eyebrowLeft * -5, 25, 5);
        ofRect(20, face.eyebrowRight * -5, 25, 5);
        ofSetRectMode(OF_RECTMODE_CORNER);
        ofPopMatrix();
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