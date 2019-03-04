#include "Frame.h"

using namespace std;

Frame::Frame() {
	for (int i = 0; i < numScaleHandles; i++) {
		ScaleHandle handle;
		scaleHandles.push_back(handle);
	}
	scaleHandleWidth = scaleHandles[0].getWidth();
	scaleHandleHeight = scaleHandles[0].getHeight();
}

bool Frame::isInsideScaleHandles() {

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


