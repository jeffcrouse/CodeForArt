#include "ofxCvHaarFinder.h"


static int qsort_carea_compare( const void* _a, const void* _b) {
	int out = 0;
	// pointers, ugh.... sorry about this
	CvSeq* a = *((CvSeq **)_a);
	CvSeq* b = *((CvSeq **)_b);
	// use opencv to calc size, then sort based on size
	float areaa = fabs(cvContourArea(a, CV_WHOLE_SEQ));
	float areab = fabs(cvContourArea(b, CV_WHOLE_SEQ));
	// note, based on the -1 / 1 flip
	// we sort biggest to smallest, not smallest to biggest
	if( areaa > areab ) { out = -1; }
	else {                out =  1; }
	return out;
}



ofxCvHaarFinder::ofxCvHaarFinder() {
	reset();
	scaleHaar = 1.2;
}

ofxCvHaarFinder::~ofxCvHaarFinder() {
	free( myMoments );
}
 
void ofxCvHaarFinder::reset() {
	blobs.clear();
}

void ofxCvHaarFinder::setScaleHaar(float scaleH) {
	scaleHaar = scaleH;
}

void ofxCvHaarFinder::setup(string haarFile) {
 
	haarFile	= ofToDataPath(haarFile);
	myMoments	= (CvMoments*)malloc( sizeof(CvMoments) );

	cascade		= (CvHaarClassifierCascade*)cvLoad( haarFile.c_str(), 0, 0, 0 );
	if( !cascade ){
	  printf("ERROR: Could not load classifier cascade\n" );
	} 

	blobs.clear();
}

void ofxCvHaarFinder::draw( float x, float y ) {
	
	ofEnableAlphaBlending();
	ofSetColor( 255,0,200,100 );
    glPushMatrix();
    
	glTranslatef( x, y, 0.0 );

	ofNoFill();
	for( int i=0; i<blobs.size(); i++ ) {
		ofRect( blobs[i].boundingRect.x, blobs[i].boundingRect.y, 
                blobs[i].boundingRect.width, blobs[i].boundingRect.height );
	}
	ofDisableAlphaBlending();

	glPopMatrix();
}


void ofxCvHaarFinder::findHaarObjects( ofxCvGrayscaleImage&  input,
									  int minArea,
									  int maxArea,
                                      int nConsidered) {
	reset();

	// opencv will clober the image it detects contours on, so we want to 
    // copy it into a copy before we detect contours.  That copy is allocated 
    // if necessary (necessary = (a) not allocated or (b) wrong size)
	// so be careful if you pass in different sized images to "findContours"
	// there is a performance penalty, but we think there is not a memory leak 
    // to worry about better to create mutiple contour finders for different 
    // sizes, ie, if you are finding contours in a 640x480 image but also a 
    // 320x240 image better to make two ofCvContourFinder objects then to use 
    // one, because you will get penalized less.

	if( inputCopy.width == 0 ) {
		inputCopy.allocate( input.width, input.height );
		inputCopy = input;
	} else {
		if( inputCopy.width == input.width && inputCopy.height == input.height ) {
			inputCopy = input;
		} else {
			// we are allocated, but to the wrong size -- 
			// been checked for memory leaks, but a warning:
			// be careful if you call this function with alot of different
			// sized "input" images!, it does allocation every time
			// a new size is passed in....
			inputCopy.clear();
			inputCopy.allocate( input.width, input.height );
			inputCopy = input;
		}
	}


    nFacesFound = 0;
    
    storage = cvCreateMemStorage(0);
    cvClearMemStorage( storage );

    if( cascade )
    {
        CvSeq* faces = cvHaarDetectObjects( inputCopy.getCvImage(), cascade, storage,
                                            scaleHaar, 2, CV_HAAR_DO_CANNY_PRUNING);

        nFacesFound = faces->total;
        
        for(int i = 0; i < (faces ? faces->total : 0); i++ )
        {
					
            CvRect* r = (CvRect*)cvGetSeqElem( faces, i );
             
       		blobs.push_back( ofxCvBlob() );
          
            float area		= r->width * r->height;
            float length	= (r->width * 2)+(r->height * 2);
            float centerx	= (r->x) + (r->width / 2.0);
            float centery	= (r->y) + (r->height / 2.0);
            
		    blobs[i].area 				= fabs(area);
      		blobs[i].hole 				= area < 0 ? true : false;
	    	blobs[i].length 			= length;
            blobs[i].boundingRect.x              = r->x;
            blobs[i].boundingRect.y              = r->y;
		    blobs[i].boundingRect.width          = r->width;
		    blobs[i].boundingRect.height         = r->height;
		    blobs[i].centroid.x 			= (int) centerx;
		    blobs[i].centroid.y 			= (int) centery;            

		    CvPoint pt;	
            pt.x = 0;
            pt.y = 0;
        
            // only 4 point in  blob struct		

            pt.x = r->x;
            pt.y = r->y;
            blobs[i].pts.push_back( ofPoint((float)pt.x, (float)pt.y) );
        
            pt.x = r->x + r->width;
            pt.y = r->y;
            blobs[i].pts.push_back( ofPoint((float)pt.x, (float)pt.y) );
    
            pt.x = r->x + r->width;
            pt.y = r->y + r->height;
            blobs[i].pts.push_back( ofPoint((float)pt.x, (float)pt.y) );
  
            pt.x = r->x;
            pt.y = r->y + r->height;
            blobs[i].pts.push_back( ofPoint((float)pt.x, (float)pt.y) );
        
        }

    }

	// Free the storage memory.
	// Warning: do this inside this function otherwise a strange memory leak
	if( storage != NULL ) { cvReleaseMemStorage(&storage); }

}

