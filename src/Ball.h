#pragma once
#include "ofColor.h"

class Ball {
public:
	float x;
	float y;
	float radius;
	float speedX;
	float speedY;
	ofColor col;

	Ball();
	Ball(float x, float y);
	Ball(float x, float y, float r);
	void init(float x, float y, float r);
	void init();
	void draw();
	void update();
	void checkBounds();
	void setPosition(float x, float y);
	float getX();
	float getY();
};