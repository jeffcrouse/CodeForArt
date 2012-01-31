#pragma once

#include "chipmunk.h"
#include "ofMain.h"

class ofxChipmunkBaseShape{
	
public:
	
	ofxChipmunkBaseShape(){
		shape		= NULL;
		body		= NULL;
		space		= NULL;
		
		isStatic	= false;
		dead		= false;
		alive		= false;
		mass		= 1.0;
		e			= 0.0;
		f			= 1.0;
	}
	
	~ofxChipmunkBaseShape() {
		kill();
	}
	
	void kill() {
		
		if(space != NULL && body != NULL){
			cpSpaceRemoveBody(space, body);
			cpBodyFree(body);
		}
		if(space != NULL && shape != NULL){
			cpSpaceRemoveShape(space, shape);
			cpShapeFree(shape);
		}
		
		if( alive ){
			alive = false;
			dead  = true;
		}
	}
	
	bool isShapeStatic(){
		return isStatic;
	}	
	
	void setRotation(float angleDeg){
		if( body!= NULL){
			float angleRad = angleDeg * DEG_TO_RAD;
			cpVect angle;
			angle.x = cos(angleRad);
			angle.y = sin(angleRad);
			body->rot = angle;
		}
	}
	
	void setSpace(cpSpace* spaceToUse){
		space = spaceToUse;
	}
	
	void setElasticity(float elasticity){
		e = elasticity;
		if(shape != NULL){
			shape->e = e;
		}
	}
	
	void setFriction(float friction){
		f = friction;
		if(shape != NULL){
			shape->u = f;
		}
	}
	
	ofPoint getPosition() {
		if(body != NULL)return ofPoint(body->p.x, body->p.y);
		return ofPoint();
	}

	void setPosition(float x, float y) {
		if(body != NULL){
			body->p.x = x;
			body->p.y = y;
		}
	}
	
	
	cpShape * shape;	
	cpBody * body;
	cpSpace * space;
	
	bool dead, alive;
	
protected:
	bool isStatic;
	float mass;
	float e, f;
	
};
