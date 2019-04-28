#include "Player.h"
#include "Tower.h"

void Player::init(vector<ofImage> animationFrames, int maxHealth)
{
	visible = true;

	timeSinceLastClick = 5.0f;

	this->maxHealth = currentHealth = maxHealth;

	position.x = 100;
	position.y = 650;
	
	hb.setHeight(32);
	hb.setWidth(32);

	hb.setX(position.x);
	hb.setY(position.y);

	animManager.init(animationFrames, 16);
}

void Player::update(std::vector<Controller*>& towers, float deltaTime, vector<Hitbox>& walls, vector<Controller*>& enemies)
{
	timeSinceLastClick += deltaTime;

	hb.setX(position.x);
	hb.setY(position.y);

	Move(towers, walls, enemies);
	animManager.update(deltaTime);
}

void Player::draw()
{
	if(visible)
		animManager.draw(position);
}

void Player::Move(vector<Controller*>& towers, vector<Hitbox>& walls, vector<Controller*>& enemies)
{

	ofVec2f moveVector = ofVec2f(input.x, input.y).normalize() * moveSpeed;
	bool canMove = true;

	for (Controller* t : towers)
	{
		if (hb.checkCollision(t->hb, moveVector.x, moveVector.y))
		{
			canMove = false;
			break;
		}
	}

	for (Controller* e : enemies)
	{
		if (hb.checkCollision(e->hb, moveVector.x, moveVector.y))
		{
			canMove = false;
			break;
		}
	}

	for (int i = 0; i < walls.size(); i++)
	{
		if (hb.checkCollision(walls[i], moveVector.x, moveVector.y))
		{
			canMove = false;
			break;
		}
	}


	if (canMove)
		position += moveVector;
}