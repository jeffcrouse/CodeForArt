#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    cam.initGrabber(640, 480);
    
    string fragmentShader = STRINGIFY(
        uniform sampler2DRect tex;
        uniform float max_radius;

        void main(void) {
          
          vec4 finalColor = vec4(0.0,0.0,0.0,1.0);
          float weight = 0.;
          int radius = int(max_radius);
          for(int x=radius*-1;x<radius;x++) {
              for(int y=radius*-1;y<radius;y++){
                  vec2 coord = gl_TexCoord[0].xy+vec2(x,y);
                  if(distance(coord, gl_TexCoord[0].xy) < float(radius)){
                      vec4 texel = texture2DRect(tex, coord);
                      float w = length(texel.rgb)+0.1;
                      weight+=w;
                      finalColor += texel*w;
                  }
              }
          }
          
          gl_FragColor = finalColor/weight;
        }
    );
    
    bokeh.unload();
    bokeh.setupShaderFromSource(GL_FRAGMENT_SHADER, fragmentShader);
    bokeh.linkProgram();
    
    doShader=true;
}

//--------------------------------------------------------------
void testApp::update(){
    cam.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    
    float r = ofMap(mouseX, 0, ofGetWidth(), 0, 20);
    
    bokeh.begin();
    bokeh.setUniformTexture("tex", cam, 0);
    bokeh.setUniform1f("max_radius", r);
    cam.draw(0,0, 1024, 768);
    bokeh.end();
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