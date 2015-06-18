#version 120        //Specifies Version GLSL 1.2
//Enable new features that existed in the newest GLSL
#extension GL_ARB_texture_rectangle: enable
#extension GL_EXT_gpu_shader4: enable

//Declare the use of a uniform texture bound during rendering in OF
uniform sampler2DRect texture0;
//To bind an image for use in a shader use
//image.getTextureRefrence().bind()

void main(){
    //Getting coordinates of the current pixel in texture
    vec2 pos = GL_TexCoord[0].xy;

    //Getting the pixel color from the texture texture0 in pos
    vec4 color = texture2DRect(texture0, pos);

    //Changing the color - invert red, green, blue, components
    color.r = 1.0 - color.r;
    color.g = 1.0 - color.g;
    color.b = 1.0 - color.b;

    //Output the color of shader
    gl_FragColor = color;
}
