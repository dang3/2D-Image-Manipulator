#pragma once

#include "Image.h"
#include "ofGraphics.h"
#include "handles/Handle.h"
#include "Utils.h"	

class Frame {
private:
	int rotateHandleHeight = 40;
	float scaleHandleWidth;
	float scaleHandleHeight;
	float xPos;
	float yPos;
	float width;
	float height;
	vector<Handle*> handles;
	Handle* selectedHandle;
	bool bUniformScale = false;
	double angle = 0;
	double scaleSensitivity = 10;
	

public:
	Frame();
	~Frame();
	Image* curImage;
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
	void processInput(glm::vec3*, glm::vec3* = NULL);
	void moveFrameFromKey(DirectionKey);
	inline void setUniformScale(bool b) { bUniformScale = b; }
	void setAngle(double d);
	inline double getAngle() { return angle; }
	void scaleFromKey(DirectionKey);
	void rotateFromKey(DirectionKey);
	void translateFromKey(DirectionKey);



	void test();
};
