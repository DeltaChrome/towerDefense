#include "AnimationManager.h"

void AnimationManager::init(vector<Animation>& a)//could add break points to see when each animation starts/length of animation if we dont have a set animation length
{
	animations = a;
	//set first animation as current animation
}

void AnimationManager::update(float deltaTime)
{
	//if()current animation should be the same ***based on input from user***
		//if it changed, then switch animations
		//change to different animation in vector as current animation
	currentAnimation->update(deltaTime);
}

void AnimationManager::draw(ofVec2f position)
{
	currentAnimation->draw(position);
}