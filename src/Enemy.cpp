#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::init(const char* sprite, std::vector<ofVec2f> path, float moveSpeed, Ability& ability, float health, float range, std::vector<Controller*>* towers, Controller* player)
{
	visible = true;

	this->sprite.load(sprite);
	this->path = path;
	this->position = path[0];
	this->moveSpeed = moveSpeed;
	this->ability = ability;
	this->agroRange = range;
	this->player = player;
	this->towers = towers;

	hb.init(position.x, position.y, 32, 32, 0, 1);

	currentHealth = maxHealth = health;
}

void Enemy::update()
{

	if (currentHealth <= 0)
	{
		dead();
	}

	hb.setX(position.x);
	hb.setY(position.y);

	Controller out_target;

	// Moves only if a Target is not in range
	if (!IsInRange(*towers, player, out_target))
	{
		if (currentPathIndex + 1 < path.size())
		{
			ofVec2f targetPoint = path[currentPathIndex + 1];
			position += (targetPoint - position).normalize() * moveSpeed;

			if (position.distance(targetPoint) == 0)
				currentPathIndex++;
		}
	}
}

void Enemy::Attack(Controller& target)
{
	// if the tower's ability is off-cooldown then attack
	if (ability.IsReady())
	{
		isAttacking = true;
		target.currentHealth -= ability.damage;
		ability.StartCooldown();
	}
}

bool Enemy::IsInRange(std::vector<Controller*>& towers, Controller* player, Controller& out_target)
{
	float distance = 0.0f;
	float closestDistance = -1.0f;
	bool targetPlayer = false;
	int index = -1;

	if (position.distance(player->position) <= agroRange)
	{
		targetPlayer = true;
		out_target = *player;
	}

	if (!targetPlayer)
	{
		for (int i = 0; i < towers.size(); i++)
		{
			// Checking if enemies are within Towers range -- For now returns closest target
			distance = position.distance(towers[i]->position);

			if (closestDistance < 0)
				closestDistance = distance;

			if (distance <= agroRange && closestDistance >= distance)
			{
				closestDistance = distance;
				index = i;
			}
		}

		// Return false if no targets are within range
		if (index < 0)
			return false;
	
		out_target = *towers[index];
	}
	
	return true;
}