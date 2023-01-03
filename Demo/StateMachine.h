#pragma once
#include"State.h"
#include"ResourceManager.h"
#include"GameOverState.h"
#include"GamePlayState.h"
#include"LogoState.h"
#include"MainMenuState.h"

class StateMachine
{
public:
	StateMachine();
	~StateMachine();
	static StateMachine* GetInstance();
	static void DestroyInstance();
	void Init(const char *path);
	void Update(float deltaTime);
	void Render(Graphics *graphics);
	void SwitchState(State *state);
private:
	State *m_currentState;
	State *m_nextState;
	bool m_isExitCurrentState;
	bool m_isEnterNextState;
	static StateMachine *instance;
};

