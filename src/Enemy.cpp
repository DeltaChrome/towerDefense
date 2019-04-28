#include "Enemy.h"

void Enemy::init(const char* sprite, std::vector<ofVec2f> path, float moveSpeed, Ability& ability, float health, float range, Controller* player)
{
	timeSinceLastClick = 99;

	visible = true;

	this->sprite.load(sprite);
	this->path = path;
	this->position = path[0];
	this->moveSpeed = moveSpeed;
	this->ability = ability;
	this->agroRange = range;
	this->player = player;
	
	hb.init(position.x, position.y, 32, 32, 0, 1);

	currentHealth = maxHealth = health;
}

void Enemy::update(float deltaTime)
{
	timeSinceLastClick += deltaTime;

	if (currentHealth <= 0)
	{
		dead();
	}

	hb.setX(position.x);
	hb.setY(position.y);

	bool isInRange = IsInRange(player);

	// Moves only if a Target is not in range
	if (!isInRange)
	{
		if (currentPathIndex + 1 < path.size())
		{
			ofVec2f targetPoint = path[currentPathIndex + 1];
			position += (targetPoint - position).normalize() * moveSpeed;

			if (position.distance(targetPoint) == 0)
				currentPathIndex++;
		}
	}
	else
	{
		if (getLastClick() > ability.cooldownTime)
			Attack(out_target);
	}
}

void Enemy::Attack(Controller* target)
{
	cout << "attacking" << endl;
	target->currentHealth -= ability.damage;
	setLastClick(0.0f);
}

bool Enemy::IsInRange(Controller* player)
{
	if (position.distance(player->position) <= agroRange)
	{
		out_target = player;
		return true;
	}

	out_target = nullptr;
	return false;
}