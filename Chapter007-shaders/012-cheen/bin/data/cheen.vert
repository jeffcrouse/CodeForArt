
uniform vec4 eyePosition;
varying vec3 lightVector, eyeVector, normal;

void main() {

	gl_Position = ftransform();
	
	// Set multitexture coords... 
	gl_TexCoord[0] = gl_MultiTexCoord0;
    
    // We need to have a normal vector at fragment
	normal = normalize(gl_NormalMatrix * gl_Normal);

	// We will use the eye vector and the normal vector in the 
	// fragment shader to compute a lookup into the LUT texture.
	vec4 worldSpacePos = gl_ModelViewMatrix * gl_Vertex;
	eyeVector = (eyePosition - worldSpacePos).xyz;
}

