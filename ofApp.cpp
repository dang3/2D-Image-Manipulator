#include "ofApp.h"

using namespace glm;

Image::Image() {

}

Image::Image(ofImage img, float imageWidth, float imageHeight, vec3 dropLocation, int position) {
	this->img = img;
	this->imageWidth = imageWidth;
	this->imageHeight = imageHeight;
	this->imagePosition = dropLocation;
	this->position = position;
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

void Image::setImagePosition(vec3 pos) {
	this->imagePosition = pos;
}

int Image::getPosition() {
	return position;
}

void Image::setPosition(int position) {
	this->position = position;
}

void Image::draw() {
	img.draw(imagePosition);
}

void ofApp::swap(Image &a, Image &b) {
	Image temp = a;
	a = b;
	b = temp;
}

void ofApp::swapImages(int curImagPos, int newImgPos) {
	// swap stored index value for each Image
	images[curImagPos].position = newImgPos;
	images[newImgPos].position = curImagPos;

	// swap places
	swap(images[curImagPos], images[newImgPos]);
	
	// keep selectedImg pointer on original Image
	selectedImg = &images[newImgPos];
}

void ofApp::moveSelectedImageUp() {
	// if image is top of stack, do nothing
	if (selectedImg->position + 1 == images.size()) return;

	// get position of images to be swapped
	int curImgPos = selectedImg->position;
	int nextImgPos = curImgPos + 1;
	
	swapImages(curImgPos, nextImgPos);
}

void ofApp::moveSelectedImageDown() {
	// if image is bottom of stack, do nothing
	if (selectedImg->position == 0) return;

	// get position of images to be swapped
	int curImgPos = selectedImg->position;
	int prevImgPos = curImgPos - 1;

	swapImages(curImgPos, prevImgPos);
}

void ofApp::deleteSelectedImage() {
	int pos = selectedImg->position;
	images.erase(images.begin() + pos);
	bImageSelected = false;
	selectedImg = nullptr;
	count--;

	// decrements indices of Image after deleted Image by 1
	for (int i = pos; i < images.size(); i++) {
		images[i].position--;
	}
}

void ofApp::drawSelectionRect() {
	ofSetLineWidth(2);
	ofSetColor(255, 255, 127);
	ofNoFill();
	float xPos = selectedImg->getImagePosition().x;
	float yPos = selectedImg->getImagePosition().y;
	float rectWidth = selectedImg->getImageWidth();
	float rectHeight = selectedImg->getImageHeight();
	ofDrawRectangle(xPos, yPos, rectWidth, rectHeight);
	ofSetColor(255, 255, 255);	// to prevent images from being colored
}

// Finds the first image that is inside the point
bool ofApp::isInsideImage(vec3 point) {
	for (int i = images.size()-1; i >= 0; i--) {
		Image curImage = images[i];
		float x1 = curImage.getImagePosition().x;
		float y1 = curImage.getImagePosition().y;
		float x2 = x1 + curImage.getImageWidth();
		float y2 = y1 + curImage.getImageHeight();
		if (point.x >= x1 && point.x <= x2 && point.y >= y1 && point.y <= y2) {
			selectedImg = &images[i];
			return true;
		}
	}
	return false;
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
	if (bImageSelected && selectedImg != nullptr) {
		if (key == OF_KEY_UP) moveSelectedImageUp();
		else if (key == OF_KEY_DOWN) moveSelectedImageDown();
		else if (key == 'd') deleteSelectedImage();
	}
	if (bImageLoaded && key == 's') {
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.save("screenShot.png");
		cout << "saved\n";
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
	if (!bImageSelected) return;
	vec3 newMousePos(x, y, 0);
	vec3 delta = newMousePos - lastMouse;
	vec3 curImgPos = selectedImg->getImagePosition();
	vec3 newPos = curImgPos + delta;
	selectedImg->setImagePosition(newPos);
	lastMouse = newMousePos;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	if (bImageLoaded && isInsideImage(vec3(x, y, 0))) {
		bImageSelected = true;
		lastMouse = vec3(x, y, 0);
	}
	else {
		bImageSelected = false;
		selectedImg = nullptr;
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	bDrag = false;
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
		Image newImage(image, imageWidth, imageHeight, dropLocation, count++);
		images.push_back(newImage);
	}
}

