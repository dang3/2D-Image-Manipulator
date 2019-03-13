#include "Handle.h"
#include "ofGraphics.h"
#include "../Frame.h"

using namespace std;
using namespace glm;

Handle::Handle() {}

float Handle::getXPos() {
	return xPos;
}

float Handle::getYPos() {
	return yPos;
}

float Handle::getHeight() {
	return height;
}

float Handle::getWidth() {
	return width;
}

bool Handle::isInsideHandle(vec3 point) {
	float xPos2 = xPos + width;
	float yPos2 = yPos + height;

	if (point.x >= xPos && point.x <= xPos2 && point.y >= yPos && point.y <= yPos2) {
		return true;
	}
	else
		return false;
}

void Handle::setXPos(float xPos) {
	this->xPos = xPos;
}

void Handle::setYPos(float yPos) {
	this->yPos = yPos;
}

void Handle::draw() {
	ofPushMatrix();
	ofTranslate(xPos, yPos);
	ofRotate(angle);
	ofSetColor(255, 255, 255);
	ofFill();
	ofDrawRectangle(0, 0, width, height);
	ofNoFill();
	ofPopMatrix();
}

void Handle::setFrame(Frame *f) {
	frame = f;
}