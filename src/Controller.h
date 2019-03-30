#pragma once
#include "ofImage.h"
#include "ofVec2f.h"
#include "Ability.h"
#include "AnimationManager.h"

class Controller
{
	AnimationManager AnimManager;

	float stunDuration;
	bool isStunned;
	float iFrameDuration;
	bool isImmune;
	ofImage sprite;
	ofVec2f position;
	Ability ability;
	int maxHealth;
	int currentHealth;

public:
	
	virtual void update();
	void draw();

};