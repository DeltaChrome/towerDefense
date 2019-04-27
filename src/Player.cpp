#include "Player.h"
#include "Tower.h"

void Player::init(vector<ofImage> animationFrames)
{
	
	hb.setHeight(32);
	hb.setWidth(32);

	hb.setX(position.x);
	hb.setY(position.y);
	animManager.init(animationFrames, 16);
}

void Player::update(std::vector<Controller*>& towers, float deltaTime)
{

	hb.setX(position.x);//might be better to just change to vec2
	hb.setY(position.y);

	Move(towers);
	animManager.update(deltaTime);
}

void Player::draw()
{
	animManager.draw(position);
}

void Player::Move(std::vector<Controller*>& towers)
{

	ofVec2f moveVector = ofVec2f(input.x, input.y).normalize() * moveSpeed;
	bool canMove = true;

	for (Controller* t : towers)
	{
		if (checkCollision(t->hb))
		{
			canMove = false;
			break;
		}
	}

	if (canMove)
		position += moveVector;
}