#include "testApp.h"

/*
 In this program
 1. make "frog food" on mouse click
 1. Assignment: make the frog move towards the food
 2. Classes!
 */


//--------------------------------------------------------------
void testApp::setup(){

	ofSetFrameRate(24);
	ofBackground(255, 255, 255);
	
	for(int i=0; i<50; i++) {
	
		myFrogs.push_back( Frog() );
		
		int x = ofRandomWidth();
		int y = ofRandomHeight();
		int scale = ofRandom(1, 5);
		int angle = ofRandom(0, 360);
		
		myFrogs[i].setup(x, y, scale, angle);
		
	}
	
	food_x = 50;
	food_y = 200;
}

//--------------------------------------------------------------
void testApp::update(){
	
	for(int i=0; i<50; i++) {
		myFrogs[i].moveTowards(food_x, food_y);
	}
	//pablo.moveTowards(food_x, food_y);
	
}

//--------------------------------------------------------------
void testApp::draw(){

	ofSetColor(0, 0, 0);
	ofCircle(food_x, food_y, 5);
	
	for(int i=0; i<50; i++) {
		
		if(myFrogs[i].isHappy()==true) 
		{
			cout << "I'm happy!" << endl;
		}
		myFrogs[i].draw();
	}
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

	if(key == 't' || key == 'T') 
	{
		cout << "you pressed 'T'" << endl;
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

	food_x = x;
	food_y = y;
	
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

