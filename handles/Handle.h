#pragma once

#include "ofMain.h"

class Frame; 

class Handle {
	protected:
		float xPos;
		float yPos;
		float width;
		float height;

	public:
		Handle();
		void draw();
		float getXPos();
		float getYPos();
		float getWidth();
		float getHeight();
		void setXPos(float);
		void setYPos(float);
		bool isInsideHandle(glm::vec3);

		virtual void mouseDrag(glm::vec3) = 0;
};

enum class HandleType {
	// Scale handles
	SCALE_TOP_RIGHT,
	SCALE_TOP_LEFT,
	SCALE_BOT_RIGHT,
	SCALE_BOT_LEFT,
};