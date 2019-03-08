#include "Frame.h"

using namespace std;
using namespace glm;

Frame::Frame() {
	ScaleHandle *handle1 = new ScaleHandle_TOP_LEFT();
	ScaleHandle *handle2 = new ScaleHandle_TOP_RIGHT();
	ScaleHandle *handle3 = new ScaleHandle_BOT_LEFT();
	ScaleHandle *handle4 = new ScaleHandle_BOT_RIGHT();

	handles.push_back(handle1);
	handles.push_back(handle2);
	handles.push_back(handle3);
	handles.push_back(handle4);

	scaleHandleWidth = handle1->getWidth();
	scaleHandleHeight = handle1->getHeight();
}

bool Frame::isInsideHandles(vec3 point) {
	// loop through every handle
	for (int i = 0; i < handles.size(); i++) {
		if (handles[i]->isInsideHandle(point)) {
			selectedHandle = handles[i];
			cout << i << endl;
			return true;
		}
	}
	return false;
}

void Frame::test() {
	for (int i = 0; i < handles.size(); i++) {
		handles[i]->setFrame(this);
	}
}

void Frame::setHandlePositions() {
	// set frame dimensions
	xPos = curImage->getImagePosition().x;
	yPos = curImage->getImagePosition().y;
	width = curImage->getImageWidth();
	height = curImage->getImageHeight();

	// set frame x & y positions
	handles[0]->setXPos(xPos - scaleHandleWidth / 2);
	handles[0]->setYPos(yPos - scaleHandleHeight / 2);

	handles[1]->setXPos(xPos+width - scaleHandleWidth / 2);
	handles[1]->setYPos(yPos - scaleHandleHeight / 2);

	handles[2]->setXPos(xPos - scaleHandleWidth / 2);
	handles[2]->setYPos(yPos+height - scaleHandleHeight / 2);

	handles[3]->setXPos(xPos+width - scaleHandleWidth / 2);
	handles[3]->setYPos(yPos+height - scaleHandleHeight / 2);
}

void Frame::setImage(Image *img) {
	this->curImage = img;
	setHandlePositions();
}

void Frame::scaleFrame(vec3 point) {
	width = point.x - xPos;
	height = point.y - yPos;
	updateImage();
}

void Frame::processInput(vec3 point) {
	selectedHandle->mouseDrag(point);
}

void Frame::updateFrameDimensions(float newWidth, float newHeight) {
	this->width = newWidth;
	this->height = newHeight;
	updateImage();
}

void Frame::updateImage() {
	curImage->setWidth(width);
	curImage->setHeight(height);
	curImage->setImagePosition(vec3(xPos, yPos, 0));
	setHandlePositions();
}

float Frame::getXPos() {
	return xPos;
}

float Frame::getYPos() {
	return yPos;
}

float Frame::getWidth() {
	return width;
}

float Frame::getHeight() {
	return height;
}

void Frame::drawBorder() {
	ofSetLineWidth(2);
	ofSetColor(255, 255, 127);
	ofNoFill();
	float xPos = curImage->getImagePosition().x;
	float yPos = curImage->getImagePosition().y;
	float borderWidth = curImage->getImageWidth();
	float borderHeight = curImage->getImageHeight();
	ofDrawRectangle(xPos, yPos, borderWidth, borderHeight);
	ofSetColor(255, 255, 255);
}

void Frame::drawHandles() {
	ofSetColor(255, 0, 0);
	for (int i = 0; i < numScaleHandles; i++) {
		handles[i]->draw();
	}
	ofSetColor(255, 255, 255);
}

void Frame::draw() {
	drawBorder();
	drawHandles();
}

void Frame::setXPos(float xPos) {
	this->xPos = xPos;
}

void Frame::setYPos(float yPos) {
	this->yPos = yPos;
}

void Frame::setWidth(float width) {
	this->width = width;
}

void Frame::setHeight(float height) {
	this->height = height;
}

Frame::~Frame() {
	for (int i = 0; i < handles.size(); i++) {
		delete handles[i];
	}
}


