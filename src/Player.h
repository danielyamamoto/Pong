#pragma once
#include "Paddle.h"

class Player : public Paddle {

public:
	void init();
	void moveUp();
	void moveDown();
	void limites();
	void limArriba();
	void limAbajo();
};