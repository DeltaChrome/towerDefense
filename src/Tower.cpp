#include "Tower.h"

void Tower::init(const char* sprite, ofVec2f& position, Ability& ability, float health, float range)
{
	timeSinceLastClick = 5;

	this->sprite.load(sprite);
	this->position = position;
	this->ability = ability;
	this->range = range;

	hb.setHeight(32);
	hb.setWidth(32);

	currentHealth = maxHealth = health;
}

void Tower::update(float deltaTime)
{
	timeSinceLastClick += deltaTime;

	if (!isPlaced)
	{
		position = cursor;
		return;
	}

	if (IsInRange(enemies))
	{
		if(getLastClick() > ability.cooldownTime)
			Attack(out_target);
	}
}

void Tower::Attack(Controller* target)
{
	target->currentHealth -= ability.damage;
	setLastClick(0.0f);
}

bool Tower::IsInRange(std::vector<Controller*>& enemies)
{
	float distance = 0.0f;
	float closestDistance = -1.0f;
	int index = -1;

	for (int i = 0; i < enemies.size(); i++)
	{
		// Checking if enemies are within Towers range -- For now returns closest target
		distance = position.distance(enemies[i]->position);
		
		if (closestDistance < 0)
			closestDistance = distance;

		if ((distance <= range) && (distance <= closestDistance))
		{
			closestDistance = distance;
			index = i;
		}
	}
	
	// Return false if no targets are within range
	if (index < 0)
	{
		out_target = nullptr;
		return false;
	}

	out_target = enemies[index];
	return true;
}
