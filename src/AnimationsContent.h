#pragma once
#include "ofMain.h"

class AnimationsContent
{
public:
	vector<ofImage> getAnimation(int animnum)
	{

		switch (animnum)
		{
		case 1://Character
			return playerFrames;
			break;
		case 2://Enemy1
			return enemyFrames;
			break;
		case 3://Enemy2
			break;
		case 4://Enemy3
			break;
		case 5://Spell1
			return spell1Frames;
			break;
		case 6://Spell2
			return spell2Frames;
			break;
		case 7://Tower1Spell
			return towerSpell1Frames;

			break;
		case 8://Tower2Spell
			return towerSpell2Frames;

			break;
		case 9://Tower3Spell
			return towerSpell3Frames;

			break;
		case 10://Wall
			break;
		case 11://Floor
			break;
		case 12://SolidButton
			break;
		default:
			break;
		}

	}
	void init()
	{
		//Init player animation frames
		for(int i = 0; i < 16; i++)
			playerFrames.push_back(ofImage());
		playerFrames[0].load("PlayerF1.png");
		playerFrames[1].load("PlayerF2.png");
		playerFrames[2].load("PlayerF3.png");
		playerFrames[3].load("PlayerF4.png");
		playerFrames[4].load("PlayerF5.png");
		playerFrames[5].load("PlayerF6.png");
		playerFrames[6].load("PlayerF7.png");
		playerFrames[7].load("PlayerF8.png");
		playerFrames[8].load("PlayerF9.png");
		playerFrames[9].load("PlayerF10.png");
		playerFrames[10].load("PlayerF11.png");
		playerFrames[11].load("PlayerF12.png");
		playerFrames[12].load("PlayerF13.png");
		playerFrames[13].load("PlayerF14.png");
		playerFrames[14].load("PlayerF15.png");
		playerFrames[15].load("PlayerF16.png");

		//Init enemy animation frames
		for (int i = 0; i < 8; i++)
			enemyFrames.push_back(ofImage());
		enemyFrames[0].load("Enemy1F1.png");
		enemyFrames[1].load("Enemy1F2.png");
		enemyFrames[2].load("Enemy1F3.png");
		enemyFrames[3].load("Enemy1F4.png");
		enemyFrames[4].load("Enemy1F5.png");
		enemyFrames[5].load("Enemy1F6.png");
		enemyFrames[6].load("Enemy1F7.png");
		enemyFrames[7].load("Enemy1F8.png");
		
		//Init play spell1 animation frames
		for (int i = 0; i < 4; i++)
			spell1Frames.push_back(ofImage());
		spell1Frames[0].load("Spell1F1.png");
		spell1Frames[1].load("Spell1F2.png");
		spell1Frames[2].load("Spell1F3.png");
		spell1Frames[3].load("Spell1F4.png");

		//Init play towerspell1 animation frames
		for (int i = 0; i < 4; i++)
			towerSpell1Frames.push_back(ofImage());
		towerSpell1Frames[0].load("TowerSpell1F1.png");
		towerSpell1Frames[1].load("TowerSpell1F2.png");
		towerSpell1Frames[2].load("TowerSpell1F3.png");
		towerSpell1Frames[3].load("TowerSpell1F4.png");

		//Init play towerspell2 animation frames
		for (int i = 0; i < 4; i++)
			towerSpell2Frames.push_back(ofImage());
		towerSpell2Frames[0].load("TowerSpell2F1.png");
		towerSpell2Frames[1].load("TowerSpell2F2.png");
		towerSpell2Frames[2].load("TowerSpell2F3.png");
		towerSpell2Frames[3].load("TowerSpell2F4.png");

		//Init play towerspell3 animation frames
		for (int i = 0; i < 4; i++)
			towerSpell2Frames.push_back(ofImage());
		towerSpell2Frames[0].load("TowerSpell3F1.png");
		towerSpell2Frames[1].load("TowerSpell3F2.png");
		towerSpell2Frames[2].load("TowerSpell3F3.png");
		towerSpell2Frames[3].load("TowerSpell3F4.png");
	
	}
private:
	vector<ofImage> playerFrames;
	vector<ofImage> enemyFrames;
	vector<ofImage> spell1Frames;
	vector<ofImage> spell2Frames;
	vector<ofImage> towerSpell1Frames;
	vector<ofImage> towerSpell2Frames;
	vector<ofImage> towerSpell3Frames;
	//vector<ofImage> towerSpell3Frames;
	//vector<ofImage> towerSpell3Frames;
};
