#include "Handle.h"
#include "ofGraphics.h"

using namespace std;

Handle::Handle() {

}

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

void Handle::setXPos(float xPos) {
	this->xPos = xPos;
}

void Handle::setYPos(float yPos) {
	this->yPos = yPos;
}

void Handle::draw() {
	ofDrawRectangle(xPos, yPos, width, height);
}