#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetFrameRate(24);
    ofBackgroundHex(0xEFDC9E);
    
    
    for(int i=0; i<NUM_PARTICLES; i++)
    {
        radius[i] = ofRandom(5, 10);
        pos[i].x = ofRandom(radius[i], ofGetWidth()-radius[i]);
        pos[i].y = ofRandom(radius[i], ofGetHeight()-radius[i]);
        vel[i].x = ofRandom(-10, 10);
        vel[i].y = ofRandom(-10, 10);
        color[i].setHsb(ofRandom(255), 200, 200);
    }
    
    acc.y = 200;
    friction = 0.9;
}

//--------------------------------------------------------------
void testApp::update(){
    
    ofSetWindowTitle("fps="+ofToString(ofGetFrameRate()));
    
    for(int i=0; i<NUM_PARTICLES; i++)
    {
        vel[i] += acc * ofGetLastFrameTime();
        pos[i] += vel[i] * ofGetLastFrameTime();
        
        // bounce off walls
        if(pos[i].x > ofGetWidth()-radius[i]) {
            pos[i].x = ofGetWidth()-radius[i];
            vel[i].x *= -friction;
        }
        if(pos[i].x < radius[i]) {
            pos[i].x = radius[i];
            vel[i].x *= -friction;
        }
        if(pos[i].y > ofGetHeight()-radius[i]) {
            pos[i].y = ofGetHeight()-radius[i];
            vel[i].y *= -friction;
        }
        if(pos[i].y < radius[i]) {
            pos[i].y = radius[i];
            vel[i].y *= -friction;
        }
        
        for(int j=0; j<NUM_PARTICLES; j++)
        {
            if(i==j) continue;
            float touching = radius[i] + radius[j];
            float dist = ofDist(pos[i].x, pos[i].y, pos[j].x, pos[j].y);
            if(dist < touching)
            {
                // get the mtd
                ofPoint delta = pos[i] - pos[j];
                float d = delta.length();
                // minimum translation distance to push balls apart after intersecting
                ofVec2f mtd = delta * (((radius[i] + radius[j])-d) / d);
                
                // resolve intersection --
                // inverse mass quantities
                float im1 = 1 / radius[i];
                float im2 = 1 / radius[j];
                
                // push-pull them apart based off their mass
                pos[i] += (mtd * (im1 / (im1 + im2)));
                pos[j] -= (mtd * (im2 / (im1 + im2)));
                
                // impact speed
                ofVec2f v = vel[i] - vel[j];
                float vn = v.dot(mtd.normalize());
                
                // sphere intersecting but moving away from each other already
                if (vn > 0.0f) continue;
                
                // collision impulse
                float n = (-(2.0) * vn) / (im1 + im2);
                ofVec2f impulse = mtd * n;
                
                // change in momentum
                vel[i] += impulse * im1 * friction;
                vel[j] = vel[j] - (impulse * im2) * friction;
                
            }
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    for(int i=0; i<NUM_PARTICLES; i++)
    {
        ofSetColor(color[i]);
        ofCircle(pos[i], radius[i]);
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
    for(int i=0; i<NUM_PARTICLES; i++)
    {
        float dist = ofDist(x, y, pos[i].x, pos[i].y);
        if(dist < 100)
        {
            vel[i].y -= 200;
            vel[i].x = ofRandom(-100, 100);
        }
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
