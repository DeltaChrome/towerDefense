#pragma once
#include "Controller.h"

class Player : public Controller
{
public:
	Player();
	~Player();

	void update() override;

private:
	ofVec2f velocity;
};

