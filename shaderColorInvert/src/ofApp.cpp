#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	shader.load("shadersGL3/shader.vert", "shadersGL3/shader.frag");

	fbo.allocate(ofGetWidth(), ofGetHeight());
	image.loadImage("sunflower.png");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    //1. Drawing into fbo buffer
    fbo.begin();        //Start drawing into the buffer
    //Draw something here
    ofBackgroundGradient(ofColor(255),ofColor(128));
    ofSetColor(255, 255, 255);
    image.draw(351, 221);

    fbo.end();

    //2. Drawing to screen through the shader
    shader.begin();     //Enable the shader

    //draw fbo image
    ofSetColor(255, 255, 255);
    fbo.draw(0,0);

    shader.end();       //Disable the shader

}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){

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

