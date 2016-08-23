#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    testImage.load("test.jpg");
    
    points.push_back(ofVec2f(0, 0));
    points.push_back(ofVec2f(testImage.getWidth(), 0));
    points.push_back(ofVec2f(testImage.getWidth(), testImage.getHeight()));
    points.push_back(ofVec2f(0, testImage.getHeight()));
    
    center = ofVec2f(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()));
    
    // gui
    panel.setup();
    panel.add(rotateValue.set("rotateValue", 10, 0, 255));
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    // ofRotate
    ofPushMatrix();
    ofTranslate(center);
    ofRotateZ(rotateValue);
    testImage.draw(-testImage.getWidth()/2.0, -testImage.getHeight()/2.0);
    ofPopMatrix();
    
    // rotateCoord
    ofSetColor(ofColor::red);
    ofPushMatrix();
    ofTranslate(center);
    for (int i = 0; i < (int)points.size(); i++) {
        ofVec2f point = points[i] - ofVec2f(testImage.getWidth()/2.0, testImage.getHeight()/2.0);
        ofVec2f rotatedPoint = rotateCoord(point, DEG_TO_RAD*rotateValue);
        ofDrawCircle(rotatedPoint , 5);
    }
    ofPopMatrix();
    ofSetColor(255);
    
    // debug
    ofDrawCircle(center, 5);
    
    // gui
    panel.draw();
}

ofVec2f ofApp::rotateCoord(ofVec2f p,float rad){
    return ofVec2f(p.x*cos(rad)-p.y*sin(rad), p.x*sin(rad)+p.y*cos(rad));
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
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    center = ofVec2f(x, y);
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
