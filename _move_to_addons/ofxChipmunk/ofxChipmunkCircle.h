#pragma once

#include "chipmunk.h"

#include "ofxChipmunkBaseShape.h"
#include "ofMain.h"


class ofxChipmunkCircle : public ofxChipmunkBaseShape{
	public:
		ofxChipmunkCircle(){
		
		}
		
		//-----------------------------------------------------------------------------------------
		virtual void setup(float x, float y, float circleRadius, float shapeMass, float elasticity, float fricton, bool bShapeStatic){
			setup(x, y, circleRadius, shapeMass, bShapeStatic);
			setElasticity(elasticity);
			setFriction(fricton);
			
			alive = true;
		}
		
		//-----------------------------------------------------------------------------------------
		virtual void draw() {
			ofCircle(body->p.x, body->p.y, radius);
		}


	protected:
		//-----------------------------------------------------------------------------------------
		virtual void setup(float x, float y, float circleRadius, float shapeMass, bool bShapeStatic){

			radius   = circleRadius;
			mass	 = shapeMass;
			isStatic = bShapeStatic;
			
			if( isStatic ){
				body = cpBodyNew(INFINITY, INFINITY);
			}else{
				body = cpBodyNew(mass,  cpMomentForCircle(mass, 0, radius, cpvzero) );
			}

			body->p = cpv(x, y);
			shape = cpCircleShapeNew(body, radius, cpvzero);
		}	
	
		float radius;
	
};
