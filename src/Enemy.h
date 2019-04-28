#pragma once
#include "Controller.h"
#include "Hitbox.h"

class Enemy : public Controller
{
public:
	void init(const char* sprite, std::vector<ofVec2f> path, float moveSpeed, Ability& ability, float health, float range, Controller* player);
	void update(float deltaTime);

private:

	void Attack(Controller* target);
	bool IsInRange(Controller* player);

	Controller* out_target = nullptr;
	Controller* player;
	std::vector<ofVec2f> path;
	float agroRange;
	float moveSpeed;

	int currentPathIndex = 0;
};

