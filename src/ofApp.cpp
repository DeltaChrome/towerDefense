#include "ofApp.h"

// Functions
void BoundaryCollision(Controller* dynamic, int width, int height, ofVec4f& boundaries);

//--------------------------------------------------------------
void ofApp::setup(){

	mainLevel.init();
	frameData.init();
	waves.init();

	path = { ofVec2f(100, 100), ofVec2f(800, 100), ofVec2f(800, 300), ofVec2f(100, 300), ofVec2f(100, 500), ofVec2f(800, 500) };

	player.init(frameData.getAnimation(1));
	
	enemy.init("Enemy1F1.png", path, 1, Ability(), 100, 100, &towers, &player);
	enemies.push_back(new Enemy(enemy));

	activeTower.init("BlueTower.png", ofVec2f(0, 0), Ability(), 100, 10);

	gameTime.Init();
}

//--------------------------------------------------------------
void ofApp::update(){

	waves.update(gameTime.GetDeltaTime());

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
			
		}
	}

	player.update(towers, gameTime.GetDeltaTime());

	for (Controller* e : enemies)
		e->update();

	for (Controller* t : towers)
		t->update();
	
	if (placingTower)
		activeTower.update();
	
	// Boundary (left x, top y, right x, bottom y)
	BoundaryCollision(&player, 32, 32, ofVec4f(0, 0, ofGetWindowWidth(), ofGetWindowHeight()));
	BoundaryCollision(&activeTower, 32, 96, ofVec4f(0, 0, ofGetWindowWidth(), ofGetWindowHeight()));

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

	player.draw();

	if (placingTower)
		activeTower.draw();
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
	if (placingTower)
	{
		if (button == OF_MOUSE_BUTTON_LEFT)
		{
			activeTower.position = ofVec2f(x, y);
			activeTower.isPlaced = true;
			towers.push_back(new Tower(activeTower));
			
			//cout << towers.size() << " - position: (" << towers[towers.size() - 1]->position.x << ", " << towers[towers.size() - 1]->position.y << ") | active position: (" << activeTower.position.x << ", " << activeTower.position.y << ")" << endl;

			// Create a new tower;
			//activeTower.init("tower.png", ofVec2f(0, 0), Ability(), 100, 10);
			placingTower = false;
		}
	}

	if (button == OF_MOUSE_BUTTON_RIGHT)
	{
		activeTower.isPlaced = false;
		placingTower = true;
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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