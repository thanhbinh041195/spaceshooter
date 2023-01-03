#pragma once
#include"State.h"

class GameOverState:public State
{
public:
	GameOverState();
	~GameOverState();
	void OnInit();
	void OnUpdate(float deltaTime);
	void OnRender(Graphics *graphics);
	void OnExit();
};

