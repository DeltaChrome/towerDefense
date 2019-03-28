#pragma once
#include "ofMain.h"

class Animation
{
private:

	vector<ofImage> animationFrames;
	int startFrame;

public:
	
	void init();
	void update();
	void draw();

};
