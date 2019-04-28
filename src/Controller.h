#pragma once
#include "ofImage.h"
#include "ofVec2f.h"
#include "ofVec4f.h"
#include "Ability.h"
#include "Hitbox.h"
#include "AnimationManager.h"

class Controller
{
protected: 
	int money;
	bool visible;


public:
	virtual void init();
	virtual void update();
	void draw();
	bool checkCollision(Hitbox& hitbox2);
	void addMoney(int m) { money += m; }

	void dead()
	{
		visible = false;
		//drop item
	}
	
	Hitbox hb;
	AnimationManager animManager;

	ofImage sprite;
	ofVec2f position;
	Ability ability;
	int maxHealth;
	int currentHealth;
};