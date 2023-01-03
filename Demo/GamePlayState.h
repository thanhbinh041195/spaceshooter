#pragma once
#include"State.h"

class GamePlayState:public State
{
public:
	GamePlayState();
	~GamePlayState();
	void OnInit();
	void OnUpdate(float deltaTime);
	void OnRender(Graphics *graphics);
	void OnExit();
	void UpdateShoot(float deltaTime);
	void UpdateRock(float deltaTime);
	void CheckColison();
private:
};

