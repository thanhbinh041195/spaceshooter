#pragma once
#include"StateMachine.h"


class ResourceManager
{
public:
	static ResourceManager* GetInstance();
	static void DestroyInstance();
	void Init(const char *path);
	Image* getImageById(char id);
	Font* getFontById(char id);
	UIButton* getUIButtonById(char id);
	Animation* getAnimationByID(char id);
private:
	ResourceManager();
	~ResourceManager();
	static ResourceManager *instance;
	map<char, Image*> images;
	map<char, Font*> font;
	map<char, UIButton*> button;
	map<char, Animation*> listAnimation;
};

