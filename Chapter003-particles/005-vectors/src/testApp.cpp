#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetFrameRate(24);
    ofBackgroundHex(0xEFDC9E);
    ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::update(){
    
    for(int i=0; i<pos.size(); i++)
    {
        pos[i] += vel[i];

        // bounce off walls
        if(pos[i].x > ofGetWidth()-radius[i]) {
            pos[i].x = ofGetWidth()-radius[i];
            vel[i].x *= -1;
        }
        if(pos[i].x < radius[i]) {
            pos[i].x = radius[i];
            vel[i].x *= -1;
        }
        if(pos[i].y > ofGetHeight()-radius[i]) {
            pos[i].y = ofGetHeight()-radius[i];
            vel[i].y *= -1;
        }
        if(pos[i].y < radius[i]) {
            pos[i].y = radius[i];
            vel[i].y *= -1;
        }
        
        float age = ofGetElapsedTimef() - born[i];
        color[i].a = ofMap(age, 0, 5, 255, 0);
        
        if(color[i].a < 10)
        {
            radius.erase(radius.begin() + i);
            pos.erase(pos.begin()+i);
            vel.erase(vel.begin()+i);
            color.erase(color.begin()+i);
            born.erase(born.begin()+i);
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    for(int i=0; i<pos.size(); i++)
    {
        ofSetColor(color[i]);
        ofCircle(pos[i], radius[i]);
    }
    
    ofSetColor(0);
    ofDrawBitmapString("particles="+ofToString(pos.size()), 10, 20);
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
void testApp::mouseDragged(int x, int y, int button) {
    
    radius.push_back( ofRandom(10, 20) );
    pos.push_back( ofPoint(x, y) );
    vel.push_back( ofPoint(ofRandom(-10, 10), ofRandom(-10, 10)) );
    color.push_back( ofColor::fromHsb(ofRandom(255), 200, 200) );
    born.push_back( ofGetElapsedTimef() );
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