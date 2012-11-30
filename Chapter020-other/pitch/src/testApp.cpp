#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	//setup of sound input
    // 0 output channels,
	// 2 input channels
	// 44100 samples per second
	// 256 samples per buffer
	// 4 num buffers (latency)
	
	soundStream.listDevices();
	soundStream.setup(this, 0, 2, 44100, BUFFER_SIZE, 4);
    
	AAleft.setup();
    AAright.setup();
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::audioIn(float * input, int bufferSize, int nChannels){
    
    float curVol = 0.0;
    
	// samples are "interleaved"
	for (int i = 0; i < bufferSize; i++)
    {
		left[i] = input[i*2];
		right[i] = input[i*2+1];
	}
    
	AAleft.processAudio(left, bufferSize);
    AAright.processAudio(right, bufferSize);
    
    
    pitch = (AAleft.pitch + AAright.pitch) / 2.0;
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(0,0,0);
    for(int x=0; x<BUFFER_SIZE; x++)
    {
        ofRect(x, ofGetHeight()-(left[x]*1000), 1, 1);
    }
    
    float y = ofMap(pitch, 100, 2000, ofGetHeight(), 0);
    ofCircle(ofGetWidth()/2, y, 20);
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