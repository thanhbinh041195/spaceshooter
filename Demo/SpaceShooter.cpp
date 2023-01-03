#include"SpaceShooter.h"
#include"ResourceManager.h"

Device *device = Device::GetInstance();
Vector2 entry_Pos;
Vector2 entry_Distance;
Vector2 temp;
Animation *animation;

SpaceShooter::SpaceShooter()
{
	ResourceManager* resource = ResourceManager::GetInstance();
	m_image = resource->getImageById(EnumImage::E_Spaceshooter);
	m_animation = resource->getAnimationByID(EnumAnimation::E_SpaceShooter);
	m_animation->PlayAnimation();
	m_position.x = device->GetWidth() / 2.25;
	m_position.y = device->GetHeight() / 1.2;
	entry_Pos.x = 0;
	entry_Pos.y = 0;
	/*entry_Distance.x = 0;
	entry_Distance.y = 0;
	temp.x = m_position.x;
	temp.y = m_position.y;*/
}
SpaceShooter::~SpaceShooter()
{

}
void SpaceShooter::Update(float deltaTime)
{
	InputManager *inputManager = InputManager::GetInstance();
	TouchData *touchData = inputManager->GetTouch();
	/*if (touchData != NULL && touchData->state == TOUCH_DOWN)
	{
	entry_Pos.x = touchData->position.x;
	entry_Pos.y = touchData->position.y;
	}
	else if (touchData != NULL && touchData->state == TOUCH_MOVE)
	{
	entry_Distance.x = (touchData->position.x - entry_Pos.x);
	entry_Distance.y = (touchData->position.y - entry_Pos.y);
	m_position.x = temp.x + entry_Distance.x;
	m_position.y = temp.y + entry_Distance.y;
	}
	else if (touchData != NULL && touchData->state == TOUCH_UP)
	{
	temp.x = m_position.x;
	temp.y = m_position.y;
	}*/
	if (touchData != NULL && (touchData->state == TOUCH_DOWN || touchData->state == TOUCH_MOVE))
	{
		entry_Pos = touchData->position - m_position - Vector2(m_image->GetWidth() / 2, m_image->GetHeight() / 2);
		if (entry_Pos.Length() < 10)
		{
			m_position = touchData->position - Vector2(m_image->GetWidth() / 2, m_image->GetHeight() / 2);
		}
		else

		{
			entry_Pos = entry_Pos / entry_Pos.Length();
			m_position += entry_Pos * deltaTime * E_SpaceshooterVelorcity;
		}
	}

}
void SpaceShooter::Render(Graphics* graphics)
{
	graphics->DrawImage(m_image, m_position.x, m_position.y);
	graphics->DrawAnimation(m_animation, m_position.x, m_position.y);
}