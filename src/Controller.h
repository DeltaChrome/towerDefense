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
	float timeSinceLastClick;
	std::vector<Controller*> enemies;

public:
	virtual void init();
	virtual void update(float deltaTime);;
	void draw();
	bool checkCollision(Hitbox& hitbox2);
	void addMoney(int m) { money += m; }
	float getLastClick() { return timeSinceLastClick; }
	void setLastClick(float time) { timeSinceLastClick = time; }
	void setEnemies(std::vector<Controller*>& enemies) { this->enemies = enemies; }

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