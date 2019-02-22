#include "ofApp.h"

using namespace glm;

Image::Image() {

}

Image::Image(ofImage img, float imageWidth, float imageHeight, vec3 dropLocation) {
	this->img = img;
	this->imageWidth = imageWidth;
	this->imageHeight = imageHeight;
	this->imagePosition = dropLocation;
	calculateImageCenter();
}

void Image::calculateImageCenter() {
	float x = imagePosition.x - (imageWidth / 2);
	float y = imagePosition.y - (imageHeight / 2);
	imageCenter = vec3(x, y, 0);
}

float Image::getImageWidth() {
	return imageWidth;
}

float Image::getImageHeight() {
	return imageHeight;
}

vec3 Image::getImagePosition() {
	return imagePosition;
}

vec3 Image::getImageCenter() {
	return imageCenter;
}

void Image::draw() {
	img.draw(imagePosition);
}

void ofApp::drawSelectionRect() {
	ofSetLineWidth(2);
	ofSetColor(255, 255, 127);
	ofNoFill();

	float xPos = selectedImg.getImagePosition().x;
	float yPos = selectedImg.getImagePosition().y;
	float rectWidth = selectedImg.getImageWidth();
	float rectHeight = selectedImg.getImageHeight();
	ofDrawRectangle(xPos, yPos, rectWidth, rectHeight);
	ofSetColor(255, 255, 255);
}

void ofApp::setSelectedImg(Image &img) {
	this->selectedImg = img;
}

// Finds the first image that is inside the point
bool ofApp::isInsideImage(vec3 point) {
	for (vector<Image>::reverse_iterator itr = images.rbegin(); itr != images.rend(); itr++) {
		Image curImage = *itr;
		float x1 = curImage.getImagePosition().x;
		float y1 = curImage.getImagePosition().y;
		float x2 = x1 + curImage.getImageWidth();
		float y2 = y1 + curImage.getImageHeight();
		if (point.x >= x1 && point.x <= x2 && point.y >= y1 && point.y <= y2) {
			setSelectedImg(curImage);
			return true;
		}
	}
}

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	if (bImageLoaded) {
		for (vector<Image>::iterator itr = images.begin(); itr != images.end(); itr++) {
			itr->draw();
		}
	}
	if (bImageSelected) {
		drawSelectionRect();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (bImageSelected) {
		if (key == OF_KEY_UP) {

		}
	}
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
void ofApp::mousePressed(int x, int y, int button) {
	if (isInsideImage(vec3(x, y, 0))) {
		bImageSelected = true;
		cout << "click\n";
	}
	else {

		bImageSelected = false;
	}
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
	if (image.load(dragInfo.files[0])) {
		bImageLoaded = true;
		float imageWidth = image.getWidth();
		float imageHeight = image.getHeight();
		vec3 dropLocation = vec3(dragInfo.position, 0);
		Image newImage(image, imageWidth, imageHeight, dropLocation);
		images.push_back(newImage);
		cout << "f\n";
	}
}

