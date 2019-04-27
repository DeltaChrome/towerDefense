#pragma once
#include "ofMain.h"
#include "Hitbox.h"

class Level
{
private:

	Hitbox tempHB;
	vector<Hitbox> hbs;
	ofImage background;
	ofImage wall;

public:

	void init();
	void draw();

	vector<Hitbox> getHitBoxes(){ return hbs; }
};
