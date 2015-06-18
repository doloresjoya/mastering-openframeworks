#include "ofApp.h"

const int N = 6;            //Number of the samples
ofSoundPlayer sound[N];     //Array of the samples
float vol[N];               //Volumes of the samples


//--------------------------------------------------------------
void ofApp::setup(){
    //Load and set up the sound samples
    for (int i=0; i<N; i++){
        sound[i].loadSound("vox" + ofToString(i + 1) + ".wav");
        sound[i].setLoop("true");

        //Do some stereo panoraming of the sounds
        sound[i].setPan(ofMap(i, 0, N-1, -0.5, 0.5));
        sound[i].setVolume(0);
        sound[i].play();    //Start a sample to play
    }

    //Decrease overall volume to eliminate volume overload
    //(audio clipping)
    ofSoundSetVolume(0.2);

}


//--------------------------------------------------------------
void ofApp::update(){
    float time = ofGetElapsedTimef();

    //Update volumes
    float tx = time * 0.1 + 50;
    for (int i=0; i<N; i++){
    //Calculate the sample volume as 2D Perlin noise
    //depending on tx and ty = i * 0.2
    float ty = i * 0.2;
    vol[i] = ofNoise(tx, ty);   //Perlin noise
    sound[i].setVolume(vol[i]); //Set samples volume
    }

    //Update sound engine
    ofSoundUpdate();
}
//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255, 255, 255);

    //Draw volumes as vertical lines
    ofSetColor(0, 0, 0);
    for (int i=0; i<N; i++){
        ofRect( i * 20 + 100, 400, 5, -vol[i] * 300);
    }

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
