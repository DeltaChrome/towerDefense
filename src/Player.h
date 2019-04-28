#pragma once
#include "Controller.h"
#include "AnimationManager.h"

class Player : public Controller
{
private:
	float moveSpeed = 5.0f;
	
public:

	void init(vector<ofImage> animationFrames, int maxHealth);
	void update(std::vector<Controller*>& towers, float deltaTime);

	void draw(); 

	void Move(std::vector<Controller*>& towers);

	ofVec2f input;
};

