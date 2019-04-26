#pragma once
#include "Controller.h"

class Enemy : public Controller
{
public:
	Enemy();
	~Enemy();

	void init(const char* sprite, std::vector<ofVec2f> path, float moveSpeed, Ability& ability, float health, float range, std::vector<Controller*>* towers, Controller* player);
	void update();

private:

	void Attack(Controller& target);
	bool IsInRange(std::vector<Controller*>& towers, Controller* player, Controller& out_target);

	Controller* player;
	std::vector<Controller*>* towers;
	std::vector<ofVec2f> path;
	bool isAttacking;
	float agroRange;
	float moveSpeed;

	int currentPathIndex = 0;
};

