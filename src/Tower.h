#pragma once
#include "Controller.h"

class Tower : public Controller
{
public:
	Tower(ofImage& sprite, ofVec2f& position, Ability& ability, float health, float range);
	~Tower();

	void update() override;
	
	Controller target;

private:

	bool isAttacking; // Used for drawing stage of OpenFrameworkds
	float range;

	bool IsInRange(std::vector<Controller> enemies, Controller& target);
	void Attack(Controller& target);
};
