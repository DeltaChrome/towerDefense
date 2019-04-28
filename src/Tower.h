#pragma once
#include "Controller.h"
#include "Hitbox.h"

class Tower : public Controller
{
public:
	void init(const char* sprite, ofVec2f& position, Ability& ability, float health, float range);
	void update(float deltaTime);

	ofVec2f cursor;

	bool isPlaced = false;
	

private:
	Controller* out_target = nullptr;
	bool isAttacking; // Used for drawing stage of OpenFrameworkds
	float range;

	bool IsInRange(std::vector<Controller*>& enemies);
	void Attack(Controller* target);
};
