#pragma once

#include "chipmunk.h"
#include "ofxChipmunkBaseShape.h"
#include "ofxChipmunkCircle.h"
#include "ofxChipmunkRect.h"
#include "ofxChipmunkLine.h"
#include "ofxChipmunkPoly.h"

#include "ofMain.h"
#include "del_interface.hpp"


class ofxChipmunk {
	
public: 
	
	//----------------------------------------------------------	
	ofxChipmunk() {
		space = NULL;
	}
	
	//---------------------------------------------------------		
	virtual cpSpace* getSpace(){
		return space;
	}
	
	//---------------------------------------------------------
	virtual void setup(int iterations, ofPoint gravity ){
		//check for non zero values			
		assert(iterations);
		
		//init chipmunk - do we need to make sure this is only called once per thread?
		ofxChipmunk::initChipmunk();
		
		//create a new space
		space = cpSpaceNew();
		
		space->iterations = iterations;
		space->gravity = cpv(gravity.x, gravity.y);
		
		//a default hash size - tweaking this can have a big improvement on fps
		cpSpaceResizeStaticHash(space, 25.0f, 2000);
		cpSpaceResizeActiveHash(space, 25.0f, 2000);
		
		//should we do this for multiple instances?
		//cpResetShapeIdCounter();
	}	
	
	//---------------------------------------------------------			
	void setGravity(ofPoint gravity){
		if(space != NULL)space->gravity = cpv(gravity.x, gravity.y);
		else printf("setGravity() - need to call setup first");
	}
	
	//---------------------------------------------------------
	void update(int numSteps = 6){
		
		//from the docs
		//  void cpSpaceStep(cpSpace *space, cpFloat dt)
		//
		//  Update the space for the given time step. 
		//  Using a fixed time step is highly recommended. 
		//  Doing so will increase the efficiency of the contact persistence, 
		//  requiring an order of magnitude fewer iterations to resolve the collisions in the usual case.
		
		cpFloat dt = (1.0f/60.0f) / numSteps;
		for(int i = 0; i < numSteps; i++)cpSpaceStep(space, dt);
		
	}
	
	//---------------------------------------------------------
	void setStaticHashSize(float dimensions, int count){
		//check for non zero values
		assert(dimensions);
		assert(count);
		cpSpaceResizeStaticHash(space, dimensions, count);
	}
	
	//---------------------------------------------------------		
	void setActiveHashSize(float dimensions, int count){
		//check for non zero values
		assert(dimensions);
		assert(count);
		cpSpaceResizeActiveHash(space, dimensions, count);
	}	
	
	//--------------------------------------------------------- add shape		
	virtual void addShape(ofxChipmunkBaseShape *baseShape){
		if(!baseShape->isShapeStatic()){
			cpSpaceAddBody(space, baseShape->body);			
			cpSpaceAddShape(space, baseShape->shape);
		}else{
			cpSpaceAddShape(space, baseShape->shape);
		}
	}
	
	//---------------------------------------------------------	add joint
	virtual void addJoint(ofxChipmunkBaseShape *shapeA, ofxChipmunkBaseShape *shapeB) {
		cpSpaceAddJoint(space, cpPinJointNew(shapeA->body, shapeB->body, cpvzero, cpvzero));		
	}

	//---------------------------------------------------------		
	virtual void addJoint(ofxChipmunkBaseShape *shapeA, ofxChipmunkBaseShape *shapeB, ofPoint anchor1, ofPoint anchor2) {
		
		cpVect a1, a2;
		a1.x = anchor1.x;
		a1.y = anchor1.y;

		a2.x = anchor2.x;
		a2.y = anchor2.y;		
		
		cpSpaceAddJoint(space, cpPinJointNew(shapeA->body, shapeB->body, a1, a2));		
	}
	
	//---------------------------------------------------------		
	virtual void addPolyShape(ofxChipmunkPoly *poly){
		if(!poly->isShapeStatic()){
			cpSpaceAddBody(space, poly->body);			
			for(int i= 0; i < poly->numShapes; i++)cpSpaceAddShape(space, poly->polyShapes[i]);
		}else{
			for(int i= 0; i < poly->numShapes; i++)cpSpaceAddShape(space, poly->polyShapes[i]);
		}
	}
	
protected:
	//----------------------------------------------------------	
	static void initChipmunk(){
		cpInitChipmunk();
		printf("chipmunk initialized");
	}
	
	
	//----------------------------------------------------------
	cpSpace *space;
};


