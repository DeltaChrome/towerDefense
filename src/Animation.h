#pragma once
#include "ofMain.h"

class Animation
{
private:

	vector<ofImage> animationFrames;
	int startFrame;
	int currentFrame;
	float currentTime;

public:
	
	void init(vector<ofImage> Frames);
	void update(float deltaTime);
	void draw(ofVec2f position);

};
