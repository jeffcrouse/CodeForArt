/*
 *  Ball.cpp
 *  vector
 *
 *  Created by Jeffrey Crouse on 3/8/11.
 *  Copyright 2011 Eyebeam. All rights reserved.
 *
 */

#include "Star.h"

// ---------------------------------------------------
void Star::drawMe()
{
    ofSetColor(r, g, b, a);
    //ofCircle(position.x, position.y, radius);
    
    ofBeginShape();
    for(int i=0; i<contour.size(); i++)
    {
        ofVertex(contour[i].x, contour[i].y);
    }
    ofEndShape(true);
    
}

// ---------------------------------------------------
void Star::updateMe(vector<Star>& stars)
{
    age++;
    angle+=rotate_speed;
    a = 255 - age;
    position += velocity;
    
    if(position.x > ofGetWidth()-radius) {
        velocity.x *= -1;
        position.x = ofGetWidth()-radius;
    }
    if(position.y > ofGetHeight()-radius) {
        velocity.y *= -1;
        position.y = ofGetHeight()-radius;
    }
    if(position.x < radius) {
        velocity.x *= -1;
        position.x = radius;
    }
    if(position.y < radius) {
        velocity.y *= -1;
        position.y = radius;
    }
    
    
    contour.clear();
    bool dip=true;
    for(int i=angle; i<angle+360; i+=(360/sides))
    {
        float r;
        if(dip) {
            r = radius-(radius/starishness);
        } else {
            r = radius;
        }
        
        ofPoint p;
        p.x = r * cos(ofDegToRad(i)) + position.x;
        p.y = r * sin(ofDegToRad(i)) + position.y;
        
        contour.push_back( p );
        dip = !dip;
    }
    
    for(int i=0; i<stars.size(); i++)
    {
        float dist = ofDist(position.x, position.y, stars[i].position.x, stars[i].position.y);
        if(dist==0) continue;
        float minDist = radius + stars[i].radius;
        
        if(dist < minDist)
        {
            resolveCollision(*this, stars[i]);
        }
    }
}

// ---------------------------------------------------
void Star::resolveCollision(Star& starA, Star& starB)
{
    // get the mtd
    ofVec2f delta = starA.position - starB.position;
    float d = delta.length();
    // minimum translation distance to push balls apart after intersecting
    ofVec2f mtd = delta * (((starA.radius + starB.radius)-d)/d); 
    
    // resolve intersection --
    // inverse mass quantities
    float im1 = 1 / starA.mass; 
    float im2 = 1 / starB.mass;
    
    // push-pull them apart based off their mass
    starA.position += (mtd * (im1 / (im1 + im2)));
    starB.position -= (mtd * (im2 / (im1 + im2)));
    
    // impact speed
    ofVec2f v = starA.velocity - starB.velocity;
    float vn = v.dot(mtd.normalize());
    
    // sphere intersecting but moving away from each other already
    if (vn > 0.0f) return;
    
    // collision impulse
    float i = (-(2.0) * vn) / (im1 + im2);
    ofVec2f impulse = mtd * i;
    
    // change in momentum
    starA.velocity += impulse * im1;
    starB.velocity = starB.velocity - (impulse * im2);
}
