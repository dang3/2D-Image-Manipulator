#pragma once

#include "Image.h"
#include "handles/ScaleHandle.h"
#include "ofGraphics.h"

class Frame {
private:
	Image* curImage;
	int numScaleHandles = 4;
	float scaleHandleWidth;
	float scaleHandleHeight;
	float xPos;
	float yPos;
	float width;
	float height;
	vector<ScaleHandle> scaleHandles;
	Handle* selectedHandle;
	void drawBorder();
	void drawHandles();
	

public:
	Frame();
	void draw();
	void setXPos(float);
	void setYPos(float);
	void setWidth(float);
	void setHeight(float);
	void setImage(Image*);
	void setHandlePositions();
	bool isInsideHandles(glm::vec3);
	float getXPos();
	float getYPos();
	float getWidth();
	float getHeight();
	void scaleFrame(glm::vec3);
	void updateImage();
	void updateFrameDimensions(float, float);
};
