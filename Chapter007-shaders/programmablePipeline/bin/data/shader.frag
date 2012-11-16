
/* step 2: invert the color?? */
void main()
{
    vec3 inverted = vec3(1.0, 1.0, 1.0) - gl_Color.rgb;
    gl_FragColor = vec4(inverted, 1.0);
}
