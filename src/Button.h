#pragma once
#include "ofImage.h"
#include "Hitbox.h"
#include "Tower.h"

class Button
{
public:
	ofImage sprite[2];
	Hitbox hb;
	Tower tower;

	bool clicked;

	void init(const char* unclickedSprite, const char* clickedSprite, int x, int y, int width, int height, Tower& tower)
	{
		this->sprite[0].load(unclickedSprite);
		this->sprite[1].load(clickedSprite);
		
		this->sprite[0].resize(width, height);
		this->sprite[1].resize(width, height);

		this->tower = tower;

		hb.init(x, y, width, height, 0, 0);
	}
	
	void draw(ofTrueTypeFont font, int cost)
	{ 
		sprite[clicked].draw(hb.getX(), hb.getY());
		tower.sprite.draw(hb.getX() + 10, hb.getY() + 10);
		font.drawString(to_string(cost), hb.getX() + hb.getWidth() / 2, hb.getY() + hb.getHeight() / 2 + 10);
	}
	
	bool click(int x, int y) { return clicked = hb.ClickedOn(x, y); }
};