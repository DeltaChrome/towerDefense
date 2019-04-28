#pragma once
#include "ofTimer.h"
#include "Hitbox.h"
#include "AnimationManager.h"

class Ability
{
private:
	int dmgType;
	
	float positionOffset;// might need to be a vec 3
	float rotationOffset;
	//animation manager
	AnimationManager animManager;
	//hitbox 
	Hitbox hb;

public:
	Ability(float damage = 0, float cooldownTime = 0)
		: damage(damage), cooldownTime(cooldownTime) 
	{
	}

	void draw() { }

	float damage;
	float cooldownTime;
};
