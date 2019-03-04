#pragma once

#include "Handle.h"

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


};