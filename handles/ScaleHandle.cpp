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

void ScaleHandle_BOT_RIGHT::mouseDrag(vec3 point) {
	float width = point.x - frame->getXPos();
	float height = point.y - frame->getYPos();
	frame->updateFrameDimensions(width, height);
}

void ScaleHandle_BOT_LEFT::mouseDrag(vec3 point) {
	cout << "in1\n\n";
	cout << point.x << endl;
	cout << "end\n";
	/*float width = point.x - frame->getXPos();
	float height = (point.y - frame->getYPos()) + frame->getHeight();
	frame->setYPos(point.y);
	frame->updateFrameDimensions(width, height);*/


}

void ScaleHandle_TOP_LEFT::mouseDrag(vec3 point) {
	cout << "in2\n\n";
}
void ScaleHandle_TOP_RIGHT::mouseDrag(vec3 point) {
	cout << "in3\n\n";
}
