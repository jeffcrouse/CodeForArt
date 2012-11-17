#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    
    cam.initGrabber(ofGetWidth(), ofGetHeight());
    buffer[0].allocate(ofGetWidth(), ofGetHeight());
    buffer[1].allocate(ofGetWidth(), ofGetHeight());
    
    
    string vertexShader = STRINGIFY(
        void main() {
            gl_TexCoord[0] = gl_MultiTexCoord0;
            gl_Position = ftransform();
        }
    );
    
    //what the blur shader does: it takes blurAmnt as input and takes for each 'pixel' / fragment a
    //weighted average of itself and 8 horizontal neighbours (which neighbours depends on the blurAmnt
    string fragmentShaderHorizontal = STRINGIFY(
        uniform sampler2DRect src_tex_unit0;
        uniform float amt;
        void main(void) {
            vec2 st = gl_TexCoord[0].st;
            vec4 color;
            color += 1.0 * texture2DRect(src_tex_unit0, st + vec2(amt * -4.0, 0.0));
            color += 2.0 * texture2DRect(src_tex_unit0, st + vec2(amt * -3.0, 0.0));
            color += 3.0 * texture2DRect(src_tex_unit0, st + vec2(amt * -2.0, 0.0));
            color += 4.0 * texture2DRect(src_tex_unit0, st + vec2(amt * -1.0, 0.0));
            color += 5.0 * texture2DRect(src_tex_unit0, st + vec2(amt, 0));
            color += 4.0 * texture2DRect(src_tex_unit0, st + vec2(amt * 1.0, 0.0));
            color += 3.0 * texture2DRect(src_tex_unit0, st + vec2(amt * 2.0, 0.0));
            color += 2.0 * texture2DRect(src_tex_unit0, st + vec2(amt * 3.0, 0.0));
            color += 1.0 * texture2DRect(src_tex_unit0, st + vec2(amt * 4.0, 0.0));
            color /= 25.0;
            gl_FragColor = color;
        }
    );
    
    // same but now for vertical neighbours
    string fragmentShaderVertical = STRINGIFY(
        uniform sampler2DRect src_tex_unit0;
        uniform float amt;
                                              
        void main(void) {
            vec2 st = gl_TexCoord[0].st;
            vec4 color;
            color += 1.0 * texture2DRect(src_tex_unit0, st + vec2(0.0, amt * 4.0));
            color += 2.0 * texture2DRect(src_tex_unit0, st + vec2(0.0, amt * 3.0));
            color += 3.0 * texture2DRect(src_tex_unit0, st + vec2(0.0, amt * 2.0));
            color += 4.0 * texture2DRect(src_tex_unit0, st + vec2(0.0, amt * 1.0));
            color += 5.0 * texture2DRect(src_tex_unit0, st + vec2(0.0, amt) );
            color += 4.0 * texture2DRect(src_tex_unit0, st + vec2(0.0, amt * -1.0));
            color += 3.0 * texture2DRect(src_tex_unit0, st + vec2(0.0, amt * -2.0));
            color += 2.0 * texture2DRect(src_tex_unit0, st + vec2(0.0, amt * -3.0));
            color += 1.0 * texture2DRect(src_tex_unit0, st + vec2(0.0, amt * -4.0));
            color /= 25.0;
            gl_FragColor = color;
        }
    );
    
    hBlur.unload();
    hBlur.setupShaderFromSource(GL_FRAGMENT_SHADER, fragmentShaderHorizontal);
    hBlur.setupShaderFromSource(GL_VERTEX_SHADER, vertexShader);
    hBlur.linkProgram();
    
    vBlur.unload();
    vBlur.setupShaderFromSource(GL_FRAGMENT_SHADER, fragmentShaderVertical);
    vBlur.setupShaderFromSource(GL_VERTEX_SHADER, vertexShader);
    vBlur.linkProgram();
    
}

//--------------------------------------------------------------
void testApp::update(){
    cam.update();
    
    buffer[0].begin();
    cam.draw(0, 0);
    ofSetColor(255);
    for(int y = 0; y<ofGetHeight(); y+=10)
        for(int x=0; x<ofGetWidth(); x+=10) {
            ofRect(x, y, 5, 5);
        }
    
    buffer[0].end();
    
    
    
    
    float amount = ofMap(mouseY, 0, ofGetHeight(), 4, 0);
    int iterations = 5;
    for (int i=0; i<iterations; i++)
    {
        //apply horizontal blur to fbo1 and put the result in fbo2
        buffer[1].begin();
        hBlur.begin();
        hBlur.setUniform1f("amt", amount);
        buffer[0].draw(0,0);
        hBlur.end();
        buffer[1].end();
        
        //apply vertical blur to fbo2 and put this back in fbo1
        buffer[0].begin();
        vBlur.begin();
        vBlur.setUniform1f("amt", amount);
        buffer[1].draw(0,0);
        hBlur.end();
        buffer[0].end();
    }
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    buffer[0].draw(0, 0, 1024, 768);
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