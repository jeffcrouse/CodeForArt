#pragma once

#include "chipmunk.h"
#include "ofxChipmunkBaseShape.h"
#include "ofMain.h"


//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------

class ofxChipmunkRect : public ofxChipmunkBaseShape{
	
	public:

		//-----------------------------------------------------------------------------------------			
		ofxChipmunkRect(){
			
		}

		//-----------------------------------------------------------------------------------------
		virtual void setup(float x, float y, float w, float h, float shapeMass, float elasticity, float fricton, bool bShapeStatic){
			setup(x, y, w, h, shapeMass, bShapeStatic);
			setElasticity(elasticity);
			setFriction(fricton);
		}
				
		//-----------------------------------------------------------------------------------------
		ofPoint getPosition(){
			if(body != NULL)return ofPoint(body->p.x, body->p.y);
			return ofPoint();
		}
		
		//-----------------------------------------------------------------------------------------
		virtual void draw() {
		
			cpBody *body = shape->body;
			cpPolyShape *poly = (cpPolyShape *)shape;
	
			int num = poly->numVerts;
			cpVect *verts = poly->verts;
			
			glBegin(GL_QUADS);
			for(int i=0; i<num; i++){
				cpVect v = cpvadd(body->p, cpvrotate(verts[i], body->rot));
				glVertex2f(v.x, v.y);
			}
			glEnd();
		}
		
	protected:
		//-----------------------------------------------------------------------------------------
		virtual void setup(float x, float y, float w, float h, float shapeMass, bool bShapeStatic){
				
			float hw = w/2;
			float hh = h/2;
		
			int num = 4;
			cpVect verts[] = {
				cpv(-hw,-hh),
				cpv(-hw, hh),
				cpv( hw, hh),
				cpv( hw,-hh),
			};
			
			mass	 = shapeMass;
			isStatic = bShapeStatic;
			
			if( isStatic ){
				body = cpBodyNew(INFINITY, INFINITY);
			}else{
				body = cpBodyNew(mass, cpMomentForPoly(mass, num, verts, cpv(0,0) ) );
			}
			
			body->p = cpv(x, y);
			shape = cpPolyShapeNew(body, num, verts, cpv(0,0));
		}
		
};
