#pragma once

#include "chipmunk.h"

#include "ofxChipmunkBaseShape.h"

#include "del_interface.hpp"
using namespace tpp;
#include "ofMain.h"


static bool InsidePolygon(ofPoint *polygon,int N, ofPoint p)
{
  int counter = 0;
  int i;
  double xinters;
  ofPoint p1,p2;

  p1 = polygon[0];
  for (i=1;i<=N;i++) {
    p2 = polygon[i % N];
    if (p.y > MIN(p1.y,p2.y)) {
      if (p.y <= MAX(p1.y,p2.y)) {
        if (p.x <= MAX(p1.x,p2.x)) {
          if (p1.y != p2.y) {
            xinters = (p.y-p1.y)*(p2.x-p1.x)/(p2.y-p1.y)+p1.x;
            if (p1.x == p2.x || p.x <= xinters)
              counter++;
          }
        }
      }
    }
    p1 = p2;
  }

  if (counter % 2 == 0)
    return false;
  else
    return true;
}

static float areaOfThreePoints(ofPoint A, ofPoint B, ofPoint C){
	float ab = sqrt( powf( A.x-B.x, 2) + powf(A.y - B.y, 2) );
	float bc = sqrt( powf( B.x-C.x, 2) + powf(B.y - C.y, 2) );
	float ca = sqrt( powf( C.x-A.x, 2) + powf(C.y - A.y, 2) );
	
	float s = 0.5*( ab + bc + ca );
	return sqrt( s*(s-ab)*(s-bc)*(s-ca) );
}

//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------

class ofxChipmunkPoly : public ofxChipmunkBaseShape{


	protected:
		void triangulatePoly(){
		
			if(points.size() < 3){
				printf("error in triangulatePoly - need at least 3 points for a shape, dumbass :) \n");
				assert(0);
			}
				
			ofPoint tmpPts[points.size()];
			
			for(int i = 0; i < points.size(); i++){
				tmpPts[i] = points[i];
			}
				
				
			Delaunay::Point tempP;
			for (int i = 0; i < points.size(); i++){
					tempP[0] = points[i].x;
					tempP[1] = points[i].y;
                    v.push_back(tempP);
			}
				
			Delaunay delobject(v);
			delobject.Triangulate();

			cpVect verts[3];

			for(Delaunay::fIterator fit  = delobject.fbegin(); fit != delobject.fend(); ++fit){
					int pta = delobject.Org(fit);
					int ptb = delobject.Dest(fit);
					int ptc = delobject.Apex(fit);
					
					if(pta == -1 || ptb == -1 || ptc == -1){
						printf("don't have a triangle man!\n");
						continue;
					}
					
					ofPoint center;
					
					center.x += points[pta].x;
					center.y += points[pta].y;

					center.x += points[ptb].x;
					center.y += points[ptb].y;					
					
					center.x += points[ptc].x;
					center.y += points[ptc].y;					
					
					center.x /= 3;
					center.y /= 3;
					
					if( !InsidePolygon(tmpPts, points.size(), center) ) continue;
									
					verts[0].x = points[ptb].x;
					verts[0].y = points[ptb].y;
					
					vects.push_back(verts[0]);

					verts[1].x = points[pta].x;
					verts[1].y = points[pta].y;

					vects.push_back(verts[1]);

					verts[2].x = points[ptc].x;
					verts[2].y = points[ptc].y;		
					
					vects.push_back(verts[2]);
					numShapes++;
			}
			
		}

	
	public:

		//-----------------------------------------------------------------------------------------			
		ofxChipmunkPoly(){
			numShapes = 0;
		}
		
		//-----------------------------------------------------------------------------------------
		virtual void addVertex(float x, float y){
			points.push_back(ofPoint(x, y));
		}
		
		//-----------------------------------------------------------------------------------------
		virtual void makePolyShape(float x, float y, float shapeMass, float elasticity, float fricton, bool bShapeStatic){
			makePolyShape(x, y, shapeMass, bShapeStatic);
			setElasticity(elasticity);
			setFriction(fricton);
		}
		
		virtual void setFriction(float friction){
			if( polyShapes.size() ){
				for(int i = 0; i < polyShapes.size(); i++){
					polyShapes[i]->u = friction;
				}
			}
		}

		virtual void setElasticity(float elasticity){
			if( polyShapes.size() ){
				for(int i = 0; i < polyShapes.size(); i++){
					polyShapes[i]->e = elasticity;
				}
			}
		}
				
		//-----------------------------------------------------------------------------------------
		ofPoint getPosition(){
			if(body != NULL)return ofPoint(body->p.x, body->p.y);
			return ofPoint();
		}
		
		//-----------------------------------------------------------------------------------------
		virtual void draw(){
			for(int i = 0; i < polyShapes.size(); i++){				
				cpBody *body = polyShapes[i]->body;
				cpPolyShape *poly = (cpPolyShape *)polyShapes[i];
		
				int num = poly->numVerts;
				cpVect *verts = poly->verts;
			
				glBegin(GL_TRIANGLES);
				for(int i=0; i<num; i++){
					cpVect v = cpvadd(body->p, cpvrotate(verts[i], body->rot));
					glVertex2f(v.x, v.y);
				}
				glEnd();
			}
		}
				
        vector< Delaunay::Point > v;	
		vector< cpVect > vects;
		vector< ofPoint > points;
		vector< cpShape * > polyShapes;	
		int numShapes;
		
		protected:
			//-----------------------------------------------------------------------------------------
			virtual void makePolyShape(float x, float y, float shapeMass, bool bShapeStatic){
					
				if(points.size() == 0 ){
					printf("need to add points to shape first!!\n");
					return;
				}	
				
				if(points.size() < 3 ){
					printf("you need at least 3 points to make a shape!!\n");
					return;
				}	
				
				triangulatePoly();
							
				mass	 = shapeMass;
				isStatic = bShapeStatic;
				
				if( isStatic ){
					body = cpBodyNew(INFINITY, INFINITY);
				}else{
				
					float numTriangles = vects.size() / 3;
					float inertia = 0.0;
					
					float totalArea = 0;
					
					float * areas = new float[vects.size()];

					for(int i = 0; i < vects.size(); i+= 3){					
						areas[i] = areaOfThreePoints(  ofPoint(vects[i].x, vects[i].y),  ofPoint(vects[i+1].x, vects[i+1].y),  ofPoint(vects[i+2].x, vects[i+2].y));
						totalArea += areas[i];
					}
					
					inertia = 0;
					
					for(int i = 0; i < vects.size(); i+= 3){
						cpVect verts[3];
						verts[0] = vects[i];
						verts[1] = vects[i+1];
						verts[2] = vects[i+2];
						
						float triangleMass = (areas[i]/totalArea) * mass;

						inertia += cpMomentForPoly( triangleMass, 3, verts, cpv(0,0) );
					}
					
					delete [] areas;
					
					//inertia /= numTriangles;
					body     = cpBodyNew(mass, inertia);
					
					for(int i = 0; i < vects.size(); i+= 3){
						cpVect verts[3];
						verts[0] = vects[i];
						verts[1] = vects[i+1];
						verts[2] = vects[i+2];
					
						polyShapes.push_back(cpPolyShapeNew(body, 3, verts, cpv(0,0) ));
					}
					
				}
				
				
				body->p = cpv(x, y);

			}
};
