//fragment shader

//Specifies GLSL 1.2
#version 120
//Enable newer GLSL version features
#extension GL_ARB_texture_rectangle:enable
#extension GL_EXT_gpu_shader4:enable
//Declare that the shader wanted to use some textures
uniform sampler2DRect texture0;


void main(){
    //Getting coordinate of the current pixel in texture
    vec2 pos = gl_TexCoord[0].xy;

    //Getting the pixel color from the texture texture0 in pos
    vec4 color = texture2DRect(texture0, pos);

    //Changing the color - invert red, green, blue components
    //color.r = 1.0 - color.r;
    //color.g = 1.0 - color.g;
    //color.b = 1.0 - color.b;

    color.rg = color.gr;

    //Output the color of the shader
    gl_FragColor = color;
}
