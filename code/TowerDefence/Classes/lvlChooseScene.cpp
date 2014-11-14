#include "lvlChooseScene.h"

lvlChooseScene::lvlChooseScene()
{
}

lvlChooseScene::~lvlChooseScene()
{
}

Scene *lvlChooseScene::createScene()
{
	auto scene = Scene::create();
	auto lvlScene = lvlChooseScene::create();// create() function defined at CREATE_FUNC()	
	scene->addChild(lvlScene);

	return scene;
}


bool lvlChooseScene::init()//create() function will call init()
{
	_lvl = 1;

	return true;
}

Label* lvlChooseScene::createLvlLabel(const char *lvlstr)
{
	auto lvlLable = Label::create(lvlstr, "Arail", 60);
	lvlLable->setColor(Color3B::RED);
	lvlLable->setPosition(ccp(60, 60));//Button size is 130x130
	return lvlLable;
}


void lvlChooseScene::lvl1(Ref *pSender)
{
	CCLOG("level 1");
}

void lvlChooseScene::lvl2(Ref *pSender)
{
	CCLOG("level 2");
}

void lvlChooseScene::lvl3(Ref *pSender)
{
	CCLOG("level 3");
}