/*		
 staticBody = cpBodyNew(INFINITY, INFINITY);
 
 body = cpBodyNew(INFINITY, INFINITY);
 body->p = cpv(ofGetWidth()/2, ofGetHeight());
 
 cpShape * box = cpSegmentShapeNew(body, cpv(-ofGetWidth()/2, 0), cpv(ofGetWidth()/2,0), 100.0);
 box->e = 0.0; box->u = 20.0;
 cpSpaceAddShape(space, box);
 
 
 static cpBody *
 make_box(cpFloat x, cpFloat y, float w, float h, cpSpace * space)
 {
 
 float hw = w/2;
 float hh = h/2;
 
 int num = 4;
 cpVect verts[] = {
 cpv(-hw,-hh),
 cpv(-hw, hh),
 cpv( hw, hh),
 cpv( hw,-hh),
 };
 
 cpBody *body = cpBodyNew(1.0, cpMomentForPoly(1.0, num, verts, cpv(0,0)));
 //	cpBody *body1 = cpBodyNew(1.0/0.0, 1.0/0.0);
 body->p = cpv(x, y);
 cpSpaceAddBody(space, body);
 cpShape *shape = cpPolyShapeNew(body, num, verts, cpv(0,0));
 shape->e = 0.0; shape->u = 1.0;
 cpSpaceAddShape(space, shape);
 
 return body;
 }
 
 class ball{
 
 public:
 
 ball(){
 
 }
 
 void setup(ofPoint center, float radius, float mass,  cpSpace * space){
 
 r = radius;
 
 body = cpBodyNew(mass, cpMomentForCircle(mass, 0, radius, cpvzero));
 body->p = cpv(center.x, center.y);
 cpSpaceAddBody(space, body);
 
 shape = cpCircleShapeNew(body, radius, cpvzero);
 shape->e = 0.2; shape->u = 5.0;
 cpSpaceAddShape(space, shape);
 
 }
 
 void update(float dt){
 
 }
 
 void draw(vectorGraphics &graph){
 graph.circle(body->p.x, body->p.y, r);
 }
 
 float r;
 cpShape * shape;	
 cpBody * body;
 
 };
 
 class staticBall{
 
 public:
 
 staticBall(){
 
 }
 
 void setup(ofPoint center, float radius, cpSpace * space){
 
 pos = center;
 
 r = radius;
 
 body = cpBodyNew(INFINITY, INFINITY);
 body->p = cpv(center.x, center.y);
 
 shape = cpCircleShapeNew(body, radius, cpvzero);
 shape->e = 0.2; shape->u = 5.0;
 cpSpaceAddShape(space, shape);
 
 }
 
 void move(ofPoint newPos){
 
 pos = newPos;
 
 body->p.x = pos.x;
 body->p.y = pos.y;		
 }
 
 void update(float dt){
 
 }
 
 void draw(vectorGraphics &graph){
 graph.circle(body->p.x, body->p.y, r);
 }
 
 float r;
 cpShape * shape;	
 cpBody * body;
 ofPoint pos;
 
 };
 
 
 
 class chain{
 
 public:
 
 chain(){
 
 }
 
 void setup(ofPoint startPoint, ofPoint endPoint, int numLinks, cpBody * staticBody, cpSpace * space){
 
 ofPoint delta = (endPoint - startPoint);
 float dist = sqrt(delta.x*delta.x + delta.y*delta.y);
 
 float spacing = (dist / numLinks);
 float unitW   = spacing * 0.95;
 float hUnitW  = unitW * 0.5;
 
 ofPoint pos = startPoint;
 ofPoint step = delta / numLinks;
 
 for(int i = 0; i < numLinks+1; i++){
 
 if( i < numLinks)bodyLinks.push_back( make_box(pos.x, pos.y, unitW, 2.0, space) );
 
 if(i == 0){
 joints.push_back( cpSlideJointNew(staticBody, bodyLinks[i], cpv(bodyLinks[i]->p.x -hUnitW,  bodyLinks[i]->p.y -1), cpv(-hUnitW, -1), unitW*0.5, spacing*0.5) );
 }
 else if(i == numLinks){
 joints.push_back( cpSlideJointNew(bodyLinks[i-1], staticBody, cpv(hUnitW, -1), cpv(bodyLinks[i-1]->p.x +hUnitW,  bodyLinks[i-1]->p.y-1), unitW*0.5, spacing*0.5) );
 }	
 else{
 joints.push_back( cpSlideJointNew(bodyLinks[i-1], bodyLinks[i], cpv(hUnitW, -1), cpv(-hUnitW, -1), unitW*0.5, spacing*0.5) );
 }
 
 cpSpaceAddJoint(space, joints[i]);
 
 pos += step;	
 }
 
 }
 
 void update(float dt){
 
 }
 
 void draw(vectorGraphics &graph){
 
 graph.setColor(0x000000);
 
 graph.beginShape();
 
 for(int i = 0; i < bodyLinks.size(); i++){
 
 if(i == 0 || i == bodyLinks.size()-1)graph.curveVertex(bodyLinks[i]->p.x, bodyLinks[i]->p.y);
 graph.curveVertex(bodyLinks[i]->p.x, bodyLinks[i]->p.y);
 
 }
 
 graph.endShape();		
 
 }
 
 
 vector <cpJoint*> joints;	
 vector <cpShape*> shapeLinks;	
 vector <cpBody*> bodyLinks;
 
 };
 
 
 cpBody *body;
 cpShape *shape;
 cpBody *staticBody;
 
 cpBody *body2;
 cpShape *shape2;		
 
 cpSpace *space;
 
 */