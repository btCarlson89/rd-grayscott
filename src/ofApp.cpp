#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    //  Shaders
    gs_shader.load("shaders/grayscott2");
    vz_shader.load("shaders/draw");
    
    //  Fbos
    pingpong.allocate(ofGetWidth(), ofGetHeight());
    output.allocate(ofGetWidth(), ofGetHeight());
    
    //  Plane
    plane.set(ofGetWidth(), ofGetHeight());
    plane.mapTexCoordsFromTexture(pingpong.src->getTexture());
    
    //  Images
    tex.load("turquoise_metal.jpg");
    
    //  OF
    ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update(){

    ofSetWindowTitle(ofToString(ofGetFrameRate(), 2));
    
    for(int i = 0; i < passes; ++i)
    {
        pingpong.dst->begin();
    
        ofClear(0, 0, 0, 255);
    
        gs_shader.begin();
    
        //    shader.setUniformTexture("prevTexture", pingpong.src->getTexture(), 0);
        //    shader.setUniform1f( "ru", (float)ru);
        //    shader.setUniform1f( "rv", (float)rv);
        //    shader.setUniform1f( "f", (float)f );
        //    shader.setUniform1f( "k", (float)k );
    
        gs_shader.setUniformTexture("iChannel0", pingpong.src->getTexture(), 0);
        gs_shader.setUniform1i( "iFrame", ofGetFrameNum());
        gs_shader.setUniform2f("iResolution", ofGetWidth(), ofGetHeight());

    
        pingpong.src->draw(0, 0);
    
        gs_shader.end();
    
        pingpong.dst->end();
    
        pingpong.swap();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    vz_shader.begin();
    
    vz_shader.setUniformTexture("tex0", pingpong.src->getTexture(), 0);
    vz_shader.setUniform2f("iResolution", ofGetWidth(), ofGetHeight());

    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    plane.draw();
    ofPopMatrix();
    
    vz_shader.end();
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
    ofDrawCircle(x, y, 32);
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
