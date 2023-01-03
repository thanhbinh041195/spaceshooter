#include"Bullet.h"
#include"ResourceManager.h"
#include"SpaceShooter.h"

Bullet::Bullet()
{
	ResourceManager* resource = ResourceManager::GetInstance();
	m_image = resource->getImageById(EnumImage::E_Bullet);
	m_velocity.x = 0;
	m_velocity.y = EnumSpeed::E_BulletSpeed;
	check = false;
}
Bullet::~Bullet()
{

}
void Bullet::Update(float deltaTime)
{
	if (check == true)
	{
		m_position.y -= m_velocity.y * deltaTime;
	}
}
void Bullet::Render(Graphics* graphics)
{
	if (check == true)
	{
		graphics->DrawImage(m_image, m_position.x, m_position.y);
	}
}