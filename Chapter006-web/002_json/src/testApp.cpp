#include "testApp.h"

/*
 This is what the reponse looks like:
 
 {"trends":
	 {"2010-11-16 21:00:00":
		 [
			 {"promoted_content":null,"query":"Prince William","name":"Prince William","events":null},
			 {"promoted_content":null,"query":"Kate Middleton","name":"Kate Middleton","events":null},
			 {"promoted_content":null,"query":"Playing God","name":"Playing God","events":null},
			 {"promoted_content":null,"query":"Halladay","name":"Halladay","events":null},
			 {"promoted_content":null,"query":"Eid Mubarak","name":"Eid Mubarak","events":null},
			 {"promoted_content":null,"query":"Giunta","name":"Giunta","events":null},
			 {"promoted_content":null,"query":"Jeff Reed","name":"Jeff Reed","events":null},
			 {"promoted_content":null,"query":"Mike Vick","name":"Mike Vick","events":null},
			 {"promoted_content":null,"query":"Denisot","name":"Denisot","events":null},
			 {"promoted_content":null,"query":"Creations","name":"Creations","events":null}
		 ]
	 },
	 "as_of":1289940268
 }
 */


//--------------------------------------------------------------
void testApp::setup(){	 
	
	// this load font loads the non-full character set
	// (ie ASCII 33-128), at size "32"
	
	franklinBook.loadFont("frabk.ttf", 32);
	franklinBook.setLineHeight(36);


	// Twitter API: http://dev.twitter.com/doc/get/trends/current
	string url = "http://api.twitter.com/1/trends/current.json?exclude=hashtags";
	

	// Now parse the JSON
	bool parsingSuccessful = result.open(url);
	if ( parsingSuccessful )
    {
		cout << result.getRawString() << endl;
		
	}
    else
    {
		cout  << "Failed to parse JSON" << endl;

	}
}


//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	
	// See this page for all of the ways to access data in a Json::Value
	// http://jsoncpp.sourceforge.net/class_json_1_1_value.html	

	ofSetHexColor(0x00FF00);
	
	vector<string> childNames = result["trends"].getMemberNames();
	string timestamp = childNames[0];
	
	int n=0;
	ofxJSONElement trends = result["trends"][timestamp];
	for(int i=0; i<trends.size(); i++)
	{
		string message = trends[i]["query"].asString();
		franklinBook.drawString(message, 10, 40*i+40);
	}
}


//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
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
