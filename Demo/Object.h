#pragma once
#include <GameEngine.h>
#include<stdio.h>
#include<map>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Object
{
public:
	Object();
	virtual ~Object();
	virtual void Update(float deltaTime) = 0;
	virtual void Render(Graphics* graphics) = 0;
	Vector2 getPosition();
	void setPosition(Vector2);
	Vector2 getVelocity();
	void setVelocity(Vector2);
	Image* getImage();
private:
protected:
	Vector2 m_position;
	Vector2 m_velocity;
	Image* m_image;
	Animation * m_animation;
	int m_type;
	bool isEnable;
};
