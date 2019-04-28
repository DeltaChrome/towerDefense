#include "Controller.h"

void Controller::init() {}
void Controller::update(float deltaTime) {}

void Controller::draw()
{
	if (visible)
		sprite.draw(position);
}

bool Controller::checkCollision(Hitbox& hitbox2)
{
	return hb.checkCollision(hitbox2,1,1);
}