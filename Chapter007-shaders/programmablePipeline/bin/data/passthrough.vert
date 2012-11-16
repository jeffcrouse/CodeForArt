
/* step 1: passthrough vertex stage */
void main()
{
    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
}