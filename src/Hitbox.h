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

	bool checkCollision(Hitbox &box, float x_input, float y_input)
	{

		if ((x + x_input + w > box.x && x + x_input + w < box.x + box.w) || (x + x_input < box.x + box.w && x + x_input > box.x))
		{
			if ((y + y_input + h > box.y && y + y_input + h < box.y + box.h) || (y + y_input < box.y + h && y + y_input > box.y))
				return true;
			else
				return false;
		}
		else
		{
			return false;
		}
	}

	bool ClickedOn(float mouse_x, float mouse_y)
	{

		if ((mouse_x > x && mouse_x < x + w))
		{
			if ((mouse_y < y + h && mouse_y > y))
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