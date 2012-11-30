#ifndef _AUBIO_SOUND_PROCESSOR
#define _AUBIO_SOUND_PROCESSOR

#include "aubio.h"
#include "ofMain.h"

class aubioAnalyzer{
	
	public:
		
		void setup();
		void processAudio(float * buffer, int bufferSize);		
		
		~aubioAnalyzer();
	
		float pitch;
		float amplitude;
		
		// ------------------------------------------------------------------
		// internal aubio variables

		unsigned int win_s;							/* window size */
		unsigned int hop_s;							/* hop size */
		unsigned int samplerate;						/* samplerate */
		unsigned int channels;						/* number of channel */
		
		aubio_pitchdetection_mode mode;
		aubio_pitchdetection_type type;

		fvec_t * in;
		aubio_pitchdetection_t * pitch_output ;
        aubio_beattracking_t * beattracking;
        
	
		// ------------------------------------------------------------------

};

#endif	

