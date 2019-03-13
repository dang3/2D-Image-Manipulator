#include "ofApp.h"

using namespace glm;

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

void ofApp::moveImageUpStack() {
	// if image is top of stack, do nothing
	if (selectedImg->position + 1 == images.size()) return;

	// get position of images to be swapped
	int curImgPos = selectedImg->position;
	int nextImgPos = curImgPos + 1;
	
	swapImages(curImgPos, nextImgPos);
}


void ofApp::moveImageDownStack() {
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

	if (images.size() == 0) bImageLoaded = false;
	else {
		// decrements indices of Image after deleted Image by 1
		for (int i = pos; i < images.size(); i++) {
			images[i].position--;
		}
	}
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
			frame.setImage(selectedImg);
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
		for (int i = 0; i < images.size(); i++) {
			ofPushMatrix();
			ofTranslate(images[i].getXPos(), images[i].getYPos());
			images[i].draw();
			ofPopMatrix();
		}

	}
	if (bImageSelected) {
		frame.draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (bImageSelected && selectedImg != nullptr) {
		if (key == OF_KEY_UP) moveImageUpStack();
		else if (key == OF_KEY_DOWN) moveImageDownStack();
		else if (key == OF_KEY_DEL) deleteSelectedImage();
		else if (key == 'w') frame.moveFrameFromKey(DirectionKey::UP); 
		else if (key == 'a') frame.moveFrameFromKey(DirectionKey::LEFT);
		else if (key == 's') frame.moveFrameFromKey(DirectionKey::DOWN);
		else if (key == 'd') frame.moveFrameFromKey(DirectionKey::RIGHT);
		else if (key == OF_KEY_SHIFT) frame.setUniformScale(true);	// enable uniform scale
	}
	if (bImageLoaded && key == 's') {
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.save("screenShot.png");
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key == OF_KEY_SHIFT) frame.setUniformScale(false);	// disable uniform scale
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	if (!bImageSelected) return;
	// Find location of new mouse & calculate the delta
	vec3 newMousePos(x, y, 0);
	vec3 delta = newMousePos - lastMouse;
	vec3 curImgPos = selectedImg->getImagePosition();
	vec3 newPos = curImgPos + delta;

	if (bScale) {			// if scaling the image
		frame.processInput(&newMousePos, &mousePressedLocation);
	}
	else if (bTranslate) { 	// if translating the image
		selectedImg->setImagePosition(newPos);
		lastMouse = newMousePos;
		frame.setHandlePositions();
	}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	if (bImageLoaded) {
		mousePressedLocation = vec3(x, y, 0);
		if (frame.isInsideHandles(mousePressedLocation)) {
			bScale = true;
		}
		else if (isInsideImage(mousePressedLocation)) {
			bImageSelected = true;
			lastMouse = vec3(x, y, 0);
			bTranslate = true;
		}
		else {
			bImageSelected = false;
			selectedImg = nullptr;
		}
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	bScale = false;
	bTranslate = false;

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
		frame.test();
	}
}

