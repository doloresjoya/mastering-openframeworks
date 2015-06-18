#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    nTri = 1500;        //The number of triangles
    nVert = nTri * 3;   //The number of the vertices equals nTri*3

    float Rad = 250;    //The sphere's radius
    float rad = 25;     //Maximal triangles radius
                        //formally, it's the max coordinates'
                        //deviation from the triangles center

    //Fill the vertices array
    vertices.resize(nVert); //Set the array size
    for (int i=0; i<nTri; i++){ //Scan all the triangles
            //Generate the center of the triangle
            //as a random point on the sphere
            //Take the random point from
            //cube [-1, 1]x[-1, 1]x[-1, 1]
            ofPoint center( ofRandom(-1, 1),
                            ofRandom(-1, 1),
                            ofRandom(-1, 1) );
            center.normalize(); //normalize vector's length to 1
            center *= Rad;      //Now the center vector has length rad

            //Generate the triangles vertices
            //as the center plus random point from
            //[-rad, rad]x[-rad, rad]x[-rad, rad]
            for(int j=0; j<3; j++){
                vertices[ i*3 + j ] =
                    center + ofPoint(ofRandom(-rad, rad),
                                     ofRandom(-rad, rad),
                                     ofRandom(-rad, rad)
                                     );
            }
    }

    //Fill the array of triangles colors
    colors.resize(nTri);
    for(int i=0; i<nTri; i++){
        //Take a random color from black to red
        colors[i] = ofColor(ofRandom(0, 255), 0, 0);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableDepthTest();   //Enable z-buffering

    //Set a gradient background from white to gray
    //for adding an illusion of visual depth to the scene
    ofBackgroundGradient( ofColor(255), ofColor(128) );

    ofPushMatrix(); //Store the coordinate system

    //Move the coordinate center to screen's center
    ofTranslate( ofGetWidth()/2, ofGetHeight()/2, 0);

    //Calculate the rotation angle
    float time = ofGetElapsedTimef();   //Get time in seconds
    float angle = time * 10;            //Compute angle. We rotate at speed
                                        //10 degrees per second
    ofRotate(angle, 0, 1, 0);           //Rotate the coordinate system
                                        //along y axis
    //Draw the triangles
    for(int i=0; i<nTri; i++){
        ofSetColor(colors[i]);  //Set color
        ofTriangle(vertices[i*3],vertices[i*3+1],vertices[i*3+2]);  //Draw triangle
    }
    ofPopMatrix();  //Restore the coordinate system
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
