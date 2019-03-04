#pragma once

#include "Image.h"
#include "handles/ScaleHandle.h"
#include "ofGraphics.h"

class Frame {
private:
	Image *curImage;
	int numScaleHandles = 4;
	float scaleHandleWidth;
	float scaleHandleHeight;
	float xPos;
	float yPos;
	float width;
	float height;
	vector<ScaleHandle> scaleHandles;
	

public:
	Frame();
	void draw();
	void setXPos(float);
	void setYPos(float);
	void setWidth(float);
	void setHeight(float);
	void setImage(Image*);
	void setHandlePositions();
	bool isInsideScaleHandles();

};
