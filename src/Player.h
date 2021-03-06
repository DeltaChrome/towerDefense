#pragma once
#include "Controller.h"
#include "AnimationManager.h"
#include "Level.h"
#include "Hitbox.h"

class Player : public Controller
{
private:
	float moveSpeed = 5.0f;
	
public:

	void init(vector<ofImage> animationFrames, int maxHealth);
	void update(std::vector<Controller*>& towers, float deltaTime, vector<Hitbox>& walls, vector<Controller*>& enemies);

	void draw(); 

	void Move(std::vector<Controller*>& towers, vector<Hitbox>& walls, vector<Controller*>& enemies);
	int getMoney() { return money; }
	
	ofVec2f input;
};

