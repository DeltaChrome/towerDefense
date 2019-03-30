#pragma once
#include <math.h>

class Hitbox
{
private:
	float x;
	float y;
	int w;
	int h;
	int radius;
	int type;

public:

	void setX(float xPos) { x = xPos; }
	void setY(float yPos) { y = yPos; }
	float getX() { return x; }
	float getY() { return y; }
	void setWidth(int width) { w = width; }
	void setHeight(int height) { h = height; }
	float getWidth() { return w; }
	float getHeight() { return h; }

	void init(float x, float y, int w, int h, int r, int t)
	{
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
		this->radius = r;
		this->type = t;
	}

	bool checkCollision(Hitbox &box)
	{

		if ((x + w > box.x && x + w < box.x + box.w) || (x < box.x + box.w && x > box.x))
		{
			if ((y + h > box.y && y + h < box.y + box.h) || (y < box.y + h && y > box.y))
				return true;
			else
				return false;
		}
		else
		{
			return false;
		}
	}

};