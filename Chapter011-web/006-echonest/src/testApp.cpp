#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
	ofSetFrameRate(24);
	ofSetWindowShape(640, 480);
    ofBackgroundHex(0xEFDC9E);
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    ofSetCircleResolution(50);
    
    // Load in the song
    string song = "song.mp3";
    songPlayer.loadSound(song);
    
    /**
     Upload a track to Echonest using: (this could be built into the app, but I'm lazy)
     curl -F "api_key=OHIGAA8TFWUEWMX6K" -F "filetype=mp3" -F "track=@song.mp3" "http://developer.echonest.com/api/v4/track/upload"
     */
    
    
    // Get the profile of the song.
    // It contains the artits, title, and also the URL to the full audio analysis
    string apiKey = "OHIGAA8TFWUEWMX6K";
    string md5 = (new md5wrapper())->getHashFromFile(ofToDataPath(song));
    string url = "http://developer.echonest.com/api/v4/track/profile?api_key="+apiKey+"&format=json&md5="+md5+"&bucket=audio_summary";
    profile.open(url);
    
    
    
    // Fetch the information from the song profile.
    artist = profile["response"]["track"]["artist"].asString();
    title = profile["response"]["track"]["title"].asString();
    complete = profile["response"]["track"]["status"].asString() == "complete";
    
    if(complete)
    {
        analysis_url = profile["response"]["track"]["audio_summary"]["analysis_url"].asString();
        
        // Now open the full analysis
        analysis.open( analysis_url );
        
        cout << "found " << analysis["sections"].size() << " sections" << endl;
        cout << "found " << analysis["bars"].size() << " bars" << endl;
        cout << "found " << analysis["beats"].size() << " beats" << endl;
        cout << "found " << analysis["tatums"].size() << " tatums" << endl;
        cout << "found " << analysis["segments"].size() << " segments" << endl;
    }

    font.loadFont("cool.ttf", 14);
}

//--------------------------------------------------------------
void testApp::update(){
    
    sectionA *= 0.9;
    barA *= 0.9;
    beatA *= 0.4;
    tatumA *= 0.2;
    segmentA *= 0.1;
    
    if(complete)
    {
        float position = songPlayer.getPositionMS() / 1000.0;
        
        if(position > analysis["sections"][section]["start"].asDouble() && section < analysis["sections"].size()-1)
        {
            sectionA = 255;
            section++;
        }
        
        if(position > analysis["bars"][bar]["start"].asDouble() && bar < analysis["bars"].size()-1)
        {
            barA = 255;
            bar++;
        }
        
        if(position > analysis["beats"][beat]["start"].asDouble() && beat < analysis["beats"].size()-1)
        {
            beatA = 255;
            beat++;
        }
        
        if(position > analysis["tatums"][tatum]["start"].asDouble() && tatum < analysis["tatums"].size()-1)
        {
            tatumA = 255;
            tatum++;
        }
        
        if(position > analysis["segments"][segment]["start"].asDouble() && segment < analysis["segments"].size()-1)
        {
            segmentA = 255;
            segment++;
        }
    }

}

//--------------------------------------------------------------
void testApp::draw(){

    ofSetColor(24, 58, 117, sectionA);
    ofCircle(100, 200, 50);
    ofSetColor(24, 58, 117);
    font.drawString(ofToString(section), 100, 300);
    
    ofSetColor(23, 142, 39, barA);
    ofCircle(200, 200, 50);
    ofSetColor(23, 142, 39);
    font.drawString(ofToString(bar), 200, 300);
    
    ofSetColor(142, 83, 23, beatA);
    ofCircle(300, 200, 50);
    ofSetColor(142, 83, 23);
    font.drawString(ofToString(beat), 300, 300);
    
    ofSetColor(132, 84, 154, tatumA);
    ofCircle(400, 200, 50);
    ofSetColor(132, 84, 154);
    font.drawString(ofToString(tatum), 400, 300);
    
    ofSetColor(6, 92, 90, segmentA);
    ofCircle(500, 200, 50);
    ofSetColor(6, 92, 90);
    font.drawString(ofToString(segment), 500, 300);
    
    
    ofSetHexColor(0xFF3300);
    if(complete)
    {
        stringstream message;
        message << title << " by " << artist << endl;
        font.drawString(message.str(), 10, 25);
    }
    else
    {
        font.drawString("incomplete!", 20, 220);
    }

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
    section = bar = beat = segment = tatum = 0;
    sectionA = barA = beatA = segmentA = tatumA = 0;
    songPlayer.play();
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