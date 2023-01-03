#include "GamePlayState.h"
#include"SpaceShooter.h"
#include"Rock.h"
#include"Bullet.h"
#include"GameOverState.h"
#include"ResourceManager.h"

SpaceShooter *MC;
int temp_Count;

GamePlayState::GamePlayState()
{
}


GamePlayState::~GamePlayState()
{
	for (list<Bullet*>::iterator i = m_listBullet1.begin(); i != m_listBullet1.end();)
	{
		delete (*i);
		m_listBullet1.erase(i);
		i = m_listBullet1.begin();
	}
	for (list<Bullet*>::iterator i = m_listBullet2.begin(); i != m_listBullet2.end();)
	{
		delete (*i);
		m_listBullet2.erase(i);
		i = m_listBullet2.begin();
	}
	for (list<Rock*>::iterator i = m_listRock.begin(); i != m_listRock.end();)
	{
		delete (*i);
		m_listRock.erase(i);
		i = m_listRock.begin();
	}
	delete MC;
}

void GamePlayState::OnInit()
{
	ResourceManager* resource = ResourceManager::GetInstance();
	m_backGround = resource->getImageById(EnumImage::E_BackGround);
	m_textScore = resource->getFontById(EnumFont::E_DefaultFont);
	m_textCount = resource->getFontById(EnumFont::E_DefaultFont);
	MC = new SpaceShooter();
	for (int i = 0; i < EnumRock::E_MaxRock; i++)
	{

		m_listRock.push_back(new Rock());
	}
	for (int i = 0; i <= EnumBullet::E_MaxBullet; i++)
	{
		m_listBullet1.push_back(new Bullet());
	}
	for (int i = 0; i <= EnumBullet::E_MaxBullet; i++)
	{
		m_listBullet2.push_back(new Bullet());
	}
	for (list<Bullet*>::iterator bullet = m_listBullet1.begin(); bullet != m_listBullet1.end(); bullet++)
	{
		(*bullet)->setPosition(Vector2(MC->getPosition().x + MC->getImage()->GetHeight() / 6.4, MC->getPosition().y));
	}
	for (list<Bullet*>::iterator bullet = m_listBullet2.begin(); bullet != m_listBullet2.end(); bullet++)
	{
		(*bullet)->setPosition(Vector2(MC->getPosition().x + MC->getImage()->GetHeight() / 1.6, MC->getPosition().y));
	}
}

void GamePlayState::OnRender(Graphics *graphics)
{
	char buffer[100];
	itoa(temp_Count, buffer, 10);
	Device *device = Device::GetInstance();
	device->GetGraphics()->ClearScreen();
	graphics->DrawImage(m_backGround, 0, 0, 0);
	graphics->DrawTextWithFont(m_textScore, device->GetWidth() / 20, device->GetHeight() / 40, "Score: ");
	graphics->DrawTextWithFont(m_textCount, device->GetWidth() / 4.2, device->GetHeight() / 40, buffer);
	MC->Render(graphics);
	for (list<Rock*>::iterator rock = m_listRock.begin(); rock != m_listRock.end(); rock++)
	{
		(*rock)->Render(graphics);
	}
	for (list<Bullet*>::iterator bullet = m_listBullet1.begin(); bullet != m_listBullet1.end(); bullet++)
	{
		(*bullet)->Render(graphics);
	}
	for (list<Bullet*>::iterator bullet = m_listBullet2.begin(); bullet != m_listBullet2.end(); bullet++)
	{
		(*bullet)->Render(graphics);
	}
}

void GamePlayState::OnUpdate(float deltaTime)
{
	MC->Update(deltaTime);
	UpdateRock(deltaTime);
	UpdateShoot(deltaTime);
	CheckColison();
}

