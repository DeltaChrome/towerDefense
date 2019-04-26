#include "Controller.h"

void Controller::init() {}
void Controller::update() {}

void Controller::draw()
{
	sprite.draw(position);
}

bool Controller::Collision(Controller* other, ofVec2f& vector)
{
	if (position.x + vector.x < other->position.x + other->collisionBox.x + other->collisionOffset.x &&
		position.x + vector.x + collisionBox.x + collisionOffset.x > other->position.x &&
		position.y + vector.y < other->position.y + other->collisionBox.y + other->collisionOffset.y &&
		position.y + vector.y + collisionBox.y + collisionOffset.y > other->position.y)
	{
		return true;
	}
	else
		return false;
}