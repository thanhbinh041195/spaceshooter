#pragma once
#include"Object.h"
#include"Rock.h"
#include"Bullet.h"
#include"Define.h"

class State
{
public:
	State();
	virtual ~State();
	virtual void OnInit() = 0;
	virtual void OnUpdate(float deltaTime) = 0;
	virtual void OnRender(Graphics *graphics) = 0;
	virtual void OnExit() = 0;
protected:
	Image *m_backGround;
	Font *m_textScore, *m_textCount, *m_textLogo, *m_textGameOver;
	UIButton *m_butStart, *m_butBack, *m_butReplay;
	list<State*> m_listState;
	list<Rock*> m_listRock;
	list<Bullet*> m_listBullet1;
	list<Bullet*> m_listBullet2;
};

