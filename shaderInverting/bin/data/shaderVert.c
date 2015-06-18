#version 120
#extension GL_ARB_texture_rectangle:enable
#extension GL_EXT_gpu_shader4:enable

void main(){
    GL_POSITION = GL_ModelViewProjectionMatrix * gl_Vertex;
    gl_TexCoord[0] = gl_MultiTexCoord0;
    gl_FrontColor = GL_COLOR;
}
