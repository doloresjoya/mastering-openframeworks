#include "ofApp.h"

Particle::Particle(){
    live = false;
}

ofPoint randomPointInCircle( float maxRad ){
    ofPoint pnt;
    float rad = ofRandom(0, maxRad);
    float angle = ofRandom(0, M_TWO_PI);
    pnt.x = cos( angle ) * rad;
    pnt.y = sin( angle ) * rad;
    return pnt;
}

Params param; //Definition of global variable

void Params::setup(){
    eCenter = ofPoint( ofGetWidth()/2, ofGetHeight()/2);
    eRad = 50;
    velRad = 200;
    lifeTime = 1.0;
    rotate = 90;
    force = 10;
    spinning = 10;
    friction = 0;
}


void Particle::setup(){
    pos = param.eCenter + randomPointInCircle(param.eRad);
    vel = randomPointInCircle(param.velRad);
    time = 0;
    lifeTime = param.lifeTime;
    live = true;
}

void Particle::update(float dt){
    if(live){
        //Rotate vel
        vel.rotate(0, 0, param.rotate * dt);
        
        ofPoint acc;
        ofPoint delta = pos - param.eCenter;
        float len = delta.length();
        if(ofInRange(len, 0, param.eRad)){
            delta.normalize();
        }
        
        //Attraction/repulsion force
        acc += delta * param.force;
        
        //Spinning force
        acc.x += -delta.y * param.spinning;
        acc.y += delta.x * param.spinning;
        
        
        
        //Update pos
        pos += vel * dt;    //Euler method
        
        //Update time and check if particle should die
        time += dt;
        if ( time >= lifeTime){
            live = false;   //Particle is now considered as died
        }
    }
}

void Particle::draw(){
    if (live) {
        //Compute size
        float size = ofMap(fabs(time - lifeTime/2), 0, lifeTime/2, 3, 1);
        //Compute Color
        ofColor color = ofColor::red;
        float hue = ofMap(time, 0, lifeTime, 128, 255);
        color.setHue(hue);
        ofSetColor(color);
        ofCircle(pos, size);    //Draw particle
    }
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    
    //Allocate drawing buffer
    int w = ofGetWidth();
    int h = ofGetHeight();
    fbo.allocate(w, h, GL_RGB32F_ARB);
    
    //Fill buffer with white color
    fbo.begin();
    ofBackground(255, 255, 255);
    fbo.end();
    
    //Set up parameters
    param.setup();
    history = 0.995;
    
    time0 = ofGetElapsedTimef();
    
    bornRate = 1000;
    bornCount = 0;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    //Compute dt
    float time = ofGetElapsedTimef();
    float dt = ofClamp(time-time0, 0, 0.1);
    time0 = time;
    
    //Delete inactive particles
    int i=0;
    while (i < p.size()) {
        if (!p[i].live) {
            p.erase(p.begin() + i);
        }
        else {
            i++;
        }
    }
    
    //Born new particles
    bornCount += dt * bornRate;     //Update bornCount value
    
    if( bornCount >= 1){            //It's time to born particle(s)
        int bornN = int(bornCount); //How many born
        bornCount -= bornN;         //Correct bornCount value
        for (int i=0; i<bornN; i++) {
            Particle newP;
            newP.setup();           //Start a new particle
            p.push_back(newP);      //Add this particle to array
        }
    }
    
    //If the particle is not active - activate it
    //if (!p.live) {
    //    p.setup();
    //}
    
    //Update the particle
    //p.update(dt);
    for (int i=0; i<p.size(); i++) {
        p[i].update(dt);
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255,255,255);
    
    fbo.begin();
    
    ofEnableAlphaBlending();
    
    float alpha =(1-history) * 255;
    ofSetColor(0, 155, 255, alpha);
    ofFill();
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    ofDisableAlphaBlending();
    
    //Draw the particle
    //ofFill();
    //p.draw();
    
    ofFill();
    for (int i=0; i<p.size(); i++) {
        p[i].draw();
    }
    
    fbo.end();
    
    ofSetColor(255, 255, 255);
    fbo.draw(0,0);

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