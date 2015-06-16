#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //Set screen frame rate
    ofSetFrameRate(60);
    
    //Set initial value
    pos0 = ofPoint (512, 300);
    pos = ofPoint ( 600, 200);
    velocity = ofPoint (100, 0);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    //Constants
    float dt = 1.0 / 60.0;
    
    //Time step
    float mass = 0.1;
    
    //Mass of a ball
    float rubberLen = 700.0;    //Segment's length
    float k = 0.5;              //Segment's stiffness
    ofPoint g(0.0, 9.8);        //Gravity force
    
    //Compute Hooke's force
    ofPoint delta = pos - pos0;
    float len = delta.length(); //Vector's length
    float hookeValue = k * (len - rubberLen);
    delta.normalize();          //Normalize vector's length
    ofPoint hookeForce = delta * (-hookeValue);
    
    //Update velocity and pos
    ofPoint force = hookeForce + g; //Resulted force
    ofPoint a = force / mass;       //Second Newton's law
    velocity += a * dt;
    //Euler method
    pos += velocity * dt;
    //Euler method

}

//--------------------------------------------------------------
void ofApp::draw(){
    //Set white background
    ofBackground(0, 153, 153);
    
    //Draw rubber as a blue line
    ofSetColor(0,0,255);
    //Set blue color
    ofLine(pos0.x, pos0.y, pos.x, pos.y);
    //Draw line
    
    //Draw ball as a red circle
    ofSetColor(255, 0, 0);
    //Set red color
    ofFill();
    //Enable filling
    ofCircle(pos.x, pos.y, 20);
    //Draw circle

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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