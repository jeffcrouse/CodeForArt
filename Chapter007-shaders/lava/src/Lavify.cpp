//
//  Lavify.cpp
//  UZTableApp
//
//  Created by Jeffrey Crouse on 7/26/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Lavify.h"



void Lavify::setup(float width, float height)
{
    string vertexShader =
    "void main() {\
        gl_TexCoord[0] = gl_MultiTexCoord0;\
        gl_Position = ftransform();\
    }";
    
    //what the blur shader does: it takes blurAmnt as input and takes for each 'pixel' / fragment a
    //weighted average of itself and 8 horizontal neighbours (which neighbours depends on the blurAmnt
    string fragmentShaderHorizontal =
    "uniform sampler2DRect src_tex_unit0;\
    uniform float amt;\
    void main(void) {\
        vec2 st = gl_TexCoord[0].st;\
        vec4 color;\
        color += 1.0 * texture2DRect(src_tex_unit0, st + vec2(amt * -4.0, 0.0));\
        color += 2.0 * texture2DRect(src_tex_unit0, st + vec2(amt * -3.0, 0.0));\
        color += 3.0 * texture2DRect(src_tex_unit0, st + vec2(amt * -2.0, 0.0));\
        color += 4.0 * texture2DRect(src_tex_unit0, st + vec2(amt * -1.0, 0.0));\
        color += 5.0 * texture2DRect(src_tex_unit0, st + vec2(amt, 0));\
        color += 4.0 * texture2DRect(src_tex_unit0, st + vec2(amt * 1.0, 0.0));\
        color += 3.0 * texture2DRect(src_tex_unit0, st + vec2(amt * 2.0, 0.0));\
        color += 2.0 * texture2DRect(src_tex_unit0, st + vec2(amt * 3.0, 0.0));\
        color += 1.0 * texture2DRect(src_tex_unit0, st + vec2(amt * 4.0, 0.0));\
        color /= 25.0;\
        gl_FragColor = color;\
    }";
    
    // same but now for vertical neighbours
    string fragmentShaderVertical =
    "uniform sampler2DRect src_tex_unit0;\
    uniform float amt;\
    void main(void) {\
        vec2 st = gl_TexCoord[0].st;\
        vec4 color;\
        color += 1.0 * texture2DRect(src_tex_unit0, st + vec2(0.0, amt * 4.0));\
        color += 2.0 * texture2DRect(src_tex_unit0, st + vec2(0.0, amt * 3.0));\
        color += 3.0 * texture2DRect(src_tex_unit0, st + vec2(0.0, amt * 2.0));\
        color += 4.0 * texture2DRect(src_tex_unit0, st + vec2(0.0, amt * 1.0));\
        color += 5.0 * texture2DRect(src_tex_unit0, st + vec2(0.0, amt) );\
        color += 4.0 * texture2DRect(src_tex_unit0, st + vec2(0.0, amt * -1.0));\
        color += 3.0 * texture2DRect(src_tex_unit0, st + vec2(0.0, amt * -2.0));\
        color += 2.0 * texture2DRect(src_tex_unit0, st + vec2(0.0, amt * -3.0));\
        color += 1.0 * texture2DRect(src_tex_unit0, st + vec2(0.0, amt * -4.0));\
        color /= 25.0;\
        gl_FragColor = color;\
    }";
    
    string fragmentShaderThreshold = 
    "uniform sampler2DRect src_tex_unit0;\
    uniform vec4 low; \
    uniform vec4 high; \
    uniform float threshold; \
    void main(void) {\
        vec4 color = texture2DRect(src_tex_unit0, gl_TexCoord[0].st); \
        float brightness = 0.3 * color.x + 0.59 * color.y+ 0.11 *color.z; \
        gl_FragColor = (brightness < threshold) ? low : high;\
    }";
    
    
    buffer[0].allocate(width, height);
    buffer[1].allocate(width, height);
    
    
    hBlur.unload();
    hBlur.setupShaderFromSource(GL_FRAGMENT_SHADER, fragmentShaderHorizontal);
    hBlur.setupShaderFromSource(GL_VERTEX_SHADER, vertexShader);
    hBlur.linkProgram();
    
    vBlur.unload();
    vBlur.setupShaderFromSource(GL_FRAGMENT_SHADER, fragmentShaderVertical);
    vBlur.setupShaderFromSource(GL_VERTEX_SHADER, vertexShader);
    vBlur.linkProgram();
    
    threshold.unload();
    threshold.setupShaderFromSource(GL_FRAGMENT_SHADER, fragmentShaderThreshold);
    threshold.setupShaderFromSource(GL_VERTEX_SHADER, vertexShader);
    threshold.linkProgram();
}

void  Lavify::begin()
{
    buffer[0].begin();
}

void  Lavify::end()
{
    buffer[0].end();
    

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

void  Lavify::draw()
{
    threshold.begin();
    threshold.setUniform1f("threshold", thresh);
    threshold.setUniform4f("low", 50/255., 225/255., 225/255.0, 1.0);
    threshold.setUniform4f("high", 253/255., 239/255., 194/255., 1.0);
    buffer[0].draw(0,0);
    threshold.end();
}


