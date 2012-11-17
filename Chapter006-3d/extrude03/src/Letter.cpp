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
    vector<ofPoint>& v = back.getVertices();
    for(int j=0; j< v.size(); j++)
    {
        v[j].z -= depth;
    }

    
    // TIP - class heirarchy
    // an ofPath is basically a container for a bunch of ofPolyLines
    // an ofPolyline is a single, continuous line that has lots of useful functions
    // such as getSmoothed, getResampledBySpacing, getClosestPoint
    
    
    // The path of a letter may contain several different lines
    // Think about the inside of a shape with a hole like "O", "P", "D"
    vector<ofPolyline> lines = letter.getOutline();
    for(int j=0; j<lines.size(); j++)
    {
        // Now we have to make the "ribbon" that gets sandwiched between
        // the front and the back
        
        
        // Loop through all of the points and make 2 triangles at a time:
        // the first one uses 2 points from "front" and one from "back"
        // the second uses 2 from "back" and 1 from "front"
        vector<ofPoint>& points = lines[j].getVertices();
        int k;
        for(k=0; k<points.size()-1; k++)
        {
            ofPoint p1 = points[k+0];
            ofPoint p2 = points[k+1];
            
            side.addVertex(p1);
            side.addVertex(p2);
            side.addVertex(ofPoint(p1.x, p1.y, p1.z-depth));
            
            side.addVertex(ofPoint(p1.x, p1.y, p1.z-depth));
            side.addVertex(ofPoint(p2.x, p2.y, p2.z-depth));
            side.addVertex(p2);
        }
        
        // Connect the last triangles to the first
        ofPoint p1 = points[k];
        ofPoint p2 = points[0];
        
        side.addVertex(p1);
        side.addVertex(p2);
        side.addVertex(ofPoint(p1.x, p1.y, p1.z-depth));
        
        side.addVertex(ofPoint(p1.x, p1.y, p1.z-depth));
        side.addVertex(ofPoint(p2.x, p2.y, p2.z-depth));
        side.addVertex(p2);
    }
}

// -----------------------------------
void Letter::draw()
{
    front.draw();
    back.draw();
    side.draw();
}