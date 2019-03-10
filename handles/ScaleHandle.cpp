#include "ScaleHandle.h"
#include "../Frame.h"

using namespace glm;

ScaleHandle::ScaleHandle() {
	width = 10;
	height = 10;
}

ScaleHandle_BOT_RIGHT::ScaleHandle_BOT_RIGHT() {}
ScaleHandle_BOT_LEFT::ScaleHandle_BOT_LEFT() {}
ScaleHandle_TOP_LEFT::ScaleHandle_TOP_LEFT() {}
ScaleHandle_TOP_RIGHT::ScaleHandle_TOP_RIGHT() {}

void ScaleHandle_BOT_RIGHT::mouseDrag(vec3* point, glm::vec3* v) {
	float width = point->x - frame->getXPos();
	float height = point->y - frame->getYPos();
	frame->updateFrameDimensions(width, height);
}

void ScaleHandle_BOT_LEFT::mouseDrag(vec3* point, glm::vec3* v) {
	float width = frame->getWidth() + (frame->getXPos() - point->x);
	float height = point->y - frame->getYPos();
	frame->setXPos(point->x);
	frame->updateFrameDimensions(width, height);
}

void ScaleHandle_TOP_LEFT::mouseDrag(vec3* point, glm::vec3* v) {
	float width = frame->getWidth() + (frame->getXPos()- point->x);
	float height = frame->getHeight() + (frame->getYPos() - point->y);
	frame->setXPos(point->x);
	frame->setYPos(point->y);
	frame->updateFrameDimensions(width, height);
}

void ScaleHandle_TOP_RIGHT::mouseDrag(vec3* point, glm::vec3* v) {
	float width = point->x - frame->getXPos();
	float height = frame->getHeight() + (frame->getYPos()- point->y);
	frame->setYPos(point->y);
	frame->updateFrameDimensions(width, height);
}