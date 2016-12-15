#include "Player.h"
#include "ofAppRunner.h"

void Player::init(){
	x = 100;
	y = ofGetHeight()/2;
	height = 150;
	width = 50;
}

void Player::moveUp(){
	y -= 20;
}

void Player::moveDown(){
	y += 20;
}

void Player::limites(){
	limAbajo();
	limArriba();
}

void Player::limArriba(){
	if (y <= 0) {
		y = 0;
	}
}

void Player::limAbajo(){
	if (y + height >= ofGetHeight()) {
		y = ofGetHeight() - height;
	}
}