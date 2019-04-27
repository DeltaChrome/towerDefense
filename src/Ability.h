#pragma once
#include "ofTimer.h"
#include "Hitbox.h"
#include "AnimationManager.h"

class Ability
{
private:
	float cooldownTime;
	float timer;
	bool readyToBeUsed = true;

	int dmgType;
	
	float duration;
	float lastTick = 0;
	float positionOffset;// might need to be a vec 3
	float rotationOffset;
	//animation manager
	AnimationManager animManager;
	//hitbox 
	Hitbox hb;

public:
	inline bool IsReady() { return readyToBeUsed; }

	void init() { }
	void update() { CheckCooldown(); };
	void draw() { }

	void StartCooldown()
	{
		readyToBeUsed = false;
		timer = cooldownTime;
	}
	void CheckCooldown()
	{
		float currentTick = ofGetElapsedTimef();
		timer -= currentTick - lastTick;

		if (timer <= 0 && !readyToBeUsed)
			readyToBeUsed = true;

		lastTick = currentTick;
	}

	float damage;
};
