#pragma once

#include "ofMain.h"
#include "AnimationsContent.h"
#include "DeltaTimer.h"
#include "Player.h"
#include "Tower.h"
#include "Enemy.h"
#include "Ability.h"
#include "Button.h"

class ofApp : public ofBaseApp
{
	public:
		void setup();
		void update();
		void draw();

		DeltaTimer gameTime;
		AnimationsContent frameData;

		Player player;
		Enemy enemy;
		Tower activeTower;
		bool placingTower = false;

		vector<Controller*> towers;
		vector<Controller*> enemies;
		vector<ofVec2f> path;

		Button buttons[3];
		ofTrueTypeFont font;

		ofImage background;

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
		
};
