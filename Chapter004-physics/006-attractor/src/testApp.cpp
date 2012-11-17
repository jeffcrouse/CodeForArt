#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(24);
    
	for(int i=0; i<10; i++) {
		Thing t;
		things.push_back( t );
	}
}

//--------------------------------------------------------------
void testApp::update(){
	for (int i = 0; i < things.size(); i++) {          // For every Thing t[i]
		
		// Thing 1 = things[i]
		
		for(int j = 0; j < things.size(); j++)
		{
			if (i != j)
			{													// Make sure we are not calculating gravtional pull on oneself
				ofPoint f = things[i].calcGravForce(&things[j]);   // Use the function we wrote above
				things[i].applyForce(f);                     // Add the force to the object to affect its acceleration
			}
		}
		
		
		things[i].update();                             // Implement the rest of the object's functionality
	}
	
}

//--------------------------------------------------------------
void testApp::draw(){
	for(int i=0; i<things.size(); i++) {
		things[i].draw();
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