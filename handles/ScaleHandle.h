#pragma once

#include "Handle.h"

class ScaleHandle : public Handle {
	public:
		ScaleHandle();
		void mouseDrag(glm::vec3);
		Frame* frame;

		void setFrame(Frame *f);

};