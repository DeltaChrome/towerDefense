#pragma once

#include "ofMain.h"
#include "AnimationsContent.h"
#include "Player.h"
#include "Tower.h"
#include "Enemy.h"
#include "Ability.h"
#include "DeltaTimer.h"
#include "WaveManager.h"
#include "Level.h"
#include "Button.h"
#include "Coin.h"
#include "TowerGem.h"
#include <time.h>

class ofApp : public ofBaseApp
{
	public:
		void setup();
		void update();
		void draw();

		ofFpsCounter fps;

		int enemyCounter;

		Level mainLevel;
		Player player;
		Enemy enemy;
		Tower activeTower;
		Coin coinTemp;
		TowerGem towerGemTemp;
		bool placingTower = false;
		DeltaTimer gameTime;
		AnimationsContent frameData;

		vector<Controller*> towers;
		vector<Controller*> enemies;
		vector<ofVec2f> path;
		vector<Coin*> coins;
		vector<TowerGem> towerGems;

		WaveManager waves;

		Button buttons[3];
		int costs[3] = { 30, 60, 120 };
		ofTrueTypeFont font;

		ofImage background;
		ofImage crosshair;

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		void newSpawn();
		
};
