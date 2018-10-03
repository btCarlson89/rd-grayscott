#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    //  Shaders
    shader.load("shaders/grayscott");
    
    //  Fbos
    output.allocate(ofGetWidth(), ofGetHeight());
    output.begin();
    ofClear(0, 255);
    output.end();
    pingpong.allocate(ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::update(){

    pingpong.dst->begin();
    
    ofClear(0, 0, 0, 255);
    
    shader.begin();
    
    shader.setUniformTexture("prevTexture", pingpong.src->getTexture(), 0);
    shader.setUniformTexture("tex0", output.getTexture(), 1);
    shader.setUniform1f( "ru", (float)ru);
    shader.setUniform1f( "rv", (float)rv);
    shader.setUniform1f( "f", (float)f );
    shader.setUniform1f( "k", (float)k );
    
    pingpong.src->draw(0, 0);
    
    shader.end();
    
    pingpong.dst->end();
    
    pingpong.swap();
}

//--------------------------------------------------------------
void ofApp::draw(){

    pingpong.src->draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

    pingpong.src->begin();
    ofSetColor(ofNoise( ofGetElapsedTimef() )*255);
    ofDrawCircle(x, y, 3);
    pingpong.src->end();
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
