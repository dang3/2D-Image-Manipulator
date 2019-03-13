#include "Image.h"

using namespace glm;

Image::Image() {
}

Image::Image(ofImage img, float imageWidth, float imageHeight, vec3 dropLocation, int position) {
	this->img = img;
	this->imageWidth = imageWidth;
	this->imageHeight = imageHeight;
	this->imagePosition = dropLocation;
	this->position = position;
	calculateImageCenter();
}

void Image::calculateImageCenter() {
	float x = imagePosition.x - (imageWidth / 2);
	float y = imagePosition.y - (imageHeight / 2);
	imageCenter = vec3(x, y, 0);
}

float Image::getImageWidth() {
	return imageWidth;
}

void Image::setHeight(float height) {
	imageHeight = height;
}

void Image::setWidth(float width) {
	imageWidth = width;
}

float Image::getImageHeight() {
	return imageHeight;
}

vec3 Image::getImagePosition() {
	return imagePosition;
}

vec3 Image::getImageCenter() {
	return imageCenter;
}

void Image::scaleImage(vec3 point) {
	imageWidth = point.x - imagePosition.x;
	imageHeight = point.y - imagePosition.y;
}

float Image::getXPos() {
	return imagePosition.x;
}

float Image::getYPos() {
	return imagePosition.y;
}

void Image::setImagePosition(vec3 pos) {
	this->imagePosition = pos;
}

int Image::getPosition() {
	return position;
}

void Image::setPosition(int position) {
	this->position = position;
}

void Image::draw() {
	vec3 origin(0, 0, 0);
	img.draw(origin, imageWidth, imageHeight);
}
