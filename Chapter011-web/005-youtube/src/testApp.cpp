#include "testApp.h"

// Helpful Stuff
// http://code.google.com/apis/youtube/2.0/developers_guide_protocol_video_feeds.html
// http://gdata.youtube.com/feeds/api/standardfeeds/most_popular?v=2&alt=json
// https://github.com/rg3/youtube-dl
// http://en.wikipedia.org/wiki/YouTube#Quality_and_codecs
// http://pastebin.com/is8xLLTD

string ofSystemCall(string command)
{
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) return "ERROR";
    char buffer[128];
    string result = "";
    while(!feof(pipe)) {
        if(fgets(buffer, 128, pipe) != NULL)
            result += buffer;
    }
    pclose(pipe);
    result.erase(remove(result.begin(), result.end(), '\n'), result.end());
    return result;
}

//--------------------------------------------------------------
void testApp::setup(){    
    
    string youtube_dl = ofToDataPath("youtube-dl", true);
    
    
    // Open a Youtube video feed
    // http://code.google.com/apis/youtube/2.0/developers_guide_protocol_video_feeds.html
    // http://gdata.youtube.com/feeds/api/standardfeeds/most_popular?v=2&alt=json
    // http://gdata.youtube.com/feeds/api/videos?q=skateboarding+dog&alt=json
    ofxJSONElement youtube;
    youtube.open("http://gdata.youtube.com/feeds/api/videos?q=slow+loris&alt=json");

    // Loop through all of the feed->entry items in the feed
    int numVideos = min(4, (int)youtube["feed"]["entry"].size());
    for(int i=0; i<numVideos; i++)
    {
        // use ofToDataPath to get the complete path to the youtube-dl program
        // https://github.com/rg3/youtube-dl
        // In each one, there will be a "link" item that contains multiple "href" strings
        // We want the first href string inside the link item
        string youtube_url = youtube["feed"]["entry"][i]["link"][UInt(0)]["href"].asString();
        cout << youtube_url << endl;
        
        // Assemble a command just like the one you would use on the command line
        // Format 18 = H264  (see http://en.wikipedia.org/wiki/YouTube#Quality_and_codecs)
        string command = youtube_dl+" --get-url --format 18 "+youtube_url;
        //cout << command << endl;
        
        // Get the full (nasty) URL of the raw video
        string vid_url = ofSystemCall(command);
        //cout << vid_url << endl;
        
        // Load the video (from a url!) and start playing it
        vids[i].loadMovie(vid_url);
        vids[i].play();
    }
}

//--------------------------------------------------------------
void testApp::update(){
    for(int i=0; i<4; i++)
    {
        vids[i].update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    vids[0].draw(0, 0, 320, 240);
    vids[1].draw(320, 0, 320, 240);
    vids[2].draw(0, 240, 320, 240);
    vids[3].draw(320, 240, 320, 240);
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