#pragma once
#include"Object.h"

class SpaceShooter:public Object
{
public:
	SpaceShooter();
	~SpaceShooter();
	void Update(float deltaTime);
	void Render(Graphics* graphics);
private:
	list<Image*> listTempImages;
	list<Image*> listImages;
};