#pragma once
#include "Animation.h"

class AnimationManager
{
private:

	//animations array
	vector<Animation> animations;
	//current animation
	Animation* currentAnimation;

public:
	
	void init(vector<Animation>& animations);
	void update(float deltaTime);
	void draw(ofVec2f position);

};
