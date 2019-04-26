#pragma once
#include "Controller.h"

class Player : public Controller
{
public:
	Player();
	~Player();

	void init(const char* sprite);
	void update(std::vector<Controller*>& towers);

	ofVec2f input;

private:
	float moveSpeed = 5.0f;
	
	void Move(std::vector<Controller*>& towers);
};

