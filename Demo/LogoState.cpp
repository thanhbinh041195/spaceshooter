#include "LogoState.h"
#include"ResourceManager.h"
#include"MainMenuState.h"
#include"StateMachine.h"

int timer= 0;


LogoState::LogoState()
{
	OnInit();
}


LogoState::~LogoState()
{
	
}

void LogoState::OnInit()
{
	ResourceManager* resource = ResourceManager::GetInstance();
	m_backGround = resource->getImageById(EnumImage::E_BackGround);
}

void LogoState::OnRender(Graphics *graphics)
{
	Device *device = Device::GetInstance();
	device->GetGraphics()->ClearScreen();
	graphics->DrawImage(m_backGround, 0, 0, 0);
	graphics->SetColor(1.0f, 1.0f, 0.0f);
	graphics->DrawRect(device->GetWidth() / 2.67, device->GetHeight() / 2, device->GetWidth() / 4, 50);
	graphics->SetColor(1.0f, 1.0f, 1.0f);
	graphics->FillRect(device->GetWidth() / 2.67, device->GetHeight()/2, timer++, 50);
}

void LogoState::OnUpdate(float deltaTime)
{
	if (timer == 150)
	{
		State* nextState = new MainMenuState();
		StateMachine::GetInstance()->SwitchState(nextState);
	}
}

void LogoState::OnExit()
{
	delete this;
}