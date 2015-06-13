#include "ofApp.h"

//Code based on Radial slit-scan ex. in Mastering OF Book by Denis Perevalov

//--------------------------------------------------------------
void ofApp::setup(){
    video.loadMovie("killbill-oren01.mov"); //Load video file
    
    //Play video with 1/4 of its normal speed
    //for better seeing slit-scan effect
    video.setSpeed(0.25);
    
    video.play();                   //Start video to play
    
    N = 150;                        //Set buffer size

}

//--------------------------------------------------------------
void ofApp::update(){
    
    video.update();                 //Decode the new frame if needed
    
    //do computing only if a new frame was obtained
    if (video.isFrameNew() ){
        //Push the new frame to the beginning of the frame list
        frames.push_front(video.getPixelsRef() );
        
        //If number of buffered frames > N,
        //then pop the oldest frame
        if (frames.size() > N ) {
            frames.pop_back();
        }
    }
    
    if (!frames.empty() ){
        if (!imagePixels.isAllocated() ){
            imagePixels = frames[0];
        }
        
        int w = frames[0].getWidth();
        int h = frames[0].getHeight();
        
        //Scan all the pixels
        for (int y=0; y<h; y++){
            for(int x=0; x<w; x++){
                ofColor color = getSlitPixelColor(x,y);
                
                imagePixels.setColor(x, y, color);
            }
        }
        image.setFromPixels(imagePixels);
    }

}

//--------------------------------------------------------------
ofColor ofApp::getSlitPixelColor(int x, int y){
    
    float dist = ofDist(x, y, mouseX, mouseY);
    
    float f = dist / 8.0; //interactive version
    //float f = y / 8.0; //non-interactive, takes calculation from y value
    
    int i0 = int(f);
    int i1 = i0 + 1;
    
    float weight0 = i1 - f;
    float weight1 = 1 - weight0;
    
    int n = frames.size() - 1;
    i0 = ofClamp(i0, 0, n);
    i1 = ofClamp(i1, 0, n);
    
    ofColor color0 = frames[i0].getColor(x, y);
    ofColor color1 = frames[i1].getColor(x, y);
    
    ofColor color = color0 * weight0 + color1 * weight1;
    
    return color;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255, 255, 255);    //Set white bg
    
    //Draw image
    ofSetColor(255, 255, 255);
    image.draw(0, 0);

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