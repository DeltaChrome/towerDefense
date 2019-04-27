#pragma once
#include "Controller.h"

class Tower : public Controller
{
public:
	Tower();
	~Tower();

	void init(const char* sprite, ofVec2f& position, Ability& ability, float health, float range);
	void update();

	Controller target;
	ofVec2f cursor;

	bool isPlaced = false;

private:

	bool isAttacking; // Used for drawing stage of OpenFrameworkds
	float range;

	bool IsInRange(std::vector<Controller*>& enemies, Controller& target);
	void Attack(Controller& target);
};
