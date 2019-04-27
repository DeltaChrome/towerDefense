#pragma once
#include "ofImage.h"
#include "ofVec2f.h"
#include "ofVec4f.h"
#include "Ability.h"
#include "Hitbox.h"
#include "AnimationManager.h"

class Controller
{
private:
	float stunDuration;
	bool isStunned;
	float iFrameDuration;
	bool isImmune;
	
public:
	virtual void init();
	virtual void update();
	void draw();
	bool checkCollision(Hitbox& hitbox2);

	Hitbox hb;
	AnimationManager animManager;

	ofImage sprite;
	ofVec2f position;
	Ability ability;
	int maxHealth;
	int currentHealth;
};