void GamePlayState::UpdateShoot(float deltaTime)
{
	static float countdown;
	countdown -= 3 * deltaTime;
	if (countdown <= 0.0f)
	{
		for (list<Bullet*>::iterator bullet = m_listBullet1.begin(); bullet != m_listBullet1.end(); bullet++)
		{
			if ((*bullet)->check == false)
			{ 
				(*bullet)->check = true;
				break;
			}
		}
		for (list<Bullet*>::iterator bullet = m_listBullet2.begin(); bullet != m_listBullet2.end(); bullet++)
		{
			if ((*bullet)->check == false)
			{
				(*bullet)->check = true;
				break;
			}
		}
		countdown =1.0f;
	}
	for (list<Bullet*>::iterator bullet = m_listBullet1.begin(); bullet != m_listBullet1.end(); bullet++)
	{
		(*bullet)->Update(deltaTime);
		if ((*bullet)->getPosition().y < 0 || (*bullet)->check == false)
		{
			(*bullet)->setPosition(Vector2(MC->getPosition().x + MC->getImage()->GetHeight() /6.4, MC->getPosition().y));
			(*bullet)->check = false;
		}
	}
	for (list<Bullet*>::iterator bullet = m_listBullet2.begin(); bullet != m_listBullet2.end(); bullet++)
	{
		(*bullet)->Update(deltaTime);
		if ((*bullet)->getPosition().y < 0 || (*bullet)->check == false)
		{
			(*bullet)->setPosition(Vector2(MC->getPosition().x + MC->getImage()->GetHeight() / 1.6, MC->getPosition().y));
			(*bullet)->check = false;
		}
	}
}

void GamePlayState::UpdateRock(float deltaTime)
{
	for (list<Rock*>::iterator rock = m_listRock.begin(); rock != m_listRock.end(); rock++)
	{
		(*rock)->Update(deltaTime);
		if (
			(*rock)->getPosition().x >= MC->getPosition().x - (*rock)->getImage()->GetHeight() / 2 &&
			(*rock)->getPosition().x <= MC->getPosition().x + (*rock)->getImage()->GetHeight() *2 &&
			(*rock)->getPosition().y >= MC->getPosition().y - (*rock)->getImage()->GetWidth() / 2&&
			(*rock)->getPosition().y <= MC->getPosition().y + (*rock)->getImage()->GetWidth() * 2)
			
		{
			GameOverState *nextState = new GameOverState();
			StateMachine::GetInstance()->SwitchState(nextState);	
		}
	}
}

void GamePlayState::CheckColison()
{
	for (list<Rock*>::iterator rock = m_listRock.begin(); rock != m_listRock.end(); rock++)
	{
		for (list<Bullet*>::iterator bullet = m_listBullet1.begin(); bullet != m_listBullet1.end(); bullet++)
		{
			if ((*bullet)->getPosition().x >= (*rock)->getPosition().x - (*rock)->getImage()->GetHeight() / 2.2 &&
				(*bullet)->getPosition().x <= (*rock)->getPosition().x + (*rock)->getImage()->GetHeight() / 1.2 &&
				(*bullet)->getPosition().y >= (*rock)->getPosition().y - (*rock)->getImage()->GetWidth() / 2 &&
				(*bullet)->getPosition().y <= ((*rock)->getPosition().y + (*rock)->getImage()->GetWidth() / 2))
			{
				(*bullet)->setPosition(Vector2(MC->getPosition().x, MC->getPosition().y));
				(*rock)->setPosition(Vector2(rand() % EnumDisplay::E_Width, EnumDisplay::E_Height));
				(*bullet)->check = false;
				temp_Count++;
			}
			
		}
	}
	for (list<Rock*>::iterator rock = m_listRock.begin(); rock != m_listRock.end(); rock++)
	{
		for (list<Bullet*>::iterator bullet = m_listBullet2.begin(); bullet != m_listBullet2.end(); bullet++)
		{
			if ((*bullet)->getPosition().x >= (*rock)->getPosition().x - (*rock)->getImage()->GetHeight() / 2.2&&
				(*bullet)->getPosition().x <= (*rock)->getPosition().x + (*rock)->getImage()->GetHeight() / 1.2 &&
				(*bullet)->getPosition().y >= (*rock)->getPosition().y - (*rock)->getImage()->GetWidth() / 2 &&
				(*bullet)->getPosition().y <= ((*rock)->getPosition().y + (*rock)->getImage()->GetWidth() / 2))
			{
				(*bullet)->setPosition(Vector2(MC->getPosition().x, MC->getPosition().y));
				(*rock)->setPosition(Vector2(rand() % EnumDisplay::E_Width, EnumDisplay::E_Height));
				(*bullet)->check = false;
				temp_Count++;
			}

		}
	}
}

void GamePlayState::OnExit()
{
	delete this;
}
