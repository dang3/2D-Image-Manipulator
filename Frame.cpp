#include "Frame.h"

using namespace std;
using namespace glm;

Frame::Frame() {
	for (int i = 0; i < numScaleHandles; i++) {
		ScaleHandle handle;
		scaleHandles.push_back(handle);
	}
	scaleHandleWidth = scaleHandles[0].getWidth();
	scaleHandleHeight = scaleHandles[0].getHeight();
}

bool Frame::isInsideHandles(vec3 point) {
	// loop through every handle
	for (int i = 0; i < scaleHandles.size(); i++) {
		if (scaleHandles[i].isInsideHandle(point)) {
			selectedHandle = &scaleHandles[i];
			return true;
		}
	}
	
	return false;
}

void Frame::setHandlePositions() {
	// set frame dimensions
	xPos = curImage->getImagePosition().x;
	yPos = curImage->getImagePosition().y;
	width = curImage->getImageWidth();
	height = curImage->getImageHeight();

	// set frame x & y positions
	scaleHandles[0].setXPos(xPos - scaleHandleWidth / 2);
	scaleHandles[0].setYPos(yPos - scaleHandleHeight / 2);

	scaleHandles[1].setXPos(xPos+width - scaleHandleWidth / 2);
	scaleHandles[1].setYPos(yPos - scaleHandleHeight / 2);

	scaleHandles[2].setXPos(xPos - scaleHandleWidth / 2);
	scaleHandles[2].setYPos(yPos+height - scaleHandleHeight / 2);

	scaleHandles[3].setXPos(xPos+width - scaleHandleWidth / 2);
	scaleHandles[3].setYPos(yPos+height - scaleHandleHeight / 2);
}

void Frame::setImage(Image *img) {
	this->curImage = img;
	setHandlePositions();
}

void Frame::scaleFrame(vec3 point) {
	width = point.x - xPos;
	height = point.y - yPos;
}

void Frame::drawBorder() {
	ofSetLineWidth(2);
	ofSetColor(255, 255, 127);
	float xPos = curImage->getImagePosition().x;
	float yPos = curImage->getImagePosition().y;
	float borderWidth = curImage->getImageWidth();
	float borderHeight = curImage->getImageHeight();
	ofDrawRectangle(xPos, yPos, borderWidth, borderHeight);
	ofSetColor(255, 255, 255);
}

void Frame::draw() {
	ofSetColor(255, 0, 0);
	for (int i = 0; i < numScaleHandles; i++) {
		scaleHandles[i].draw();
	}
	ofSetColor(255, 255, 255);
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


