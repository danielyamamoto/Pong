#include "Enemy.h"
#include "ofAppRunner.h"

Enemy::Enemy() {
	x = 0;
	y = 0;
	width = 0;
	height = 0;
	speedY = 2;
}

void Enemy::init(float x, float y, float w, float h) {
	this->x = x;
	this->y = y;
	width = w;
	height = h;
}

void Enemy::init()
{
	x = ofGetWidth() - 150;
	y = ofGetHeight() / 2;
	width = 50;
	height = 150;
}

void Enemy::moveUp(){
	y -= 20;
}

void Enemy::moveDown(){
	y += 20;
}

void Enemy::limites(){
	limAbajo();
	limArriba();
}

void Enemy::limArriba(){
	if (y <= 0) {
		y = 0;
	}
}

void Enemy::limAbajo(){
	if (y + height >= ofGetHeight()) {
		y = ofGetHeight() - height;
	}
}

void Enemy::update(Ball	ball){
	float enemyPosY = y + (height / 2);

	if (ball.speedX < 0) {
		if (enemyPosY < ofGetHeight() / 2) {
			y += speedY;
		}
		else if (enemyPosY > ofGetHeight() / 2) {
			y -= speedY;
		}
	}
	else if (ball.speedX > 0) {
		if (ball.y < enemyPosY) {
			y -= speedY;
		}			
		else if (ball.y > enemyPosY) {
			y += speedY;
		}
	}
}