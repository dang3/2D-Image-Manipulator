#pragma once

#include "ofMain.h"

class Image {
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

	// Not sure if these will be necessary
	glm::vec3 getImagePosition();
	glm::vec3 getImageCenter();
};