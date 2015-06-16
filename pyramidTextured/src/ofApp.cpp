#include "ofApp.h"

ofImage image;

//--------------------------------------------------------------
void ofApp::setup(){
    //Pyramid's base vertices
    ofPoint v0 = ofPoint( -200, -100, 0 );
    ofPoint v1 = ofPoint( 200, -100, 0 );
    ofPoint v2 = ofPoint(  0, 200, 0 );
    //Pyramid's top vertex
    ofPoint v3 = ofPoint( 0, 0, 100 );
    
    //Add triangles by its vertices
    mesh.addVertex( v3 ); mesh.addVertex( v2 ); mesh.addVertex( v0 );
    mesh.addVertex( v3 ); mesh.addVertex( v1 ); mesh.addVertex( v2 );
    mesh.addVertex( v3 ); mesh.addVertex( v0 ); mesh.addVertex( v1 );
    mesh.setupIndicesAuto();	//Set up indices
    
    setNormals( mesh );			//Set normals to the surface
    //Note, setNormals is our function,
    //which is declared
    
    //set up the texture coordinate for all the vertices
    mesh.addTexCoord(ofPoint(100, 100) );   //v3
    mesh.addTexCoord(ofPoint(10, 300) );    //v2
    mesh.addTexCoord(ofPoint(10, 10) );     //v0
    
    mesh.addTexCoord(ofPoint(100, 100));    //v3
    mesh.addTexCoord(ofPoint(300, 10));    //v0
    mesh.addTexCoord(ofPoint(10, 300));    //v1
    
    mesh.addTexCoord(ofPoint(100, 100));    //v3
    mesh.addTexCoord(ofPoint(10, 10));    //v0
    mesh.addTexCoord(ofPoint(300, 10));    //v1
    
    //Load an image
    image.loadImage("sunflower.png");
    
    //Enabling light source
    light.enable();

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableDepthTest();			//Enable z-buffering
    
    //Set a background
    ofBackgroundGradient( ofColor( 255 ), ofColor( 128 ) );
    
    ofPushMatrix();					//Store the coordinate system
    
    //Move coordinate center to screen's center
    ofTranslate( ofGetWidth()/2, ofGetHeight()/2, 0 );
    
    //Rotate the coordinate system
    float time = ofGetElapsedTimef(); //Get time in seconds
    float angle = time * 30;		//Rotate angle
    ofRotate( angle, 0, 1, 1 );
    
    ofSetColor( 255, 255, 255 );	//Set white color
    image.bind();                   //Use image's texture for drawing
    mesh.draw();                    //Draw mesh
    image.unbind();                 //End using image's texture
    
    ofPopMatrix();					//Restore the coordinate system

}

//--------------------------------------------------------------
//Universal function which sets normals for the triangle mesh
void setNormals( ofMesh &mesh ){
    
    //The number of the vertices
    int nV = mesh.getNumVertices();
    
    //The number of the triangles
    int nT = mesh.getNumIndices() / 3;
    
    vector<ofPoint> norm( nV );		//Array for the normals
    
    //Scan all the triangles. For each triangle add its
    //normal to norm's vectors of triangle's vertices
    for (int t=0; t<nT; t++) {
        
        //Get indices of the triangle t
        int i1 = mesh.getIndex( 3 * t );
        int i2 = mesh.getIndex( 3 * t + 1 );
        int i3 = mesh.getIndex( 3 * t + 2 );
        
        //Get vertices of the triangle
        const ofPoint &v1 = mesh.getVertex( i1 );
        const ofPoint &v2 = mesh.getVertex( i2 );
        const ofPoint &v3 = mesh.getVertex( i3 );
        
        //Compute the triangle's normal
        ofPoint dir = ( (v2 - v1).crossed( v3 - v1 ) ).normalized();
        
        //Accumulate it to norm array for i1, i2, i3
        norm[ i1 ] += dir;
        norm[ i2 ] += dir;
        norm[ i3 ] += dir;
    }
    
    //Normalize the normal's length
    for (int i=0; i<nV; i++) {
        norm[i].normalize();
    }
    
    //Set the normals to mesh
    mesh.clearNormals();
    mesh.addNormals( norm );
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