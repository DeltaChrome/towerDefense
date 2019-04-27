#pragma once
#include "ofMain.h"
#include "AnimationManager.h"

class GameObject
{
private:
	//ofImage texture;
	AnimationManager AnimManager;

	//ofImage sprite;
	ofVec2f position;

public:

	void setPosition(float x, float y) { position.set(x, y); }
	ofVec2f getPosition() { return position; }

	void changePosition(float x, float y) { position.set(position.x + x, position.y + y); }

	void setXPosition(float x) { position.set(x, position.y); }
	void setYPosition(float y) { position.set(position.x, y); }
	float getXPosition() { return position.x; }
	float getYPosition() { return position.y; }

	void initAnimations();//take in pointer to animations

	void update();
	void draw();

};