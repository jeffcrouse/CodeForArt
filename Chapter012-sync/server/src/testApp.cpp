#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);
    ofSetFrameRate(60);
        
    //bConnected = server.setup( 9092 );
    
    ofxLibwebsockets::ServerOptions options = ofxLibwebsockets::defaultServerOptions();
    options.port = 9092;
    options.protocol = "of-protocol";
    bConnected = server.setup( options );
    
    server.addListener(this);
    
    particles.setup(30);
}

//--------------------------------------------------------------
void testApp::update(){
    particles.update();
    //cout << (string)particles << endl;
}

//--------------------------------------------------------------
void testApp::draw() {
    particles.draw();
    
    ofSetColor(255);
    ofDrawBitmapString(ofToString(ofGetFrameRate()), 10, 20);
}



//--------------------------------------------------------------
void testApp::onConnect( ofxLibwebsockets::Event& args ){
    cout << "on connected" << endl;
}

//--------------------------------------------------------------
void testApp::onOpen( ofxLibwebsockets::Event& args ){
    cout << "new connection open" << endl;
    cout << args.conn.getClientIP() << endl;
    
    args.conn.send("Welcome!");
}

//--------------------------------------------------------------
void testApp::onClose( ofxLibwebsockets::Event& args ){
    cout<<"on close"<<endl;
}

//--------------------------------------------------------------
void testApp::onIdle( ofxLibwebsockets::Event& args ){
    cout<<"on idle"<<endl;
}

//--------------------------------------------------------------
void testApp::onMessage( ofxLibwebsockets::Event& args ){
    cout<<"got message "<<args.message<<endl;
  
}

//--------------------------------------------------------------
void testApp::onBroadcast( ofxLibwebsockets::Event& args ){
    cout<<"got broadcast "<<args.message<<endl;
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key==' ') {
        server.send("Hello!");
    }
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