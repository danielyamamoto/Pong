#pragma once
#include "Paddle.h"
#include "Ball.h"

class Enemy : public Paddle {

public:
	Enemy();
	void init(float x, float y, float w, float h);
	void init();
	void moveUp();
	void moveDown();
	void limites();
	void limArriba();
	void limAbajo();
	void update(Ball ball);
	float speedY;
};
