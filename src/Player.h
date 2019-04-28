#pragma once
#include "Controller.h"
#include "AnimationManager.h"
#include "Level.h"
#include "Hitbox.h"

class Player : public Controller
{
protected:
	float timeSinceLastClick;
private:
	float moveSpeed = 5.0f;
	
public:

	void init(vector<ofImage> animationFrames, int maxHealth);
	void update(std::vector<Controller*>& towers, float deltaTime, vector<Hitbox>& walls, vector<Controller*>& enemies);

	void draw(); 

	void Move(std::vector<Controller*>& towers, vector<Hitbox>& walls, vector<Controller*>& enemies);
	int getMoney() { return money; }
	float getLastClick() { return timeSinceLastClick; }
	void setLastClick(float time) { timeSinceLastClick = time; }

	ofVec2f input;
};

