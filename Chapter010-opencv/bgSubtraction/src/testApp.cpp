#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(24);
    
    bGetBackground = true;
    threshold = 28;
    blur = 3;
    dilate = 2;
    
    cam.initGrabber(320, 240);
    colorImage.allocate(320, 240);
    grayImage.allocate(320, 240);
    bgImage.allocate(320, 240);
    diffImage.allocate(320, 240);
    
    button.x = ofGetWidth() * 0.75;
    button.y = ofGetHeight() * 0.25;
    buttonRadius = 30;
    
    gui.addSlider("threshold", threshold, 0, 255);
    gui.addSlider("blur", blur, 0, 5);
    gui.addSlider("dilate", dilate, 0, 10);
    
    gui.show();
}

//--------------------------------------------------------------
void testApp::update(){
    cam.update();
    if( cam.isFrameNew() )
    {
        colorImage.setFromPixels(cam.getPixelsRef());
        colorImage.mirror(false, true);
        
        grayImage = colorImage;
        if(bGetBackground)
        {
            bgImage = grayImage;
            bGetBackground = false;
        }
        diffImage.absDiff(bgImage, grayImage);
        diffImage.blur( blur*2 + 1 );
  
        diffImage.threshold(threshold);
        
        for(int i=0; i<dilate; i++)
            diffImage.dilate();
    
        contourFinder.findContours(diffImage, 320*240*0.01, 320*240*.9, 4, false);

        for(int i=0; i<contourFinder.nBlobs; i++)
        {
            ofxCvBlob& blob = contourFinder.blobs[i];
            for(int j=0; j<blob.pts.size(); j++)
            {
                blob.pts[j].x= ofMap(blob.pts[j].x, 0, 320, 0, ofGetWidth());
                blob.pts[j].y = ofMap(blob.pts[j].y, 0, 240, 0, ofGetHeight());
            }
            
            if( ofInsidePoly(button, blob.pts) )
            {
                cout << "play sound" << endl;
            }
        }
        
        

    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    /*
    ofSetColor(255);
    cam.draw(10, 10);
    colorImage.draw(340, 10);
    grayImage.draw(670, 10);
    bgImage.draw(10, 260);
    diffImage.draw(340, 260);
    //contourFinder.draw(670, 260);
    */
    
    ofSetColor(0);
    ofNoFill();
    for(int i=0; i<contourFinder.nBlobs; i++)
    {
        ofxCvBlob& blob = contourFinder.blobs[i];
        
        ofBeginShape();
        for(int j=0; j<blob.pts.size(); j++)
        {
            ofVertex(blob.pts[j]);
        }
        ofEndShape();
    }
    
    gui.draw();
    
    ofFill();
    ofCircle(button, buttonRadius);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    if(key==' ')
        bGetBackground = true;
    if(key=='g')
        gui.toggleDraw();
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