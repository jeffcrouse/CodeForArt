#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetFrameRate(24);
    ofBackground(0);
    
    // Load the font
    string filename = "planet_kosmos.ttf";
    int fontSize = 320;
    bool bAntiAliased = false;
    bool bFullCharacterSet = true;
    bool makeContours = true;
    float simplifyAmt = 0.3; // uses ofPolyline::simplify
    font.loadFont(filename, fontSize, bAntiAliased, bFullCharacterSet, makeContours, simplifyAmt);
    
    
    // Get the bounding box of the text
    text = "KTC";
    bb = font.getStringBoundingBox(text, 0, 0);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0);
    
    int nVerts = 0;
    
    
    ofNoFill();
    ofPushMatrix();
    {
        ofTranslate((ofGetWidth()/2.0)-(bb.getWidth()/2.0), (ofGetHeight()/2.0)+(bb.height/4.0));

        // Create a bunch of Letter objects
        vector<ofPath> letterPaths = font.getStringAsPoints(text);
        for(int i=0; i<letterPaths.size(); i++)
        {
            vector<ofPolyline> lines = letterPaths[i].getOutline();
            for(int j=0; j<lines.size(); j++)
            {
                ofPolyline line = lines[j];
                line.simplify(0.3);
            
                ofBeginShape();
                for(int k=0; k<line.size(); k++)
                {
                    ofVertex(line[k].x, line[k].y);
                    ofCircle(line[k].x, line[k].y, 5);
                    nVerts++;
                }
                ofEndShape(true);
            }
        }
    }
    ofPopMatrix();
    
    
    ofDrawBitmapString("nVerts = "+ofToString(nVerts), 10, 20);
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