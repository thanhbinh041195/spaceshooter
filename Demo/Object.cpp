#include"Object.h"

Object::Object()
{ 

}
Object::~Object()
{

}
Vector2 Object::getPosition()
{
	return m_position;
}
void Object::setPosition(Vector2 position)
{
	m_position = position;
}
Vector2 Object::getVelocity()
{
	return m_velocity;
}

void Object::setVelocity(Vector2 Velocity)
{
	m_velocity = Velocity;
}

Image* Object::getImage()
{
	return m_image;
}

