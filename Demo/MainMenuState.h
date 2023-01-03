#pragma once
#include"State.h"

class MainMenuState:public State
{
public:
	MainMenuState();
	~MainMenuState();
	void OnInit();
	void OnUpdate(float deltaTime);
	void OnRender(Graphics *graphics);
	void OnExit();
private:
	
};

