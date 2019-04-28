#pragma once
#include "GameObject.h"

class TowerGem : public GameObject
{
private:

	int gemType;

public:

	void init(float gemT) { gemType = gemT; }

	void update(float deltaTime, Controller* player)
	{
		if (visible == true)
		{
			if (hb.checkCollision(player->hb, 0, 0))
			{
				visible = false;
				if (gemType == 1)
				{
					//player->addGem(1);

				}
				if (gemType == 2)
				{
					//player->addGem(2);

				}
				if (gemType == 3)
				{
					//player->addGem(3);

				}
					
			}
		}
	}

};