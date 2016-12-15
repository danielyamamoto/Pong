#include "Paddle.h"
#include "ofGraphics.h"

Paddle::Paddle()
:x(0), y(10), width(10), height(20), col(0, 100, 255)
{

}

Paddle::Paddle(float x, float y, float w, float h) 
:x(x), y(y), width(w), height(h)
{

}

void Paddle::draw() {
	ofSetColor(col);
	ofDrawRectangle(x, y, width, height);
}