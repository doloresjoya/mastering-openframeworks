#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){

	ofSetupOpenGL(1024,768, OF_WINDOW);			// <-------- setup the GL context

	// The pendulum app draws a moving pendulum in 2D, consisting of a ball dangled on a rubber segment
	ofRunApp( new ofApp());

}
