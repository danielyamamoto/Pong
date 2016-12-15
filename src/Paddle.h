#pragma once
#include "ofColor.h"


class Paddle {
public:
	float x;
	float y;
	float width;
	float height;
	ofColor col;

	Paddle();
	Paddle(float x, float y, float w, float h);

	void draw();
};