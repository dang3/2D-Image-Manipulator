#pragma once

#include "ofMain.h"

class Image {
private:
	double angle = 0;

public:
	ofImage img;
	float imageWidth;
	float imageHeight;
	glm::vec3 imagePosition;
	glm::vec3 imageCenter;
	void calculateImageCenter();

	Image();
	Image(ofImage img, float imageWidth, float imageHeight,
		glm::vec3 imagePosition, int position);
	float getImageWidth();
	float getImageHeight();
	void setPosition(int);
	void setImagePosition(glm::vec3);
	int getPosition();
	void draw();
	void scaleImage(glm::vec3);
	void setWidth(float);
	void setHeight(float);

	int position;
	float getXPos();
	float getYPos();
	inline double getAngle() { return angle; }
	inline void setAngle(double d) { angle = d; }


	// Not sure if these will be necessary
	glm::vec3 getImagePosition();
	glm::vec3 getImageCenter();

};