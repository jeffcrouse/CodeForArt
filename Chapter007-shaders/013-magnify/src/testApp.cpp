#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    cam.initGrabber(640, 480);
    bDrawSquares = true;
    buffer.allocate(ofGetWidth(), ofGetHeight());
    shader.load("zoom");
    
    radius = 120;
}

//--------------------------------------------------------------
void testApp::update(){
    cam.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    buffer.begin();
    cam.draw(0, 0, 1024, 768);
    
    if(bDrawSquares)
    {
        ofSetColor(255);
        for(int y = 0; y<ofGetHeight(); y+=10)
            for(int x=0; x<ofGetWidth(); x+=10) {
                ofRect(x, y, 5, 5);
            }
    }
    buffer.end();
    
    
    shader.begin();
    shader.setUniform2f("circlePos", mouseX, mouseY);
    shader.setUniform1f("circleRadius", radius);
    shader.setUniform1f("minZoom", 0.1);
    shader.setUniform1f("maxZoom", 1);
    buffer.draw(0, 0);
    shader.end();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    if(key==' ') {
        bDrawSquares = !bDrawSquares;
    }
    if(key==OF_KEY_UP && radius < 300) {
        radius += 10;
    }
    if(key==OF_KEY_DOWN && radius > 20) {
        radius -= 10;
    }
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