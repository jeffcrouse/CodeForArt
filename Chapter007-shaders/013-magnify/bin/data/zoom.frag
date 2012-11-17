uniform sampler2DRect src_tex_unit0;
uniform vec2 src_tex_offset0;

uniform vec2 circlePos;
uniform float circleRadius;
uniform float minZoom;
uniform float maxZoom;

vec4 color;

void main( void )
{  
	
	vec2 st		= gl_TexCoord[0].st;
	
	
	//check if our pixels fit in the bounding rect - so we avoid expensive operations like sqrt. 
	
	float maxX = circlePos.x + circleRadius;
	float minX = circlePos.x - circleRadius;
	
	float maxY = circlePos.y + circleRadius;
	float minY = circlePos.y - circleRadius;
	
	if( st.s > minX && st.s < maxX && st.t > minY && st.t < maxY){
		
		float relX = st.s - circlePos.x;
		float relY = st.t - circlePos.y;
		
		float ang =  atan(relY, relX);
		float dist = sqrt(relX*relX + relY*relY);
		
		if( dist <= circleRadius ){
		
			//figure a zoom value for the pixel based on its distance from the center of the circle
			float newRad = dist * ( (maxZoom * dist/circleRadius) + minZoom );
		
			float newX = circlePos.x + cos( ang ) * newRad;
			float newY = circlePos.y + sin( ang ) * newRad;		

			gl_FragColor = texture2DRect(src_tex_unit0, vec2(newX, newY) );
			
		}else{
			//just draw the pixels as normal
			gl_FragColor = texture2DRect(src_tex_unit0, st );
		}
		
	}else{
			//just draw the pixels as normal
			gl_FragColor = texture2DRect(src_tex_unit0, st );
	}
}