#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    float  a, b;           //Angle and its increment
    ofPoint pos, lastPos;   //Current and last drawing
    ofColor color;          //Drawing color
    int colorStep;          //Counter for color changing
    ofFbo fbo;              //Drawing buffer
    void draw1(){
        //Change a
        a += b * DEG_TO_RAD;
        //Draw one line segment
        //a holds values in radians, b holds values in degrees
        //so when changing a we multiply b to DEG_TO_RAD constant
        
        //Change b
        b = b + 7;
        
        //Shift pos in direction defined by angle a
        lastPos = pos;      //Store last pos value
        ofPoint d = ofPoint( cos(a), sin(a) );
        float len = 20;
        pos += d * len;
        
        //Change color each 100 steps
        if (colorStep % 100 == 0 ){
            //Generate random color
            color = ofColor ( ofRandom(0, 255),
                              ofRandom(0, 255),
                              ofRandom(0, 255) );
        }
        colorStep++;
        
        //Draw line segment
        ofSetColor(color);
        ofLine(lastPos, pos);
        ofSetLineWidth(15);
        ofEnableSmoothing();
    }
};
