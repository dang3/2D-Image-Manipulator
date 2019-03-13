#include "Frame.h"
#include "handles/ScaleHandle.h"
#include "handles/RotateHandle.h"

using namespace std;
using namespace glm;

Frame::Frame() {
	ScaleHandle *handle1 = new ScaleHandle_TOP_LEFT();
	ScaleHandle *handle2 = new ScaleHandle_TOP_RIGHT();
	ScaleHandle *handle3 = new ScaleHandle_BOT_LEFT();
	ScaleHandle *handle4 = new ScaleHandle_BOT_RIGHT();
	RotateHandle *handle5 = new RotateHandle();
	
	handles.push_back(handle1);
	handles.push_back(handle2);
	handles.push_back(handle3);
	handles.push_back(handle4);
	handles.push_back(handle5);

	scaleHandleWidth = handle1->getWidth();
	scaleHandleHeight = handle1->getHeight();
}

bool Frame::isInsideHandles(vec3 point) {
	// loop through every handle
	for (int i = 0; i < handles.size(); i++) {
		if (handles[i]->isInsideHandle(point)) {
			selectedHandle = handles[i];
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
	// set handle dimensions
	xPos = curImage->getImagePosition().x;
	yPos = curImage->getImagePosition().y;
	width = curImage->getImageWidth();
	height = curImage->getImageHeight();

	// set handle x & y positions
	handles[0]->setXPos(xPos - scaleHandleWidth / 2);
	handles[0]->setYPos(yPos - scaleHandleHeight / 2);

	handles[1]->setXPos(xPos+width - scaleHandleWidth / 2);
	handles[1]->setYPos(yPos - scaleHandleHeight / 2);

	handles[2]->setXPos(xPos - scaleHandleWidth / 2);
	handles[2]->setYPos(yPos+height - scaleHandleHeight / 2);

	handles[3]->setXPos(xPos+width - scaleHandleWidth / 2);
	handles[3]->setYPos(yPos+height - scaleHandleHeight / 2);

	handles[4]->setXPos(xPos + width / 2);
	handles[4]->setYPos(yPos-rotateHandleHeight);

	// set handle orientatin
	for (int i = 0; i < handles.size(); i++) {
		handles[i]->setAngle(angle);
	}
}

void Frame::scaleFromKey(DirectionKey key) {
	if (key == DirectionKey::UP) {
		width += scaleSensitivity;
		height += scaleSensitivity;
	}
	else if (key == DirectionKey::DOWN) {
		width -= scaleSensitivity;
		height -= scaleSensitivity;
	}
	updateImage();
}

void Frame::setImage(Image *img) {
	cout << "in\n";
	this->curImage = img;
	setHandlePositions();
}

void Frame::scaleFrame(vec3 point) {
	width = point.x - xPos;
	height = point.y - yPos;
	updateImage();
}

void Frame::moveFrameFromKey(DirectionKey dir) {
	if (dir == DirectionKey::UP) yPos--;
	else if (dir == DirectionKey::DOWN) yPos++;
	else if (dir == DirectionKey::LEFT) xPos--;
	else if (dir == DirectionKey::RIGHT) xPos++;
	updateImage();
}

void Frame::processInput(vec3* point2, vec3* point1) {
	selectedHandle->mouseDrag(point2, point1, bUniformScale);
}

void Frame::updateFrameDimensions(float newWidth, float newHeight) {
	this->width = newWidth;
	this->height = newHeight;
	updateImage();
}

void Frame::updateImage() {
	curImage->setImagePosition(vec3(xPos, yPos, 0));
	curImage->setWidth(width);
	curImage->setHeight(height);
	curImage->setAngle(angle);
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
	//cout << xPos << "  " << yPos << endl;	// THIS BECOMES VERY SMALL
	ofPushMatrix();
	ofTranslate(xPos, yPos);
	ofRotate(angle);
	ofDrawRectangle(0, 0, borderWidth, borderHeight);
	ofPopMatrix();

	//ofSetColor(255, 255, 255);
}

void Frame::drawHandles() {
	ofSetColor(255, 0, 0);
	for (int i = 0; i < handles.size(); i++) {
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