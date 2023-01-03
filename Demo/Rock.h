#pragma once
#include"Object.h"

class Rock :public Object
{
public:
	Rock();
	~Rock();
	void Update(float deltaTime);
	void Render(Graphics* graphics);
private:
};