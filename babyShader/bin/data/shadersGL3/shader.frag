//fragment shader
#version 150

uniform vec4 globalColor;
out vec4 outputColor;

void main(){
    //gl_FragCoord contains the window relative coordinate for the fragment.
    //we use gl_FragCoord.x position to control the red color value.
    //we use gl_FragCoord.y position to control the green color value.
    //All r, g, b, values are between 0 and 1.

    //float windowWidth = 1024.0;
    //float windowHeight = 768.0;

    //float r = gl_FragCoord.x/windowWidth;
    //float g = gl_FragCoord.y/windowHeight;
    //float b = 1.0;
    //float a = 1.0;
    //outputColor = vec4(r, g, b, a);
    outputColor = globalColor;
}
