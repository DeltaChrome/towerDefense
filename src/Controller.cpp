#include "Controller.h"

void Controller::init() {}
void Controller::update() {}

void Controller::draw()
{
	sprite.draw(position);
}

bool Controller::checkCollision(Hitbox& hitbox2)
{
	return hb.checkCollision(hitbox2);
}