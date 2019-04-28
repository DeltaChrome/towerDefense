#pragma once
#include "ofMain.h"
#include "Hitbox.h"
#include "Controller.h"

class GameObject
{
protected:

	Hitbox hb;
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
	bool getVisiblility() { return visible; }

	void init(string fileName)
	{
		visible = true;
		sprite.load(fileName);

		position.x = rand() % 900 - 96;
		position.y = rand() % 800 - 96;
		hb.init(position.x,position.y,32,32,1,1);
	}

	virtual void update(float deltaTime, Controller* player)
	{
		hb.setX(position.x);
		hb.setY(position.y);
	}

	void draw()
	{
		if (visible)
		{
			sprite.draw(position);
		} 
	}

};