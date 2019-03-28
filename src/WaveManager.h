#pragma once
class WaveManager
{
private:

	int waveNum;
	int numEnemies;//some number of waves, each wave as number of enemies
	int numEnemiesAlive;

public:
	
	void init();
	void update();

	void startWave();

};

