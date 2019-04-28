#include "ofApp.h"

// Functions
void BoundaryCollision(Controller* dynamic, int width, int height, ofVec4f& boundaries);

//--------------------------------------------------------------
void ofApp::setup(){

	srand(time(NULL));

	mainLevel.init();
	frameData.init();
	waves.init();

	// GUI
	ofTrueTypeFont::setGlobalDpi(72);
	font.load("verdana.ttf", 24, true, true);
	font.setLineHeight(34.0f);
	font.setLetterSpacing(1.035);

	Tower blueTower;
	blueTower.init("BlueTower.png", ofVec2f(0, 0), Ability(), 50, 10);
	Tower pinkTower;
	pinkTower.init("PinkTower.png", ofVec2f(0, 0), Ability(), 100, 20);
	Tower redTower;
	redTower.init("RedTower.png", ofVec2f(0, 0), Ability(), 200, 30);

	buttons[0].init("Button.png", "ButtonSolid.png", 0, ofGetWindowHeight() - 60, 150, 60, blueTower);
	buttons[1].init("Button.png", "ButtonSolid.png", 150, ofGetWindowHeight() - 60, 150, 60, pinkTower);
	buttons[2].init("Button.png", "ButtonSolid.png", 300, ofGetWindowHeight() - 60, 150, 60, redTower);

	//init path for enemies
	path = { ofVec2f(100, 100), ofVec2f(800, 100), ofVec2f(800, 300), ofVec2f(100, 300), ofVec2f(100, 500), ofVec2f(800, 500) };

	//init player
	player.init(frameData.getAnimation(1));

	//init towers
	activeTower.init("BlueTower.png", ofVec2f(0, 0), Ability(), 100, 10);
	
	//init timer
	gameTime.Init();
}

//--------------------------------------------------------------
void ofApp::update(){

	fps.newFrame();

	//update wave manager
	waves.update(gameTime.GetDeltaTime());

	//check to spawn enemy
	newSpawn();

	//update player
	player.update(towers, gameTime.GetDeltaTime(), mainLevel.getHitBoxes(), enemies);

	//update enemies
	for (Controller* e : enemies)
		e->update();

	//update towers
	for (Controller* t : towers)
		t->update();

	//update coins
	for (Coin* c : coins)
		c->update(gameTime.GetDeltaTime(), &player);
	
	if (placingTower)
		activeTower.update();
	
	// Boundary (left x, top y, right x, bottom y)
	BoundaryCollision(&player, 32, 32, ofVec4f(0, 0, ofGetWindowWidth(), ofGetWindowHeight()));
	BoundaryCollision(&activeTower, 32, 32, ofVec4f(0, 0, ofGetWindowWidth(), ofGetWindowHeight()));

	fps.update();

	//tick timer
	gameTime.Update();
}

//--------------------------------------------------------------
void ofApp::draw(){

	mainLevel.draw();

	for (Controller* t : towers)
		t->draw();
	
	for (Controller* e : enemies)
		e->draw();

	for (Coin* c : coins)
		c->draw();

	player.draw();

	if (placingTower)
		activeTower.draw();
		
	for (int i = 0; i < 3; i++)
	{
		if (coin >= costs[i])
			ofSetColor(225);
		else
			ofSetColor(60);

		buttons[i].draw(font, costs[i]);
	}

	if (placingTower)
		activeTower.draw();

	ofSetColor(225);
	//font.drawString(to_string(fps.getFps()), 100, 100);
	string playerHealth = "Health: " + to_string(player.currentHealth) + "/" + to_string(player.maxHealth);
	font.drawString(playerHealth, ofGetWindowWidth() - 280, ofGetWindowHeight() - 40);
	font.drawString(to_string(coin), ofGetWindowWidth() - 280, ofGetWindowHeight() - 12);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	switch (key)
	{
	// Vertical
	case 'w':
		player.input.y = -1;
		break;
	case 's':
		player.input.y = 1;
		break;

	// Horizontal
	case 'a':
		player.input.x = -1;
		break;
	case 'd':
		player.input.x = 1;
		break;

	default:
		break;
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	// Vertical
	if (key == 'w' || key == 's')
		player.input.y = 0;

	// Horizontal
	if (key == 'a' || key == 'd')
		player.input.x = 0;

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	activeTower.cursor = ofVec2f(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	if (button == OF_MOUSE_BUTTON_LEFT)
	{
		if (placingTower)
		{
			activeTower.isPlaced = true;

			activeTower.hb.setX(x);
			activeTower.hb.setY(y);
			towers.push_back(new Tower(activeTower));

			placingTower = false;
		}
		else
		{
			for (int i = 0; i < 3; i++)
			{
				if (buttons[i].click(x, y) && coin >= costs[i])
				{
					coin -= costs[i];

					activeTower = buttons[i].tower;
					activeTower.cursor = ofVec2f(x, y);
					placingTower = true;
					activeTower.isPlaced = false;
				}
			}
		}
	}

	if (button == OF_MOUSE_BUTTON_RIGHT)
	{
		placingTower = false;

		coin += 5;
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if (button == OF_MOUSE_BUTTON_LEFT)
	{
		for (int i = 0; i < 3; i++)
			buttons[i].clicked = false;
	}
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void BoundaryCollision(Controller* dynamic, int width, int height, ofVec4f& boundaries)
{
	if (dynamic->position.x < boundaries.x+32)
		dynamic->position.x = boundaries.x+32;
			   
	if (dynamic->position.y < boundaries.y+32)
		dynamic->position.y = boundaries.y+32;
			   
	if (dynamic->position.x > boundaries.z-32 - width)
		dynamic->position.x = boundaries.z-32 - width;
			   
	if (dynamic->position.y > boundaries.w-32 - height)
		dynamic->position.y = boundaries.w-32 - height;
}

void ofApp::newSpawn()
{
	if (waves.getNewWave())
	{
		if (waves.getSpawn())
		{
			switch (waves.getEnemyLevel())
			{
			case 1:
				enemy.init("Enemy1F1.png", path, 1, Ability(), 100, 100, &towers, &player);
				enemies.push_back(new Enemy(enemy));
				break;
			case 2:
				enemy.init("Enemy1F1.png", path, 1, Ability(), 150, 100, &towers, &player);
				enemies.push_back(new Enemy(enemy));
				break;
			case 3:
				enemy.init("Enemy1F1.png", path, 1, Ability(), 300, 100, &towers, &player);
				enemies.push_back(new Enemy(enemy));
				break;
			default:
				break;
			}
			for (int i = 0; i < 2; i++)
			{
				coinTemp.init("Coin.png");
				coins.push_back(new Coin(coinTemp));
			}
		}
	}
}