#include "Level.h"

void Level::init()
{
	background.load("Floor.png");
	wall.load("Wall.png");
}

void Level::draw()
{
	background.draw(0, 0);

	//edges
	for (int i = 0; i < 32; i++)
	{
		wall.draw(i * 32, 0);
		wall.draw(i * 32, 768-32);
		wall.draw(0, i * 32);
		wall.draw(1024-32, i * 32);
	}

	for (int i = 10; i < 20; i++)
	{
		wall.draw(i * 32, 32 * 8);

		wall.draw(i * 32, 32 * 11);

		if (i != 11 && i != 12 && i != 13 && i != 14)
		{
			wall.draw((i - 10) * 32, 32 * 14);
		}

		wall.draw((i - 10) * 32, 32 * 17);
		
	}

	//horizontal
	tempHB.init(10 * 32, 32 * 8, 32 * 10, 32, 0, 1);
	hbs.push_back(Hitbox(tempHB));

	tempHB.init(10 * 32, 32 * 11, 32 * 10, 32, 0, 1);
	hbs.push_back(Hitbox(tempHB));

	tempHB.init(1 * 32, 32 * 17, 32 * 9, 32, 0, 1);
	hbs.push_back(Hitbox(tempHB));

	tempHB.init(5 * 32, 32 * 14, 32 * 5, 32, 0, 1);
	hbs.push_back(Hitbox(tempHB));

	////vertical
	//tempHB.init(5 * 32, 32 * 14, 32, 32 * 4, 0, 1);
	//hbs.push_back(Hitbox(tempHB));



	for (int i = 0; i < 5; i++)
	{
		wall.draw((i + 22) * 32, 32 * 14);
		wall.draw((i + 22) * 32, 32 * 18);

	}
	tempHB.init(22 * 32, 32 * 14, 32 * 5, 32, 0, 1);
	hbs.push_back(Hitbox(tempHB));

	tempHB.init(22 * 32, 32 * 18, 32 * 5, 32, 0, 1);
	hbs.push_back(Hitbox(tempHB));


	wall.draw(27 * 32, 32 * 15);
	wall.draw(27 * 32, 32 * 16);
	wall.draw(27 * 32, 32 * 17);
	tempHB.init(27 * 32, 32 * 15, 32, 32 * 4, 0, 1);
	hbs.push_back(Hitbox(tempHB));

	wall.draw(27 * 32, 32 * 1);
	wall.draw(27 * 32, 32 * 2);
	wall.draw(27 * 32, 32 * 3);
	wall.draw(27 * 32, 32 * 4);
	wall.draw(27 * 32, 32 * 5);
	wall.draw(27 * 32, 32 * 6);
	wall.draw(27 * 32, 32 * 7);
	tempHB.init(27 * 32, 32 * 1, 32, 32 * 8, 0, 1);
	hbs.push_back(Hitbox(tempHB));


}