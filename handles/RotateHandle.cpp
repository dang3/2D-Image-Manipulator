#include "RotateHandle.h"

using namespace glm;

RotateHandle::RotateHandle() {
	width = 10;
	height = 10;
}

void RotateHandle::mouseDrag(vec3* point1, vec3* point2) {
	double deltaY = point2->y - point1->y;
	double deltaX = point2->x - point1->x;
	double theta = atan(deltaY/deltaX)* 180 / pi<float>();
	//cout << "point1: " << *point1 << "  " << "point2: " << *point2 << endl;
	cout << theta << endl;
	
}
