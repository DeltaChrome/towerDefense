#include "Tower.h"

Tower::Tower()
{
}

Tower::~Tower()
{
}

void Tower::init(const char* sprite, ofVec2f& position, Ability& ability, float health, float range)
{
	this->sprite.load(sprite);
	this->position = position;
	this->ability = ability;
	this->range = range;

	hb.setHeight(32);
	hb.setWidth(32);

	currentHealth = maxHealth = health;
}

void Tower::update()
{
	if (!isPlaced)
	{
		position = cursor;
		return;
	}

	// Temporary -- Used for compiler: Remove when Game Manager is finished and use the enemies stored in their instead
	std::vector<Controller*> enemies;
	
	if (IsInRange(enemies, target))
		Attack(target);
}

void Tower::Attack(Controller& target)
{
	// if the tower's ability is off-cooldown then attack
	if (ability.IsReady())
	{
		isAttacking = true;
		target.currentHealth -= ability.damage;
		ability.StartCooldown();
	}
}

bool Tower::IsInRange(std::vector<Controller*>& enemies, Controller& out_target)
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

		if (distance <= range && closestDistance >= distance)
		{
			closestDistance = distance;
			index = i;
		}
	}
	
	// Return false if no targets are within range
	if (index < 0)
		return false;

	out_target = *enemies[index];
	return true;
}
