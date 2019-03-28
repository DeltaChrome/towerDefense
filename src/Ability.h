#pragma once
class Ability
{
private:

	int dmgType;
	float duration;
	float lastTick;
	float positionOffset;// might need to be a vec 3
	float rotationOffset;
	//animation manager
	//hitbox 

public:

	void init();
	void update();
	void draw();

};

