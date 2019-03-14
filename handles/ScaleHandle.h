#pragma once

#include "Handle.h"

class ScaleHandle : public Handle {
public:
	ScaleHandle();
};

class ScaleHandle_BOT_RIGHT : public ScaleHandle {
public:
	ScaleHandle_BOT_RIGHT();
	void mouseDrag(glm::vec3*, glm::vec3* = NULL, bool = false);
	void draw(float, float, float, float);
};

class ScaleHandle_BOT_LEFT : public ScaleHandle {
public:
	ScaleHandle_BOT_LEFT();
	void mouseDrag(glm::vec3*, glm::vec3* = NULL, bool = false);
	void draw(float, float, float, float);
};

class ScaleHandle_TOP_RIGHT : public ScaleHandle {
public:
	ScaleHandle_TOP_RIGHT();
	void mouseDrag(glm::vec3*, glm::vec3* = NULL, bool = false);
	void draw(float, float, float, float);
};

class ScaleHandle_TOP_LEFT : public ScaleHandle {
public:
	ScaleHandle_TOP_LEFT();
	void mouseDrag(glm::vec3*, glm::vec3* = NULL, bool = false);
	void draw(float, float, float, float);
};
