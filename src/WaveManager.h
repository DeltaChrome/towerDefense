#pragma once
class WaveManager
{
private:

	int waveNum;
	int numEnemies;//enemies left to spawn
	int numEnemiesAlive;//enemies already spawned
	int enemyLevel;
	bool newWave;
	bool spawnNewEnemy;

	float tsinceLastSpawn;

public:
	
	void init()
	{
		waveNum = 0;
		numEnemiesAlive = 0;
		numEnemies = 0;
		enemyLevel = 0;
		spawnNewEnemy = 0;
		newWave = true;
		spawnNewEnemy = false;

		tsinceLastSpawn = 0.0f;

	}
	void update(float deltaTime)
	{
		tsinceLastSpawn += deltaTime;

		if (numEnemiesAlive == 0 && numEnemies == 0)
		{
			waveNum += 1;
			startWave();
			newWave = true;
		}
		else if (numEnemies == 0)
		{
			newWave = false;
		}

		if (newWave && tsinceLastSpawn > 2.0f)
		{
			spawnNewEnemy = true;
			numEnemies -= 1;
			numEnemiesAlive += 1;
			tsinceLastSpawn = 0.0f;
		}
		else
		{
			spawnNewEnemy = false;
		}

	}

	void startWave()
	{
		switch (waveNum)
		{
		case 1:
			//spawn  5 enemies + 2 * waveNum
			numEnemies = 2 * waveNum + 5;
			enemyLevel = 1;

			break;
		case 2:
			//spawn  5 enemies + 2 * waveNum
			numEnemies = 2 * waveNum + 5;
			enemyLevel = 1;

			break;
		case 3:
			//spawn  5 medium enemies + 2 * waveNum
			numEnemies = 2 * waveNum + 5;
			enemyLevel = 2;

			break;
		case 4:
			//spawn  5 medium enemies + 2 * waveNum
			numEnemies = 2 * waveNum + 5;
			enemyLevel = 2;

			break;
		case 5:
			//spawn  5 hard enemies + 2 * waveNum
			numEnemies = 2 * waveNum + 5;
			enemyLevel = 3;

			break;
		default:
			break;
		}
	}

	int getWaveNum() { return waveNum; }
	int getSpawnNumber() { return numEnemies; }
	int getEnemyLevel() { return enemyLevel; }
	bool getNewWave() { return newWave; }
	bool getSpawn() { return spawnNewEnemy; }
	void changeEnemiesAlive(int enemiesAlive) { numEnemiesAlive += enemiesAlive; }
};

