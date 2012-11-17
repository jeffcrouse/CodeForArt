//
//  Letter.cpp
//  extrude
//
//  Created by Jeffrey Crouse on 10/24/12.
//
//

#include "Letter.h"

// -----------------------------------
void Letter::setup(ofPath letter, float depth)
{    
    // Tessellation is subdividing a concave polygon into convex polygons.
    front = letter.getTessellation();
    back = front;  
    
    // Loop through all of the vertices in the "back" mesh
    // and move them back in on the "z" axis
    vector<ofPoint>& f = front.getVertices();
    vector<ofPoint>& b = back.getVertices();
    for(int j=0; j< f.size(); j++)
    {
        f[j].z += depth/2.0;
        b[j].z -= depth/2.0;
    }
}

// -----------------------------------
void Letter::draw()
{
    front.draw();
    back.draw();
}