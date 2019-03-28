#pragma once
class Controller
{
private:

	float xPosition;
	float yPosition;
	float xVelocity;
	float yVelocity;
	int maxHealth;
	int currentHealth;
	//animationManagerclass
	//ability class
	float stunDuration;
	bool isStunned;
	float iFrameDuration;
	bool isImmune;

public:
	
	void update();
	void draw();
	void createAnimation();

};