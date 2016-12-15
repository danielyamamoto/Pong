#include "Ball.h"
#include "ofGraphics.h"
#include "ofAppRunner.h"


Ball::Ball() : x(10), y(10), radius(10), speedX(ofRandom(2)+0.5), speedY(ofRandom(2)+0.5), col(0,255,0){
}

Ball::Ball(float x, float y) {
	this->x = x;
	this->y = y;
	radius = 50;
}

Ball::Ball(float x, float y, float r) {
	this->x = x;
	this->y = y;
	this->radius = r;
}


void Ball::init(float x, float y, float r) {
	this->x = x;
	this->y = y;
	this->radius = r;
}

void Ball::init(){
	x = 300;
	y = 300;
	radius = 10;
}

void Ball::draw() {
	ofSetColor(col);
	ofDrawCircle(x, y, radius);
}

void Ball::update() {
	x += speedX;
	y += speedY;
	checkBounds();
}

void Ball::checkBounds() {
	// Revisa colisión contra borde superior
	if (y+radius > ofGetHeight()) {
		speedY *= -1;
	}
	//Revisa colisión contra borde inferior
	else if (y-radius < 0) {
		speedY *= -1;
	}
}

void Ball::setPosition(float x, float y){
	this->x = x;
	this->y = y;
}

float Ball::getX(){
	return x;
}

float Ball::getY(){
	return y;
}
