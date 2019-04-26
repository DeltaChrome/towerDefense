#pragma once
#include "ofImage.h"
#include "ofVec2f.h"
#include "ofVec4f.h"
#include "Ability.h"


class Controller
{
	//animationManagerclass

	float stunDuration;
	bool isStunned;
	float iFrameDuration;
	bool isImmune;

public:
	virtual void init();
	virtual void update();
	void draw();

	bool Collision(Controller* other, ofVec2f& vector);
	ofVec2f collisionBox;
	ofVec2f collisionOffset;

	ofImage sprite;
	ofVec2f position;
	Ability ability;
	int maxHealth;
	int currentHealth;
};