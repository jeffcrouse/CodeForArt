#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    theCountImage.initGrabber(320, 240);
}

//--------------------------------------------------------------
void testApp::update(){
    xAngle += 5;
    theCountImage.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(255);

    /*
    ofEnableAlphaBlending();
    theCountImage.draw(100, 100);
    ofDisableAlphaBlending();
    */
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2.0, ofGetHeight()/2.0);
    ofRotateX(xAngle);
    
    ofPixels pix = theCountImage.getPixelsRef();
    for(int y=0; y<pix.getHeight(); y++)
    {
        for(int x=0; x<pix.getWidth(); x++)
        {
            ofColor c = pix.getColor(x, y);
            if(c.a > 0)
            {
                float b = c.getBrightness();
                float z = ofMap(b, 0, 255, -100, 100);
                ofSetColor(c);
                ofRect(x, y, z, 1, 1);
            }
        }
    }
    ofPopMatrix();
    
    
    ofSetColor(0);
    ofDrawBitmapString("fps: "+ofToString(ofGetFrameRate()), 10, 20);
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