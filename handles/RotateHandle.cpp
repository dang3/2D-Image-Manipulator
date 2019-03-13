#include "RotateHandle.h"
#include "../Frame.h"

using namespace glm;

RotateHandle::RotateHandle() {
	width = 10;
	height = 10;
}

void RotateHandle::mouseDrag(vec3* point1, vec3* point2, bool shiftPressed) {
	double deltaY = point2->y - point1->y;
	double deltaX = point2->x - point1->x;
	double angle = atan(deltaY / deltaX); // angle in radians
	//cout << "point1: " << *point1 << "  " << "point2: " << *point2 << endl;
	//frame->setAngle(angle);
	
}
