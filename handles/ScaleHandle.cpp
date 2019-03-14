#include "ScaleHandle.h"
#include "../Frame.h"
#include <cmath>

using namespace glm;

ScaleHandle::ScaleHandle() {
	width = 10;
	height = 10;
}

ScaleHandle_BOT_RIGHT::ScaleHandle_BOT_RIGHT() {}
ScaleHandle_BOT_LEFT::ScaleHandle_BOT_LEFT() {}
ScaleHandle_TOP_LEFT::ScaleHandle_TOP_LEFT() {}
ScaleHandle_TOP_RIGHT::ScaleHandle_TOP_RIGHT() {}

void ScaleHandle_BOT_RIGHT::mouseDrag(vec3* point2, vec3*point1, bool uniformScale) {
	float width = point2->x - frame->getXPos();
	float height = 0;

	if (uniformScale) {
		float ratio = width / frame->getWidth();
		height = frame->getHeight() * ratio;
	}
	else height = point2->y - frame->getYPos();
	frame->updateFrameDimensions(width, height);
}

void ScaleHandle_BOT_LEFT::mouseDrag(vec3* point2, vec3*point1, bool uniformScale) {
	float width = frame->getWidth() + (frame->getXPos() - point2->x);
	float height = 0;

	if (uniformScale) {
		float ratio = width / frame->getWidth();
		height = frame->getHeight() * ratio;
	}
	else height = point2->y - frame->getYPos();
	frame->setXPos(point2->x);
	frame->updateFrameDimensions(width, height);
}

void ScaleHandle_TOP_LEFT::mouseDrag(vec3* point2, vec3*point1, bool uniformScale) {
	float width = frame->getWidth() + (frame->getXPos() - point2->x);
	float height = 0;

	if (uniformScale) {
		vec3 anchor(frame->getXPos() + frame->getWidth(), frame->getYPos() + frame->getHeight(), 0);
		float ratio = width / frame->getWidth();
		height = frame->getHeight() * ratio;
		frame->setXPos(anchor.x - width);
		frame->setYPos(anchor.y - height);
	}
	else {
		height = frame->getHeight() + (frame->getYPos() - point2->y);
		frame->setXPos(point2->x);
		frame->setYPos(point2->y);
	}
	frame->updateFrameDimensions(width, height);
}

void ScaleHandle_TOP_RIGHT::mouseDrag(vec3* point2, vec3*point1, bool uniformScale) {
	float width = point2->x - frame->getXPos();
	float height = 0;

	if (uniformScale) {
		vec3 anchor(frame->getXPos(), frame->getYPos() + frame->getHeight(), 0);
		float ratio = width / frame->getWidth();
		height = frame->getHeight() * ratio;
		frame->setYPos(anchor.y - height);
	}
	else {
		height = frame->getHeight() + (frame->getYPos() - point2->y);
		frame->setYPos(point2->y);
	}
	frame->updateFrameDimensions(width, height);
}

void ScaleHandle_BOT_RIGHT::draw(float x, float y, float frameWidth, float frameHeight) {
	xPos = x + frameWidth - width / 2;
	yPos = y + frameHeight - height / 2;
	ofPushMatrix();
	ofTranslate(frameWidth / 2 - width / 2, frameHeight / 2 - height / 2);
	ofDrawRectangle(0, 0, width, height);
	ofPopMatrix();
}

void ScaleHandle_BOT_LEFT::draw(float x, float y, float frameWidth, float frameHeight) {
	xPos = x - width / 2;
	yPos = y + frameHeight - height / 2;
	ofPushMatrix();
	ofTranslate(-frameWidth / 2 - width / 2, frameHeight / 2 - height / 2);
	ofDrawRectangle(0, 0, width, height);
	ofPopMatrix();
}

void ScaleHandle_TOP_LEFT::draw(float x, float y, float frameWidth, float frameHeight) {
	xPos = x - width / 2;
	yPos = y - height / 2;
	ofPushMatrix();
	ofTranslate(-frameWidth / 2 - width / 2, -frameHeight / 2 - height / 2);
	ofDrawRectangle(0, 0, width, height);
	ofPopMatrix();
}

void ScaleHandle_TOP_RIGHT::draw(float x, float y, float frameWidth, float frameHeight) {
	xPos = x + frameWidth - width / 2;
	yPos = y-height / 2;
	ofPushMatrix();
	ofTranslate(frameWidth / 2 - width / 2, -frameHeight / 2 - height / 2);
	ofDrawRectangle(0, 0, width, height);
	ofPopMatrix();
}