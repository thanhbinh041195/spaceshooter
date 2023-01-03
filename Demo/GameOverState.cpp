#include "GameOverState.h"
#include"GamePlayState.h"
#include"MainMenuState.h"
#include"ResourceManager.h"

extern int temp_Count;

GameOverState::GameOverState()
{
}


GameOverState::~GameOverState()
{

}

void GameOverState::OnInit()
{
	ResourceManager* resource = ResourceManager::GetInstance();
	m_backGround = resource->getImageById(EnumImage::E_BackGround);
	m_textScore = resource->getFontById(EnumFont::E_DefaultFont);
	m_textCount = resource->getFontById(EnumFont::E_DefaultFont);
	m_textGameOver = resource->getFontById(EnumFont::E_DefaultFont);
	m_butBack = resource->getUIButtonById(EnumButton::E_ButtonBack);
	m_butReplay = resource->getUIButtonById(EnumButton::E_ButtonReplay);
}

void GameOverState::OnRender(Graphics *graphics)
{
	char buffer[100];
	itoa(temp_Count, buffer, 10);
	Device *device = Device::GetInstance();
	graphics->DrawImage(m_backGround, 0, 0, 0);
	graphics->DrawTextWithFont(m_textGameOver, device->GetWidth() / 3.15, device->GetHeight() / 3, "Game over");
	graphics->DrawTextWithFont(m_textScore, device->GetWidth() / 3, device->GetHeight() / 2, "Score: ");
	graphics->DrawTextWithFont(m_textCount, device->GetWidth() / 1.875, device->GetHeight() / 2, buffer);
	m_butBack->SetPositionButton(Vector2(device->GetWidth() / 3.5, device->GetHeight() / 1.75));
	graphics->DrawUIButton(m_butBack);
	m_butReplay->SetPositionButton(Vector2(device->GetWidth() / 2, device->GetHeight() / 1.75));
	graphics->DrawUIButton(m_butReplay);
}

void GameOverState::OnUpdate(float deltaTime)
{
	if (m_butReplay->IsPressedButton())
	{
		State* nextState = new GamePlayState();
		m_listState.push_back(nextState);
		StateMachine::GetInstance()->SwitchState(nextState);
		temp_Count = 0;
	}
	if (m_butBack->IsPressedButton())
	{
		State* nextState = new MainMenuState();
		StateMachine::GetInstance()->SwitchState(nextState);
		temp_Count = 0;
	}
}

void GameOverState::OnExit()
{
	delete this;
}