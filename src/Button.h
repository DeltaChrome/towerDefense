#pragma once
#include "ofImage.h"
#include "Hitbox.h"
#include "Tower.h"

class Button
{
public:
	ofImage sprite[2];
	Hitbox hb;
	
	bool clicked;


	void init(const char* unclickedSprite, const char* clickedSprite, int x, int y, int width, int height)
	{
		this->sprite[0].load(unclickedSprite);
		this->sprite[1].load(clickedSprite);
		
		this->sprite[0].resize(width, height);
		this->sprite[1].resize(width, height);

		hb.init(x, y, width, height, 0, 0);
	}
	
	void draw() { sprite[clicked].draw(hb.getX(), hb.getY()); }
	
	bool click(int x, int y) { return clicked = hb.ClickedOn(x, y); }
};