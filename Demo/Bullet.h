#pragma once
#include"Object.h"

class Bullet :public Object
{
public:
	Bullet();
	~Bullet();
	void Update(float deltaTime);
	void Render(Graphics* graphics);
	bool check;
private:
};