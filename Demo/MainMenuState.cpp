#include "MainMenuState.h"
#include"ResourceManager.h"
#include"GamePlayState.h"

MainMenuState::MainMenuState()
{
}


MainMenuState::~MainMenuState()
{

}

void MainMenuState::OnInit()
{
	ResourceManager* resource = ResourceManager::GetInstance();
	m_butStart = resource->getUIButtonById(EnumButton::E_ButtonPlay);
	m_backGround = resource->getImageById(EnumImage::E_BackGround);
	m_textLogo = resource->getFontById(EnumFont::E_DefaultFont);
}

void MainMenuState::OnRender(Graphics *graphics)
{
	Device *device = Device::GetInstance();
	device->GetGraphics()->ClearScreen();
	ResourceManager* resource = ResourceManager::GetInstance();
	graphics->DrawImage(m_backGround, 0, 0, 0);
	m_butStart->SetPositionButton(Vector2(device->GetWidth() / 2 - 75, device->GetHeight() / 2));
	graphics->DrawUIButton(m_butStart);
	graphics->DrawTextWithFont(m_textLogo, device->GetWidth() / 2 - 120,
		device->GetHeight() / 2-100, "Space shooter");

}

void MainMenuState::OnUpdate(float deltaTime)
{
	if (m_butStart->IsPressedButton())
	{
		State* nextState = new GamePlayState();
		StateMachine::GetInstance()->SwitchState(nextState);
	}
}

void MainMenuState::OnExit()
{
	delete this;
}