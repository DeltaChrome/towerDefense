#pragma once
#include "ofMain.h"

class GameObject
{
private:

	ofImage sprite;
	ofVec2f position;
	bool visible;

public:

	void setPosition(float x, float y) { position.set(x, y); }
	ofVec2f getPosition() { return position; }

	void changePosition(float x, float y) { position.set(position.x + x, position.y + y); }

	void setXPosition(float x) { position.set(x, position.y); }
	void setYPosition(float y) { position.set(position.x, y); }
	float getXPosition() { return position.x; }
	float getYPosition() { return position.y; }

	void init(string fileName)
	{
		visible = false;
		sprite.load(fileName);
	}
	void update(float deltaTime);
	void draw() { sprite.draw(position); }

};