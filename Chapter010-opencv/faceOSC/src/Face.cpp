//
// a template for receiving face tracking osc messages from
// Kyle McDonald's FaceOSC https://github.com/kylemcdonald/ofxFaceTracker/downloads
//
// 2012 Dan Wilcox danomatika.com
// for the IACD class at the CMU School of Art
//
#include "Face.h"
#include "ofxOscMessage.h"

Face::Face() : found(0), poseScale(0), posePosition(), poseOrientation(),
         mouthWidth(0), mouthHeight(0), eyeLeft(0), eyeRight(0),
         eyebrowLeft(0), eyebrowRight(0), jaw(0), nostrils(0) {}
            
bool Face::parseOSC(ofxOscMessage& m) {

    if(m.getAddress() == "/found") {
        found = m.getArgAsInt32(0);
        return true;
    }      
          
    // pose
    else if(m.getAddress() == "/pose/scale") {
        poseScale = m.getArgAsFloat(0);
        return true;
    }
    else if(m.getAddress() == "/pose/position") {
        posePosition.x = m.getArgAsFloat(0);
        posePosition.y = m.getArgAsFloat(1);
        return true;
    }
    else if(m.getAddress() == "/pose/orientation") {
        poseOrientation.x = m.getArgAsFloat(0);
        poseOrientation.y = m.getArgAsFloat(1);
        poseOrientation.z = m.getArgAsFloat(2);
        return true;
    }
    
    // gesture
    else if(m.getAddress() == "/gesture/mouth/width") {
        mouthWidth = m.getArgAsFloat(0);
        return true;
    }
    else if(m.getAddress() == "/gesture/mouth/height") {
        mouthHeight = m.getArgAsFloat(0);
        return true;
    }
    else if(m.getAddress() == "/gesture/eye/left") {
        eyeLeft = m.getArgAsFloat(0);
        return true;
    }
    else if(m.getAddress() == "/gesture/eye/right") {
        eyeRight = m.getArgAsFloat(0);
        return true;
    }
    else if(m.getAddress() == "/gesture/eyebrow/left") {
        eyebrowLeft = m.getArgAsFloat(0);
        return true;
    }
    else if(m.getAddress() == "/gesture/eyebrow/right") {
        eyebrowRight = m.getArgAsFloat(0);
        return true;
    }
    else if(m.getAddress() == "/gesture/jaw") {
        jaw = m.getArgAsFloat(0);
        return true;
    }
    else if(m.getAddress() == "/gesture/nostrils") {
        nostrils = m.getArgAsFloat(0);
        return true;
    }
    
    return false;
}

 string Face::toString() {
    stringstream stream;
    stream << "found: " << found << endl
           << "pose" << endl
           << " scale: " << poseScale << endl
           << " position: " << posePosition << endl
           << " orientation: " << poseOrientation << endl
           << "gesture" << endl
           << " mouth: " << mouthWidth << " " << mouthHeight << endl
           << " eye: " << eyeLeft << " " << eyeRight << endl
           << " eyebrow: " << eyebrowLeft << " " << eyebrowRight << endl
           << " jaw: " << jaw << endl
           << " nostrils: " << nostrils << endl;
    return stream.str();
 }
