#pragma once
class Tower
{
private:

	int width;
	int height;
	float health;
	float damage;
	float attackSpeed;
	float range;
	//ability

public:

	void init();
	void update();
	void draw();
	void attack();

};
