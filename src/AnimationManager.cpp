#include "AnimationManager.h"

void AnimationManager::init(vector<ofImage>& a, int size)//could add break points to see when each animation starts/length of animation if we dont have a set animation length
{
	Animation tempAnimation;
	tempAnimation.init(a);
	animations.push_back(tempAnimation);
	currentAnimation = &animations[0];
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