#include "ofApp.h"

int W = 100;		//Grid size
int H = 100;

//The circle parameters
float Rad = 25;
//Radius of circle
float circleStep = 3;
//Step size for circle motion
int circleN = 40;
//Number of points on the circle
ofPoint pos;
//Circle center
ofPoint axeX, axyY, axyZ;
//Circle's coordinate system

//--------------------------------------------------------------
void ofApp::setup(){
    pos = ofPoint(0, 0, 0);
    //Start from the center coordinate
    axeX = ofPoint(1, 0, 0);    //Set initial coordinate system
    axyY = ofPoint(0, 1, 0);
    axyZ = ofPoint(0, 0, 1);
    light.enable();
    //Enable lighting
    ofSetFrameRate(60);
    //Set the rate of screen redrawing
}

//--------------------------------------------------------------
void ofApp::update(){
    addRandomCircle(mesh);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableDepthTest();    //Enable z-buffering
    //Set a gradient background from white to gray
    ofBackgroundGradient( ofColor(255), ofColor(128) );

    ofPushMatrix(); //Store the coordinate system
    //Move the coordinate center to screen's center
    ofTranslate( ofGetWidth()/2, ofGetHeight()/2, 0 );

    //Calculate the rotation angle
    float time = ofGetElapsedTimef();
    float angle = time * 20;
    ofRotate(angle, 0, 1, 0);

    ofTranslate( -mesh.getCentroid() );

    mesh.draw();

    ofPopMatrix();

}

void ofApp::addRandomCircle( ofMesh &mesh ){

    float time = ofGetElapsedTimef();
    //Parameters - twisting and rotating angles and color
    float twistAngle = 5.0 * ofSignedNoise( time * 0.3 + 332.4 );
    float rotateAngle = 1.5;
    ofFloatColor color( ofNoise(time * 0.05),
                        ofNoise(time * 0.1),
                        ofNoise(time * 0.15)
                       );
    color.setSaturation(1.0);   //Make the color maximally colorful

    //Rotate the coordinate system of the circle
    axeX.rotate( twistAngle, axyZ );
    //Print twist angle
    cout << "twist angle" << twistAngle <<
    endl;
    axyY.rotate( twistAngle, axyZ );

    axeX.rotate( rotateAngle, axyY );
    axyZ.rotate( rotateAngle, axyY );

    //Move the circle on a step
    ofPoint move = axyZ * circleStep;
    pos += move;

    //Add vertices
    for(int i=0; i<circleN; i++){
        float angle = float(i) / circleN * TWO_PI;
        float x = Rad * cos(angle);
        float y = Rad * sin(angle);
        //We would like to distort this point
        //to make the knot's surface embossed
        float distort = ofNoise(x*0.2, y*0.2, time*0.2+30);
        distort = ofMap( distort, 0.2, 0.8, 0.8, 1.2 );
        x *= distort;
        y *= distort;

        ofPoint p = axeX * x + axyY * y + pos;
        mesh.addVertex(p);
        mesh.addColor(color);
    }

    //Add the triangles
    int base = mesh.getNumVertices() - 2 * circleN;
    if (base >= 0){
        for(int i=0; i<circleN; i++){
            int a = base + i;
            int b = base + (i + 1) % circleN;
            int c = circleN + a;
            int d = circleN + b;

            mesh.addTriangle(a, b, d);
            mesh.addTriangle(a, d, c);
        }
        //Update the normals
        setNormals(mesh);
    }
}


//Universal function which sets normals for the triangle mesh
void setNormals( ofMesh &mesh ){

	//The number of the vertices
	int nV = mesh.getNumVertices();

	//The number of the triangles
	int nT = mesh.getNumIndices() / 3;

	vector<ofPoint> norm( nV ); //Array for the normals

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
