uniform sampler2DRect src_tex_unit0;
uniform vec2 sampleDivisor;

void main( void )
{
	vec2 samplePos = gl_TexCoord[0].st - mod( gl_TexCoord[0].st, sampleDivisor );
	gl_FragColor = texture2DRect( src_tex_unit0, samplePos );
}