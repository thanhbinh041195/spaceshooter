#include"Rock.h"
#include"ResourceManager.h"

Rock::Rock()
{
	ResourceManager* resource = ResourceManager::GetInstance();
	m_image = resource->getImageById(EnumImage::E_Rock);
	m_position.y = -(rand() % 810);
	m_position.x = rand() % 550;
	m_velocity.x = 0;
	m_velocity.y = rand() % EnumSpeed::E_RockMaxSpeed + EnumSpeed::E_RockMinSpeed;
}
Rock::~Rock()
{
	
}
void Rock::Update(float deltaTime)
{
	m_position.y += m_velocity.y * deltaTime;
	if (m_position.y > 800)
	{
		m_position.y = -800;
		m_position.x = rand() % 550;
	}
}
void Rock::Render(Graphics* graphics)
{
	graphics->DrawImage(m_image, m_position.x, m_position.y);
}