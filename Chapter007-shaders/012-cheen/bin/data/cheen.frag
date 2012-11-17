uniform sampler2DRect Tex0;
uniform float alpha;
uniform vec2 textureSize;

varying vec3 eyeVector, normal;

void main() {

	vec3 nNormal = normalize(normal);
	vec3 nEyeVector = normalize(eyeVector);
	vec2 uv;

	// use eye dot normal to lookup the appropriate surface color.
	float nDotE = dot(nEyeVector, nNormal);
	uv.y = 1.0;
	uv.x = nDotE * textureSize.x;
	vec4 c1 = texture2DRect(Tex0, uv);

	gl_FragColor = vec4(c1.rgb, alpha);
}

