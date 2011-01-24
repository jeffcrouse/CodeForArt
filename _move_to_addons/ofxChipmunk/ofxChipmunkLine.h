#pragma once

#include "chipmunk.h"

#include "ofxChipmunkBaseShape.h"
#include "ofMain.h"


//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------

class ofxChipmunkLine : public ofxChipmunkBaseShape{
	
	public:

		//-----------------------------------------------------------------------------------------			
		ofxChipmunkLine(){
			
		}

		//-----------------------------------------------------------------------------------------
		virtual void setup(float x1, float y1, float x2, float y2, float thickness, float elasticity, float fricton){
			setup(x1, y1, x2, y2, thickness);
			setElasticity(elasticity);
			setFriction(fricton);
		}
				
		//-----------------------------------------------------------------------------------------
		ofPoint getPosition(){
			if(body != NULL)return ofPoint(body->p.x, body->p.y);
			return ofPoint();
		}
		
		//-----------------------------------------------------------------------------------------
		virtual void draw(){
		
			cpBody *body = shape->body;
			cpSegmentShape *seg = (cpSegmentShape *)shape;
			cpVect a = cpvadd(body->p, cpvrotate(seg->a, body->rot));
			cpVect b = cpvadd(body->p, cpvrotate(seg->b, body->rot));
			
			glBegin(GL_LINES); {
				glVertex2f(a.x, a.y);
				glVertex2f(b.x, b.y);
			} glEnd();

		}
		
	protected:
		//-----------------------------------------------------------------------------------------
		virtual void setup(float x1, float y1, float x2, float y2, float thickness){
				
			isStatic = true;
			
			body  = cpBodyNew(INFINITY, INFINITY);			
			shape = cpSegmentShapeNew(body, cpv(x1,y1), cpv(x2,y2), thickness);

		}
		
};
