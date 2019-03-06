#include "ScaleHandle.h"
#include "../Frame.h"

using namespace glm;

ScaleHandle::ScaleHandle() {
	width = 10;
	height = 10;
}

void ScaleHandle::setFrame(Frame *f) {
	frame = f;
}

void ScaleHandle::mouseDrag(vec3 point) {
	float width = point.x - frame->getXPos();
	float height = point.y - frame->getYPos();
	frame->updateFrameDimensions(width, height);
}

