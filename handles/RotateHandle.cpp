#include "RotateHandle.h"
#include "../Frame.h"

using namespace glm;

RotateHandle::RotateHandle() {
	width = 10;
	height = 10;
}

void RotateHandle::draw(float x, float y, float frameWidth, float frameHeight) {
	xPos = x + frameWidth / 2 - width / 2;
	yPos = y - 40 - height / 2;
	ofPushMatrix();
	ofTranslate(-width / 2, -frameHeight / 2 - 40 - height / 2);
	ofDrawRectangle(0, 0, width, height);
	ofPopMatrix();
}

void RotateHandle::mouseDrag(vec3* point1, vec3* point2, bool shiftPressed) {
	frame->setAngle(point1->x - point2->x);
}
