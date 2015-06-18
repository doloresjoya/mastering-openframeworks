//vertex shader

#version 150

uniform mat4 modelViewProjectionMatrix;
in vec4 position;

void main(){
    GL_POSITION = modelViewProjectionMatrix * position;
}
