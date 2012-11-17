#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    light.enable();
    ofEnableSeparateSpecularLight();
    
    shader.load("cheen");
    lut.loadImage("LUTs/cheen-lut_blueGreen2.png");
    
    
    glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_RECTANGLE_ARB);
    ofEnableAlphaBlending();
	ofEnableNormalizedTexCoords();
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    lut.draw(5, 5);
    
    cam.begin();
    
    float weight = ofMap(mouseX, 0, ofGetWidth(), 0.5, 1);
    
    shader.begin();
    shader.setUniformTexture("Tex0", lut.getTextureReference(), 0);
    shader.setUniform2f("textureSize", lut.getWidth(), lut.getHeight());
    shader.setUniform1f("alpha", weight);
    shader.setUniform4f("eyePosition", 0.0, 0.0, 1000.0, 0.0);
    
    ofBox(0, 0, 0, 200);
    
    shader.end();
    
    
    cam.end();
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