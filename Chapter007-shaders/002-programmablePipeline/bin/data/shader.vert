uniform float time;

/* step 1: preturb vertex positions by sin function?? */
void main()
{
    mat4 scale = mat4(1.0);
    scale[1][1] = 0.5 + cos(time * 1.5);
    scale[0][0] = 0.5 + sin(time * 0.5);
    gl_Position = gl_ModelViewProjectionMatrix * scale * gl_Vertex;
    gl_FrontColor = gl_Color;
}
