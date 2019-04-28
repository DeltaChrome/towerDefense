#pragma once
#include "GameObject.h"

class Coin : public GameObject
{
private:



public:

	void update(float deltaTime, Controller* player)
	{
		hb.setX(position.x);
		hb.setY(position.y);

		cout << visible << endl;


		if (visible == true)
		{
			if (hb.checkCollision(player->hb, 0, 0))
			{
				visible = false;
				player->addMoney(25);
			}
		}

	}

};
