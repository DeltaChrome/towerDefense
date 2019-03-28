#pragma once
#include "ofImage.h"
#include "ofVec2f.h"
#include "Ability.h"

class Controller
{
	//animationManagerclass

	float stunDuration;
	bool isStunned;
	float iFrameDuration;
	bool isImmune;

public:
	
	virtual void update();
	void draw();

	ofImage sprite;
	ofVec2f position;
	Ability ability;
	int maxHealth;
	int currentHealth;
};