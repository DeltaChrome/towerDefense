#include "Player.h"
#include "Tower.h"

Player::Player()
{
	
}

Player::~Player()
{
}

void Player::init(const char* sprite)
{
	this->sprite.load(sprite);

	collisionBox = ofVec2f(32, 32);
	collisionOffset = ofVec2f(0, 0);
}

void Player::update(std::vector<Controller*>& towers)
{
	Move(towers);
}

void Player::Move(std::vector<Controller*>& towers)
{
	ofVec2f moveVector = ofVec2f(input.x, input.y).normalize() * moveSpeed;
	bool canMove = true;

	for (Controller* t : towers)
	{
		if (Collision(t, moveVector))
		{
			canMove = false;
			break;
		}
	}

	if (canMove)
		position += moveVector;
}