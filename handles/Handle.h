#pragma once

#include "ofMain.h"

class Frame; 

class Handle {
	protected:
		float xPos;
		float yPos;
		float width;
		float height;
		Frame* frame;

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
		void setFrame(Frame *f);
};