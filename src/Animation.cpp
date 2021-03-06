#include "Animation.h"

void Animation::init(vector<ofImage> Frames)
{
	currentFrame = 0;
	currentTime = 0;
	animationFrames = Frames;
}

void Animation::update(float deltaTime)
{
	currentTime += deltaTime;

	while (currentTime >= (1.0f / 16.0f))//(float)frameRate of animation
	{
		currentTime -= 1.0f / 16.0f;
		++currentFrame;
	}

	while (currentFrame >= animationFrames.size())
	{
		currentFrame -= animationFrames.size();
	}

}

void Animation::draw(ofVec2f position)
{
	animationFrames[currentFrame].draw(position);
}