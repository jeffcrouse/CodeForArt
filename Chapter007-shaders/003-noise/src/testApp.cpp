#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    cam.initGrabber(640, 480);
    
    string vertexShader = STRINGIFY(
        void main() {
            gl_TexCoord[0] = gl_MultiTexCoord0;
            gl_FrontColor = gl_Color;
            gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
        }
    );
    
    string fragmentShader = STRINGIFY(
        uniform sampler2DRect tex0;
        uniform float time;
                                      
        float rand(vec2 co){
              return fract(sin(dot(co.xy ,vec2(12.9898,78.233))) * 43758.5453);
          }
                                      
        void main(void){
            vec2 c = gl_TexCoord[0].st;
            c.x += time;
            float rand = rand( c ) ;
            vec4 noise = vec4( rand, rand, rand, rand );
            gl_FragColor = texture2DRect(tex0, gl_TexCoord[0].st) + noise;
            //gl_FragColor = gl_Color;
        }
    );
    
    noise.unload();
    noise.setupShaderFromSource(GL_VERTEX_SHADER, vertexShader);
    noise.setupShaderFromSource(GL_FRAGMENT_SHADER, fragmentShader);
    noise.linkProgram();
}

//--------------------------------------------------------------
void testApp::update(){
    cam.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255);
    
    
    noise.begin();
    noise.setUniform1f("time", ofGetElapsedTimef());
    cam.draw(0, 0, 1024, 768);
    noise.end();

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