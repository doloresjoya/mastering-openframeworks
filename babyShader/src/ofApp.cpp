#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(34, 34, 34);
	ofSetVerticalSync(false);
	ofEnableAlphaBlending();

	float planeScale = 0.75
	int planeWidth = ofGetWidth() * planeScale;
	int planeHeight = ofGetHeight() * planeScale;
	int planeGridSize = 20;
	int planeColumns = planeWidth / planeGridSize;
	int planeRows = planeHeight / planeGridSize;

	plane.set(planeWidth, planeHeight, planeColumns, planeRows, OF_PRIMITIVE_TRIANGLES);


	//we load a font and tell OF to make outlines so we can draw it as GL shapes rather than textures
	//font.loadFont("type/verdana.ttf", 100, true, false, true, 0.4, 72);
	//#ifdef TARGET_OPENGLES
	//shader.load("shaders_gles/noise.vert","shaders_gles/noise.frag");
	//#else
	//if(ofGetGLProgrammableRenderer()){
	//	shader.load("shadersGL3/shader.vert", "shadersGL3/shader.frag");
	//}else{
	//	shader.load("shadersGL2/shader.vert", "shadersGL2/shader.frag");
	//}
	//#endif

	//doShader = true;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    FLOAT percentX = mouseX / (float)ofGetWidth();
    percentX = ofClamp(percentX, 0, 1);

    //the mouse/touch X position changes the color of the plane.
    //please have a look inside the frag shader,
    //we are using the globalColor value that OF passes into the shader everytime you call ofSetColor
    ofColor colorLeft = ofColor::magenta;
    ofColor colorRight = ofColor::cyan;
    ofColor colorMix = colorLeft.getLerped(colorRight, percentX);
    ofSetColor(colorMix);

    //shader.begin();//start shading

    shader.setUniform1f("time", ofGetElapsedTimef());

    float tx = ofGetWidth()/2;
    float ty = ofGetHeight()/2;
    ofTranslate(tx, ty);

    float percentY = mouseY / (float)ofGetHeight();
    float rotation = ofMap(percentY, 0, 1, -60, 60, true) + 60;
    ofRotate(rotation, 1, 0, 0);

    plane.drawWireframe();

    //shader.end(); //end shading!


	//Shader gradient screen fill
	//ofSetColor(225);

	//if( doShader ){
	//	shader.begin();
	//		ofRect(0, 0, ofGetWidth(), ofGetHeight());
	//}
    //
	//if( doShader ){
	//	shader.end();
	//}
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
	//if( key == 's' ){
	//	doShader = !doShader;
	//}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}

