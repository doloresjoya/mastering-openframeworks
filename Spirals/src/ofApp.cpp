#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);     //Set screen frame rate
    
    //Allocate drawing buffer
    fbo.allocate( ofGetWidth(), ofGetHeight() );
    
    //Fill buffer with white color
    fbo.begin();
    ofBackground(0, 0, 0);
    fbo.end();
    
    //Initialize variables
    a = 0;
    b = 0;
    pos = ofPoint( ofGetWidth() / 2, ofGetHeight() / 2 );
    //Screen center
    colorStep = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    fbo.begin(); //Begin draw to buffer
    for ( int i=0; i<200; i++) {
        draw1();
    }
    fbo.end();  //End draw to buffer
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0, 0, 0); ///Set white bg
    
    //Draw buffer
    ofSetColor(255, 255, 255);
    fbo.draw(0,0);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if ( key == ' ') {
        ofImage image; //Declare image object
        //Grab contents of the screen
        image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        
        image.saveImage("screen.png");
        //Save image to file
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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