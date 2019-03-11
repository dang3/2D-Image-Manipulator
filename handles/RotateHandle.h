#pragma once

#include "Handle.h"

class RotateHandle : public Handle {
public:
	RotateHandle();
	void mouseDrag(glm::vec3*, glm::vec3* = NULL, bool = false);
};