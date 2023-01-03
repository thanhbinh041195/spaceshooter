#include "StateMachine.h"



StateMachine::StateMachine()
{
}


StateMachine::~StateMachine()
{
	m_currentState->OnExit();
}

StateMachine* StateMachine::instance = 0;

StateMachine* StateMachine::GetInstance()
{
	if (instance == 0)
	{
		instance = new StateMachine();
	}
	return instance;
}

void StateMachine::Init(const char *path)
{
	ResourceManager::GetInstance()->Init("Data.bin");
	m_isExitCurrentState = false;
	m_isEnterNextState = false;
	m_currentState = new LogoState();
}

void StateMachine::Render(Graphics *graphics)
{
	graphics->ClearScreen();
	m_currentState->OnRender(graphics);
}


void StateMachine::Update(float deltaTime)
{
	m_currentState->OnUpdate(deltaTime);
	if (m_isExitCurrentState)
	{
		m_isExitCurrentState = false;
		m_currentState->OnExit();
		m_isEnterNextState = true;
	}
	if (m_isEnterNextState)
	{
		m_isEnterNextState = false;
		m_currentState = m_nextState;
		m_currentState->OnInit();	
	}
}

void StateMachine::SwitchState(State *state)
{
	m_nextState = state;
	m_isExitCurrentState = true;
}

void StateMachine::DestroyInstance()
{
	delete instance;
}