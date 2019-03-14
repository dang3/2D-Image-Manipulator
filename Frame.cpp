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
	xPos = curImage->getXPos();
	yPos = curImage->getYPos();
	width = curImage->getImageWidth();
	height = curImage->getImageHeight();
	angle = curImage->getAngle();
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

void Frame::setAngle(double d) { 
	angle = d; 
	updateImage(); 
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

void Frame::rotateFromKey(DirectionKey key) {
	if (key == DirectionKey::UP) setAngle(angle + 2);
	else if (key == DirectionKey::DOWN) setAngle(angle - 2);
}

void Frame::draw() {
	ofSetLineWidth(2);
	ofSetColor(255, 255, 127);
	ofNoFill();
	ofPushMatrix();
	//ofTranslate(xPos, yPos);

	ofTranslate(xPos + width / 2, yPos + height / 2);
	ofRotate(angle);
	ofPushMatrix(); 
		ofDrawRectangle(-width/2, -height/2, width, height);	// draws border

	 // draw handles
	ofSetColor(255, 0, 0);
	for (int i = 0; i < handles.size(); i++) {
		handles[i]->draw(xPos, yPos, width, height);
	}
	ofSetColor(255, 255, 255); 
	ofPopMatrix();
	ofPopMatrix();
}

void Frame::translateFromKey(DirectionKey key) {
	if (key == DirectionKey::UP) setYPos(yPos - 5);
	else if (key == DirectionKey::DOWN) setYPos(yPos + 5);
	else if (key == DirectionKey::LEFT) setXPos(xPos - 5);
	else if (key == DirectionKey::RIGHT) setXPos(xPos + 5);
	updateImage();
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