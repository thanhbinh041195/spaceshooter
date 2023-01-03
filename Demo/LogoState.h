#pragma once
#include"State.h"

class LogoState:public State
{
public:
	LogoState();
	~LogoState();
	void OnInit();
	void OnUpdate(float deltaTime);
	void OnRender(Graphics *graphics);
	void OnExit();
private:
};

